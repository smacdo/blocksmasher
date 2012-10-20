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

GameAppContext::GameAppContext()
    : video_driver( "" ),
      display( 0 ),
      window_title( "SimpleGL Demo" ),
      window_icon( "" ),
      window_x( 0 ),
      window_y( 0 ),
      window_width( WINDOW_WIDTH ),
      window_height( WINDOW_HEIGHT ),
      depth( 0 ),
      refresh_rate( 0 ),
      num_windows( 0 )
{

}

GameAppContext InitGame()
{
    GameAppContext context;

    // Allow SDL logging
    SDL_LogSetPriority( SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_SYSTEM, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_AUDIO, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_VIDEO, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_VERBOSE );
    SDL_LogSetPriority( SDL_LOG_CATEGORY_INPUT, SDL_LOG_PRIORITY_VERBOSE );

    // Create an SDL window
    if ( SDL_CreateWindowAndRenderer( context.window_width,
                                      context.window_height,
                                      0,
                                      &context.pWindow,
                                      &context.pRenderer ) )
    {
        raiseError( "Failed to create SDL window and renderer" );
    }

    return context;
}

void DestroyGame( GameAppContext& context )
{
    if ( context.glContext )
    {
        SDL_GL_DeleteContext( context.glContext );
    }
}