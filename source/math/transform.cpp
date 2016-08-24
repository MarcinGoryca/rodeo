/*
 | ----------------------------------------------
 |   mona Game Engine
 |   Copyright(c) Marcin Goryca
 |   marcin.goryca@gmail.com
 |   http://marcingoryca.pl
 | ----------------------------------------------
 */
#include "..\include\math\transform.h"
#include "..\include\math\matrix3.h"
#include "..\include\math\matrix4.h"

namespace mona
{
namespace math
{
/*
 * ----------------------------------------------------
 *    Scale Transformation
 * ----------------------------------------------------
 */
Matrix4 Transform::scale(float x, float y, float z)
{
    Matrix4 scaleMatrix;
    scaleMatrix.loadIdentity();

    scaleMatrix._m4[0] = x;
    scaleMatrix._m4[5] = y;
    scaleMatrix._m4[10] = z;

    return scaleMatrix;
}

/*
 * -----------------------------------------------------
 *     Rotation Transformation
 * -----------------------------------------------------
 */
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

    rotation._m4[0] = x2 * a + c;
    rotation._m4[1] = y * x * a + z * s;
    rotation._m4[2] = x * z * a - y * s;
    rotation._m4[3] = 0.0f;
    rotation._m4[4] = x * y * a - z * s;
    rotation._m4[5] = y2 * a + c;
    rotation._m4[6] = y * z * a + x * s;
    rotation._m4[7] = 0.0f;
    rotation._m4[8] = x * z * a + y * s;
    rotation._m4[9] = y * z * a - x * s;
    rotation._m4[10] = z2 * a + c;
    rotation._m4[11] = 0.0f;
    rotation._m4[12] = 0.0f;
    rotation._m4[13] = 0.0f;
    rotation._m4[14] = 0.0f;
    rotation._m4[15] = 1.0f;

    return rotation;
}

/* 
 * ------------------------------------------------
 *     Translate 
 * ------------------------------------------------
 */
Matrix4 Transform::translate(const float x, const float y, const float z)
{
    Matrix4 m;

    m.loadIdentity();

    m._m4[3] = x;
    m._m4[7] = y;
    m._m4[11] = z;

    return m;
}
}    // end of math namespace
}    // end of mona namespace