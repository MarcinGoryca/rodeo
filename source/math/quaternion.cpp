/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include <iostream>
#include "math\quaternion.h"

using namespace std;

namespace mg
{
namespace math
{
Quaternion::Quaternion(const Vector4& v)
{
    setX(v._x);
    setY(v._y);
    setZ(v._z);
    setW(v._w);
}

//--------------------------------------------------------------------------------------------------
Quaternion::Quaternion(const Vector3& v, float w)
{
    setX(v._x);
    setY(v._y);
    setZ(v._z);
    setW(w);
}

//--------------------------------------------------------------------------------------------------
const Quaternion& Quaternion::get() const
{
    return *this;
}

//--------------------------------------------------------------------------------------------------
const void Quaternion::positiveIdentity()
{
    Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}

//--------------------------------------------------------------------------------------------------
const void Quaternion::negativeIdentity()
{
    Vector4(0.0f, 0.0f, 0.0f, -1.0f);
}

//void Quaternion::Conjugate(Vector3& v)
//{
//	v.Negate();
//}

//--------------------------------------------------------------------------------------------------
void Quaternion::identity()
{
    setX(0.0f);
    setY(0.0f);
    setZ(0.0f);
    setW(1.0f);
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutX(float angle)
{
    float halfAngle = angle * 0.5f;

    setX(::sin(halfAngle));
    setY(0.0f);
    setZ(0.0f);
    setW(::cos(halfAngle));
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutY(float angle)
{
    float halfAngle = angle * 0.5f;

    setX(0.0f);
    setY(::sin(halfAngle));
    setZ(0.0f);
    setW(::cos(halfAngle));
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutZ(float angle)
{
    float halfAngle = angle * 0.5f;

    setX(0.0f);
    setY(0.0f);
    setZ(::sin(halfAngle));
    setW(::cos(halfAngle));
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutAxis(const Vector3& axis, float angle)
{
	//assert(fabs(vectorMag(axis) - 1.0f) < 0.01f);

    float halfAngle = angle * 0.5f;
    float sinHalfAngle = ::sin(halfAngle);

    setX(axis._x * sinHalfAngle);
    setY(axis._y * sinHalfAngle);
    setZ(axis._z * sinHalfAngle);
}

//--------------------------------------------------------------------------------------------------
void Quaternion::inverse(const Quaternion& q)
{
    //Quaternion temp;
    //temp = q;
    //conjugate(temp);
    //q = temp / q.length();
}

//--------------------------------------------------------------------------------------------------
float Quaternion::length()
{
    return ::sqrt(getW() * getW() + getX() * getX() + getY() * getY() + getZ() * getZ());
}

//void Quaternion::SetToRotateObjectToInertial(const EulerAngles& orientation)
//{
//	float sp, sy, sr;
//	float cp, cy, cr;
//
//	SinCos(&sp, &cp, orientation.pitch * 0.5f);
//	SinCos(&sy, &cy, orientation.yaw * 0.5f);
//	SinCos(&sr, &cr, orientation.roll * 0.5f);
//
//	x = cr * sp * cy + sr * cp * sy;
//	y = -cr * sp * sr + sr * cp * cy;
//	z = -sr * sp * cy + cr * cp * sy;
//	w = cr * cp * cy + sr * sp * cy;
//}
//void  Quaternion::SetToRotateInertialToObject(const EulerAngles& orientation)
//{
//	float sp, sy, sr;
//	float cp,cy, cr;
//
//	SinCos(&sp, &cp, orientation.pitch * 0.5f);
//	SinCos(&sy, &cy, orientation.yaw * 0.5f);
//	SinCos(&sr, &cr, orientation.roll * 0.5f);
//
//	x = -cr * sp * cy - sr * cp * sy;
//	y = cr * sp * sy - sr * cy * cp;
//	z = sr * sp * cy - cr * cp * sy;
//	w = cr * cp * cy + sr * sp * sy;
//}

//--------------------------------------------------------------------------------------------------
Quaternion Quaternion::operator*(const Quaternion& q)const
{
    Quaternion result;

    result.setX(getW() * q.getX() + getX() * q.getW() + getZ() * q.getY() - getY() * q.getZ());
    result.setY(getW() * q.getY() + getY() * q.getW() + getX() * q.getZ() - getZ() * q.getX());
    result.setZ(getW() * q.getZ() + getZ() * q.getW() + getY() * q.getX() - getX() * q.getY());
    result.setW(getW() * q.getW() - getX() * q.getX() - getY() * q.getY() - getZ() * q.getZ());

    return result;
}

//--------------------------------------------------------------------------------------------------
Quaternion& Quaternion::operator *= (const Quaternion& q)
{
    *this = *this * q;

    return *this;
}

//--------------------------------------------------------------------------------------------------
void Quaternion::normalize()
{
    float magnitude = static_cast<float>(sqrt(getW() * getW() + getX() * getX() + getY() * getY() + getZ() * getZ()));

    if(magnitude > 0.0f)
    {
        float temp = 1.0f / magnitude;

        setW(getW() * temp);
        setX(getX() * temp);
        setY(getY() * temp);
        setZ(getZ() * temp);
    }
    else
    {
        identity();
    }
}

//--------------------------------------------------------------------------------------------------
void Quaternion::negate()
{
    setX(-getX());
    setY(-getY());
    setZ(-getZ());
    setW(-getW());
}

//--------------------------------------------------------------------------------------------------
float Quaternion::getRotationAngle()const
{
    float halfAngle = 0.0f;// = SafeAcos(w);

    return halfAngle * 2.0f;
}

//--------------------------------------------------------------------------------------------------
Vector3 Quaternion::getRotationAxis()const
{
    float temp = 1.0f - getW() * getW();

    if(temp <= 0.0f)
    {
        return Vector3(1.0f, 0.0f, 0.0f);
    }

    float temp2 = 1.0f / sqrt(temp);

    return Vector3(getX() * temp2, getY() * temp2, getZ() * temp2);
}

//float DotProduct(const Quaternion& q1, const Quaternion& q2)
//{
//	//
//}

//--------------------------------------------------------------------------------------------------
Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t)
{
    if(t <= 0.0f) return q1;
    if(t >= 1.0f) return q2;

    float cosOmega = 0.0f;// = Dot(q1, q2);

    float qw = q2.getW();
    float qx = q2.getX();
    float qy = q2.getY();
    float qz = q2.getZ();

    if(cosOmega < 0.0f)
    {
        qw = -qw;
        qx = -qx;
        qy = -qy;
        qz = -qz;

        cosOmega = -cosOmega;
    }
    //assert(cosOmega < 1.1f);

    float k0, k1;

    if(cosOmega > 0.9999f)
    {
        k0 = 1.0f - t;
        k1 = t;
    }
    else
    {
        float sinOmega = ::sqrt(1.0f - cosOmega * cosOmega);
        float omega = ::atan2(sinOmega, cosOmega);

        float temp = 1.0f / sinOmega;

        k0 = ::sin((1.0f - t) * omega) * temp;
        k1 = ::sin(t * omega) * temp;
    }

    Quaternion result;

	result.setX(k0 * q1.getX() + k1 * qx);
    result.setY(k0 * q1.getY() + k1 * qy);
    result.setZ(k0 * q1.getZ() + k1 * qz);
    result.setW(k0 * q1.getW() + k1 * qw);

    return result;
}

//--------------------------------------------------------------------------------------------------
Quaternion conjugate(const Quaternion& q)
{
    Quaternion result;

    result.setW(q.getW());

    result.setX(-q.getX());
    result.setY(-q.getY());
    result.setZ(-q.getZ()); 

    return result;
}

//--------------------------------------------------------------------------------------------------
Quaternion power(const Quaternion& q, float exp)
{
    if(::fabs(q.getW()) > 0.9999f) return q;

    float alpha = ::acos(q.getW());
    float newAlpha = alpha * exp;

    Quaternion result;
    result.setW(::cos(newAlpha));

    float mult = ::sin(newAlpha) / ::sin(alpha);

    result.setX(q.getX() * mult);
    result.setY(q.getY() * mult);
    result.setZ(q.getZ() * mult);

    return result;
}

//--------------------------------------------------------------------------------------------------
const void printQ(const Quaternion& q)
{
    std::cout << "Quaternion(" << q.getX() << ", " << q.getY() << ", " << q.getZ() << ", " << q.getW() << ")" << std::endl;
}

//--------------------------------------------------------------------------------------------------
const void printQ(const char* message, const Quaternion& q)
{
    std::cout << message << "\tQuaternion(" << q.getX() << ", " << q.getY() << ", " << q.getZ() << ", " << q.getW() << ")" << std::endl;
}

//--------------------------------------------------------------------------------------------------
Quaternion multiply(const Quaternion& q1, const Quaternion& q2)
{
    Quaternion result;

    result.setW(q1.getW() * q2.getW() - q1.getX() * q2.getX() - q1.getY() * q2.getY() - q1.getZ() * q2.getZ());
    result.setX(q1.getW() * q2.getX() + q1.getX() * q2.getW() + q1.getY() * q2.getZ() - q1.getZ() * q2.getY());
    result.setY(q1.getW() * q2.getY() - q1.getX() * q2.getZ() + q1.getY() * q2.getW() + q1.getZ() * q2.getX());
    result.setZ(q1.getW() * q2.getZ() + q1.getX() * q2.getY() - q1.getY() * q2.getX() + q1.getZ() * q2.getW());

    return result;
}
}    // end of math namespace
}    // end of mg namespace