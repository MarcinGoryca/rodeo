/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "math\vector3.h"

using namespace std;

namespace mg
{
namespace math
{
const Vector3 Vector3::S_VECTOR3_ZERO_(0.0f, 0.0f, 0.0f);

//--------------------------------------------------------------------------------------------------
float Vector3::length()
{
	float length = 0.0f;
	length = sqrt(_x * _x + _y * _y + _z * _z);
	return length;
}

//--------------------------------------------------------------------------------------------------
Vector3 cross(const Vector3& v1, const Vector3& v2)
{
	Vector3 v = Vector3::S_VECTOR3_ZERO_;
	v._x = v1._y * v2._z - v2._y * v1._z;
    v._y = v1._x * v2._z - v2._x * v1._z;
    v._z = v1._x * v2._y - v2._x * v1._y;
	return v;
}

//--------------------------------------------------------------------------------------------------
void printV3(const Vector3& v)
{
	std::cout << "Vector3(" << v._x << ", " << v._y << ", " << v._z << ")" << std::endl;
}

//--------------------------------------------------------------------------------------------------
void printV3(const char* message, const Vector3& v)
{
    std::cout << message << "\t" << "Vector3(" << v._x << ", " << v._y << ", " << v._z << ")" << std::endl;
}
}    // end of math namespace
}    // end of mg namespace