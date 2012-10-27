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
#include "sprite.h"
#include "renderer.h"
#include "gameappcontext.h"

BreakoutScreen::BreakoutScreen()
    : BaseScreen()
{

}

BreakoutScreen::~BreakoutScreen()
{

}

void BreakoutScreen::update()
{
    assert( mpSprite != NULL && "How on earth is this null?" );
    mpSprite->update();
}

void BreakoutScreen::render( Renderer& renderer )
{
    renderer.draw( mpSprite );
}

void BreakoutScreen::startup( GameAppContext& context )
{
    mpSprite = LoadSpriteFromFile( context.pRenderer, "sample.bmp" );
    mpSprite->setVelocity( Vector2( 0.2f, 0.1f ) );
}

void BreakoutScreen::shutdown()
{
    delete mpSprite;
}