/*
 * abstractprocessor.cpp
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
#include "abstractprocessor.h"

#include "gameobject.h"
#include "gametime.h"

#include <vector>
#include <set>

AbstractProcessor::AbstractProcessor()
    : mGameObjects()
{

}

AbstractProcessor::~AbstractProcessor()
{
    detachAllGameObjects();
}

void AbstractProcessor::start()
{
    onStart();
}

void AbstractProcessor::stop()
{
    onStop();
}

void AbstractProcessor::update( const GameTime& time )
{
    onUpdate( time );
}

void AbstractProcessor::attachGameObject( GameObject * pObject )
{
    if ( mGameObjects.find( pObject ) == mGameObjects.end() )
    {
        // Add the game object to our list of objects to track
        mGameObjects.insert( pObject );
        onGameObjectAttached( pObject );
    }
    else
    {
        // looks like the game object was already added. Is this an error?
    }
}

void AbstractProcessor::detachGameObject( GameObject * pObject )
{
    assert( mGameObjects.find( pObject ) != mGameObjects.end() );

    // Remove the game object from our list of actively tracked game objects
    mGameObjects.erase( pObject );

    // Now inform the derived processor that the game object was removed
    onGameObjectDetached( pObject );
}

void AbstractProcessor::detachAllGameObjects()
{
    // Copy the game objects into a temporary set, and clear the actual list of
    // tracked objects. This way an object won't get confused if it looks for
    // other game objects while detaching (even though it shouldn't look)
    std::set<GameObject*> objects = mGameObjects;
    mGameObjects.clear();

    // Now detach everyone
    for ( auto itr = objects.begin(); itr != objects.end(); ++itr )
    {
        onGameObjectDetached( *itr );
    }
}

/**
 * Called by the game object factory when this game object is about to be
 * deleted.
 */
void AbstractProcessor::gameObjectDeletedCallback( GameObject * pObject )
{
    // Do we even care?
    if ( mGameObjects.find( pObject ) != mGameObjects.end() )
    {
        detachGameObject( pObject );
    }
}