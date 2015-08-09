/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_MATRIX4_H_
#define MG_MATH_MATRIX4_H_

#ifndef MG_MATH_VECTOR4_H_
#include "vector4.h"
#endif

namespace mg
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
      m4_[0] = m00;
      m4_[1] = m01;
      m4_[2] = m02;
      m4_[3] = m03;
      m4_[4] = m04;
      m4_[5] = m05;
      m4_[6] = m06;
      m4_[7] = m07;
      m4_[8] = m08;
      m4_[9] = m09;
      m4_[10] = m10;
      m4_[11] = m11;
      m4_[12] = m12;
      m4_[13] = m13;
      m4_[14] = m14;
      m4_[15] = m15;
     }

    // Parameter arr - Array of values
    Matrix4(const float* arr)
    {
        for(int i=0; i<16; ++i)
            m4_[i] = arr[i];
    }

    Matrix4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4);

    // Copy constructor
    Matrix4(const Matrix4& mc)
    {
        for(int i = 0; i < 16; ++i)
            m4_[i] = mc.m4_[i];
    }

    // Constructing Matrix with Vector
    // Vector is assigned ONLY to three values of the matrix
    Matrix4(const Vector3& v3)
    {
        m4_[0] = 1.0f;
        m4_[1] = 0.0f;
        m4_[2] = 0.0f;
        m4_[3] = 0.0f;
        m4_[4] = 0.0f;
        m4_[5] = 1.0f;
        m4_[6] = 0.0f;
        m4_[7] = 0.0f;
        m4_[8] = 0.0f;
        m4_[9] = 0.0f;
        m4_[10] = 1.0f;
        m4_[11] = 0.0f;
        m4_[12] = v3.x_;
        m4_[13] = v3.y_;
        m4_[14] = v3.z_;
        m4_[15] = 1.0f;
    }

    ~Matrix4(){}

    // ---- ///
    Matrix4& loadIdentity();

    // ---- //
    inline Matrix4& transpose()
    {
        float temp = 0.0f;

        m4_[0] = m4_[0];
        m4_[5] = m4_[5];
        m4_[10] = m4_[10];
        m4_[15] = m4_[15];

        if(m4_[15] != 1.0f)
             m4_[15] = 1.0f;

		//ENGINESwap(m4_[1], m4_[4]);

        temp = m4_[1];
        m4_[1] = m4_[4];
        m4_[4] = temp;

        temp = m4_[2];
        m4_[2] = m4_[8];
        m4_[8] = temp;

        temp = m4_[3];
        m4_[3] = m4_[12];
        m4_[12] = temp;

        temp = m4_[6];
        m4_[6] = m4_[9];
        m4_[9] = temp;

        temp = m4_[13];
        m4_[13] = m4_[7];
        m4_[7] = temp;

        temp = m4_[14];
        m4_[14] = m4_[11];
        m4_[11] = temp;

        return *this;
    }

    // Multiplying a matrix by a scalar
    // Returns This Matrix
    inline Matrix4& operator*(float scalar)
    {
        for(int i = 0; i < 16; ++i)
            m4_[i] =  m4_[i] * scalar;
        return *this;
    }

    // Multpilying a matrix by a matrix
    // Returns Matrix
    inline Matrix4 operator*(Matrix4& mc)
    {
        Matrix4 out = S_IDENTITY_;
        out.m4_[0] = m4_[0] * mc.m4_[0] + m4_[1] * mc.m4_[4] + m4_[2] * mc.m4_[8] + m4_[3] * mc.m4_[12];
        out.m4_[1] = m4_[0] * mc.m4_[1] + m4_[1] * mc.m4_[5] + m4_[2] * mc.m4_[9] + m4_[3] * mc.m4_[13];
        out.m4_[2] = m4_[0] * mc.m4_[2] + m4_[1] * mc.m4_[6] + m4_[2] * mc.m4_[10] + m4_[3] * mc.m4_[14];
        out.m4_[3] = m4_[0] * mc.m4_[3] + m4_[1] * mc.m4_[7] + m4_[2] * mc.m4_[11] + m4_[3] * mc.m4_[15];

        out.m4_[4] = m4_[4] * mc.m4_[0] + m4_[5] * mc.m4_[4] + m4_[6] * mc.m4_[8] + m4_[7] * mc.m4_[12];
        out.m4_[5] = m4_[4] * mc.m4_[1] + m4_[5] * mc.m4_[5] + m4_[6] * mc.m4_[9] + m4_[7] * mc.m4_[13];
        out.m4_[6] = m4_[4] * mc.m4_[2] + m4_[5] * mc.m4_[6] + m4_[6] * mc.m4_[10] + m4_[7] * mc.m4_[14];
        out.m4_[7] = m4_[4] * mc.m4_[3] + m4_[5] * mc.m4_[7] + m4_[6] * mc.m4_[11] + m4_[7] * mc.m4_[15];

        out.m4_[8] = m4_[8] * mc.m4_[0] + m4_[9] * mc.m4_[4] + m4_[10] * mc.m4_[8] + m4_[11] * mc.m4_[12];
        out.m4_[9] = m4_[8] * mc.m4_[1] + m4_[9] * mc.m4_[5] + m4_[10] * mc.m4_[9] + m4_[11] * mc.m4_[13];
        out.m4_[10] = m4_[8] * mc.m4_[2] + m4_[9] * mc.m4_[6] + m4_[10] * mc.m4_[10] + m4_[11] * mc.m4_[14];
        out.m4_[11] = m4_[8] * mc.m4_[3] + m4_[9] * mc.m4_[7] + m4_[10] * mc.m4_[11] + m4_[11] * mc.m4_[15];

        out.m4_[12] = m4_[12] * mc.m4_[0] + m4_[13] * mc.m4_[4] + m4_[14] * mc.m4_[8] + m4_[15] * mc.m4_[12]; 	
        out.m4_[13] = m4_[12] * mc.m4_[1] + m4_[13] * mc.m4_[5] + m4_[14] * mc.m4_[9] + m4_[15] * mc.m4_[13];
        out.m4_[14] = m4_[12] * mc.m4_[2] + m4_[13] * mc.m4_[6] + m4_[14] * mc.m4_[10] + m4_[15] * mc.m4_[14]; 
        out.m4_[15] = m4_[12] * mc.m4_[3] + m4_[13] * mc.m4_[7] + m4_[14] * mc.m4_[11] + m4_[15] * mc.m4_[15];

        return out;
    }

    // Asigning one matrix to another
    // Returns This Matrix
    inline Matrix4& operator= (const Matrix4& mc)
    {
        for(int i=0; i<16; ++i)
            m4_[i] = mc.m4_[i];

        return *this;
    }

    // Checking equality of two matrices
    // Returns TRUE if matrices are equal, FALSE otherwise
    inline bool operator== (const Matrix4& mc)const
    {
        if(m4_[0] == mc.m4_[0] && m4_[1] == mc.m4_[1] && m4_[2] == mc.m4_[2] && m4_[3] == mc.m4_[3] &&
        m4_[4] == mc.m4_[4] && m4_[5] == mc.m4_[5] && m4_[6] == mc.m4_[6] && m4_[7] == mc.m4_[7] &&
        m4_[8] == mc.m4_[8] && m4_[9] == mc.m4_[9] && m4_[10] == mc.m4_[10] && m4_[11] == mc.m4_[11] &&
        m4_[12] == mc.m4_[12] && m4_[13] == mc.m4_[13] && m4_[14] == mc.m4_[14] && m4_[15] == mc.m4_[15])
            return true;
        else
           return false;
    }

    // Checking if two matrices are NOT equal
    // Returns TRUE if two matrices are NOT equal, TRUE otherwise
    inline bool operator!= (const Matrix4& mc) const
    {
        if(
            m4_[0] != mc.m4_[0] || m4_[1] != mc.m4_[1] || m4_[2] != mc.m4_[2] || m4_[3] != mc.m4_[3] ||
            m4_[4] != mc.m4_[4] || m4_[5] != mc.m4_[5] || m4_[6] != mc.m4_[6] || m4_[7] != mc.m4_[7] ||
            m4_[8] != mc.m4_[8] || m4_[9] != mc.m4_[9] || m4_[10] != mc.m4_[10] || m4_[11] != mc.m4_[11] ||
            m4_[12] != mc.m4_[12] || m4_[13] != mc.m4_[13] || m4_[14] != mc.m4_[14] || m4_[15] != mc.m4_[15]
            )
        return true;
        else
        return false;
    }

    // ---- //
    inline Matrix4 operator+(const Matrix4& mc)const
    {
        Matrix4 ret;

        ret.m4_[0] = m4_[0] + mc.m4_[0];
        ret.m4_[1] = m4_[1] + mc.m4_[1];
        ret.m4_[2] = m4_[2] + mc.m4_[2];
        ret.m4_[3] = m4_[3] + mc.m4_[3];
        ret.m4_[4] = m4_[4] + mc.m4_[4];
        ret.m4_[5] = m4_[5] + mc.m4_[5];
        ret.m4_[6] = m4_[6] + mc.m4_[6];
        ret.m4_[7] = m4_[7] + mc.m4_[7];
        ret.m4_[8] = m4_[8] + mc.m4_[8];
        ret.m4_[9] = m4_[9] + mc.m4_[9];
        ret.m4_[10] = m4_[10] + mc.m4_[10];
        ret.m4_[11] = m4_[11] + mc.m4_[11];
        ret.m4_[12] = m4_[12] + mc.m4_[12];
        ret.m4_[13] = m4_[13] + mc.m4_[13];
        ret.m4_[14] = m4_[14] + mc.m4_[14];
        ret.m4_[15] = m4_[15] + mc.m4_[15];

        return ret;
    }

    // ---- //
    inline Matrix4 operator-(const Matrix4& mc) const
    {
        Matrix4 ret;

        ret.m4_[0] = m4_[0] - mc.m4_[0]; 
        ret.m4_[1] = m4_[1] - mc.m4_[1];
        ret.m4_[2] = m4_[2] - mc.m4_[2];
        ret.m4_[3] = m4_[3] - mc.m4_[3];
        ret.m4_[4] = m4_[4] - mc.m4_[4];
        ret.m4_[5] = m4_[5] - mc.m4_[5];
        ret.m4_[6] = m4_[6] - mc.m4_[6];
        ret.m4_[7] = m4_[7] - mc.m4_[7];
        ret.m4_[8] = m4_[8] - mc.m4_[8];
        ret.m4_[9] = m4_[9] - mc.m4_[9];
        ret.m4_[10] = m4_[10] - mc.m4_[10];
        ret.m4_[11] = m4_[11] - mc.m4_[11];
        ret.m4_[12] = m4_[12] - mc.m4_[12];
        ret.m4_[13] = m4_[13] - mc.m4_[13];
        ret.m4_[14] = m4_[14] - mc.m4_[14];
        ret.m4_[15] = m4_[15] - mc.m4_[15];

        return ret;
    }

    // ---- //
    inline Matrix4& operator+=(const Matrix4& mc)
    {
        m4_[0] += mc.m4_[0];
        m4_[1] += mc.m4_[1];
        m4_[2] += mc.m4_[2];
        m4_[3] += mc.m4_[3];
        m4_[4] += mc.m4_[4];
        m4_[5] += mc.m4_[5];
        m4_[6] += mc.m4_[6];
        m4_[7] += mc.m4_[7];
        m4_[8] += mc.m4_[8];
        m4_[9] += mc.m4_[9];
        m4_[10] += mc.m4_[10];
        m4_[11] += mc.m4_[11];
        m4_[12] += mc.m4_[12];
        m4_[13] += mc.m4_[13];
        m4_[14] += mc.m4_[14];
        m4_[15] += mc.m4_[15];

        return *this;
    }

    // ---- //
    inline Matrix4& operator-= (const Matrix4& mc)
    {
        m4_[0] -= mc.m4_[0];
        m4_[1] -= mc.m4_[1];
        m4_[2] -= mc.m4_[2];
        m4_[3] -= mc.m4_[3];
        m4_[4] -= mc.m4_[4];
        m4_[5] -= mc.m4_[5]; 
        m4_[6] -= mc.m4_[6];
        m4_[7] -= mc.m4_[7];
        m4_[8] -= mc.m4_[8];
        m4_[9] -= mc.m4_[9]; 
        m4_[10] -= mc.m4_[10];
        m4_[11] -= mc.m4_[11];
        m4_[12] -= mc.m4_[12];
        m4_[13] -= mc.m4_[13];
        m4_[14] -= mc.m4_[14];
        m4_[15] -= mc.m4_[15];

        return *this;
    }

    // ---- //
   inline Matrix4& operator *= (float scalar)
    {
        for(int i=0; i<16; ++i)
            m4_[i] *= scalar;

       return *this;
    }

    // ---- //
    inline Vector4 operator* (const Vector4& v)
    {
        Vector4 result;
        result.x_ = m4_[0] * v.x_ + m4_[4] * v.y_ + m4_[8] * v.z_ + m4_[12] * v.w_;
        result.y_ = m4_[1] * v.x_ + m4_[5] * v.y_ + m4_[9] * v.z_ + m4_[13] * v.w_;
        result.z_ = m4_[2] * v.x_ + m4_[6] * v.y_ + m4_[10] * v.z_ + m4_[14] * v.w_;
        result.w_ = m4_[3] * v.x_ + m4_[7] * v.y_ + m4_[11] * v.z_ + m4_[15] * v.w_;
        return result;
    }

    // ---- //
    inline Matrix4& operator = (float value)
    {
        for(int i=0; i<16; ++i)
            m4_[i] = value;

        return *this;
    }

    // ---- //
    inline void inverse(Matrix4& m)
    {
        for(int i=0; i<16; ++i)
        {
            m.m4_[i] = -m.m4_[i];
        }
    }

    // ---- //
    inline Matrix4& inverse()
    {
        for(int i=0; i < 16; ++i)
        {
            m4_[i] = -m4_[i];
        }
        return *this;
    }

    // ---- //
    inline Matrix4& operator*= (const Matrix4& m1)
    {
        this->m4_[0] = this->m4_[0] * m1.m4_[0] + this->m4_[1] * m1.m4_[4] + this->m4_[2] * m1.m4_[8] + this->m4_[3] * m1.m4_[12];
        this->m4_[1] = this->m4_[0] * m1.m4_[1] + this->m4_[1] * m1.m4_[5] + this->m4_[2] * m1.m4_[9] + this->m4_[3] * m1.m4_[13];
        this->m4_[2] = this->m4_[0] * m1.m4_[2] + this->m4_[1] * m1.m4_[6] + this->m4_[2] * m1.m4_[10] + this->m4_[3] * m1.m4_[14];
        this->m4_[3] = this->m4_[0] * m1.m4_[3] + this->m4_[1] * m1.m4_[7] + this->m4_[2] * m1.m4_[11] + this->m4_[3] * m1.m4_[15];
        this->m4_[4] = this->m4_[4] * m1.m4_[0] + this->m4_[5] * m1.m4_[4] + this->m4_[6] * m1.m4_[8] + this->m4_[7] * m1.m4_[12];
        this->m4_[5] = this->m4_[4] * m1.m4_[1] + this->m4_[5] * m1.m4_[5] + this->m4_[6] * m1.m4_[9] + this->m4_[7] * m1.m4_[13];
        this->m4_[6] = this->m4_[4] * m1.m4_[2] + this->m4_[5] * m1.m4_[6] + this->m4_[6] * m1.m4_[10] + this->m4_[7] * m1.m4_[14];
        this->m4_[7] = this->m4_[4] * m1.m4_[3] + this->m4_[5] * m1.m4_[7] + this->m4_[6] * m1.m4_[11] + this->m4_[7] * m1.m4_[15];
        this->m4_[8] = this->m4_[8] * m1.m4_[0] + this->m4_[9] * m1.m4_[4] + this->m4_[10] * m1.m4_[8] + this->m4_[11] * m1.m4_[12];
        this->m4_[9] = this->m4_[8] * m1.m4_[1] + this->m4_[9] * m1.m4_[5] + this->m4_[10] * m1.m4_[9] + this->m4_[11] * m1.m4_[13];
        this->m4_[10] = this->m4_[8] * m1.m4_[2] + this->m4_[9] * m1.m4_[6] + this->m4_[10] * m1.m4_[10] + this->m4_[11] * m1.m4_[14];
        this->m4_[11] = this->m4_[8] * m1.m4_[3] + this->m4_[9] * m1.m4_[7] + this->m4_[10] * m1.m4_[11] + this->m4_[11] * m1.m4_[15];
        this->m4_[12] = this->m4_[12] * m1.m4_[0] + this->m4_[13] * m1.m4_[4] + this->m4_[14] * m1.m4_[8] + this->m4_[15] * m1.m4_[12];
        this->m4_[13] = this->m4_[12] * m1.m4_[1] + this->m4_[13] * m1.m4_[5] + this->m4_[14] * m1.m4_[9] + this->m4_[15] * m1.m4_[13];
        this->m4_[14] = this->m4_[12] * m1.m4_[2] + this->m4_[13] * m1.m4_[6] + this->m4_[14] * m1.m4_[10] + this->m4_[15] * m1.m4_[14];
        this->m4_[15] = this->m4_[12] * m1.m4_[3] + this->m4_[13] * m1.m4_[7] + this->m4_[14] * m1.m4_[11] + this->m4_[15] * m1.m4_[15];

        return *this;
    }

    float m4_[16];
    static const Matrix4 S_IDENTITY_;
    static const Matrix4 S_ZERO_;

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
}    // end of math namespace
}    // end of mg namespace
#endif