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
#include "..\include\math\matrix3.h"

namespace laura
{
namespace math
{
Matrix3& Matrix3::multiplyByScalar(const float& scalar)
{
    this->_m3[0] *= scalar;
    this->_m3[1] *= scalar;
    this->_m3[2] *= scalar;
    this->_m3[3] *= scalar;
    this->_m3[4] *= scalar;
    this->_m3[5] *= scalar;
    this->_m3[6] *= scalar;
    this->_m3[7] *= scalar;
    this->_m3[8] *= scalar;
    return *this;
}

//--------------------------------------------------------------------------------------------------
Matrix3::Matrix3()
{
    _m3[0] = 0.0f;
    _m3[1] = 0.0f;
    _m3[2] = 0.0f;
    _m3[3] = 0.0f;
    _m3[4] = 0.0f;
    _m3[5] = 0.0f;
    _m3[6] = 0.0f;
    _m3[7] = 0.0f;
    _m3[8] = 0.0f;
}

//--------------------------------------------------------------------------------------------------
float determinant(const Matrix3& m)
{
    float determinant = 0.0f; 
 
	determinant = (m.getM3(0) * m.getM3(4) * m.getM3(8)) +
		(m.getM3(3) * m.getM3(7) * m.getM3(2)) +
		(m.getM3(6) * m.getM3(1) * m.getM3(5)) -
		(m.getM3(6) * m.getM3(4) * m.getM3(2)) -
		(m.getM3(3) * m.getM3(1) * m.getM3(8)) -
		(m.getM3(0) * m.getM3(7) * m.getM3(5));
	
    return determinant;
}

//--------------------------------------------------------------------------------------------------
void printM3(const Matrix3& m)
{
    std::cout << "[" << m.getM3(0) << ", " << m.getM3(1) << ", " << m.getM3(2) << std::endl;
    std::cout << m.getM3(3) << ", " << m.getM3(4) << ", " << m.getM3(5) << std::endl;
    std::cout << m.getM3(6) << ", " << m.getM3(7) << ", " << m.getM3(8) << "]" << std::endl;
}

//--------------------------------------------------------------------------------------------------
Matrix3 multiply(const Matrix3& m1, const Matrix3& m2)
{
    Matrix3 m;

    /*m._m3[0] = m1._m3[0] * m2._m3[0] + m1._m3[1] * m2._m3[3] + m1._m3[2] * m2._m3[6];
    m._m3[1] = m1._m3[0] * m2._m3[1] + m1._m3[1] * m2._m3[4] + m1._m3[2] * m2._m3[7];
    m._m3[2] = m1._m3[0] * m2._m3[2] + m1._m3[1] * m2._m3[5] + m1._m3[2] * m2._m3[8];

    m._m3[3] = m1._m3[3] * m2._m3[0] + m1._m3[4] * m2._m3[3] + m1._m3[5] * m2._m3[6];
    m._m3[4] = m1._m3[3] * m2._m3[1] + m1._m3[4] * m2._m3[4] + m1._m3[5] * m2._m3[7];
    m._m3[5] = m1._m3[3] * m2._m3[2] + m1._m3[4] * m2._m3[5] + m1._m3[5] * m2._m3[8];

    m._m3[6] = m1._m3[6] * m2._m3[0] + m1._m3[7] * m2._m3[3] + m1._m3[8] * m2._m3[6];
    m._m3[7] = m1._m3[6] * m2._m3[1] + m1._m3[7] * m2._m3[4] + m1._m3[8] * m2._m3[7];
    m._m3[8] = m1._m3[6] * m2._m3[2] + m1._m3[7] * m2._m3[5] + m1._m3[8] * m2._m3[8];*/

	m.setM3(0, m1.getM3(0) * m2.getM3(0) + m1.getM3(1) * m2.getM3(3) + m1.getM3(2) * m2.getM3(6));
	m.setM3(1, m1.getM3(0) * m2.getM3(1) + m1.getM3(1) * m2.getM3(4) + m1.getM3(2) * m2.getM3(7));
	m.setM3(2, m1.getM3(0) * m2.getM3(2) + m1.getM3(1) * m2.getM3(5) + m1.getM3(2) * m2.getM3(8));
	m.setM3(3, m1.getM3(3) * m2.getM3(0) + m1.getM3(4) * m2.getM3(3) + m1.getM3(5) * m2.getM3(6));
	m.setM3(4, m1.getM3(3) * m2.getM3(1) + m1.getM3(4) * m2.getM3(4) + m1.getM3(5) * m2.getM3(7));
	m.setM3(5, m1.getM3(3) * m2.getM3(2) + m1.getM3(4) * m2.getM3(5) + m1.getM3(5) * m2.getM3(8));
	m.setM3(6, m1.getM3(6) * m2.getM3(0) + m1.getM3(7) * m2.getM3(3) + m1.getM3(8) * m2.getM3(6));
	m.setM3(7, m1.getM3(6) * m2.getM3(1) + m1.getM3(7) * m2.getM3(4) + m1.getM3(8) * m2.getM3(7));
	m.setM3(8, m1.getM3(6) * m2.getM3(2) + m1.getM3(7) * m2.getM3(5) + m1.getM3(8) * m2.getM3(8));

    return m;
}

//--------------------------------------------------------------------------------------------------
Vector3 multiplyByVector(const Matrix3& m, const Vector3& v)
{
    Vector3 vout;
    /*vout._x = m._m3[0] * v._x + m._m3[1] * v._y + m._m3[2] * v._z;
    vout._y = m._m3[3] * v._x + m._m3[4] * v._y + m._m3[5] * v._z;
    vout._z = m._m3[6] * v._x + m._m3[7] * v._y + m._m3[8] * v._z;*/

	vout.setX(m.getM3(0) * v.getX() + m.getM3(1) * v.getY() + m.getM3(2) * v.getZ());
	vout.setY(m.getM3(3) * v.getX() + m.getM3(4) * v.getY() + m.getM3(5) * v.getZ());
	vout.setZ(m.getM3(6) * v.getX() + m.getM3(7) * v.getY() + m.getM3(8) * v.getZ());

    return vout;
}

//--------------------------------------------------------------------------------------------------
/*
Matrix3 rotateAboutX(const float& angle, const float& x)
{
    Matrix3 mat;

    mat._m3[0] = x;
    mat._m3[1] = 0.0f;
    mat._m3[2] = 0.0f;
    mat._m3[3] = 0.0f;
    mat._m3[4] = cos(angle);
    mat._m3[5] = sin(angle);
    mat._m3[6] = 0.0f;
    mat._m3[7] = -(sin(angle));
    mat._m3[7] = cos(angle);
    return mat;
}
*/

/**
 *
 */
/*
Matrix3 rotateAboutY(const float& angle, const float& y)
{
    Matrix3 mat;

    mat._m3[0] = cos(angle);
    mat._m3[1] = 0.0f;
    mat._m3[2] = -(sin(angle));
    mat._m3[3] = 0.0f;
    mat._m3[4] = y;
    mat._m3[5] = 0.0f;
    mat._m3[6] = sin(angle);
    mat._m3[7] = 0.0f;
    mat._m3[8] = cos(angle);

    return mat;
}
*/
/**
 *
 */
/*
Matrix3 rotateAboutZ(const float& angle, const float& z)
{
    Matrix3 mat;

    mat._m3[0] = cos(angle);
    mat._m3[1] = sin(angle);
    mat._m3[2] = 0.0f;
    mat._m3[3] = -(sin(angle));
    mat._m3[4] = cos(angle);
    mat._m3[5] = 0.0f;
    mat._m3[6] = 0.0f;
    mat._m3[7] = 0.0f;
    mat._m3[8] = z;

    return mat;
}
*/
}    // end of math namespace
}    // end of laura namespace
