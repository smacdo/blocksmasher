/*
 * resourcesloader.h
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
#ifndef SCOTT_HAILSTORM_RESOURCESLOADER_H
#define SCOTT_HAILSTORM_RESOURCESLOADER_H

class Sprite;
struct SDL_Renderer;

#include <string>

/**
 * Loads resources from disk based storage and returns them as usable resources.
 */
class ResourcesLoader
{
public:
    ResourcesLoader();
    ~ResourcesLoader();

    Sprite * loadSprite( SDL_Renderer *pRenderer, const std::string& file );

private:
};

#endif