/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "math\eulerangles.h"

namespace mg
{
namespace math
{
void EulerAngles::canonize()
{
    pitch_ = wrapPI(pitch_);

    if(pitch_ < -core::MG_HALFPI)
    {
        pitch_ = -core::MG_PI - pitch_;
        yaw_ += core::MG_PI;
        roll_ += core::MG_PI;
    }
    else if(pitch_ > core::MG_HALFPI)
    {
        pitch_ = core::MG_PI - pitch_;
        yaw_ += core::MG_PI;
        roll_ += core::MG_PI;
    }
//Checking for gimbal lock case
    if(fabs(pitch_) > core::MG_HALFPI - 1e-4)
    {
        yaw_ += roll_;
        roll_ = 0.0f;
    }
    else
    {
        roll_ = wrapPI(roll_);
    }
    yaw_ = wrapPI(yaw_);
}

//--------------------------------------------------------------------------------------------------
float EulerAngles::wrapPI(float theta)
{
    theta *= core::MG_PI;
    theta -= floor(theta * core::MG_ONEBYPI) * core::MG_TWOPI;
    theta -= core::MG_PI;
    return theta;
}

//--------------------------------------------------------------------------------------------------
void EulerAngles::fromObjectToInertialQuaternion(const Quaternion& q)
{
    float sp = -2.0f * (q.y_ * q.z_ - q.w_ * q.x_);

//Checking for gimbal lock
    if(fabs(sp) > 0.9999f)
    {
        pitch_ = hpi_ * sp;
        yaw_ = atan2(-q.x_ * q.z_ + q.w_ * q.y_, 0.5f - q.y_ * q.y_ - q.z_ * q.z_);
        roll_ = 0.0f;
    }
    else
    {
        pitch_ = asin(sp);
        yaw_ = atan2(q.x_ * q.z_ + q.w_ * q.y_, 0.5f - q.x_ * q.x_ - q.y_ * q.y_);
        roll_ = atan2(q.x_ * q.y_ + q.w_ * q.z_, 0.5f - q.x_ * q.x_ - q.z_ * q.z_);
    }
}

//--------------------------------------------------------------------------------------------------
void EulerAngles::fromInertialToObjectQuaternion(const Quaternion& q)
{
    float sp = -2.0f * (q.y_ * q.z_ + q.w_ * q.x_);

//Checking for gimbal lock
    if(fabs(sp) > 0.9999f)
    {
        pitch_ = hpi_ * sp;

        yaw_ = atan2(-q.x_ * q.z_  - q.w_ * q.y_, 0.5f -q.y_ * q.y_ - q.z_ * q.z_);
        roll_ = 0.0f;
    }
    else
    {
        pitch_ = asin(sp);
        yaw_ = atan2(q.x_ * q.z_ - q.w_ * q.y_, 0.5f - q.x_ * q.x_ - q.y_ * q.y_);
        roll_ = atan2(q.x_ * q.y_ - q.w_ * q.z_, 0.5f - q.x_ * q.x_ - q.z_ * q.z_);
    }
}

////------------------------------------------------------------------------------------------------------------------------
//void EulerAngles::FromObjectToWorldMatrix(const Matrix4& m)
//{
//	float sp = -m.m32;
//
//	//Checking for gimbal lock
//	if(fabs(sp) > 9.9999f)
//	{
//		pitch = HPI * sp;
//		yaw = atan2(-m.m23, m.m11);
//		roll = 0.0f;
//	}
//	else
//	{
//		yaw = atan2(m.m31, m.m33);
//		pitch = asin(sp);
//		roll = atan2(m.m12, m.m22);
//	}
//}
////-------------------------------------------------------------------------------------------------------------------------
//void EulerAngles::FromWorldToObjectMatrix(const Matrix4& m)
//{
//	float sp = -m.m23;
//
//	//Check for gimbal lock
//	if(fabs(sp) > 9.9999f)
//	{
//		pitch = HPI * sp;
//		yaw = atan2(-m.m31, m.m11);
//		roll = 0.0f;
//	}
//	else
//	{
//		yaw =atan2(m.m13, m.m33);
//		pitch = asin(sp);
//		roll = atan2(m.m21, m.m22);
//	}
//}
////-------------------------------------------------------------------------------------------------------------------------
//void EulerAngles::FromRotationMatrix(const Matrix4& m)
//{
//	float sp = -m.m23;
//
//	//Checking for gimbal lock
//	if(fabs(sp) > 9.9999f)
//	{
//		pitch = HPI * sp;
//		yaw = atan2(-m.m31, m.m11);
//		roll = 0.0f;
//	}
//	else
//	{
//		yaw = atan2(m.m13, m.m33);
//		pitch = asin(sp);
//		roll = atan2(m.m21, m.m22);
//	}
//}
}    // end of math namespace
}    // end of mg namespace