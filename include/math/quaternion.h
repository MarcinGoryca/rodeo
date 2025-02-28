﻿/*
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
#ifndef RODEO_MATH_QUATERNION_H_
#define RODEO_MATH_QUATERNION_H_

#ifndef RODEO_MATH_VECTOR4_H_
#include "vector4.h"
#endif

namespace rodeo
{
namespace math
{
class Quaternion
{
public:
	/*
	 | -------------------------------------------------------------------------------------
	 |     Default Constructor
	 | -------------------------------------------------------------------------------------
	 */
    Quaternion()
        :_x(0.0f), _y(0.0f), _z(0.0f), _w(1.0f)
    {}

    /*
	 | -------------------------------------------------------------------------------------
	 |     Constructing quaternion by vector
	 | -------------------------------------------------------------------------------------
	 */
    Quaternion(const Vector4& v);

    /*
	 | -------------------------------------------------------------------------------------
	 |     Constructing quaternion by vector and a number
	 |     Parameter Vector3, float value
	 | -------------------------------------------------------------------------------------
	 */
    Quaternion(const Vector3& v, float w);

    /*
	 | -------------------------------------------------------------------------------------
	 |     Constructing quaternion from four numbers
	 | -------------------------------------------------------------------------------------
	 */
    Quaternion(float fx, float fy, float fz, float fw)
        :_x(fx), _y(fy), _z(fz), _w(fw)
    {}
    
	/*
	 | -------------------------------------------------------------------------------------
	 |     Destructor
	 | -------------------------------------------------------------------------------------
	 */
    ~Quaternion(){}

    /*
	 | -------------------------------------------------------------------------------------
	 |     Gets the Quaternion
	 | -------------------------------------------------------------------------------------
	 */
    const Quaternion& get() const;

    /*
	 | -------------------------------------------------------------------------------------
	 |     Positive identity quaternion 
     |     No angualar displacement [1, 0]
	 | -------------------------------------------------------------------------------------
	 */
    static const void positiveIdentity();

    /*
	 | -------------------------------------------------------------------------------------
	 |     Negative identity quatenion
     |     No angular displacement [-1, 0]
	 | -------------------------------------------------------------------------------------
	 */
    static const void negativeIdentity();

    /*
	 | -------------------------------------------------------------------------------------
	 |     Sets Quaternion to Identity
	 | -------------------------------------------------------------------------------------
	 */
    void identity();

    /*
	 | -------------------------------------------------------------------------------------
     |     Rotates about X-axis
	 | -------------------------------------------------------------------------------------
	 */
    void rotateAboutX(float angle);

    /*
	 | -------------------------------------------------------------------------------------
	 |     Rotates about Y-axis 
	 | -------------------------------------------------------------------------------------
	 */
    void rotateAboutY(float angle);

    /*
	 | -------------------------------------------------------------------------------------
	 |    Rotates about Z-axis
	 | -------------------------------------------------------------------------------------
	*/ 
    void rotateAboutZ(float angle);

    // Rotates about specified axis 
    void rotateAboutAxis(const Vector3& axis, float angle);

    // Inverse quaternion q pow(-1) = [w -v] / length(q)
    void inverse(const Quaternion& q);

    // Negate vector 
    void negate();

    // Length of Quaternion 
    //	|| q || = sqrt(w^2 + x^2 + y^2 + z^2) 
    float length();

    // Cross Product 
    Quaternion operator* (const Quaternion& a)const;

    Quaternion& operator*= (const Quaternion& a);
    void normalize();
    float getRotationAngle()const;
    Vector3 getRotationAxis()const;
    inline float dot(const Quaternion& q1, const Quaternion& q2)
    {
        return q1._w * q2._w + q1._x * q2._x + q1._y * q2._y + q1._z * q2._z;
    }

	float getX() const { return _x; }
	float getY() const { return _y; }
	float getZ() const { return _z; }
	float getW() const { return _w; }

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setZ(float z) { _z = z; }
	void setW(float w) { _w = w; }

private:
	float _x, _y, _z, _w;
};

// Dot Product of two quaternions
// Returns float value of a dot product
float dotProduct(const Quaternion& q1, const Quaternion& q2);
Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t);

// Conjugate - negating vector part of a quaternion;
Quaternion conjugate(const Quaternion& q);
Quaternion power(const Quaternion& q, float exp);

// Multiplying quaternions
Quaternion multiply(const Quaternion& q1, const Quaternion& q2);

// Helper function - prints out Quaternion to standard output
const void printQ(const Quaternion& q);

// Helper function - prints out Quaternion to standard output
// Parameter message - Message to console
const void printQ(const char* message, const Quaternion& q);
}
}
#endif

/*
 * NOTES:
 * Q = [w, v] == [w, (x, y, z)]
 * w - scalar
 * v - vector
 *
 * w = cos(angle(theta)/2)
 * v = sin(angle(theta)/2)
 *
 * Quaternions have a vector (x, y, z) - represents which axis the rotation occurs,
 * and a scalar - value of the angle
 * i = sqrt(-1);
 * i = j = k = sqrt(-1)
 * q = w + xi + yj + zk;
 * imaginary part (i, j, k) is not needed in programming
 * Normalizing a quaternion
 * magnitude = sqrt(w*w + x*x + y*y + z*z);
 * w = w / magnitude;
 * x = x / magnitude;
 * y = y / magnitude;
 * z = z / magnitude;
 * Multiplying quaternions
 * Q1, Q2;
 * (Q1 * Q2).w = (w1w2 - x1x2 - y1y2 - z1z2);
 * (Q1 * Q2).x = (w1x2 + x1w2 + y1z2 - z1y2);
 * (Q1 * Q2).y = (w1y2 - x1z2 + y1w2 + z1x2);
 * (Q1 * Q2).z = (w1z2 + x1y2 - y1x2 + z1w2);
 */
