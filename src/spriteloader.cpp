/*
 * spriteloader.cpp
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
#include "sprite.h"
#include "utils.h"
#include <SDL.h>

/**
 * Loads a sprite from disk
 */
Sprite * LoadSpriteFromFile( SDL_Renderer *pRenderer,
    const std::string& file )
{
    // Load the texture image from a file
    SDL_Surface *pSurface = SDL_LoadBMP( file.c_str() );

    // Make sure the file loaded
    if ( pSurface == NULL )
    {
        raiseError( "Failed to open texture file", EERROR_SDL );
    }

    // Convert the SDL surface into a texture
    SDL_Texture * pTexture = SDL_CreateTextureFromSurface( pRenderer,
        pSurface );

    if ( pTexture == NULL )
    {
        raiseError( "Failed to create SDL texture from image", EERROR_SDL );
    }

    // Query the dimensions of the image before destroying the SDL surface
    //  (Since we already copied it into an SDL texture)
    float width  = static_cast<float>( pSurface->w );
    float height = static_cast<float>( pSurface->h );

    Vector2 size = Vector2( width, height );

    SDL_FreeSurface( pSurface );

    // Create a sprite to hold the texture, and return it to the caller
    return new Sprite( pTexture, size, Vector2::ZERO );
}