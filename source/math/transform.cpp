/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "..\include\math\transform.h"
#include "..\include\math\matrix3.h"
#include "..\include\math\matrix4.h"

namespace mg
{
namespace math
{
// -- Scale Transformation
Matrix4 Transform::scale(float x, float y, float z)
{
    Matrix4 scaleMatrix;
    scaleMatrix.loadIdentity();

    scaleMatrix.m4_[0] = x;
    scaleMatrix.m4_[5] = y;
    scaleMatrix.m4_[10] = z;

    return scaleMatrix;
}

// -- Rotation Transformation
Matrix4 Transform::rotate(float angle, float x, float y, float z)
{
    Matrix4 rotation;
    rotation.loadIdentity();

    const float x2 = x * x;
    const float y2 = y * y;
    const float z2 = z * z;
    float radians = angle * (3.141519265 / 180);
    const float c = ::cosf(radians);
    const float s = ::sinf(radians);
    const float a = 1.0f - c;

    rotation.m4_[0] = x2 * a + c;
    rotation.m4_[1] = y * x * a + z * s;
    rotation.m4_[2] = x * z * a - y * s;
    rotation.m4_[3] = 0.0f;
    rotation.m4_[4] = x * y * a - z * s;
    rotation.m4_[5] = y2 * a + c;
    rotation.m4_[6] = y * z * a + x * s;
    rotation.m4_[7] = 0.0f;
    rotation.m4_[8] = x * z * a + y * s;
    rotation.m4_[9] = y * z * a - x * s;
    rotation.m4_[10] = z2 * a + c;
    rotation.m4_[11] = 0.0f;
    rotation.m4_[12] = 0.0f;
    rotation.m4_[13] = 0.0f;
    rotation.m4_[14] = 0.0f;
    rotation.m4_[15] = 1.0f;

    return rotation;
}

// -- Translate 
Matrix4 Transform::translate(const float x, const float y, const float z)
{
    Matrix4 m;

    m.loadIdentity();

    m.m4_[3] = x;
    m.m4_[7] = y;
    m.m4_[11] = z;

    return m;
}
}    // end of math namespace
}    // end of mg namespace