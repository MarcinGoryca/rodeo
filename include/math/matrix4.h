/*
----------------------------------------------
    laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
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
    // ---- //
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

    // Parameter arr - Array of values
    Matrix4(const float* arr)
    {
        for(int i=0; i<16; ++i)
            _m4[i] = arr[i];
    }

    Matrix4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4);

    // Copy constructor
    Matrix4(const Matrix4& mc)
    {
        for(int i = 0; i < 16; ++i)
            _m4[i] = mc._m4[i];
    }

    // Constructing Matrix with Vector
    // Vector is assigned ONLY to three values of the matrix
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

    ~Matrix4(){}

    // ---- ///
    Matrix4& loadIdentity();

    // ---- //
    inline Matrix4& transpose()
    {
        float temp = 0.0f;

        _m4[0] = _m4[0];
        _m4[5] = _m4[5];
        _m4[10] = _m4[10];
        _m4[15] = _m4[15];

        if(_m4[15] != 1.0f)
             _m4[15] = 1.0f;

		//ENGINESwap(_m4[1], _m4[4]);

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

    // Multiplying a matrix by a scalar
    // Returns This Matrix
    inline Matrix4& operator*(float scalar)
    {
        for(int i = 0; i < 16; ++i)
            _m4[i] =  _m4[i] * scalar;
        return *this;
    }

    // Multpilying a matrix by a matrix
    // Returns Matrix
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

    // Asigning one matrix to another
    // Returns This Matrix
    inline Matrix4& operator= (const Matrix4& mc)
    {
        for(int i=0; i<16; ++i)
            _m4[i] = mc._m4[i];

        return *this;
    }

    // Checking equality of two matrices
    // Returns TRUE if matrices are equal, FALSE otherwise
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

    // Checking if two matrices are NOT equal
    // Returns TRUE if two matrices are NOT equal, TRUE otherwise
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

    // ---- //
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

    // ---- //
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

    // ---- //
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

    // ---- //
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

    // ---- //
   inline Matrix4& operator *= (float scalar)
    {
        for(int i=0; i<16; ++i)
            _m4[i] *= scalar;

       return *this;
    }

    // ---- //
    inline Vector4 operator* (const Vector4& v)
    {
        Vector4 result;
        result.setX(_m4[0] * v.getX() + _m4[4] * v.getY() + _m4[8] * v.getZ() + _m4[12] * v.getW());
        result.setY(_m4[1] * v.getX() + _m4[5] * v.getY() + _m4[9] * v.getZ() + _m4[13] * v.getW());
        result.setZ(_m4[2] * v.getX() + _m4[6] * v.getY() + _m4[10] * v.getZ() + _m4[14] * v.getW());
        result.setW(_m4[3] * v.getX() + _m4[7] * v.getY() + _m4[11] * v.getZ() + _m4[15] * v.getW());
        return result;
    }

    // ---- //
    inline Matrix4& operator = (float value)
    {
        for(int i=0; i<16; ++i)
            _m4[i] = value;

        return *this;
    }

    // ---- //
    inline void inverse(Matrix4& m)
    {
        for(int i=0; i<16; ++i)
        {
            m._m4[i] = -m._m4[i];
        }
    }

    // ---- //
    inline Matrix4& inverse()
    {
        for(int i=0; i < 16; ++i)
        {
            _m4[i] = -_m4[i];
        }
        return *this;
    }

    // ---- //
    inline Matrix4& operator*= (const Matrix4& m1)
    {
        this->_m4[0] = this->_m4[0] * m1._m4[0] + this->_m4[1] * m1._m4[4] + this->_m4[2] * m1._m4[8] + this->_m4[3] * m1._m4[12];
        this->_m4[1] = this->_m4[0] * m1._m4[1] + this->_m4[1] * m1._m4[5] + this->_m4[2] * m1._m4[9] + this->_m4[3] * m1._m4[13];
        this->_m4[2] = this->_m4[0] * m1._m4[2] + this->_m4[1] * m1._m4[6] + this->_m4[2] * m1._m4[10] + this->_m4[3] * m1._m4[14];
        this->_m4[3] = this->_m4[0] * m1._m4[3] + this->_m4[1] * m1._m4[7] + this->_m4[2] * m1._m4[11] + this->_m4[3] * m1._m4[15];
        this->_m4[4] = this->_m4[4] * m1._m4[0] + this->_m4[5] * m1._m4[4] + this->_m4[6] * m1._m4[8] + this->_m4[7] * m1._m4[12];
        this->_m4[5] = this->_m4[4] * m1._m4[1] + this->_m4[5] * m1._m4[5] + this->_m4[6] * m1._m4[9] + this->_m4[7] * m1._m4[13];
        this->_m4[6] = this->_m4[4] * m1._m4[2] + this->_m4[5] * m1._m4[6] + this->_m4[6] * m1._m4[10] + this->_m4[7] * m1._m4[14];
        this->_m4[7] = this->_m4[4] * m1._m4[3] + this->_m4[5] * m1._m4[7] + this->_m4[6] * m1._m4[11] + this->_m4[7] * m1._m4[15];
        this->_m4[8] = this->_m4[8] * m1._m4[0] + this->_m4[9] * m1._m4[4] + this->_m4[10] * m1._m4[8] + this->_m4[11] * m1._m4[12];
        this->_m4[9] = this->_m4[8] * m1._m4[1] + this->_m4[9] * m1._m4[5] + this->_m4[10] * m1._m4[9] + this->_m4[11] * m1._m4[13];
        this->_m4[10] = this->_m4[8] * m1._m4[2] + this->_m4[9] * m1._m4[6] + this->_m4[10] * m1._m4[10] + this->_m4[11] * m1._m4[14];
        this->_m4[11] = this->_m4[8] * m1._m4[3] + this->_m4[9] * m1._m4[7] + this->_m4[10] * m1._m4[11] + this->_m4[11] * m1._m4[15];
        this->_m4[12] = this->_m4[12] * m1._m4[0] + this->_m4[13] * m1._m4[4] + this->_m4[14] * m1._m4[8] + this->_m4[15] * m1._m4[12];
        this->_m4[13] = this->_m4[12] * m1._m4[1] + this->_m4[13] * m1._m4[5] + this->_m4[14] * m1._m4[9] + this->_m4[15] * m1._m4[13];
        this->_m4[14] = this->_m4[12] * m1._m4[2] + this->_m4[13] * m1._m4[6] + this->_m4[14] * m1._m4[10] + this->_m4[15] * m1._m4[14];
        this->_m4[15] = this->_m4[12] * m1._m4[3] + this->_m4[13] * m1._m4[7] + this->_m4[14] * m1._m4[11] + this->_m4[15] * m1._m4[15];

        return *this;
    }

    float _m4[16];
    static const Matrix4 _S_IDENTITY;
    static const Matrix4 _S_ZERO;

private:
};

// Multiplying Matrices - return new matrix
// Parameter Matrix4 first matrix in multiplication
// Parameter Matrix4 second matrix in multiplication
// Returns new Matrix4
// Matrix4 result = multiply(&matrix1, &matrix2)
Matrix4 multiply(const Matrix4* m1, const Matrix4* m2);

// Helper function
void printM4(const Matrix4& m);
}
}
#endif