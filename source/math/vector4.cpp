/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "..\include\math\vector4.h"

namespace mg
{
namespace math
{
float Vector4::length()
{
    float length = 0.0f;
    length = sqrt(_x * _x + _y * _y + _z * _z + _w * _w);
    return length;
}

//...............................//
void printV4(const Vector4& v)
{
    std::cout << "Vector4(" << v._x << ", " << v._y << ", " << v._z << ", " << v._w << ")" << std::endl;
}

//................................//
void printV4(const char* message, const Vector4& v)
{
    std::cout << message << "\t" << "Vector4(" << v._x << ", " << v._y << ", " << v._z << ", " << v._w << ")" << std::endl;
}
}    // end of math namespace
}    // end of mg namespace