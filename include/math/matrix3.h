/*
----------------------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_MATH_MATRIX3_H_
#define LAURA_MATH_MATRIX3_H_

#include <iostream>

#ifndef LAURA_MATH_VECTOR3_H_
#include "vector3.h"
#endif

namespace laura
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
        _m3[0] = mt[0];
        _m3[1] = mt[1];
        _m3[2] = mt[2];
        _m3[3] = mt[3];
        _m3[4] = mt[4];
        _m3[5] = mt[5];
        _m3[6] = mt[6];
        _m3[7] = mt[7];
        _m3[8] = mt[8];
    }
    // ---- //
    Matrix3(const Vector3& a, const Vector3& b, const Vector3& c)
    {
        _m3[0] = a.getX();
        _m3[1] = b.getX();
        _m3[2] = c.getX();

        _m3[3] = a.getY();
        _m3[4] = b.getY();
        _m3[5] = c.getY();

        _m3[6] = a.getZ();
        _m3[7] = b.getZ();
        _m3[8] = c.getZ();
    }

    ~Matrix3(){}

    // Transpositing the Matrix
    // Returns This Matrix
    Matrix3& transpose()
    {
        float temp = 0.0f;
        _m3[0] = _m3[0];
        _m3[4] = _m3[4];
        _m3[8] = _m3[8];

        temp = _m3[1];
        _m3[1] = _m3[3];
        _m3[3] = temp;

        temp = _m3[2];
        _m3[2] = _m3[6];
        _m3[6] = temp;

        temp = _m3[5];
        _m3[5] = _m3[7];
        _m3[7] = temp;

        return *this;
    }

    // Resetting the Matrix to Identity
    // Returns This Matrix
    Matrix3& identity()
    {
        _m3[0] = 1.0f;
        _m3[1] = 0.0f;
        _m3[2] = 0.0f;
        _m3[3] = 0.0f;
        _m3[4] = 1.0f;
        _m3[5] = 0.0f;
        _m3[6] = 0.0f;
        _m3[7] = 0.0f;
        _m3[8] = 1.0f;

        return *this;
    }

    // ---- //
    Matrix3& multiplyByScalar(const float& scalar);

	/*
	 * ----------------------------------------------------------
	 *	Returns member of a matrix
	 *  Parameter member of the matrix (int)
	 * ----------------------------------------------------------
	 */
	float getM3(int index) const { return _m3[index]; }

	/*
	 * ----------------------------------------------------------
	 *	Sets a member of a matrix
	 *	Parameter index (int) number of a member
	 *  Parameter m3 (float) value of the member
	 * ----------------------------------------------------------
	 */
	void setM3(int index, float m3) { _m3[index] = m3; }

private:
	float _m3[9];
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
}
} 
#endif