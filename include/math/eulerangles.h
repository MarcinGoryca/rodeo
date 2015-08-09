/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_EULERANGLES_H_
#define MG_MATH_EULERANGLES_H_

#ifndef MG_MATH_MATHTOOLS_H_
#include "math\mathtools.h"
#endif

#ifndef MG_MATH_QUATERNION_H_
#include "math\quaternion.h"
#endif

#ifndef MG_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

namespace mg
{
namespace math
{
class EulerAngles
{
public:
    EulerAngles()
        :pitch_(0.0f),
         yaw_(0.0f),
         roll_(0.0f),
         hpi_(0.0f)
    {}

// Parameter p - pitch (x-axis)
// Parameter y - yaw (y-axis)
// Parameter r - roll (z-axis)
    EulerAngles(float p, float y, float r)
        :pitch_(p), yaw_(y), roll_(r)
    {}

    ~EulerAngles(){}

    void identity(){ pitch_ = yaw_ = roll_ = 0.0f; }
    void canonize();

    void fromObjectToInertialQuaternion(const Quaternion& q);
    void fromInertialToObjectQuaternion(const Quaternion& q);

private:
    float wrapPI(float theta);

    float pitch_;
    float yaw_;
    float roll_;
    float hpi_;
};
}    // end of math namespace
}    // end of mg namespace
#endif