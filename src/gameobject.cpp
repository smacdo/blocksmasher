/*
 * ganmeobject.cpp
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
#include "gameobject.h"
#include "gameobjectid.h"
#include "sprite.h"
#include "config.h"        // for window width/height
#include "utils.h"

#include <cassert>
#include <iostream>

GameObject::GameObject( game_object_id_t id )
    : mId( id ),
      mpSprite( NULL ),
      mSize( 0, 0 ),
      mPosition( 0, 0 ),
      mVelocity( 0, 0 )
{

}
/**
 * Destructor
 */
GameObject::~GameObject()
{
    Delete( mpSprite );
}

/**
 * Return the sprite representing this game object
 */
const Sprite * GameObject::sprite() const
{
    return mpSprite;
}

/**
 * Get the width of the game object
 */
float GameObject::width() const
{
    return mSize.x();
}

/**
 * Get the height of the game object
 */
float GameObject::height() const
{
    return mSize.y();
}

/**
 * Get the position of the game object
 */
Vector2 GameObject::position() const
{
    return mPosition;
}

/**
 * Get the size of the game object
 */
Vector2 GameObject::size() const
{
    return mSize;   
}

/**
 * Sets the game object's sprite object
 */
void GameObject::setSprite( Sprite * pSprite )
{
    mpSprite = pSprite;
}

/**
 * Set the position of the game object
 */
void GameObject::setPosition( const Vector2& position )
{
    mPosition = position;
}

/**
 * Set the size of the game object
 */
void GameObject::setSize( const Vector2& size )
{
    mSize = size;

    // TODO: don't do this, have the renderer look up the size correctly?
    if ( mpSprite != NULL )
    {
        mpSprite->setSize( size );
    }
}

/**
 * Get the velocity of the game object
 */
Vector2 GameObject::velocity() const
{
    return mVelocity;
}

/**
 * Set the velocity of the game object
 */
void GameObject::setVelocity( const Vector2& velocity )
{
    mVelocity = velocity;
}

/**
 * Update the sprite according to the time step
 */
void GameObject::update( const GameTime& gameTime )
{
}