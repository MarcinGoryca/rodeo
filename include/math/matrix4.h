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
#ifndef LAURA_MATH_MATRIX4_H_
#define LAURA_MATH_MATRIX4_H_

#ifndef LAURA_MATH_VECTOR4_H_
#include "vector4.h"
#endif

namespace laura
{
namespace math
{
class Matrix4
{
public:
    Matrix4();
    
	/*
	 | --------------------------------------------------------------------------
	 |     Class Constructor
	 |     Parameters 16 float values
	 | --------------------------------------------------------------------------
	 */
    Matrix4(float m00, float m01, float m02, float m03,
            float m04, float m05, float m06, float m07,
            float m08, float m09, float m10, float m11,
            float m12, float m13, float m14, float m15)
     {
      _m4[0] = m00;
      _m4[1] = m01;
      _m4[2] = m02;
      _m4[3] = m03;
      _m4[4] = m04;
      _m4[5] = m05;
      _m4[6] = m06;
      _m4[7] = m07;
      _m4[8] = m08;
      _m4[9] = m09;
      _m4[10] = m10;
      _m4[11] = m11;
      _m4[12] = m12;
      _m4[13] = m13;
      _m4[14] = m14;
      _m4[15] = m15;
     }

    /*
	 | ---------------------------------------------------------------------
	 |     Constructor with one parameter
	 |     Parameter arr - Array of values
	 | ---------------------------------------------------------------------
	 */
    Matrix4(const float* arr)
    {
        for(int i=0; i<16; ++i)
            _m4[i] = arr[i];
    }

	/*
	 | ---------------------------------------------------------------------
	 |     Constructor with four parameters
	 |     Parameters - Vector4 objects
	 | ---------------------------------------------------------------------
	 */
    Matrix4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4);

    /*
	 | ---------------------------------------------------------------------
	 |     Copy constructor
	 | ---------------------------------------------------------------------
	 */
    Matrix4(const Matrix4& mc)
    {
        for(int i = 0; i < 16; ++i)
            _m4[i] = mc._m4[i];
    }

    /* 
	 | ---------------------------------------------------------------------
	 |     Constructing Matrix with Vector
     |     Vector is assigned ONLY to three values of the matrix
	 |     Positions affected 12,13,14
	 | ---------------------------------------------------------------------
	 */
    Matrix4(const Vector3& v3)
    {
        _m4[0] = 1.0f;
        _m4[1] = 0.0f;
        _m4[2] = 0.0f;
        _m4[3] = 0.0f;
        _m4[4] = 0.0f;
        _m4[5] = 1.0f;
        _m4[6] = 0.0f;
        _m4[7] = 0.0f;
        _m4[8] = 0.0f;
        _m4[9] = 0.0f;
        _m4[10] = 1.0f;
        _m4[11] = 0.0f;
        _m4[12] = v3.getX();
        _m4[13] = v3.getY();
        _m4[14] = v3.getZ();
        _m4[15] = 1.0f;
    }

	/*
	 | ----------------------------------------------------------------------------
	 |     Destructor
	 | ----------------------------------------------------------------------------
	 */
    ~Matrix4(){}

    /*
	 | ----------------------------------------------------------------------------
	 |     Loads Identity Matrix
	 | ----------------------------------------------------------------------------
	 */
    Matrix4& loadIdentity();

    /*
	 | ----------------------------------------------------------------------------
	 |     Transpose Matrix
	 | ----------------------------------------------------------------------------
	 */
    inline Matrix4& transpose()
    {
        float temp = 0.0f;

        _m4[0] = _m4[0];
        _m4[5] = _m4[5];
        _m4[10] = _m4[10];
        _m4[15] = _m4[15];

        if(_m4[15] != 1.0f)
             _m4[15] = 1.0f;

        temp = _m4[1];
        _m4[1] = _m4[4];
        _m4[4] = temp;

        temp = _m4[2];
        _m4[2] = _m4[8];
        _m4[8] = temp;

        temp = _m4[3];
        _m4[3] = _m4[12];
        _m4[12] = temp;

        temp = _m4[6];
        _m4[6] = _m4[9];
        _m4[9] = temp;

        temp = _m4[13];
        _m4[13] = _m4[7];
        _m4[7] = temp;

        temp = _m4[14];
        _m4[14] = _m4[11];
        _m4[11] = temp;

        return *this;
    }

