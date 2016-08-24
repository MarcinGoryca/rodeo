/*
----------------------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MONA_MATH_EULERANGLES_H_
#define MONA_MATH_EULERANGLES_H_

#ifndef MONA_MATH_MATHTOOLS_H_
#include "math\mathtools.h"
#endif

#ifndef MONA_MATH_QUATERNION_H_
#include "math\quaternion.h"
#endif

#ifndef MONA_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

namespace mona
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