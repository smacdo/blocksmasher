/*
 * vector2.h
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
#ifndef SCOTT_SIMPLEGL_VECTOR2_H
#define SCOTT_SIMPLEGL_VECTOR2_H

#include <cassert>
#include <iosfwd>

class Vector2
{
public:
    Vector2()
        : mX( 0.0f ), mY( 0.0f )
    {
    }

    Vector2( float x, float y )
        : mX( x ), mY( y )
    {
    }

    Vector2( const Vector2& v )
        : mX( v.mX ), mY( v.mY )
    {
    }

    Vector2& operator = ( const Vector2& v )
    {
        mX = v.mX;
        mY = v.mY;

        return *this;
    }

    float& operator[] ( size_t index )
    {
        assert( index < 2 && "Vector2 index out of bounds" );
        return *( &mX + index );
    }

    const float& operator[] ( size_t index ) const
    {
        assert( index < 2 && "Vector2 index out of bounds" );
        return *( &mX + index );
    }

    Vector2 operator - () const
    {
        return Vector2( -mX, -mY );
    }

    Vector2 operator + ( const Vector2& rhs ) const
    {
        return Vector2( mX + rhs.mX, mY + rhs.mY );
    }

    Vector2 operator - ( const Vector2& rhs ) const
    {
        return Vector2( mX - rhs.mX, mY - rhs.mY );
    }

    Vector2 operator * ( float rhs ) const
    {
        return Vector2( mX * rhs, mY * rhs );
    }

    Vector2 operator / ( float rhs ) const
    {
        return Vector2( mX / rhs, mY / rhs );
    }

    Vector2& operator += ( const Vector2& rhs )
    {
        mX += rhs.mX;
        mY += rhs.mY;
        return *this;
    }

    Vector2& operator -= ( const Vector2& rhs )
    {
        mX -= rhs.mX;
        mY -= rhs.mY;
        return *this;
    }

    Vector2& operator *= ( const Vector2& rhs )
    {
        mX *= rhs.mX;
        mY *= rhs.mY;
        return *this;
    }

    Vector2& operator /= ( const Vector2& rhs )
    {
        mX /= rhs.mX;
        mY /= rhs.mY;
        return *this;
    }

    float x() const
    {
        return mX;
    }

    float y() const
    {
        return mY;
    }

    bool operator == ( const Vector2& rhs ) const;
    bool operator != ( const Vector2& rhs ) const;

    static Vector2 ZERO;

private:
    float mX;
    float mY;
};

std::ostream& operator << ( std::ostream& os, const Vector2& vec );
std::istream& operator >> ( std::istream& os, const Vector2& vec );

#endif