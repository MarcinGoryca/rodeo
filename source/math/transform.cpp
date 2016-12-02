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
#include "..\include\math\transform.h"
#include "..\include\math\matrix3.h"
#include "..\include\math\matrix4.h"

namespace laura
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
}    // end of laura namespace
