/*
 * sprite.cpp
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
#include "math/vector2.h"

#include <SDL.h>
#include <string>
#include <iostream>

Sprite::Sprite( SDL_Texture *pTexture, const Vector2& size )
    : mpTexture( pTexture ),
      mOriginalSize( size ),
      mSize( size )
{
}

Sprite::~Sprite()
{
    SDL_DestroyTexture( mpTexture );
}

const SDL_Texture * Sprite::getTexture() const
{
    return mpTexture;
}

/**
 * Get the size of the sprite
 */
Vector2 Sprite::size() const
{
    return mSize;
}

/**
 * Set the size of the sprite. Cannot be larger than the source image
 */
void Sprite::setSize( const Vector2& newSize )
{
    assert( newSize.x() <= mOriginalSize.x() );
    assert( newSize.y() <= mOriginalSize.y() );

    if ( newSize.x() <= mOriginalSize.x() && 
         newSize.y() <= mOriginalSize.y() )
    {
        mSize = newSize;
    }
}