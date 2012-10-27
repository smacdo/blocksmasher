/*
 * ball.h
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
#ifndef SCOTT_BREAKOUT_BALL_H
#define SCOTT_BREAKOUT_BALL_H

#include "math/vector2.h"

class Sprite;

/**
 * A ball that bounces around the game screen according to pseudo physics
 */
class Ball
{
public:
    Ball( Sprite * pSprite,
          const Vector2& position,
          const Vector2& veloicty );
    ~Ball();

    const Sprite * sprite() const;

    Vector2 size() const;

    Vector2 position() const;
    void setPosition( const Vector2& position );

    Vector2 velocity() const;
    void setVelocity( const Vector2& velocity );

    void update();

    float width() const;
    float height() const;

private:
    Sprite * mpSprite;
    Vector2 mSize;
    Vector2 mPosition;
    Vector2 mVelocity;
};

#endif