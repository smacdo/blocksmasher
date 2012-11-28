/*
 * renderer.cpp
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
#include "renderer.h"
#include "sprite.h"
#include "gameappcontext.h"
#include "resourcesloader.h"
#include "gametime.h"
#include "utils.h"

#include <string>
#include <map>

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_render.h>

#include <cassert>

/**
 * Constructor
 */
Renderer::Renderer( GameAppContext& gameContext, SDL_Renderer *pRenderer )
    : mGameContext( gameContext ),
      mpRenderer( pRenderer ),
      mCachedTextures()
{
}

/**
 * Destructor
 */
Renderer::~Renderer()
{
    // destroy all cached surfaces
    for ( auto itr = mCachedTextures.begin(); itr != mCachedTextures.end(); ++itr )
    {
        SDL_DestroyTexture( itr->second );  // don't delete, SDL specific
    }

    mCachedTextures.clear();

    // destroy the renderer object?
}

/**
 * Loads an image from disks and then returns it as a newly created sprite
 * instance
 */
Sprite * Renderer::createSprite( const std::string& imagePath )
{
    ResourcesLoader& resources = mGameContext.resourcesLoader();

    // Obtain a SDL_Texture instance representing this image. First search the
    // texture cache to see if image was already loaded, and if not then load it
    // from disk.
    texture_cache_t::iterator itr = mCachedTextures.find( imagePath );
    SDL_Surface * pSurface = NULL;
    SDL_Texture * pTexture = NULL;

    if ( itr == mCachedTextures.end() )
    {
        // Texture was not already created. Load it from disk and then put it
        // into the cache (but only if was successfully loaded)
        pSurface = resources.loadSurface( imagePath, mpRenderer );

        if ( pSurface != NULL )
        {
            // Convert the SDL_Surface into a SDL_Texture by instructing SDL
            // to upload it into the video card's memory
            pTexture = SDL_CreateTextureFromSurface( mpRenderer, pSurface );

            SDL_FreeSurface( pSurface );
        }
    }
    else
    {
        // Surface was already created and cached, just load it
        pTexture = itr->second;
    }

    // Make sure the SDL_Texture was actually loaded and constructed.
    //  TODO: Create a fallback here when the texture object is not correctly
    //        constructed
    assert( pTexture != NULL && "Was not able to create a SDL_Texture representing the image" );

    if ( pTexture == NULL )
    {
        raiseError( "Failed to load image, SDL_Texture was NULL", EERROR_APP );
    }

    // Query texture information so we can get the image width and height
    Uint32 format = 0;
    int access = 0, imageWidth = 0, imageHeight = 0;

    SDL_QueryTexture( pTexture, &format, &access, &imageWidth, &imageHeight );

    // Construct a sprite instance representing the image and return it to the
    // caller
    float width  = static_cast<float>( imageWidth );
    float height = static_cast<float>( imageHeight );

    return new Sprite( pTexture, Vector2( width, height ) );
}

/**
 * Update the renderer subsystem
 */
void Renderer::update( const GameTime& gameTime )
{

}

/**
 * Clear the screen
 */
void Renderer::clear()
{
    SDL_SetRenderDrawColor( mpRenderer, 0xA0, 0xA0, 0xA0, 0xFF );
    SDL_RenderClear( mpRenderer );
}

/**
 * Draw a sprite
 */
void Renderer::draw( const Sprite* pSprite, const Vector2& position )
{
    assert( pSprite != NULL && "There is no way I can render a null sprite" );

    // Get the dimensions of the sprite we are trying to draw, and generate
    // the correct rectangle describing it's offset and size in it's source
    // sprite sheet
    Vector2 size = pSprite->size();
    SDL_Rect sourceRect = { 0,
                            0,
                            static_cast<int>( size.x() ),
                            static_cast<int>( size.y() ) };

    // Also calculate a rectangle into which we will draw the texture on the
    // screen
    SDL_Rect targetRect = { static_cast<int>( position.x() ), 
                            static_cast<int>( position.y() ),
                            static_cast<int>( size.x() ),
                            static_cast<int>( size.y() ) };

    // Get a copy of the SDL_Texture, and cast away its const-ness
    //  (since SDL doesn't support const)
    SDL_Texture *pTexture = const_cast<SDL_Texture*>( pSprite->getTexture() );
    assert( pTexture != NULL && "Really? Seriously? A null texture?" );

    // Now draw the sprite
    SDL_RenderCopy( mpRenderer, pTexture, &sourceRect, &targetRect );
}

/**
 * Possibly sync to the monitor refresh rate, and then draw the contents of the 
 * backbuffer to the front buffer
 */
void Renderer::present()
{
    SDL_RenderPresent( mpRenderer );
}