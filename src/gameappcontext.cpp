/*
 * gameappcontext.cpp
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
#include "gameappcontext.h"
#include "config.h"
#include "utils.h"

#include "gameobjectfactory.h"
#include "resourcesloader.h"
#include "renderer.h"
#include "inputmanager.h"
#include "movementprocessor.h"

#include <string>
#include <vector>
#include <cassert>
#include <SDL.h>

GameAppContext::GameAppContext()
    : mpGameObjectFactory( NULL ),
      mpMovementProcessor( NULL ),
      mpResourcesLoader( NULL ),
      mpRenderer( NULL ),
      mpInputManager( NULL ),
      pWindow( NULL ),
      pSdlRenderer( NULL ),
      glContext( NULL ),
      isQuiting( false ),
      display( "NULL", 0, 0, 0 ),
      window( "SimpleGL Test",
              SDL_WINDOWPOS_UNDEFINED,
              SDL_WINDOWPOS_UNDEFINED,
              DEFAULT_WINDOW_WIDTH,
              DEFAULT_WINDOW_HEIGHT ),
      window_count( 1 )
{

}

/**
 * Sets the game object factory
 */
void GameAppContext::setGameObjectFactory( GameObjectFactory * pFactory )
{
    Delete( mpGameObjectFactory );
    mpGameObjectFactory = pFactory;
}

/**
 * Sets the resources loader
 */
void GameAppContext::setResourcesLoader( ResourcesLoader * pResourcesLoader )
{
    Delete( mpResourcesLoader );
    mpResourcesLoader = pResourcesLoader;
}

/**
 * Sets the renderer
 */
void GameAppContext::setRenderer( Renderer * pRenderer )
{
    Delete( mpRenderer );
    mpRenderer = pRenderer;
}

/**
 * Sets the movement processor
 */
void GameAppContext::setMovementProcessor( MovementProcessor * pProcessor )
{
    Delete( mpMovementProcessor );
    mpMovementProcessor = pProcessor;
}

/**
 * Sets the input processor
 */
void GameAppContext::setInputManager( InputManager * pManager )
{
    Delete( mpInputManager );
    mpInputManager = pManager;
}


/**
 * Return the active game object factory as a reference
 */
GameObjectFactory& GameAppContext::gameObjectFactory()
{
    // Make sure the loader is created and set
    assert( mpGameObjectFactory != NULL && "Must create game object factory before accessing" );

    if ( mpGameObjectFactory == NULL )
    {
        raiseError( "Did not create game object factory prior to using it", EERROR_APP );
    }

    // This is going to fail horribly if we get this far and there's no valid
    // pointer
    return *mpGameObjectFactory;
}

/**
 * Return the active resources loader as a reference
 */
ResourcesLoader& GameAppContext::resourcesLoader()
{
    // Make sure the loader is created and set
    assert( mpResourcesLoader != NULL && "Must create resources loader before accessing" );

    if ( mpResourcesLoader == NULL )
    {
        raiseError( "Did not create resources loader prior to using it", EERROR_APP );
    }

    // This is going to fail horribly if we get this far and there's no valid
    // pointer
    return *mpResourcesLoader;
}

/**
 * Return the active renderer as a reference
 */
Renderer& GameAppContext::renderer()
{
    // Make sure the renderer is created and set
    assert( mpRenderer != NULL && "Must create renderer before accessing" );

    if ( mpRenderer == NULL )
    {
        raiseError( "Did not create renderer prior to using it", EERROR_APP );
    }

    // This is going to fail horribly if we get this far and there's no valid
    // pointer
    return *mpRenderer;
}

/**
 * Gets the movement processor
 */
MovementProcessor& GameAppContext::movementProcessor()
{
    // Make sure the renderer is created and set
    assert( mpMovementProcessor != NULL && "Must create renderer before accessing" );

    if ( mpMovementProcessor == NULL )
    {
        raiseError( "Did not create movement processor prior to using it", EERROR_APP );
    }

    // This is going to fail horribly if we get this far and there's no valid
    // pointer
    return *mpMovementProcessor;
}

InputManager& GameAppContext::inputManager()
{
    // Make sure the renderer is created and set
    assert( mpInputManager != NULL && "Must create input manager before accessing" );

    if ( mpInputManager == NULL )
    {
        raiseError( "Did not create movement processor prior to using it", EERROR_APP );
    }

    // This is going to fail horribly if we get this far and there's no valid
    // pointer
    return *mpInputManager;
}