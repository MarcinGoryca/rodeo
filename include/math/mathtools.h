/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
#ifndef RODEO_MATH_MATHTOOLS_H_
#define RODEO_MATH_MATHTOOLS_H_

#ifndef RODEO_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

//TODO
// Move all from this file to MathSystem

namespace rodeo
{
namespace math
{
inline void sinCos(float* s, float* c, float theta)
{
    *s = ::sin(theta);
    *c = ::cos(theta);
}

inline void buildSinusTable(float* angles)
{
    for(core::ui i=0; i < core::RODEO_FULL_CIRCLE; ++i)
    {
        angles[i] = ::sin(i * core::RODEO_RADIAN);
    }
}

inline void buildCosinusTable(float* angles)
{
    for(core::ui i=0; i < core::RODEO_FULL_CIRCLE; ++i)
    {
        angles[i] = ::cos(i * core::RODEO_RADIAN);
    }
}

 // * Radians
 // *
 // * 360 degrees = 2 PI radians
 // * 180 degrees = PI radians
 // * 90 degrees = PI / 2 radians
 // * 45 degrees = PI / 4 radians
 // * 30 degrees = PI / 6 radians
 // * 0 degrees = 0 * PI radians :)
 // *
 // * radian = degree * PI / 180
 // *
 // * degree = radian * 180 / PI
 // */

// Converting from Radians to Degrees
// Returns float value in degrees

inline float radiansToDegrees(float radian)
{
    float degree = 0.0f;
    degree = radian * (180 / core::RODEO_PI);
    return degree;
}

// Converting from Degrees to Radians
// Returns float value in radians
inline float degreesToRadians(float degree)
{
    float radian = 0.0f;
    radian = degree * (core::RODEO_PI / 180);
    return radian;
}

// Converting Number to a String
// Returns String
template <typename T>
inline std::string toString(T number)
{
    std::stringstream s;
    s << number;
    std::string str = s.str();
    return str;
}

// Converting float, double number to a string
// Parameter digitPrecision - how many digits to print
// Returns String
template <typename T>
inline std::string toString(T number, int digitPrecision)
{
    std::stringstream s;
    s << fixed << setprecision(digitPrecision) << number;
    std::string str = s.str();
    return str;
}

// Swapping function
template <typename T>
inline void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Swapping Float Values
inline void mySwapFloat(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

// Converting a string to an int
// Returns integer
template <typename T>
inline int toInt(T string)
{
    std::istringstream buffer(string);
    int value = 0;
    buffer >> value;
    return value;
}

inline float cotangent(float angle)
{
    return (1.0f / ::tan(angle));
}
}
}
#endif