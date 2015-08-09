/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "math\ray.h"

namespace mg
{
namespace math
{
void Ray::detransform(const Matrix3& m)
{
    Matrix3 invert;
    Matrix3 temp;
    temp = m;

    //inverse translation
    origin_.x_ -= temp.m3_[12];
    origin_.y_ -= temp.m3_[13];
    origin_.z_ -= temp.m3_[14];

    //delete translation in the matrix
    temp.m3_[12] = 0.0f;
    temp.m3_[13] = 0.0f;
    temp.m3_[14] = 0.0f;
}

//--------------------------------------------------------------------------------------------------
void Ray::set(const Vector3& org, const Vector3& dir)
{
    origin_ = org;
    direction_ = dir;
}
}    // end of math namespace
}    // end of mg namespace