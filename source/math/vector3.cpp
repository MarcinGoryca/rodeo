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
	length = sqrt(x_ * x_ + y_ * y_ + z_ * z_);
	return length;
}

//--------------------------------------------------------------------------------------------------
Vector3 cross(const Vector3& v1, const Vector3& v2)
{
	Vector3 v = Vector3::S_VECTOR3_ZERO_;
	v.x_ = v1.y_ * v2.z_ - v2.y_ * v1.z_;
    v.y_ = v1.x_ * v2.z_ - v2.x_ * v1.z_;
    v.z_ = v1.x_ * v2.y_ - v2.x_ * v1.y_;
	return v;
}

//--------------------------------------------------------------------------------------------------
void printV3(const Vector3& v)
{
	std::cout << "Vector3(" << v.x_ << ", " << v.y_ << ", " << v.z_ << ")" << std::endl;
}

//--------------------------------------------------------------------------------------------------
void printV3(const char* message, const Vector3& v)
{
    std::cout << message << "\t" << "Vector3(" << v.x_ << ", " << v.y_ << ", " << v.z_ << ")" << std::endl;
}
}    // end of math namespace
}    // end of mg namespace