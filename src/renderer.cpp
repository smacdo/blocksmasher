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
#include <SDL.h>
#include <SDL_opengl.h>

#include <cassert>

Renderer::Renderer( SDL_Renderer *pRenderer )
    : mpRenderer( pRenderer )
{

}

Renderer::~Renderer()
{
    // destroy the renderer object?
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor( mpRenderer, 0xA0, 0xA0, 0xA0, 0xFF );
    SDL_RenderClear( mpRenderer );
}

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

void Renderer::present()
{
    SDL_RenderPresent( mpRenderer );
}