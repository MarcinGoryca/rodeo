///*
// |  --------------------------------------------------------------------------------------
// |    mona GAME ENGINE
// |    [ GLDrawing.cpp ] / [ renderer/gl ]
// |    Copyright (c) Marcin Goryca
// |    marcin.goryca@gmail.com
// |    http://marcingoryca.pl
// |  --------------------------------------------------------------------------------------
// */
//
//#include "renderer\gl\gldrawing.h"
//
//namespace mona {
//    namespace renderer {
//        /*
//         |  ---------------------------------------------------
//         |    pointSize() implementation
//         |  ---------------------------------------------------
//         */
//        void GLDrawing::pointSize(float size)
//        {
//            glPointSize(size);
//        }
//
//        /*
//         |  ---------------------------------------------------
//         |    lineWidth() implementation
//         |  ---------------------------------------------------
//         */
//        void GLDrawing::lineWidth(float width)
//        {
//            glLineWidth(width);
//        }
//
//        /*
//         |  ---------------------------------------------------
//         |    polygonMode() implementation
//         |  ---------------------------------------------------
//         */
//        void GLDrawing::polygonMode(PolygonFace face, PolygonMode mode)
//        {
//            glPolygonMode(face, mode);
//        }
//
//        /*
//         |  ---------------------------------------------------
//         |    frontFace() implementation
//         |  ---------------------------------------------------
//         */
//        void GLDrawing::frontFace(FrontFaceMode mode)
//        {
//            glFrontFace(mode);
//        }
//
//        /*
//         |  --------------------------------------------------
//         |    cullFace() implementation
//         |  --------------------------------------------------
//         */
//        void GLDrawing::cullFace(CullFaceMode mode)
//        {
//            glCullFace(mode);
//        }
//    }
//}