/*
----------------------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include <iostream>
#include "..\include\math\matrix4.h"

using namespace std;
using namespace laura::core;

namespace laura
{
namespace math
{
//const float Matrix4::MATRIX4_W = 1.0f;
//const float Matrix4::MATRIX4_ZERO = 0.0f;

Matrix4::Matrix4()
{
    for(int i=0; i < 16; ++i)
    {
        _m4[i] = 0.0f;
    }
}

//--------------------------------------------------------------------------------------------------
Matrix4::Matrix4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4)
{
    _m4[0] = v1.getX();
    _m4[1] = v2.getX();
    _m4[2] = v3.getX();
    _m4[3] = v4.getX();
    _m4[4] = v1.getY();
    _m4[5] = v2.getY();
    _m4[6] = v3.getY();
    _m4[7] = v4.getY();
    _m4[8] = v1.getZ();
    _m4[9] = v2.getZ();
    _m4[10] = v3.getZ();
    _m4[11] = v4.getZ();
    _m4[12] = v1.getW();
    _m4[13] = v2.getW();
    _m4[14] = v3.getW();
    _m4[15] = v4.getW();
}

//--------------------------------------------------------------------------------------------------
const Matrix4 Matrix4::_S_IDENTITY
(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
);

//--------------------------------------------------------------------------------------------------
const Matrix4 Matrix4::_S_ZERO
(
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f
);

//--------------------------------------------------------------------------------------------------
Matrix4& Matrix4::loadIdentity()
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
    _m4[12] = 0.0f;
    _m4[13] = 0.0f;
    _m4[14] = 0.0f;
    _m4[15] = 1.0f;
    return *this;
}

/**
 * Code solution comes from http://openglbook.com/the-book/chapter-4-entering-the-third-dimension/
 */
Matrix4 multiply(Matrix4* m1, Matrix4* m2)
{
    Matrix4 out = Matrix4::_S_IDENTITY;

    ui row, column, ro_woffset;

    for(row = 0, ro_woffset = row * 4; row < 4; ++row, ro_woffset = row * 4)
    {
		for (column = 0; column < 4; ++column)
		{
			out._m4[ro_woffset + column] =
                (m1->getM4(ro_woffset + 0) * m2->getM4(column + 0)) + 
                (m1->getM4(ro_woffset + 1) * m2->getM4(column + 4)) +
                (m1->getM4(ro_woffset + 2) * m2->getM4(column + 8)) +
                (m1->getM4(ro_woffset + 3) * m2->getM4(column + 12));
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
        std::cout << m.getM4(i) << ", ";
    }
    std::cout << "\n";
}
}    // end of math namespace
}    // end of laura namespace