    /* 
	 | ----------------------------------------------------------------------------
	 |     Multiplying a matrix by a scalar
     |     Returns This Matrix
	 | ----------------------------------------------------------------------------
	 */
    inline Matrix4& operator*(float scalar)
    {
        for(int i = 0; i < 16; ++i)
            _m4[i] =  _m4[i] * scalar;
        return *this;
    }

    /*
	 | ----------------------------------------------------------------------------------------------------------
	 |     Multiplying a matrix by a matrix
     |     Returns Matrix
	 | ----------------------------------------------------------------------------------------------------------
	 */
    inline Matrix4 operator*(Matrix4& mc)
    {
        Matrix4 out = _S_IDENTITY;
        out._m4[0] = _m4[0] * mc._m4[0] + _m4[1] * mc._m4[4] + _m4[2] * mc._m4[8] + _m4[3] * mc._m4[12];
        out._m4[1] = _m4[0] * mc._m4[1] + _m4[1] * mc._m4[5] + _m4[2] * mc._m4[9] + _m4[3] * mc._m4[13];
        out._m4[2] = _m4[0] * mc._m4[2] + _m4[1] * mc._m4[6] + _m4[2] * mc._m4[10] + _m4[3] * mc._m4[14];
        out._m4[3] = _m4[0] * mc._m4[3] + _m4[1] * mc._m4[7] + _m4[2] * mc._m4[11] + _m4[3] * mc._m4[15];

        out._m4[4] = _m4[4] * mc._m4[0] + _m4[5] * mc._m4[4] + _m4[6] * mc._m4[8] + _m4[7] * mc._m4[12];
        out._m4[5] = _m4[4] * mc._m4[1] + _m4[5] * mc._m4[5] + _m4[6] * mc._m4[9] + _m4[7] * mc._m4[13];
        out._m4[6] = _m4[4] * mc._m4[2] + _m4[5] * mc._m4[6] + _m4[6] * mc._m4[10] + _m4[7] * mc._m4[14];
        out._m4[7] = _m4[4] * mc._m4[3] + _m4[5] * mc._m4[7] + _m4[6] * mc._m4[11] + _m4[7] * mc._m4[15];

        out._m4[8] = _m4[8] * mc._m4[0] + _m4[9] * mc._m4[4] + _m4[10] * mc._m4[8] + _m4[11] * mc._m4[12];
        out._m4[9] = _m4[8] * mc._m4[1] + _m4[9] * mc._m4[5] + _m4[10] * mc._m4[9] + _m4[11] * mc._m4[13];
        out._m4[10] = _m4[8] * mc._m4[2] + _m4[9] * mc._m4[6] + _m4[10] * mc._m4[10] + _m4[11] * mc._m4[14];
        out._m4[11] = _m4[8] * mc._m4[3] + _m4[9] * mc._m4[7] + _m4[10] * mc._m4[11] + _m4[11] * mc._m4[15];

        out._m4[12] = _m4[12] * mc._m4[0] + _m4[13] * mc._m4[4] + _m4[14] * mc._m4[8] + _m4[15] * mc._m4[12]; 	
        out._m4[13] = _m4[12] * mc._m4[1] + _m4[13] * mc._m4[5] + _m4[14] * mc._m4[9] + _m4[15] * mc._m4[13];
        out._m4[14] = _m4[12] * mc._m4[2] + _m4[13] * mc._m4[6] + _m4[14] * mc._m4[10] + _m4[15] * mc._m4[14]; 
        out._m4[15] = _m4[12] * mc._m4[3] + _m4[13] * mc._m4[7] + _m4[14] * mc._m4[11] + _m4[15] * mc._m4[15];

        return out;
    }

    /*
	 | ------------------------------------------------------------------------------------------------------
	 |     Asigning one matrix to another
     |     Returns This Matrix
	 | ------------------------------------------------------------------------------------------------------
	 */
    inline Matrix4& operator= (const Matrix4& mc)
    {
        for(int i=0; i<16; ++i)
            _m4[i] = mc._m4[i];

        return *this;
    }

