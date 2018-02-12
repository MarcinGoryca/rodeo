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
#include "math\vector3.h"

using namespace std;

namespace rodeo
{
namespace math
{
const Vector3 Vector3::S_VECTOR3_ZERO_(0.0f, 0.0f, 0.0f);

/*
 * ------------------------------------------------------------
 *     Vector length
 * ------------------------------------------------------------
 */
float Vector3::length()
{
	float length = 0.0f;
	length = sqrt(_x * _x + _y * _y + _z * _z);
	return length;
}

/*
* ----------------------------------------------------------------------------
*		Helper method
* ----------------------------------------------------------------------------
*/
Vector3 cross(const Vector3& v1, const Vector3& v2)
{
	Vector3 v = Vector3::S_VECTOR3_ZERO_;
	v.setX(v1.getY() * v2.getZ() - v2.getY() * v1.getZ());
    v.setY(v1.getZ() * v2.getX() - v2.getZ() * v1.getX());
    v.setZ(v1.getX() * v2.getY() - v2.getX() * v1.getY());

    return v;
}

/*
 * ----------------------------------------------------------------------------
 *		Helper method
 * ----------------------------------------------------------------------------
 */
void printV3(const Vector3& v)
{
	std::cout << "Vector3(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")" << std::endl;
}

/*
* ----------------------------------------------------------------------------
*		Helper method
* ----------------------------------------------------------------------------
*/
void printV3(const char* message, const Vector3& v)
{
    std::cout << message << "\t" << "Vector3(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")" << std::endl;
}
}    // end of math namespace
}    // end of rodeo namespace
