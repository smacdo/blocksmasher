/*
 * utils.h
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
#ifndef SCOTT_FORGE_UTILS_H
#define SCOTT_FORGE_UTILS_H

#include <string>
#include <boost/checked_delete.hpp>

enum EErrorType
{
    EERROR_APP,
    EERROR_SYSTEM,
    EERROR_SDL
};

void raiseError( const std::string& error, EErrorType type = EERROR_APP );

/**
 * Safely delete a pointer and set it to null
 */
template<typename T>
void Delete( T*& pointer )
{
    boost::checked_delete( pointer );
    pointer = NULL;
}

#endif