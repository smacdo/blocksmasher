/*
 * renderer.h
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
#ifndef SCOTT_FORGE_RENDERER_H
#define SCOTT_FORGE_RENDERER_H

#include <string>
#include <map>

struct SDL_Renderer;
struct SDL_Texture;
class GameTime;
class Sprite;
class Vector2;
class GameAppContext;

typedef std::map< std::string, SDL_Texture* > texture_cache_t;

class Renderer
{
public:
    Renderer( GameAppContext& mGameContext, SDL_Renderer *pRenderer );
    ~Renderer();

    Sprite * createSprite( const std::string& imagePath );

    void update( const GameTime& time );
    void clear();
    void draw( const Sprite* pSprite, const Vector2& position );
    void present();

private:
    GameAppContext& mGameContext;
    SDL_Renderer * mpRenderer;
    texture_cache_t mCachedTextures;
};

#endif