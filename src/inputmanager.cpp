/*
 * inputmanager.cpp
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
#include "inputmanager.h"

#include <SDL.h>
#include <SDL_input.h>
#include <algorithm>

/**
 * Constructor
 */
InputManager::InputManager()
    : mButtonStates( EINPUT_BUTTON_MAX, false ),
      mAxisValues( EINPUT_AXIS_MAX, 0.0f )
{
    // empty
}

/**
 * Destructor
 */
InputManager::~InputManager()
{
    // empty
}

/**
 * Resets the state of all input back to the default of nothing pressed
 */
void InputManager::reset()
{
    std::fill( mButtonStates.begin(), mButtonStates.end(), false );
    std::fill( mAxisValues.begin(), mAxisValues.end(), 0.0f );
}

/**
 * Process a keyboard event and stores the results in this input manager for
 * later retrieval.
 */
void InputManager::processKeyboardInput( const SDL_Keysym& key, bool isDown )
{
    // What key was pressed?
    switch ( key.sym )
    {
        case SDLK_ESCAPE:
            mButtonStates[EINPUT_BUTTON_EXIT] = isDown;
            break;
    }
}

/**
 * Returns the current state of a named input button. The returned value is true
 * if the button was depressed, otherwise false.
 */
bool InputManager::button( EInputButton button ) const
{
    assert( button < EINPUT_BUTTON_MAX && "Must be a valid input button type" );
    bool value = false;

    if ( button < EINPUT_BUTTON_MAX )
    {
        value = mButtonStates[ button ];
    }

    return value;
}

/**
 * Returns the current state of a named input axis. The value returned ranges
 * from 1.0 to -1.0. Zero means there was no input detected on that axis.
 */
float InputManager::axis( EInputAxis axis ) const
{
    assert( axis < EINPUT_AXIS_MAX && "Must be a valid axis type" );
    float value = 0.0f;

    if ( axis < EINPUT_AXIS_MAX )
    {
        value = mAxisValues[ axis ];
    }

    return value;
}

/**
 * Checks if the escape button was pressed
 */
bool InputManager::escapedPressed() const
{
    return mButtonStates[EINPUT_BUTTON_EXIT];
}