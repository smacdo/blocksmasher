/*
 * gameobjectfactory.cpp
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
#include "gameobjectfactory.h"
#include "gameobjectid.h"
#include "gameobject.h"
#include "utils.h"

#include <algorithm>
#include <boost/checked_delete.hpp>

GameObjectFactory::GameObjectFactory()
    : mAliveGameObjects(),
      mGameObjectsToDestroy(),
      mpNextId( new game_object_id_t( 1 ) )
{

} 

GameObjectFactory::~GameObjectFactory()
{
    // Delete all game objects still left, do not bother notifying any
    // still remaining listeners. A game object factory should only be deleted
    // at game unload.
    //   (TODO: Maybe we could implement the correct behavior when we have time?)
    DeleteContainer( mAliveGameObjects );
}

GameObject * GameObjectFactory::create()
{
    // Create the game object
    GameObject * pObject = new GameObject( generateNewId() );

    // Register the game object so we can keep track of it in the future
    mAliveGameObjects.insert( pObject );

    return pObject;
}

void GameObjectFactory::destroy( GameObject * pObject )
{
    if ( mGameObjectsToDestroy.find( pObject ) != mGameObjectsToDestroy.end() )
    {
        mGameObjectsToDestroy.insert( pObject );
    }
}

void GameObjectFactory::update( )
{
    processPendingDeletes();
}

void GameObjectFactory::processPendingDeletes()
{
    for ( auto itr  = mGameObjectsToDestroy.begin(); 
               itr != mGameObjectsToDestroy.end();
             ++itr )
    {
        // Remove it from the list of alive game objects
        mAliveGameObjects.erase( *itr );

        // Notify anyone who cares that we are about to delete this game object

        // Now we can actually delete this game object
        boost::checked_delete( *itr );
    }

    mGameObjectsToDestroy.clear();
}

game_object_id_t GameObjectFactory::generateNewId()
{
    // this is not thread safe... if we allocate objects in separate threads
    // we'll need to do it smarter
    game_object_id_t nextId = *mpNextId;
    *mpNextId = *mpNextId + 1;

    return nextId;
}