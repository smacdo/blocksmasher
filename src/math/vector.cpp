/*
 * vector.cpp
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
#include "math/vector2.h"

#include <cmath>
#include <numeric>

#include <ostream>
#include <istream>
#include <ios>

Vector2 Vector2::ZERO = Vector2( 0.0f, 0.0f );

bool Vector2::operator == ( const Vector2& rhs ) const
{
    return ( std::fabs( mX - rhs.mX ) <= std::numeric_limits<float>::epsilon() &&
             std::fabs( mY - rhs.mY ) <= std::numeric_limits<float>::epsilon() );
}

bool Vector2::operator != ( const Vector2& rhs ) const
{
    return ( std::fabs( mX - rhs.mX ) > std::numeric_limits<float>::epsilon() ||
             std::fabs( mY - rhs.mY ) > std::numeric_limits<float>::epsilon() );
}

std::ostream& operator << ( std::ostream& os, const Vector2& vec )
{
    os << "< " << vec.x() << ", " << vec.y() << " >";
    return os;
}

std::ostream& operator >> ( std::ostream& os, Vector2& vec )
{
    float x = 0.0f;
    float y = 0.0f;

    os << "<" << x << ", " << y << " >";

    vec = Vector2( x, y );

    return os;
}