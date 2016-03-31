/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "..\include\math\matrix3.h"

namespace mg
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
    determinant = (m._m3[0] * m._m3[5] * m._m3[8]) + (m._m3[3] * m._m3[7] * m._m3[2]) + (m._m3[6] * m._m3[1] * m._m3[5])
        - (m._m3[6] * m._m3[4] * m._m3[2]) - (m._m3[3] * m._m3[1] * m._m3[8]) - (m._m3[0] * m._m3[7] * m._m3[5]);
    return determinant;
}

//--------------------------------------------------------------------------------------------------
void printM3(const Matrix3& m)
{
    std::cout << "[" << m._m3[0] << ", " << m._m3[1] << ", " << m._m3[2] << std::endl;
    std::cout << m._m3[3] << ", " << m._m3[4] << ", " << m._m3[5] << std::endl;
    std::cout << m._m3[6] << ", " << m._m3[7] << ", " << m._m3[8] << "]" << std::endl;
}

//--------------------------------------------------------------------------------------------------
Matrix3 multiply(const Matrix3& m1, const Matrix3& m2)
{
    Matrix3 m;

    m._m3[0] = m1._m3[0] * m2._m3[0] + m1._m3[1] * m2._m3[3] + m1._m3[2] * m2._m3[6];
    m._m3[1] = m1._m3[0] * m2._m3[1] + m1._m3[1] * m2._m3[4] + m1._m3[2] * m2._m3[7];
    m._m3[2] = m1._m3[0] * m2._m3[2] + m1._m3[1] * m2._m3[5] + m1._m3[2] * m2._m3[8];

    m._m3[3] = m1._m3[3] * m2._m3[0] + m1._m3[4] * m2._m3[3] + m1._m3[5] * m2._m3[6];
    m._m3[4] = m1._m3[3] * m2._m3[1] + m1._m3[4] * m2._m3[4] + m1._m3[5] * m2._m3[7];
    m._m3[5] = m1._m3[3] * m2._m3[2] + m1._m3[4] * m2._m3[5] + m1._m3[5] * m2._m3[8];

    m._m3[6] = m1._m3[6] * m2._m3[0] + m1._m3[7] * m2._m3[3] + m1._m3[8] * m2._m3[6];
    m._m3[7] = m1._m3[6] * m2._m3[1] + m1._m3[7] * m2._m3[4] + m1._m3[8] * m2._m3[7];
    m._m3[8] = m1._m3[6] * m2._m3[2] + m1._m3[7] * m2._m3[5] + m1._m3[8] * m2._m3[8];

    return m;
}

//--------------------------------------------------------------------------------------------------
Vector3 multiplyByVector(const Matrix3& m, const Vector3& v)
{
    Vector3 vout;
    vout._x = m._m3[0] * v._x + m._m3[1] * v._y + m._m3[2] * v._z;
    vout._y = m._m3[3] * v._x + m._m3[4] * v._y + m._m3[5] * v._z;
    vout._z = m._m3[6] * v._x + m._m3[7] * v._y + m._m3[8] * v._z;
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
}    // end of mg namespace
