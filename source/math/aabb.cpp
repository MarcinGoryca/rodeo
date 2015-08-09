/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "math\aabb.h"

namespace mg
{
namespace math
{
void AABB::resize()
{
    min_ = min_ * 1.2f;
    max_ = max_ * 1.2f;
}
}    // end of math namespace
}    // end of mg namespace