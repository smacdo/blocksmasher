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

#include <SDL.h>
#include <string>
#include <vector>
#include <iostream>

GameAppContext::GameAppContext()
    : display( "NULL",
               0,
               0,
               0 ),
      window( "SimpleGL Test",
              SDL_WINDOWPOS_UNDEFINED,
              SDL_WINDOWPOS_UNDEFINED,
              DEFAULT_WINDOW_WIDTH,
              DEFAULT_WINDOW_HEIGHT ),
      window_count( 1 )
{

}

GameAppContext InitGame( int argc, char ** argv )
{
    GameAppContext context;
    SDL_Log( "The game is starting up\n" );

    // Allow SDL logging
    SDL_LogSetPriority( SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_SYSTEM, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_AUDIO, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_VIDEO, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_INPUT, SDL_LOG_PRIORITY_VERBOSE );

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
            
            context.drivers.push_back( driverName );
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

    context.pWindow = SDL_CreateWindow( context.window.title,
                                        context.window.x,
                                        context.window.y,
                                        context.window.width,
                                        context.window.height,
                                        windowFlags );

    if ( context.pWindow == NULL )
    {
        raiseError( "Failed to create main window", EERROR_SDL );
    }

    // Now create the renderer
    Uint32 renderFlags = SDL_RENDERER_ACCELERATED |
                         SDL_RENDERER_PRESENTVSYNC |
                         SDL_RENDERER_TARGETTEXTURE;

    context.pRenderer = SDL_CreateRenderer( context.pWindow,
                                            -1,
                                            renderFlags );

    if ( context.pRenderer == NULL )
    {
        raiseError( "Failed to create hardware accelerated renderer",
                    EERROR_SDL );
    }

    // So what happened?
    SDL_Log( "Using %s video driver\n", SDL_GetCurrentVideoDriver() );

    return context;
}

void DestroyGame( GameAppContext& context )
{
    if ( context.glContext )
    {
        SDL_GL_DeleteContext( context.glContext );
    }

    if ( context.pRenderer != NULL )
    {
        SDL_DestroyRenderer( context.pRenderer );
    }

    if ( context.pWindow != NULL )
    {
        SDL_DestroyWindow( context.pWindow );
    }

    SDL_Quit();
}