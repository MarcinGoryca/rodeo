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
    x_ = v.x_;
    y_ = v.y_;
    z_ = v.z_;
    w_ = v.w_;
}

//--------------------------------------------------------------------------------------------------
Quaternion::Quaternion(const Vector3& v, float w)
{
    x_ = v.x_;
    y_ = v.y_;
    z_ = v.z_;
    w_ = w;
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
    x_ = 0.0f;
    y_ = 0.0f;
    z_ = 0.0f;
    w_ = 1.0f;
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutX(float angle)
{
    float halfAngle = angle * 0.5f;

    x_ = ::sin(halfAngle);
    y_ = 0.0f;
    z_ = 0.0f;
    w_ = ::cos(halfAngle);
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutY(float angle)
{
    float halfAngle = angle * 0.5f;

    x_ = 0.0f;
    y_ = ::sin(halfAngle);
    z_ = 0.0f;
    w_ = ::cos(halfAngle);
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutZ(float angle)
{
    float halfAngle = angle * 0.5f;

    x_ = 0.0f;
    y_ = 0.0f;
    z_ = ::sin(halfAngle);
    w_ = ::cos(halfAngle);
}

//--------------------------------------------------------------------------------------------------
void Quaternion::rotateAboutAxis(const Vector3& axis, float angle)
{
	//assert(fabs(vectorMag(axis) - 1.0f) < 0.01f);

    float halfAngle = angle * 0.5f;
    float sinHalfAngle = ::sin(halfAngle);

    x_ = axis.x_ * sinHalfAngle;
    y_ = axis.y_ * sinHalfAngle;
    z_ = axis.z_ * sinHalfAngle;
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
    return ::sqrt(w_ * w_ + x_ * x_ + y_ * y_ + z_ * z_);
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

    result.x_ = w_ * q.x_ + x_ * q.w_ + z_ * q.y_ - y_ * q.z_;
    result.y_ = w_ * q.y_ + y_ * q.w_ + x_ * q.z_ - z_ * q.x_;
    result.z_ = w_ * q.z_ + z_ * q.w_ + y_ * q.x_ - x_ * q.y_;
    result.w_ = w_ * q.w_ - x_ * q.x_ - y_ * q.y_ - z_ * q.z_;

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
    float magnitude = static_cast<float>(sqrt(w_ * w_ + x_ * x_ + y_ * y_ + z_ * z_));

    if(magnitude > 0.0f)
    {
        float temp = 1.0f / magnitude;

        w_ *= temp;
        x_ *= temp;
        y_ *= temp;
        z_ *= temp;
    }
    else
    {
        identity();
    }
}

//--------------------------------------------------------------------------------------------------
void Quaternion::negate()
{
    x_ = -x_;
    y_ = -y_;
    z_ = -z_;
    w_ = -w_;
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
    float temp = 1.0f - w_ * w_;

    if(temp <= 0.0f)
    {
        return Vector3(1.0f, 0.0f, 0.0f);
    }

    float temp2 = 1.0f / sqrt(temp);

    return Vector3(x_ * temp2, y_ * temp2, z_ * temp2);
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

    float qw = q2.w_;
    float qx = q2.x_;
    float qy = q2.y_;
    float qz = q2.z_;

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

    result.x_ = k0 * q1.x_ + k1 * qx;
    result.y_ = k0 * q1.y_ + k1 * qy;
    result.z_ = k0 * q1.z_ + k1 * qz;
    result.w_ = k0 * q1.w_ + k1 * qw;

    return result;
}

//--------------------------------------------------------------------------------------------------
Quaternion conjugate(const Quaternion& q)
{
    Quaternion result;

    result.w_ = q.w_;

    result.x_ = -q.x_;
    result.y_ = -q.y_;
    result.z_ = -q.z_; 

    return result;
}

//--------------------------------------------------------------------------------------------------
Quaternion power(const Quaternion& q, float exp)
{
    if(::fabs(q.w_) > 0.9999f) return q;

    float alpha = ::acos(q.w_);
    float newAlpha = alpha * exp;

    Quaternion result;
    result.w_ = ::cos(newAlpha);

    float mult = ::sin(newAlpha) / ::sin(alpha);

    result.x_ = q.x_ * mult;
    result.y_ = q.y_ * mult;
    result.z_ = q.z_ * mult;

    return result;
}

//--------------------------------------------------------------------------------------------------
const void printQ(const Quaternion& q)
{
    std::cout << "Quaternion(" << q.x_ << ", " << q.y_ << ", " << q.z_ << ", " << q.w_ << ")" << std::endl;
}

//--------------------------------------------------------------------------------------------------
const void printQ(const char* message, const Quaternion& q)
{
    std::cout << message << "\tQuaternion(" << q.x_ << ", " << q.y_ << ", " << q.z_ << ", " << q.w_ << ")" << std::endl;
}

//--------------------------------------------------------------------------------------------------
Quaternion multiply(const Quaternion& q1, const Quaternion& q2)
{
    Quaternion result;

    result.w_ = q1.w_ * q2.w_ - q1.x_ * q2.x_ - q1.y_ * q2.y_ - q1.z_ * q2.z_;
    result.x_ = q1.w_ * q2.x_ + q1.x_ * q2.w_ + q1.y_ * q2.z_ - q1.z_ * q2.y_;
    result.y_ = q1.w_ * q2.y_ - q1.x_ * q2.z_ + q1.y_ * q2.w_ + q1.z_ * q2.x_;
    result.z_ = q1.w_ * q2.z_ + q1.x_ * q2.y_ - q1.y_ * q2.x_ + q1.z_ * q2.w_;

    return result;
}
}    // end of math namespace
}    // end of mg namespace