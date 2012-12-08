/*
 * inputmanager.h
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
#ifndef SCOTT_FORGE_INPUT_MANAGER_H
#define SCOTT_FORGE_INPUT_MANAGER_H

#include "math/vector2.h"
#include <vector>
#include <boost/noncopyable.hpp>

struct SDL_Keysym;

/**
 * A symbolic value representing an input action
 */
enum EInputButton
{
    EINPUT_BUTTON_EXIT,
    EINPUT_BUTTON_MOVE_LEFT,
    EINPUT_BUTTON_MOVE_RIGHT,
    EINPUT_BUTTON_MAX
};

/**
 * A symbolic value representing an input axis
 */
enum EInputAxis
{
    EINPUT_AXIS_MOVE_HORIZONTAL,
    EINPUT_AXIS_MOVE_VERTICAL,
    EINPUT_AXIS_MAX
};

/**
 * Process input reported from SDL and maps it to controllable actions that can
 * be queried elsewhere in the game
 */
class InputManager : boost::noncopyable
{
public:
    InputManager();
    ~InputManager();

    void reset();
    void processKeyboardInput( const SDL_Keysym& key, bool isDown );

    bool button( EInputButton button ) const;
    float axis( EInputAxis axis ) const;

    bool escapedPressed() const;

private:
    std::vector<bool> mButtonStates;
    std::vector<float> mAxisValues;
};

#endif