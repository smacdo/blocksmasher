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

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

struct SDL_Window;
struct SDL_Renderer;

struct GameAppContext
{
    GameAppContext();

    SDL_Window * pWindow;
    SDL_Renderer * pRenderer;
    void * glContext;

    const char * video_driver;
    int display;
    const char * window_title;
    const char * window_icon;
    int window_x;
    int window_y;
    int window_width;
    int window_height;
    int depth;
    int refresh_rate;
    int num_windows;

    SDL_Window ** pWindows;
};

GameAppContext InitGame();
void DestroyGame( GameAppContext& context );

#endif