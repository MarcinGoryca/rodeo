/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_RAY_H_
#define MG_MATH_RAY_H_

#ifndef MG_MATH_MATRIX3_H_
#include "math\matrix3.h"
#endif

#ifndef MG_MATH_VECTOR4_H_
#include "math\vector4.h"
#endif

namespace mg
{
namespace math
{
class Ray
{
public:
    Ray()
        :origin_(0.0f, 0.0f, 0.0f),
         direction_(0.0f, 0.0f, 0.0f)
    {
    }

    ~Ray(){}

    // Sets new Ray
    void set(const Vector3& org, const Vector3& dir);

    // Gets the Ray
    Ray& get() { return *this; };

    // Gets the Origin of the Ray
    Vector3 getOrigin()const { return origin_; }

    // Sets the Origin of the Ray
    void setOrigin(Vector3 new_origin) { origin_ = new_origin; }

    // Gets the Direction of the Ray
    Vector3 getDirection() const { return direction_; }

    // Sets the Direction of the Ray
    void setDirection(Vector3 new_direction) { direction_ = new_direction; }


    // Transforms model from its coordinate space
    // With using Rays it's not necessary to transform whole model
    // by multiplying its vertices by transform matrix
    // on the CPU, this operation is very slow. 
    void detransform(const Matrix3& m);
    bool intersects(const Vector3& v0, const Vector3& v1, const Vector3& v2, bool cull, float* t);

private:
    // Copy Constructor
    Ray(const Ray& copy);

    // Copy operator
    Ray operator=(const Ray& copy);

private:
    // Origin Point of a Ray
    Vector3 origin_;

    // Direction which Ray is running
    // Normalized is better
    Vector3 direction_;
};
}    // end of math namespace
}    // end of mg namespace
#endif

/*
Parametric line:
P(t) = origin + t * direction

for every pixel
    construct a ray from the eye
    for every object in the scene
        find intersection with the ray
        keep it closest
    shade depending on light and normal vector
*/
