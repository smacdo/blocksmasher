/*
 * basescreen.h
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
#ifndef SCOTT_FORGE_BASESCREEN_H
#define SCOTT_FORGE_BASESCREEN_H

#include "movementprocessor.h"

class GameAppContext;
class Renderer;
class GameTime;

/**
 * Base class for all game play related code
 */
class BaseScreen
{
public:
    BaseScreen();
    virtual ~BaseScreen();

    virtual void startup( GameAppContext& context ) = 0; // TODO: Pull this out
    virtual void shutdown( GameAppContext& context ) = 0;
    virtual void update( const GameTime& gameTime, GameAppContext& context ) = 0;
    virtual void render( Renderer& renderer ) = 0;

private:
};

#endif