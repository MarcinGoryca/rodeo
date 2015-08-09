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
    this->m3_[0] *= scalar;
    this->m3_[1] *= scalar;
    this->m3_[2] *= scalar;
    this->m3_[3] *= scalar;
    this->m3_[4] *= scalar;
    this->m3_[5] *= scalar;
    this->m3_[6] *= scalar;
    this->m3_[7] *= scalar;
    this->m3_[8] *= scalar;
    return *this;
}

//--------------------------------------------------------------------------------------------------
Matrix3::Matrix3()
{
    m3_[0] = 0.0f;
    m3_[1] = 0.0f;
    m3_[2] = 0.0f;
    m3_[3] = 0.0f;
    m3_[4] = 0.0f;
    m3_[5] = 0.0f;
    m3_[6] = 0.0f;
    m3_[7] = 0.0f;
    m3_[8] = 0.0f;
}

//--------------------------------------------------------------------------------------------------
float determinant(const Matrix3& m)
{
    float determinant = 0.0f; 
    determinant = (m.m3_[0] * m.m3_[5] * m.m3_[8]) + (m.m3_[3] * m.m3_[7] * m.m3_[2]) + (m.m3_[6] * m.m3_[1] * m.m3_[5])
        - (m.m3_[6] * m.m3_[4] * m.m3_[2]) - (m.m3_[3] * m.m3_[1] * m.m3_[8]) - (m.m3_[0] * m.m3_[7] * m.m3_[5]);
    return determinant;
}

//--------------------------------------------------------------------------------------------------
void printM3(const Matrix3& m)
{
    std::cout << "[" << m.m3_[0] << ", " << m.m3_[1] << ", " << m.m3_[2] << std::endl;
    std::cout << m.m3_[3] << ", " << m.m3_[4] << ", " << m.m3_[5] << std::endl;
    std::cout << m.m3_[6] << ", " << m.m3_[7] << ", " << m.m3_[8] << "]" << std::endl;
}

//--------------------------------------------------------------------------------------------------
Matrix3 multiply(const Matrix3& m1, const Matrix3& m2)
{
    Matrix3 m;

    m.m3_[0] = m1.m3_[0] * m2.m3_[0] + m1.m3_[1] * m2.m3_[3] + m1.m3_[2] * m2.m3_[6];
    m.m3_[1] = m1.m3_[0] * m2.m3_[1] + m1.m3_[1] * m2.m3_[4] + m1.m3_[2] * m2.m3_[7];
    m.m3_[2] = m1.m3_[0] * m2.m3_[2] + m1.m3_[1] * m2.m3_[5] + m1.m3_[2] * m2.m3_[8];

    m.m3_[3] = m1.m3_[3] * m2.m3_[0] + m1.m3_[4] * m2.m3_[3] + m1.m3_[5] * m2.m3_[6];
    m.m3_[4] = m1.m3_[3] * m2.m3_[1] + m1.m3_[4] * m2.m3_[4] + m1.m3_[5] * m2.m3_[7];
    m.m3_[5] = m1.m3_[3] * m2.m3_[2] + m1.m3_[4] * m2.m3_[5] + m1.m3_[5] * m2.m3_[8];

    m.m3_[6] = m1.m3_[6] * m2.m3_[0] + m1.m3_[7] * m2.m3_[3] + m1.m3_[8] * m2.m3_[6];
    m.m3_[7] = m1.m3_[6] * m2.m3_[1] + m1.m3_[7] * m2.m3_[4] + m1.m3_[8] * m2.m3_[7];
    m.m3_[8] = m1.m3_[6] * m2.m3_[2] + m1.m3_[7] * m2.m3_[5] + m1.m3_[8] * m2.m3_[8];

    return m;
}

//--------------------------------------------------------------------------------------------------
Vector3 multiplyByVector(const Matrix3& m, const Vector3& v)
{
    Vector3 vout;
    vout.x_ = m.m3_[0] * v.x_ + m.m3_[1] * v.y_ + m.m3_[2] * v.z_;
    vout.y_ = m.m3_[3] * v.x_ + m.m3_[4] * v.y_ + m.m3_[5] * v.z_;
    vout.z_ = m.m3_[6] * v.x_ + m.m3_[7] * v.y_ + m.m3_[8] * v.z_;
    return vout;
}

//--------------------------------------------------------------------------------------------------
/*
Matrix3 rotateAboutX(const float& angle, const float& x)
{
    Matrix3 mat;

    mat.m3_[0] = x;
    mat.m3_[1] = 0.0f;
    mat.m3_[2] = 0.0f;
    mat.m3_[3] = 0.0f;
    mat.m3_[4] = cos(angle);
    mat.m3_[5] = sin(angle);
    mat.m3_[6] = 0.0f;
    mat.m3_[7] = -(sin(angle));
    mat.m3_[7] = cos(angle);
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

    mat.m3_[0] = cos(angle);
    mat.m3_[1] = 0.0f;
    mat.m3_[2] = -(sin(angle));
    mat.m3_[3] = 0.0f;
    mat.m3_[4] = y;
    mat.m3_[5] = 0.0f;
    mat.m3_[6] = sin(angle);
    mat.m3_[7] = 0.0f;
    mat.m3_[8] = cos(angle);

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

    mat.m3_[0] = cos(angle);
    mat.m3_[1] = sin(angle);
    mat.m3_[2] = 0.0f;
    mat.m3_[3] = -(sin(angle));
    mat.m3_[4] = cos(angle);
    mat.m3_[5] = 0.0f;
    mat.m3_[6] = 0.0f;
    mat.m3_[7] = 0.0f;
    mat.m3_[8] = z;

    return mat;
}
*/
}    // end of math namespace
}    // end of mg namespace
