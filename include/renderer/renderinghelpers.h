/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_RENDERINGHELPERS_H_
#define MG_RENDERER_RENDERINGHELPERS_H_

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "gl\glcommon.h"
#endif

namespace mg
{
namespace renderer
{
class Colors;
class RenderingHelpers
{
public:
    RenderingHelpers(){ init(); }
    ~RenderingHelpers(){}

    void init();

    bool has_pivot_axes_;

    void drawLine(float* start, float* end, Colors rgb); 
};
}    // end of renderer namespace
}    // end of mg namespace
#endif