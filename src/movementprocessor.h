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
#ifndef SCOTT_FORGE_MOVEMENT_PROCESSOR_H
#define SCOTT_FORGE_MOVEMENT_PROCESSOR_H

#include "abstractprocessor.h"

/**
 * Processes the movement of game objects
 */
class MovementProcessor : public AbstractProcessor
{
public:
    MovementProcessor();
    ~MovementProcessor();

private:
    virtual void onStart();
    virtual void onStop();
    virtual void onUpdate( const GameTime& time );
    virtual void onGameObjectAttached( GameObject * pObject );
    virtual void onGameObjectDetached( GameObject * pObject );

    void updateObject( const GameTime& time, GameObject * object );
};

#endif