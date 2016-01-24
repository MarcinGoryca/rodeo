#pragma once

#ifndef MG_RENDERER_GLCOMMON_H_
#include "glcommon.h"
#endif

namespace mg {
    namespace renderer {
        enum Primitives {
            GL_POINTS,
            GL_LINES,
            GL_LINE_STRIP,
            GL_LINE_LOOP,
            GL_TRIANGLES,
            GL_TRIANGLE_STRIP,
            GL_TRIANGLE_FAN
        };

        /*
         |  -------------------------------------------
         |    POLYGON MODE
         |    GL_POINT / GL_LINE / GL_FILL
         |  -------------------------------------------
         */
        enum PolygonMode {
            GL_POINT,
            GL_LINE,
            GL_FILL
        };

        /*
         |  ------------------------------------------
         |    POLYGON FACE
         |    GL_FRONT_AND_BACK
         |  ------------------------------------------
         */
        enum PolygonFace {
            GL_FRONT_AND_BACK
        };

        /*
         |  ------------------------------------------
         |    FRONT FACE MODE
         |    GL_CCW, GL_CW
         |  ------------------------------------------
         */
        enum FrontFaceMode {
            GL_CCW,
            GL_CW
        };

        /*
         |  ------------------------------------------
         |    CULL FACE MODE
         |    GL_FRONT, GL_BACK, GL_FRONT_AND_BACK
         |  ------------------------------------------
         */
        enum CullFaceMode {
            GL_FRONT,
            GL_BACK,
            GL_FRONT_AND_BACK
        };
    }   // end of renderer namespace

}   // end of mg namespace