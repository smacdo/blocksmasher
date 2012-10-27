/*
 * gameapp.h
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
#ifndef SCOTT_SIMPLEGL_GAMEAPP_H
#define SCOTT_SIMPLEGL_GAMEAPP_H

#include <vector>
#include <string>
#include "gameappcontext.h"

class Renderer;
class BaseScreen;
class GameTime;

class GameApp
{
public:
    GameApp( int argc, char ** argv );
    ~GameApp();

    void run( BaseScreen * pScreen );
    void tick( const GameTime& time );
    void doInput( const GameTime& time );
    void doUpdate( const GameTime& time );
    void doRender( const GameTime& time );

private:
    void startup();
    void shutdown();

private:
    std::vector<std::string> mCommandLineArguments;
    GameAppContext mContext;
    Renderer * mpRenderer;
    BaseScreen * mpGameScreen;
    bool mWasShutdown;
};

#endif