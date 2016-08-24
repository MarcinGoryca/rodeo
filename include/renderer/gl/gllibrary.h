//// TODO
//// THIS FILE MUST BE CLEARED AND DELETED!
//
//
///*
// | ----------------------------------------------
// |   mona Game Engine
// |   [ GLLibrary.h ] / [renderer/gl]
// |   Copyright(c) Marcin Goryca
// |   marcin.goryca@gmail.com
// |   http://marcingoryca.pl
// | ----------------------------------------------
// */
//
//#ifndef MONA_RENDERER_GLLIBRARY_H
//#define MONA_RENDERER_GLLIBRARY_H
//
//#ifndef MONA_GLCOMMON_H_
//#include "glcommon.h"
//#endif
//
//namespace mona
//{
//namespace renderer
//{
//    // Antialiasing 
//    // NOT RECOMMENDED for performance
//    bool lineAntialias();
//    bool pointAntialias();
//    bool polygonAntialias();
//
//    //	
//    // Polygon Rendering Modes 
//    // Parameter	GLenum face - GL_FRONT	front of polygon will be rendered
//    //			  GL_BACK	back of polygon will be rendered
//    //				  GL_FRONT_AND_BACK	front and back will be rendered
//    //	GLenum mode - GL_FILL	fill in all polygon(solid)
//    //						  GL_LINE	polygon will be rendered with edges
//    //						  GL_POINT	polygon will be rendered with points
//    void polygonMode(GLenum face, GLenum mode);
//    bool polyFrontFill();
//    bool polyFrontLine();
//    bool polyFrontPoint();
//    bool polyFrontBackFill();
//    bool polyFrontBackLine();
//    bool polyFrontBackPoint();
//
//    //	
//    // Culling Modes	
//    // Front - front side of the polygon will be culled\n
//    // Back - back side of the polygon will be culled\n
//    // Front and back	- all polygon will be culled\n
//    bool cullFrontOn();
//    bool cullBackOn();
//    bool cullFrontBackOn();
//    bool cullFrontOff();
//    bool cullBackOff();
//    bool cullFrontBackOff();
//  
//    //	
//    // Winding Polygons
//    // Default OpenGL mode is counterclockwise for front facing polygon\n
//    // and clockwise for back facing polygon
//    // Parameter GL_CCW - counterclockwise\n
//    //           GL_CW - clockwise	
//    bool polygonWinding(GLenum mode);
//
//    // Edges to display
//    // GLboolean  - GL_TRUE\n
//    //              GL_FALSE
//    bool polygonWithEdges(GLboolean edge);
//
//    // Shade model
//    // Parameter GLenum mode - GL_SMOOTH (default)\n
//    //                         GL_FLAT	
//    bool shadeMode(GLenum mode);
//    bool lightingOn();
//    bool lightingOff();
//
//    // Enables / Disables Depth Test 
//    bool depthTestOn();
//    bool depthTestOff();
//    bool scissorsOn();
//    bool scissorsOff();
//    bool stencilOn();
//    bool stencilOff();
//    void push();
//    void pop();
//    bool pointSize(float ps);
//    bool lineWidth(float lw);
//
//    // Light model
//    // Parameter mode - GL_LIGHT_MODEL_AMBIENT
//    // Parameter mode - GL_LIGHT_MODEL_LOCAL_VIEWER
//    // Parameter mode - GL_LIGHT_MODEL_TWO_SIDE
//    // Parameter mode - GL_LIGHT_MODEL_COLOR_CONTROL
//    bool lightModel(GLenum mode, float r, float g, float b);
//    bool colorMaterial();
//
//    // Color material mode
//    // Parameter face - GL_FRONT
//    // Parameter face - GL_BACK
//    // Parameter face - GL_FRONT_AND_BACK (default)
//    // Parameter mode - GL_AMBIENT
//    // Parameter mode - GL_DIFFUSE
//    // Parameter mode - GL_SPECULAR,
//    // Parameter mode - GL_AMBIENT_AND_DIFFUSE (defualt)
//    // Parameter mode -  GL_EMISSION
//    bool colorMaterialMode(GLenum face, GLenum mode);
//    bool blendingOn();
//    bool blendingOff();
//    bool texturingOn();
//    bool texturingOff();
//

//}    // end of renderer namespace
//}    // end of mona namespace
//#endif