    /*
	 | --------------------------------------------------------------------------------------------
	 |     Checking equality of two matrices
     |     Returns TRUE if matrices are equal, FALSE otherwise
	 | --------------------------------------------------------------------------------------------
	 */
    inline bool operator== (const Matrix4& mc)const
    {
        if(_m4[0] == mc._m4[0] && _m4[1] == mc._m4[1] && _m4[2] == mc._m4[2] && _m4[3] == mc._m4[3] &&
        _m4[4] == mc._m4[4] && _m4[5] == mc._m4[5] && _m4[6] == mc._m4[6] && _m4[7] == mc._m4[7] &&
        _m4[8] == mc._m4[8] && _m4[9] == mc._m4[9] && _m4[10] == mc._m4[10] && _m4[11] == mc._m4[11] &&
        _m4[12] == mc._m4[12] && _m4[13] == mc._m4[13] && _m4[14] == mc._m4[14] && _m4[15] == mc._m4[15])
            return true;
        else
           return false;
    }

    /*
	 | ---------------------------------------------------------------------------------------------
	 |     Checking if two matrices are NOT equal
     |     Returns TRUE if two matrices are NOT equal, TRUE otherwise
	 | ---------------------------------------------------------------------------------------------
	 */
    inline bool operator!= (const Matrix4& mc) const
    {
        if(
            _m4[0] != mc._m4[0] || _m4[1] != mc._m4[1] || _m4[2] != mc._m4[2] || _m4[3] != mc._m4[3] ||
            _m4[4] != mc._m4[4] || _m4[5] != mc._m4[5] || _m4[6] != mc._m4[6] || _m4[7] != mc._m4[7] ||
            _m4[8] != mc._m4[8] || _m4[9] != mc._m4[9] || _m4[10] != mc._m4[10] || _m4[11] != mc._m4[11] ||
            _m4[12] != mc._m4[12] || _m4[13] != mc._m4[13] || _m4[14] != mc._m4[14] || _m4[15] != mc._m4[15]
            )
        return true;
        else
        return false;
    }

    /*
	 | --------------------------------------------------------------------------------------------------
	 |     Adding Two Matrices
	 |     Returns Matrix4
	 | --------------------------------------------------------------------------------------------------
	 */
    inline Matrix4 operator+(const Matrix4& mc)const
    {
        Matrix4 ret;

        ret._m4[0] = _m4[0] + mc._m4[0];
        ret._m4[1] = _m4[1] + mc._m4[1];
        ret._m4[2] = _m4[2] + mc._m4[2];
        ret._m4[3] = _m4[3] + mc._m4[3];
        ret._m4[4] = _m4[4] + mc._m4[4];
        ret._m4[5] = _m4[5] + mc._m4[5];
        ret._m4[6] = _m4[6] + mc._m4[6];
        ret._m4[7] = _m4[7] + mc._m4[7];
        ret._m4[8] = _m4[8] + mc._m4[8];
        ret._m4[9] = _m4[9] + mc._m4[9];
        ret._m4[10] = _m4[10] + mc._m4[10];
        ret._m4[11] = _m4[11] + mc._m4[11];
        ret._m4[12] = _m4[12] + mc._m4[12];
        ret._m4[13] = _m4[13] + mc._m4[13];
        ret._m4[14] = _m4[14] + mc._m4[14];
        ret._m4[15] = _m4[15] + mc._m4[15];

        return ret;
    }

    /*
	 | ------------------------------------------------------------------------------------------------
	 |     Subtracting two matrices
	 |     Returns Matrix4
	 | ------------------------------------------------------------------------------------------------
	 */
    inline Matrix4 operator-(const Matrix4& mc) const
    {
        Matrix4 ret;

        ret._m4[0] = _m4[0] - mc._m4[0]; 
        ret._m4[1] = _m4[1] - mc._m4[1];
        ret._m4[2] = _m4[2] - mc._m4[2];
        ret._m4[3] = _m4[3] - mc._m4[3];
        ret._m4[4] = _m4[4] - mc._m4[4];
        ret._m4[5] = _m4[5] - mc._m4[5];
        ret._m4[6] = _m4[6] - mc._m4[6];
        ret._m4[7] = _m4[7] - mc._m4[7];
        ret._m4[8] = _m4[8] - mc._m4[8];
        ret._m4[9] = _m4[9] - mc._m4[9];
        ret._m4[10] = _m4[10] - mc._m4[10];
        ret._m4[11] = _m4[11] - mc._m4[11];
        ret._m4[12] = _m4[12] - mc._m4[12];
        ret._m4[13] = _m4[13] - mc._m4[13];
        ret._m4[14] = _m4[14] - mc._m4[14];
        ret._m4[15] = _m4[15] - mc._m4[15];

        return ret;
    }

