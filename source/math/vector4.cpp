/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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
#include "..\include\math\vector4.h"

namespace rodeo
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
}    // end of rodeo namespace
