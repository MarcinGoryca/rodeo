/*
 | ----------------------------------------------
 |    laura Game Engine
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 | ----------------------------------------------
 */
#include "..\include\math\vector4.h"

namespace laura
{
namespace math
{

/*
 * ------------------------------------------------------
 *    Vector length
 * ------------------------------------------------------
 */
float Vector4::length()
{
    float length = 0.0f;
    length = sqrt(_x * _x + _y * _y + _z * _z + _w * _w);
    return length;
}

/*
 * ------------------------------------------------------
 *		Helper method
 * ------------------------------------------------------
 */
void printV4(const Vector4& v)
{
    std::cout << "Vector4(" << v.getX() << ", " 
		<< v.getY() << ", " << v.getZ() << ", " 
		<< v.getW() << ")" << std::endl;
}

/*
 * ----------------------------------------------------------------
 *		Helper method
 * ----------------------------------------------------------------
 */
void printV4(const char* message, const Vector4& v)
{
    std::cout << message << "\t" << "Vector4(" 
		<< v.getX() << ", " << v.getY() << ", " 
		<< v.getZ() << ", " << v.getW() << ")" 
		<< std::endl;
}
}    // end of math namespace
}    // end of laura namespace
