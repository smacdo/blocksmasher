/*
 * gameapp.cpp
 * Copyright 2012 Scott MacDonald
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "gameapp.h"
#include "utils.h"
#include "renderer.h"
#include "basescreen.h"
#include "gametime.h"
#include "resourcesloader.h"
#include "gameobjectfactory.h"
#include "inputmanager.h"

#include <SDL.h>
#include <string>
#include <vector>
#include <stdint.h>
#include <cassert>

/**
 * Game application constructor
 */
GameApp::GameApp( int argc, char ** argv )
    : mCommandLineArguments( &argv[0], &argv[argc] ),
      mContext(),
      mWasShutdown( false )
{

}

/**
 * Game application destructor
 */
GameApp::~GameApp()
{
    // In case we somehow forgot to clean up, do it as we're exiting
    if ( !mWasShutdown )
    {
        shutdown();
    }
}

/**
 * Runs the game to completion
 */
void GameApp::run( BaseScreen * pGameScreen )
{
    // First start the game up! (Otherwise we might have some issues)
    startup();

    // Hold on to the game scene, we're going to need during execution
    assert( pGameScreen != NULL && "Cannot run a null game screen" );
    mpGameScreen = pGameScreen;

    mpGameScreen->startup( mContext );

    // Now keep running the game until the player decides to quit
    uint64_t timerFreq = SDL_GetPerformanceFrequency();
    uint64_t startTime = SDL_GetPerformanceCounter();
    uint64_t lastTime  = startTime;
    uint64_t nowTime   = startTime;
    float elapsedTime  = 0.0;
    float gameTime     = 0.0;

    // Game loop
    while ( !mContext.isQuiting )
    {
        // Calculate the amount of time that has passed
        nowTime      = SDL_GetPerformanceCounter();
        timerFreq    = SDL_GetPerformanceFrequency();

        elapsedTime  = static_cast<float>(nowTime - lastTime) /
                       static_cast<float>(timerFreq);
        gameTime    += elapsedTime;

        // Update the simulation
        tick( GameTime( gameTime, elapsedTime ) );

        // Update timer
        lastTime = nowTime;
    }

    // Be a good person and clean up our mess before leaving
    shutdown();
}

/**
 * Executes a single time slice for the game
 */
void GameApp::tick( const GameTime& time )
{    
    doInput( time );
    doUpdate( time );
    doRender( time );
}

/**
 * Check for any new input that has occurred since the last time we
 * checked for input
 */
void GameApp::doInput( const GameTime& time )
{
    SDL_Event event;

    // Process the input queue and dispatch events to their proper managers for
    // handling
    InputManager& input = mContext.inputManager();

    while ( SDL_PollEvent( &event ) )
    {
        switch ( event.type )
        {
            case SDL_KEYDOWN:
                input.processKeyboardInput( event.key.keysym, true );
                break;

            case SDL_KEYUP:
                input.processKeyboardInput( event.key.keysym, false );
                break;

            case SDL_QUIT:
                mContext.isQuiting = true;
                break;
        }
    }

    // Did the player want to quit?
    if ( input.escapedPressed() )
    {
        mContext.isQuiting = true;
    }
}

/**
 * Updates all active game objects
 */
void GameApp::doUpdate( const GameTime& time )
{
    assert( mpGameScreen != NULL && "How on earth did you become null?" );

    // Update our processors
    mContext.movementProcessor().update( time );

    // Now let the game screen itself do any needed processing
    mpGameScreen->update( time, mContext );
}

/**
 * Draws all active game objects on the screen
 */
void GameApp::doRender( const GameTime& time )
{
    assert( mpGameScreen != NULL && "Cannot render a null game screen" );

    // Clear the screen before letting the active game scene take a crack at
    // drawing
    Renderer& renderer = mContext.renderer();

    renderer.clear();
    mpGameScreen->render( renderer );

    renderer.present();
}

/**
 * Game application start up code
 */
void GameApp::startup()
{
    SDL_Log( "The game is starting up\n" );

    // Allow SDL logging
    SDL_LogSetPriority( SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_SYSTEM, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_AUDIO, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_VIDEO, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_INPUT, SDL_LOG_PRIORITY_VERBOSE );

    // Ensure the game object is the first thing created
    GameObjectFactory * pFactory = new GameObjectFactory();
    mContext.setGameObjectFactory( pFactory );

    // Create the resources loader
    ResourcesLoader * pLoader = new ResourcesLoader();
    mContext.setResourcesLoader( pLoader );

    // Find all video drivers
    int driverCount = SDL_GetNumVideoDrivers();

    if ( driverCount == 0 )
    {
        raiseError( "Could not locate any video drivers" );
    }
    else
    {
        for ( int i = 0; i < driverCount; ++i )
        {
            const char * driverName = SDL_GetVideoDriver(i);
            
            mContext.drivers.push_back( driverName );
            SDL_Log( "Found %s video driver\n", driverName );
        }
    }

    // Configure various OpenGL settings
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 );
    SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 4 );
    SDL_GL_SetAttribute( SDL_GL_ACCELERATED_VISUAL, 1 );

    // Create a main window
    Uint32 windowFlags = SDL_WINDOW_SHOWN |
                         SDL_WINDOW_RESIZABLE; // SDL_WINDOW_INPUT_GRABBED

    mContext.pWindow = SDL_CreateWindow( mContext.window.title,
                                         mContext.window.x,
                                         mContext.window.y,
                                         mContext.window.width,
                                         mContext.window.height,
                                         windowFlags );

    if ( mContext.pWindow == NULL )
    {
        raiseError( "Failed to create main window", EERROR_SDL );
    }

    // Now create the renderer
    Uint32 renderFlags = SDL_RENDERER_ACCELERATED |
                         SDL_RENDERER_PRESENTVSYNC |
                         SDL_RENDERER_TARGETTEXTURE;

    mContext.pSdlRenderer = SDL_CreateRenderer( mContext.pWindow, -1, renderFlags );

    if ( mContext.pSdlRenderer == NULL )
    {
        raiseError( "Failed to create hardware accelerated renderer",
                    EERROR_SDL );
    }

    // Setup the forge graphics renderer
    Renderer * pRenderer = new Renderer( mContext, mContext.pSdlRenderer );
    mContext.setRenderer( pRenderer );

    // Set up our processors
    mContext.setMovementProcessor( new MovementProcessor() );

    // Rest of the system
    mContext.setInputManager( new InputManager );

    // So what happened?
    SDL_Log( "Using %s video driver\n", SDL_GetCurrentVideoDriver() );
}

/**
 * Game application shutdown code
 */
void GameApp::shutdown()
{
    assert( !mWasShutdown && "Cannot shutdown more than once" );

    // Destroy the active game scene
    mpGameScreen->shutdown( mContext );
    delete mpGameScreen;

    // Destroy our subsystems
    mContext.setRenderer( NULL );
    mContext.setResourcesLoader( NULL );
    mContext.setInputManager( NULL );

    // Now unload our OpenGL context
    if ( mContext.glContext )
    {
        SDL_GL_DeleteContext( mContext.glContext );
    }

    if ( mContext.pSdlRenderer != NULL )
    {
        SDL_DestroyRenderer( mContext.pSdlRenderer );
    }

    if ( mContext.pWindow != NULL )
    {
        SDL_DestroyWindow( mContext.pWindow );
    }

    SDL_Quit();

    mWasShutdown = true;
}