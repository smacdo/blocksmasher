/*
 * paddle.h
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
#ifndef SCOTT_BREAKOUT_PADDLE_H
#define SCOTT_BREAKOUT_PADDLE_H

#include "gameobject.h"

class Sprite;
class Vector2;

/**
 * Represents a player paddle game object. The player can move this paddle
 * and uses it to bounce balls around the scene.
 */
class Paddle : public GameObject
{
public:
    Paddle( Sprite * pSprite,
            const Vector2& centerPosition,
            float paddleWidth );
    virtual ~Paddle();

private:
    float mPaddleWidth;
};

#endif