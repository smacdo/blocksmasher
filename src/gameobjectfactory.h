/*
 * gameobjectfactory.h
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
#ifndef SCOTT_FORGE_GAME_OBJECT_FACTORY_H
#define SCOTT_FORGE_GAME_OBJECT_FACTORY_H

#include <set>
#include <boost/noncopyable.hpp>

class GameObject;

/**
 * Responsible for the creation and destruction of game objects.
 */
class GameObjectFactory : boost::noncopyable
{
public:
    GameObjectFactory();
    ~GameObjectFactory();

    GameObject * create();
    void destroy( GameObject * object );
    void update();

private:
    void processPendingDeletes();

private:
    std::set<GameObject*> mAliveGameObjects;
    std::set<GameObject*> mGameObjectsToDestroy;
};

#endif