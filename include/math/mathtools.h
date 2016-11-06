/*
----------------------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_MATH_MATHTOOLS_H_
#define LAURA_MATH_MATHTOOLS_H_

#ifndef LAURA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace laura
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
    for(core::ui i=0; i < core::LAURA_FULL_CIRCLE; ++i)
    {
        angles[i] = ::sin(i * core::LAURA_RADIAN);
    }
}

inline void buildCosinusTable(float* angles)
{
    for(core::ui i=0; i < core::LAURA_FULL_CIRCLE; ++i)
    {
        angles[i] = ::cos(i * core::LAURA_RADIAN);
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
    degree = radian * (180 / core::LAURA_PI);
    return degree;
}

// Converting from Degrees to Radians
// Returns float value in radians
inline float degreesToRadians(float degree)
{
    float radian = 0.0f;
    radian = degree * (core::LAURA_PI / 180);
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
inline void rodeoSwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Swapping Float Values
inline void rodeoSwapFloat(float& a, float& b)
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