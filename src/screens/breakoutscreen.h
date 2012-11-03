/*
 * breakoutscreen.h
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
#ifndef SCOTT_BREAKOUT_BREAKOUTSCREEN_H
#define SCOTT_BREAKOUT_BREAKOUTSCREEN_H

#include "basescreen.h"

class Ball;
class Renderer;
class Paddle;
struct GameAppContext;

/**
 * Main game play implementation of breakout
 */
class BreakoutScreen : public BaseScreen
{
public:
    BreakoutScreen();
    virtual ~BreakoutScreen();

    void startup( GameAppContext& context );     // TODO: Pull this out
    void shutdown();
    void update();
    void render( Renderer& renderer );

private:
    Paddle * mpPaddle;
    Ball * mpBall;
};

#endif