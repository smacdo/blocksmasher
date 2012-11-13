/*
 * sprite.h
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
#ifndef SCOTT_FORGE_SPRITE_H
#define SCOTT_FORGE_SPRITE_H

#include <string>
#include "math/vector2.h"

struct SDL_Texture;
struct SDL_Renderer;

/**
 * Represents a 2d graphical sprite that can be drawn on the screen
 */
class Sprite
{
public:
    Sprite( SDL_Texture * pTexture, const Vector2& size );
    ~Sprite();

    const SDL_Texture * getTexture() const;

    void setSize( const Vector2& newSize );
    Vector2 size() const;

private:
    SDL_Texture * mpTexture;
    Vector2 mOriginalSize;
    Vector2 mSize;
};

#endif