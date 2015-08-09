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
    length = sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
    return length;
}

//...............................//
void printV4(const Vector4& v)
{
    std::cout << "Vector4(" << v.x_ << ", " << v.y_ << ", " << v.z_ << ", " << v.w_ << ")" << std::endl;
}

//................................//
void printV4(const char* message, const Vector4& v)
{
    std::cout << message << "\t" << "Vector4(" << v.x_ << ", " << v.y_ << ", " << v.z_ << ", " << v.w_ << ")" << std::endl;
}
}    // end of math namespace
}    // end of mg namespace