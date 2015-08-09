/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_MATRIX3_H_
#define MG_MATH_MATRIX3_H_

#include <iostream>

#ifndef MG_MATH_VECTOR3_H_
#include "vector3.h"
#endif

namespace mg
{
namespace math
{
class Matrix3
{
public:
    Matrix3();

    // Parameter mt - array of values
    Matrix3(const float* mt)
    {
        m3_[0] = mt[0];
        m3_[1] = mt[1];
        m3_[2] = mt[2];
        m3_[3] = mt[3];
        m3_[4] = mt[4];
        m3_[5] = mt[5];
        m3_[6] = mt[6];
        m3_[7] = mt[7];
        m3_[8] = mt[8];
    }
    // ---- //
    Matrix3(const Vector3& a, const Vector3& b, const Vector3& c)
    {
        m3_[0] = a.x_;
        m3_[1] = b.x_;
        m3_[2] = c.x_;

        m3_[3] = a.y_;
        m3_[4] = b.y_;
        m3_[5] = c.y_;

        m3_[6] = a.z_;
        m3_[7] = b.z_;
        m3_[8] = c.z_;
    }

    ~Matrix3(){}

    // Transpositing the Matrix
    // Returns This Matrix
    Matrix3& transpose()
    {
        float temp = 0.0f;
        m3_[0] = m3_[0];
        m3_[4] = m3_[4];
        m3_[8] = m3_[8];

        temp = m3_[1];
        m3_[1] = m3_[3];
        m3_[3] = temp;

        temp = m3_[2];
        m3_[2] = m3_[6];
        m3_[6] = temp;

        temp = m3_[5];
        m3_[5] = m3_[7];
        m3_[7] = temp;

        return *this;
    }

    // Resetting the Matrix to Identity
    // Returns This Matrix
    Matrix3& identity()
    {
        m3_[0] = 1.0f;
        m3_[1] = 0.0f;
        m3_[2] = 0.0f;
        m3_[3] = 0.0f;
        m3_[4] = 1.0f;
        m3_[5] = 0.0f;
        m3_[6] = 0.0f;
        m3_[7] = 0.0f;
        m3_[8] = 1.0f;

        return *this;
    }

    // ---- //
    Matrix3& multiplyByScalar(const float& scalar);

    float m3_[9];
private:
};

// Determinant of the matrix
float determinant(const Matrix3& m);

// Helper function - prints out the matrix to the standard output
void printM3(const Matrix3& m);

// Multiplying to matrices
Matrix3 multiply(const Matrix3& m1, const Matrix3& m2);

// Multiplying the matrix by vector
// Returns Vector
Vector3 multiplyByVector(const Matrix3& m, const Vector3& v);

//Matrix3 rotateAboutX(const float& angle, const float& x);
//Matrix3 rotateAboutY(const float& angle, const float& y);
//Matrix3 rotateAboutZ(const float& angle, const float& z);
}    // end of math namespace
}    // end of mg namespace
#endif