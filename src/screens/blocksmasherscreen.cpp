/*
 * blocksmasherscreen.cpp
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
#include "screens/blocksmasherscreen.h"
#include "renderer.h"
#include "gameobject.h"
#include "sprite.h"
#include "resourcesloader.h"
#include "gameappcontext.h"
#include "gameobjectfactory.h"
#include "config.h"

#include <cassert>

/**
 * Breakout game screen constructor
 */
BlockSmasherScreen::BlockSmasherScreen()
    : BaseScreen(),
      mpPaddle( NULL ),
      mpBall( NULL )
{

}

/**
 * Destructor
 */
BlockSmasherScreen::~BlockSmasherScreen()
{

}

/**
 * Update all objects
 */
void BlockSmasherScreen::update( const GameTime& gameTime, GameAppContext& context )
{
    assert( mpBall != NULL && "How on earth is this null?" );
//    mpBall->update( gameTime );
//    mpPaddle->update( gameTime );
}

/**
 * Draw everything
 */
void BlockSmasherScreen::render( Renderer& renderer )
{
    renderer.draw( mpBall->sprite(), mpBall->position() );
    renderer.draw( mpPaddle->sprite(), mpPaddle->position() );
}

void BlockSmasherScreen::startup( GameAppContext& context )
{
    GameObjectFactory& factory = context.gameObjectFactory();
    Renderer& renderer = context.renderer();

    // Create the initial ball object
    mpBall = factory.create();

    mpBall->setSprite( renderer.createSprite( "sample.bmp" ) );
    mpBall->setPosition( Vector2::ZERO );
    mpBall->setVelocity( Vector2( 125.0f, 125.0f ) );
    mpBall->setSize( Vector2( 16.0f, 16.0f ) );

    // Calculate the position of the player's paddle
    float paddleX = DEFAULT_WINDOW_WIDTH / 2.0f;
    float paddleY = DEFAULT_WINDOW_HEIGHT - 24.0f;

    // Create the player's paddle object
    mpPaddle = factory.create();

    mpPaddle->setSprite( renderer.createSprite( "sample.bmp" ) );
    mpPaddle->setPosition( Vector2( paddleX, paddleY ) - Vector2( 300.0f / 2.0f, 32.0f ));
    mpPaddle->setSize( Vector2( 300.0f, 32.0f ) );
    mpPaddle->setVelocity( Vector2( 50.0f, 0.0f ) );

    // Register everything
    MovementProcessor& movement = context.movementProcessor();

    movement.attachGameObject( mpBall );
    movement.attachGameObject( mpPaddle );
}

void BlockSmasherScreen::shutdown( GameAppContext& context )
{
    // TODO: change this to gameobject factory, no delete
    context.movementProcessor().detachGameObject( mpBall );

    delete mpBall;
    delete mpPaddle;
}