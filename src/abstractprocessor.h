/*
 * abstractprocessor.h
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
#ifndef SCOTT_FORGE_ABSTRACT_PROCESSOR_H
#define SCOTT_FORGE_ABSTRACT_PROCESSOR_H

#include <boost/noncopyable.hpp>
#include <set>

class GameTime;
class GameObject;

/**
 * The base class for all forge processors. A processor is a system that runs
 * once every update tick, and processes a collection of game objects.
 */
class AbstractProcessor : boost::noncopyable
{
public:
    AbstractProcessor();
    virtual ~AbstractProcessor();

    // Starts the abstract processor
    void start();

    // Stops the processor
    void stop();

    // Allows the processor to update and process the given time slice
    void update( const GameTime& time );

    void attachGameObject( GameObject * pObject );
    void detachGameObject( GameObject * pObject );
    void detachAllGameObjects();

    void gameObjectDeletedCallback( GameObject * pObject );

protected:
    /// The list of game objects registered with this processor
    ///  (The processor does NOT own these pointers)
    std::set<GameObject*> mGameObjects;

protected:
    virtual void onStart() = 0;
    virtual void onStop() = 0;
    virtual void onUpdate( const GameTime& time ) = 0;
    virtual void onGameObjectAttached( GameObject * pObject ) = 0;
    virtual void onGameObjectDetached( GameObject * pObject ) = 0;
};

#endif