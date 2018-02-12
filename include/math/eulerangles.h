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
#ifndef RODEO_MATH_EULERANGLES_H_
#define RODEO_MATH_EULERANGLES_H_

#ifndef RODEO_MATH_MATHTOOLS_H_
#include "math\mathtools.h"
#endif

#ifndef RODEO_MATH_QUATERNION_H_
#include "math\quaternion.h"
#endif

#ifndef RODEO_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

namespace rodeo
{
namespace math
{
class EulerAngles
{
public:
    EulerAngles()
        :_pitch(0.0f),
         _yaw(0.0f),
         _roll(0.0f),
         _hpi(0.0f)
    {}

// Parameter p - pitch (x-axis)
// Parameter y - yaw (y-axis)
// Parameter r - roll (z-axis)
    EulerAngles(float p, float y, float r)
        :_pitch(p), 
		 _yaw(y), 
		 _roll(r)
    {}

    ~EulerAngles(){}

    void identity(){ _pitch = _yaw = _roll = 0.0f; }
    void canonize();

    void fromObjectToInertialQuaternion(const Quaternion& q);
    void fromInertialToObjectQuaternion(const Quaternion& q);

private:
    float _pitch;
    float _yaw;
    float _roll;
    float _hpi;

	float wrapPI(float theta);
};
}
}
#endif