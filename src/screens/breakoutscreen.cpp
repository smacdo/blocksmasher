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
#include "breakout/paddle.h"
#include "renderer.h"
#include "sprite.h"
#include "application.h"
#include "resourcesloader.h"
#include "gameappcontext.h"
#include "config.h"

#include <cassert>

/**
 * Breakout game screen constructor
 */
BreakoutScreen::BreakoutScreen()
    : BaseScreen(),
      mpPaddle( NULL ),
      mpBall( NULL )
{

}

/**
 * Destructor
 */
BreakoutScreen::~BreakoutScreen()
{

}

/**
 * Update all objects
 */
void BreakoutScreen::update( const GameTime& gameTime )
{
    assert( mpBall != NULL && "How on earth is this null?" );
    mpBall->update( gameTime );
    mpPaddle->update( gameTime );
}

/**
 * Draw everything
 */
void BreakoutScreen::render( Renderer& renderer )
{
    renderer.draw( mpBall->sprite(), mpBall->position() );
    renderer.draw( mpPaddle->sprite(), mpPaddle->position() );
}

void BreakoutScreen::startup( GameAppContext& context )
{
    Renderer& renderer = Application::renderer();

    // Create the initial ball object
    Sprite * pBallSprite = renderer.createSprite( "sample.bmp" );
    mpBall = new Ball( pBallSprite, Vector2::ZERO, Vector2( 75.0f, 75.0f ) );

    // Calculate the position of the player's paddle
    float paddleX = DEFAULT_WINDOW_WIDTH / 2.0f;
    float paddleY = DEFAULT_WINDOW_HEIGHT - 24.0f;

    // Create the player's paddle object
    Sprite * pPaddleSprite = renderer.createSprite( "sample.bmp" );
    mpPaddle = new Paddle( pPaddleSprite,
                           Vector2( paddleX, paddleY ),
                           300.0f );
}

void BreakoutScreen::shutdown()
{
    delete mpBall;
    delete mpPaddle;
}