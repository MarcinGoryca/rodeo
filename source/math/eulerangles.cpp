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
    _pitch = wrapPI(_pitch);

    if(_pitch < -core::MG_HALFPI)
    {
        _pitch = -core::MG_PI - _pitch;
        _yaw += core::MG_PI;
        _roll += core::MG_PI;
    }
    else if(_pitch > core::MG_HALFPI)
    {
        _pitch = core::MG_PI - _pitch;
        _yaw += core::MG_PI;
        _roll += core::MG_PI;
    }
//Checking for gimbal lock case
    if(fabs(_pitch) > core::MG_HALFPI - 1e-4)
    {
        _yaw += _roll;
        _roll = 0.0f;
    }
    else
    {
        _roll = wrapPI(_roll);
    }
    _yaw = wrapPI(_yaw);
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
    float sp = -2.0f * (q.getY() * q.getZ() - q.getW() * q.getX());

//Checking for gimbal lock
    if(fabs(sp) > 0.9999f)
    {
        _pitch = _hpi * sp;
        _yaw = atan2(-q.getX() * q.getZ() + q.getW() * q.getY(), 0.5f - q.getY() * q.getY() - q.getZ() * q.getZ());
        _roll = 0.0f;
    }
    else
    {
        _pitch = asin(sp);
        _yaw = atan2(q.getX() * q.getZ() + q.getW() * q.getY(), 0.5f - q.getX() * q.getX() - q.getY() * q.getY());
        _roll = atan2(q.getX() * q.getY() + q.getW() * q.getZ(), 0.5f - q.getX() * q.getX() - q.getZ() * q.getZ());
    }
}

//--------------------------------------------------------------------------------------------------
void EulerAngles::fromInertialToObjectQuaternion(const Quaternion& q)
{
    float sp = -2.0f * (q.getY() * q.getZ() + q.getW() * q.getX());

//Checking for gimbal lock
    if(fabs(sp) > 0.9999f)
    {
        _pitch = _hpi * sp;

        _yaw = atan2(-q.getX() * q.getZ()  - q.getW() * q.getY(), 0.5f -q.getY() * q.getY() - q.getZ() * q.getZ());
        _roll = 0.0f;
    }
    else
    {
        _pitch = asin(sp);
        _yaw = atan2(q.getX() * q.getZ() - q.getW() * q.getY(), 0.5f - q.getX() * q.getX() - q.getY() * q.getY());
        _roll = atan2(q.getX() * q.getY() - q.getW() * q.getZ(), 0.5f - q.getX() * q.getX() - q.getZ() * q.getZ());
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