    /*
	 | ------------------------------------------------------------------------------------------
	 |      Adding two matrices
	 |      Returns Matrix4
	 | ------------------------------------------------------------------------------------------
	 */
    inline Matrix4& operator+=(const Matrix4& mc)
    {
        _m4[0] += mc._m4[0];
        _m4[1] += mc._m4[1];
        _m4[2] += mc._m4[2];
        _m4[3] += mc._m4[3];
        _m4[4] += mc._m4[4];
        _m4[5] += mc._m4[5];
        _m4[6] += mc._m4[6];
        _m4[7] += mc._m4[7];
        _m4[8] += mc._m4[8];
        _m4[9] += mc._m4[9];
        _m4[10] += mc._m4[10];
        _m4[11] += mc._m4[11];
        _m4[12] += mc._m4[12];
        _m4[13] += mc._m4[13];
        _m4[14] += mc._m4[14];
        _m4[15] += mc._m4[15];

        return *this;
    }

    /*
	 | ----------------------------------------------------------------------------------------------
	 |     Subtracting two matrices
	 |     Returns Matrix4
	 | ----------------------------------------------------------------------------------------------
	 */
    inline Matrix4& operator-= (const Matrix4& mc)
    {
        _m4[0] -= mc._m4[0];
        _m4[1] -= mc._m4[1];
        _m4[2] -= mc._m4[2];
        _m4[3] -= mc._m4[3];
        _m4[4] -= mc._m4[4];
        _m4[5] -= mc._m4[5]; 
        _m4[6] -= mc._m4[6];
        _m4[7] -= mc._m4[7];
        _m4[8] -= mc._m4[8];
        _m4[9] -= mc._m4[9]; 
        _m4[10] -= mc._m4[10];
        _m4[11] -= mc._m4[11];
        _m4[12] -= mc._m4[12];
        _m4[13] -= mc._m4[13];
        _m4[14] -= mc._m4[14];
        _m4[15] -= mc._m4[15];

        return *this;
    }

    /*
	 | ---------------------------------------------------------------------------------------------------
	 |     Multiplying a matrix by a scalar
	 |     Returns Matrix4
	 | ---------------------------------------------------------------------------------------------------
	 */
   inline Matrix4& operator *= (float scalar)
    {
        for(int i=0; i<16; ++i)
            _m4[i] *= scalar;

       return *this;
    }

    /*
	 | ---------------------------------------------------------------------------------------------------
	 |     Assigning a value to the matrix
	 |     Returns Matrix4
	 | ---------------------------------------------------------------------------------------------------
	 */
    inline Matrix4& operator = (float value)
    {
        for(int i=0; i<16; ++i)
            _m4[i] = value;

        return *this;
    }

    /*
	 | ----------------------------------------------------------------------------------------------------
	 |     Inversion of a Matrix
	 |     Returns Matrix4
	 | ----------------------------------------------------------------------------------------------------
	 */
    inline void inverse(Matrix4& m)
    {
        for(int i=0; i<16; ++i)
        {
            m._m4[i] = -m._m4[i];
        }
    }

    /*
	 | ----------------------------------------------------------------------------------------------------
	 |     Inversion of a Matrix
	 |     Returns Matrix4
	 | ----------------------------------------------------------------------------------------------------
	 */
    inline Matrix4& inverse()
    {
        for(int i=0; i < 16; ++i)
        {
            _m4[i] = -_m4[i];
        }
        return *this;
    }

