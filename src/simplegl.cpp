/*
 * simplegl.cpp
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

#include "simplegl.h"
#include "gameapp.h"
#include "sprite.h"
#include "renderer.h"

#include <SDL.h>
#include <SDL_opengl.h>

/**
 * Application entry point
 */
int main( int argc, char **argv )
{
    // Start the game up
    GameAppContext app = InitGame( argc, argv );
    Renderer renderer( app.pRenderer );

    // Create a sprite to bounce around
    Sprite * pSprite = LoadSpriteFromFile( app.pRenderer, "sample.bmp" );
    pSprite->setVelocity( Vector2( 0.2f, 0.1f ) );

    // Main game loop
    SDL_Event event;
    bool keepRunning = true;

    while ( keepRunning )
    {
        // Check for any input or window events
        while ( SDL_PollEvent( &event ) )
        {
            // Did the player press exit?
            if ( event.type == SDL_QUIT )
            {
                keepRunning = false;
            }
        }

        // Draw
        pSprite->update();

        renderer.clear();
        renderer.draw( pSprite );
        renderer.present();
    }

    // All done, clean up before exiting
    delete pSprite;
    DestroyGame( app );
    return 0;
}