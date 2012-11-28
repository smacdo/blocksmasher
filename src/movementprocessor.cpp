/*
 * movementprocessor.h
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
#include "movementprocessor.h"
#include "gameobject.h"
#include "gametime.h"
#include "config.h"

#include <iostream>

MovementProcessor::MovementProcessor()
{
    // empty
}

MovementProcessor::~MovementProcessor()
{
    // empty
}

void MovementProcessor::onStart()
{
    // empty
}

void MovementProcessor::onStop()
{
    // empty
}

void MovementProcessor::onUpdate( const GameTime& gameTime )
{
    for ( auto itr = mGameObjects.begin(); itr != mGameObjects.end(); ++itr )
    {
        updateObject( gameTime, *itr );
    }
}

void MovementProcessor::updateObject(  const GameTime& gameTime, GameObject * pObject )
{
    assert( pObject != NULL && "Cannot update a null object" );

    // What's our position and velocity?
    Vector2 velocity = pObject->velocity();
    Vector2 position = pObject->position();
    
    position += velocity * gameTime.deltaTime();

    // Reverse velocity once we hit a wall
    float x = position.x();
    float y = position.y();

    if ( x < 0.0f || x >= ( DEFAULT_WINDOW_WIDTH - pObject->width() ) )
    {
        velocity *= Vector2( -1.0f, 1.0f );
    }

    if ( y < 0.0f || y >= ( DEFAULT_WINDOW_HEIGHT - pObject->height() ) )
    {
        velocity *= Vector2( 1.0f, -1.0f );
    }

    // Apply the new position and velocity
    pObject->setPosition( position );
    pObject->setVelocity( velocity );
}

void MovementProcessor::onGameObjectAttached( GameObject * pObject )
{
    // empty
}

void MovementProcessor::onGameObjectDetached( GameObject * pObject )
{
    // empty
}