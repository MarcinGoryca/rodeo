/*
 | ----------------------------------------------
 |   Laura Game Engine
 |   Copyright(c) Marcin Goryca
 |   marcin.goryca@gmail.com
 |   http://marcingoryca.pl
 | ----------------------------------------------
 */
#include "math\vector3.h"

using namespace std;

namespace laura
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
    v.setY(v1.getX() * v2.getZ() - v2.getX() * v1.getZ());
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
}    // end of laura namespace
