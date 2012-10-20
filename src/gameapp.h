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

const int DEFAULT_WINDOW_WIDTH = 640;
const int DEFAULT_WINDOW_HEIGHT = 480;

struct SDL_Window;
struct SDL_Renderer;

struct GameAppContext
{
    GameAppContext();

    SDL_Window * pWindow;
    SDL_Renderer * pRenderer;
    void * glContext;

    /**
     * List of video drivers available on this system
     */
    std::vector<std::string> drivers;

    struct display_t
    {
        display_t( const char *driver_, int display_, int depth_, int refresh_ )
            : video_driver(driver_),
              display(display_),
              depth(depth_),
              refresh_rate(refresh_)
        {
        }

        const char * video_driver;
        int display;
        int depth;
        int refresh_rate;
    } display;

    struct window_t
    {
        window_t( const char * title_, int x_, int y_, int width_, int height_ )
            : title(title_), x(x_), y(y_), width(width_), height(height_)
        {
        }

        const char * title;
        const char * icon;
        int x;
        int y;
        int width;
        int height;

    } window;

    int window_count;

    SDL_Window ** pWindows;
};

GameAppContext InitGame( int argc, char ** argv  );
void DestroyGame( GameAppContext& context );

#endif