	// TODO
    /*
	 | -----------------------------------------------------------------------------------------------------
	 |     Multiplying a matrix by matrix
	 |     Returns Matrix4
	 | -----------------------------------------------------------------------------------------------------
	 */
    inline Matrix4& operator*= (const Matrix4& m1)
    {
		Matrix4 result;
        result._m4[0] = this->_m4[0] * m1._m4[0] + this->_m4[1] * m1._m4[4] + this->_m4[2] * m1._m4[8] + this->_m4[3] * m1._m4[12];
        result._m4[1] = this->_m4[0] * m1._m4[1] + this->_m4[1] * m1._m4[5] + this->_m4[2] * m1._m4[9] + this->_m4[3] * m1._m4[13];
        result._m4[2] = this->_m4[0] * m1._m4[2] + this->_m4[1] * m1._m4[6] + this->_m4[2] * m1._m4[10] + this->_m4[3] * m1._m4[14];
		result._m4[3] = this->_m4[0] * m1._m4[3] + this->_m4[1] * m1._m4[7] + this->_m4[2] * m1._m4[11] + this->_m4[3] * m1._m4[15];
		result._m4[4] = this->_m4[4] * m1._m4[0] + this->_m4[5] * m1._m4[4] + this->_m4[6] * m1._m4[8] + this->_m4[7] * m1._m4[12];
		result._m4[5] = this->_m4[4] * m1._m4[1] + this->_m4[5] * m1._m4[5] + this->_m4[6] * m1._m4[9] + this->_m4[7] * m1._m4[13];
		result._m4[6] = this->_m4[4] * m1._m4[2] + this->_m4[5] * m1._m4[6] + this->_m4[6] * m1._m4[10] + this->_m4[7] * m1._m4[14];
		result._m4[7] = this->_m4[4] * m1._m4[3] + this->_m4[5] * m1._m4[7] + this->_m4[6] * m1._m4[11] + this->_m4[7] * m1._m4[15];
		result._m4[8] = this->_m4[8] * m1._m4[0] + this->_m4[9] * m1._m4[4] + this->_m4[10] * m1._m4[8] + this->_m4[11] * m1._m4[12];
		result._m4[9] = this->_m4[8] * m1._m4[1] + this->_m4[9] * m1._m4[5] + this->_m4[10] * m1._m4[9] + this->_m4[11] * m1._m4[13];
		result._m4[10] = this->_m4[8] * m1._m4[2] + this->_m4[9] * m1._m4[6] + this->_m4[10] * m1._m4[10] + this->_m4[11] * m1._m4[14];
		result._m4[11] = this->_m4[8] * m1._m4[3] + this->_m4[9] * m1._m4[7] + this->_m4[10] * m1._m4[11] + this->_m4[11] * m1._m4[15];
		result._m4[12] = this->_m4[12] * m1._m4[0] + this->_m4[13] * m1._m4[4] + this->_m4[14] * m1._m4[8] + this->_m4[15] * m1._m4[12];
		result._m4[13] = this->_m4[12] * m1._m4[1] + this->_m4[13] * m1._m4[5] + this->_m4[14] * m1._m4[9] + this->_m4[15] * m1._m4[13];
		result._m4[14] = this->_m4[12] * m1._m4[2] + this->_m4[13] * m1._m4[6] + this->_m4[14] * m1._m4[10] + this->_m4[15] * m1._m4[14];
		result._m4[15] = this->_m4[12] * m1._m4[3] + this->_m4[13] * m1._m4[7] + this->_m4[14] * m1._m4[11] + this->_m4[15] * m1._m4[15];

        return result;
    }

	/*
	 | ----------------------------------------------------------------------------
	 |     Gets member of a matrix
	 |     Parameter - index of a member
	 |     Returns float value 
	 | ----------------------------------------------------------------------------
	 */
	float getM4(int index) const
	{
		return _m4[index];
	}

	/*
	 | ----------------------------------------------------------------------------
	 |     Sets member of a matrix
	 |     Parameter - int index of a member { 0 .. 15 }
	 |     Parameter - float value of a member
	 | ----------------------------------------------------------------------------
	 */
	void setM4(int index, float value)
	{
		_m4[index] = value;
	}
    
	/*
	 | -----------------------------------------------------------------------------
	 |     Loads Identity
	 | ----------------------------------------------------------------------------- 
	 */
    static const Matrix4 _S_IDENTITY;

	/*
	 | -----------------------------------------------------------------------------
	 |     Zeroying the matrix
	 | -----------------------------------------------------------------------------
	 */
    static const Matrix4 _S_ZERO;
	float _m4[16];
private:
	
};

/*
 | ----------------------------------------------------------------------------------
 |     Multiplying Matrices - return new matrix
 |     Parameter Matrix4 first matrix in multiplication
 |     Parameter Matrix4 second matrix in multiplication
 |     Returns new Matrix4
 |     Matrix4 result = multiply(&matrix1, &matrix2)
 | ----------------------------------------------------------------------------------
 */
Matrix4 multiply(const Matrix4* m1, const Matrix4* m2);

/*
 | ----------------------------------------------------------------------------------
 |     Helper function
 | ----------------------------------------------------------------------------------
 */
void printM4(const Matrix4& m);
}
}
#endif