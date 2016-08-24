﻿/*
----------------------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\renderinghelpers.h"
#include "renderer\colors.h"

namespace mona
{
namespace renderer
{
void RenderingHelpers::init()
{
    _has_pivot_axes = false;
}


void RenderingHelpers::drawLine(float* start, float* end, Colors rgb)
{
    //glBegin(GL_LINES);
    //glColor3f(rgb.red_, rgb.g_, rgb.b_);
    //glVertex3f(start[0], start[1], start[2]);
    //glVertex3f(end[0], end[1], end[2]);
    //glEnd();
}
}    // end of renderer namespace
}    // end of mona namespace