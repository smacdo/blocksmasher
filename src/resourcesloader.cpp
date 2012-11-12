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
#include "resourcesloader.h"
#include "utils.h"
#include <SDL.h>

/**
 * Constructor
 */
ResourcesLoader::ResourcesLoader()
{

}

/**
 * Destructor
 */
ResourcesLoader::~ResourcesLoader()
{

}

/**
 * Loads a SDL_Surface from an image stored on disk.
 *  TODO: Don't use SDL to load the image... just load it as a raw blob and
 *        return it.
 *
 * \param  pRenderer  Pointer to a valid SDL renderer
 * \param  file       The sprite's file path
 * \return            Loaded SDL_Surface, or NULL if it fails
 */
SDL_Surface * ResourcesLoader::loadSurface( const std::string& imagePath,
                                            SDL_Renderer * pRenderer )
{
    // Load the texture image from a file
    SDL_Surface *pSurface = SDL_LoadBMP( imagePath.c_str() );

    // Make sure the file loaded
    if ( pSurface == NULL )
    {
        raiseError( "Failed to load image file", EERROR_SDL );
    }

    return pSurface;
}