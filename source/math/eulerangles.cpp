/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
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
#include "math\eulerangles.h"

namespace laura
{
namespace math
{
void EulerAngles::canonize()
{
    _pitch = wrapPI(_pitch);

    if(_pitch < -core::LAURA_HALFPI)
    {
        _pitch = -core::LAURA_PI - _pitch;
        _yaw += core::LAURA_PI;
        _roll += core::LAURA_PI;
    }
    else if(_pitch > core::LAURA_HALFPI)
    {
        _pitch = core::LAURA_PI - _pitch;
        _yaw += core::LAURA_PI;
        _roll += core::LAURA_PI;
    }
//Checking for gimbal lock case
    if(fabs(_pitch) > core::LAURA_HALFPI - 1e-4)
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
    theta *= core::LAURA_PI;
    theta -= floor(theta * core::LAURA_ONEBYPI) * core::LAURA_TWOPI;
    theta -= core::LAURA_PI;
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
}    // end of laura namespace