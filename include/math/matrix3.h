/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
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
#ifndef RODEO_MATH_MATRIX3_H_
#define RODEO_MATH_MATRIX3_H_

#include <iostream>

#ifndef RODEO_MATH_VECTOR3_H_
#include "vector3.h"
#endif

namespace rodeo
{
namespace math
{
class Matrix3
{
public:
    Matrix3();

    /*
	 | -------------------------------------------------------------------
	 |     Class constructor 
	 |     Parameter mt - array of values
	 | -------------------------------------------------------------------
	 */
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
    
	/*
	 | -------------------------------------------------------------------
	 |     Class Constructor
	 |     Parameter a - Vector3
	 |        You must note that it will produce x, y, z values
	 |        for specified positions in the matrix
	 |        first value (x) goes to the first position
	 |        second value (y) goes to the fourth position
	 |        third value (z) goes to the seventh position
	 |     Parameter b - Vector3
	 |        You must note that it will produce x, y, z values
	 |        for specified positions in the matrix
	 |        first value (x) goes to the second position
	 |        second value (y) goes to the fifth position
	 |        third value (z) goes to the eight position
	 |     Parameter c - Vector3
	 |        You must note that it will produce x, y, z values
	 |        for specified positions in the matrix
	 |        first value (x) goes to the third position
	 |        second value (y) goes to the sixth position
	 |        third value (z) goes to the ninth position
	 | -------------------------------------------------------------------
	 */
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

	/*
	 | -------------------------------------------------------------------
	 |     Destructor
	 | -------------------------------------------------------------------
	 */
    ~Matrix3(){}

    /*
	 | -------------------------------------------------------------------
	 |     Transpositing the Matrix
	 |     Returns This Matrix
	 | -------------------------------------------------------------------
     */ 
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

    /*
	 | ----------------------------------------------------------------------
	 |     Resetting the Matrix to Identity
     |     Returns This Matrix
	 | ----------------------------------------------------------------------
	 */
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

    /*
	 | ------------------------------------------------------------
	 |     Multiplying a matrix by a scalar
	 |     Parameter float value of a scalar
	 |     Returns this Matrix3 multiplied by a scalar
	 | ------------------------------------------------------------
	 */
    Matrix3& multiplyByScalar(const float& scalar);

	/*
	 | ----------------------------------------------------------
	 |	Returns member of a matrix
	 |  Parameter member of the matrix (int)
	 | ----------------------------------------------------------
	 */
	float getM3(int index) const { return _m3[index]; }

	/*
	 | ----------------------------------------------------------
	 |	Sets a member of a matrix
	 |	Parameter index (int) number of a member
	 |  Parameter m3 (float) value of the member
	 | ----------------------------------------------------------
	 */
	void setM3(int index, float m3) { _m3[index] = m3; }

private:
	float _m3[9];
};

/*
 | ----------------------------------------------------------------------------
 |     Determinant of the Matrix
 |     Returns float value
 | ----------------------------------------------------------------------------
 */
float determinant(const Matrix3& m);

/*
 | ----------------------------------------------------------------------------
 |     Helper function - prints out the matrix to the standard output
 | ----------------------------------------------------------------------------
 */
void printM3(const Matrix3& m);

/*
 | ----------------------------------------------------------------------------
 |     Multiplying two matrices
 |     Returns new Matrix3, result of multiplication
 | ----------------------------------------------------------------------------
 */
Matrix3 multiply(const Matrix3& m1, const Matrix3& m2);

/*
 | ----------------------------------------------------------------------------
 |     Multiplying the matrix by vector
 |     Returns Vector3
 | ----------------------------------------------------------------------------
 */
Vector3 multiplyByVector(const Matrix3& m, const Vector3& v);

//Matrix3 rotateAboutX(const float& angle, const float& x);
//Matrix3 rotateAboutY(const float& angle, const float& y);
//Matrix3 rotateAboutZ(const float& angle, const float& z);
}
} 
#endif