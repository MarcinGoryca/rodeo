/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_RENDERMODE_H_
#define MG_RENDERER_RENDERMODE_H_

#ifndef MG_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

namespace mg
{
namespace renderer
{
class RenderMode
{
public:
    RenderMode()
        :face_type_(GL_FRONT_AND_BACK),
         face_mode_(GL_FILL)
    {}
    virtual ~RenderMode(){}

protected:
    float point_size_;
    float line_width_;

    // For PolygonMode
    // Parameter - GL_FRONT_AND_BACK
    // Parameter - GL_FRONT
    // Parameter - GL_BACK
    GLenum face_type_;

    // Face mode for PolygonMode
    // Parameter - GL_LINE
    // Parameter - GL_POINT
    // Parameter - GL_FILL
    GLenum face_mode_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif