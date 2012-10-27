/*
 * breakoutscreen.cpp
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
#include "screens/breakoutscreen.h"
#include "breakout/ball.h"
#include "renderer.h"
#include "sprite.h"
#include "gameappcontext.h"

#include <cassert>

BreakoutScreen::BreakoutScreen()
    : BaseScreen(),
      mpBall( NULL )
{

}

BreakoutScreen::~BreakoutScreen()
{

}

void BreakoutScreen::update()
{
    assert( mpBall != NULL && "How on earth is this null?" );
    mpBall->update();
}

void BreakoutScreen::render( Renderer& renderer )
{
    renderer.draw( mpBall->sprite(), mpBall->position() );
}

void BreakoutScreen::startup( GameAppContext& context )
{
    // Create the initial ball object
    Sprite * pBallSprite = LoadSpriteFromFile( context.pRenderer, "sample.bmp" );
    mpBall = new Ball( pBallSprite, Vector2( 0, 0 ), Vector2( 2.5f, 2.5f ) );
}

void BreakoutScreen::shutdown()
{
    delete mpBall;
}