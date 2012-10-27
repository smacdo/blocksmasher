/*
 * ball.cpp
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
#include "ball.h"
#include "sprite.h"
#include "config.h"        // for window width/height

#include <cassert>
#include <iostream>

/**
 * Ball constructor
 */
Ball::Ball( Sprite * pSprite,
            const Vector2& position,
            const Vector2& velocity )
    : mpSprite( pSprite ),
      mSize( Vector2( 32, 32 ) ),
      mPosition( position ),
      mVelocity( velocity )
{
    assert( pSprite != NULL && "Did you really think that would fly?" );

    // Re-assign the sprite to the correct size of the ball object
    //  temp-hack...
    pSprite->setSize( mSize );
}

/**
 * Destructor
 */
Ball::~Ball()
{

}

/**
 * Get the sprite for the ball
 */
const Sprite * Ball::sprite() const
{
    return mpSprite;
}

/**
 * Get the width of the ball
 */
float Ball::width() const
{
    return mSize.x();
}

/**
 * Get the height of the ball
 */
float Ball::height() const
{
    return mSize.y();
}

/**
 * Get the position of the ball
 */
Vector2 Ball::position() const
{
    return mPosition;
}

/**
 * Get the size of the ball
 */
Vector2 Ball::size() const
{
    return mSize;   
}

/**
 * Set the position of the ball
 */
void Ball::setPosition( const Vector2& position )
{
    mPosition = position;
}

/**
 * Get the velocity of the ball
 */
Vector2 Ball::velocity() const
{
    return mVelocity;
}

/**
 * Set the velocity of the ball
 */
void Ball::setVelocity( const Vector2& velocity )
{
    mVelocity = velocity;
}

/**
 * Update the sprite according to the time step
 */
void Ball::update()
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