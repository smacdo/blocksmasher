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
#include "config.h"        // for window width/height

#include <SDL.h>
#include <string>
#include <iostream>

Sprite::Sprite( SDL_Texture *pTexture,
                const Vector2& size,
                const Vector2& position )
    : mpTexture( pTexture ),
      mSize( size ),
      mPosition( position ),
      mVelocity()
{
}

Sprite::Sprite( SDL_Texture *pTexture,
                const Vector2& size,
                const Vector2& position,
                const Vector2& velocity )
    : mpTexture( pTexture ),
      mSize( size ),
      mPosition( position ),
      mVelocity( velocity )
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

float Sprite::width() const
{
    return mSize.x();
}

float Sprite::height() const
{
    return mSize.y();
}

Vector2 Sprite::position() const
{
    return mPosition;
}

Vector2 Sprite::size() const
{
    return mSize;   
}

void Sprite::setPosition( const Vector2& position )
{
    mPosition = position;
}

Vector2 Sprite::velocity() const
{
    return mVelocity;
}

void Sprite::setVelocity( const Vector2& velocity )
{
    mVelocity = velocity;
}

/**
 * Update the sprite according to the time step
 */
void Sprite::update()
{
    // Update our position according to velocity
    mPosition += mVelocity;

    std::cout << mPosition << std::endl;

    // Reverse velocity once we hit a wall
    float x = mPosition.x();
    float y = mPosition.y();

    if ( x < 0.0f || x >= ( DEFAULT_WINDOW_WIDTH - width() ) )
    {
        mVelocity *= Vector2( -1.0f, 1.0f );
    }

    if ( y < 0.0f || y >= ( DEFAULT_WINDOW_HEIGHT - height() ) )
    {
        mVelocity *= Vector2( 1.0f, -1.0f );
    }
}