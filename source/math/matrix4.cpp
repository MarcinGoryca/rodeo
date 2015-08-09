/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include <iostream>
#include "..\include\math\matrix4.h"

using namespace std;
using namespace mg::core;

namespace mg
{
namespace math
{
//const float Matrix4::MATRIX4_W = 1.0f;
//const float Matrix4::MATRIX4_ZERO = 0.0f;

Matrix4::Matrix4()
{
    for(int i=0; i < 16; ++i)
    {
        m4_[i] = 0.0f;
    }
}

//--------------------------------------------------------------------------------------------------
Matrix4::Matrix4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4)
{
    m4_[0] = v1.x_;
    m4_[1] = v2.x_;
    m4_[2] = v3.x_;
    m4_[3] = v4.x_;
    m4_[4] = v1.y_;
    m4_[5] = v2.y_;
    m4_[6] = v3.y_;
    m4_[7] = v4.y_;
    m4_[8] = v1.z_;
    m4_[9] = v2.z_;
    m4_[10] = v3.z_;
    m4_[11] = v4.z_;
    m4_[12] = v1.w_;
    m4_[13] = v2.w_;
    m4_[14] = v3.w_;
    m4_[15] = v4.w_;
}

//--------------------------------------------------------------------------------------------------
const Matrix4 Matrix4::S_IDENTITY_
(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
);

//--------------------------------------------------------------------------------------------------
const Matrix4 Matrix4::S_ZERO_
(
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f
);

//--------------------------------------------------------------------------------------------------
Matrix4& Matrix4::loadIdentity()
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
    m4_[12] = 0.0f;
    m4_[13] = 0.0f;
    m4_[14] = 0.0f;
    m4_[15] = 1.0f;
    return *this;
}

/**
 * Code solution comes from http://openglbook.com/the-book/chapter-4-entering-the-third-dimension/
 */
Matrix4 multiply(const Matrix4* m1, const Matrix4* m2)
{
    Matrix4 out = Matrix4::S_IDENTITY_;

    ui row, column, row_offset;

    for(row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4)
    {
        for(column = 0; column < 4; ++column)
        {
            out.m4_[row_offset + column] = 
                (m1->m4_[row_offset + 0] * m2->m4_[column + 0]) + 
                (m1->m4_[row_offset + 1] * m2->m4_[column + 4]) +
                (m1->m4_[row_offset + 2] * m2->m4_[column + 8]) +
                (m1->m4_[row_offset + 3] * m2->m4_[column + 12]);
        }
    }
    return out;
}

//--------------------------------------------------------------------------------------------------
void printM4(const Matrix4& m)
{
    for(int i=0; i < 16; ++i)
    {
        if(i == 4) std::cout << "\n";
        if(i == 8) std::cout << "\n";
        if(i == 12) std::cout << "\n";
        std::cout << m.m4_[i] << ", ";
    }
    std::cout << "\n";
}
}    // end of math namespace
}    // end of mg namespace