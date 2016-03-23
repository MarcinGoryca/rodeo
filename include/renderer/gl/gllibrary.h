//// TODO
//// THIS FILE MUST BE CLEARED AND DELETED!
//
//
///*
// | ----------------------------------------------
// |   MG Game Engine
// |   [ GLLibrary.h ] / [renderer/gl]
// |   Copyright(c) Marcin Goryca
// |   marcin.goryca@gmail.com
// |   http://marcingoryca.pl
// | ----------------------------------------------
// */
//
//#ifndef MG_RENDERER_GLLIBRARY_H
//#define MG_RENDERER_GLLIBRARY_H
//
//#ifndef MG_GLCOMMON_H_
//#include "glcommon.h"
//#endif
//
//namespace mg
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
//    // How to draw geometry
//    enum DrawingMode
//    {
//        MG_TRIANGLES = GL_TRIANGLES,
//        MG_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
//        MG_TRIANGLE_FAN = GL_TRIANGLE_FAN,
//        MG_POINTS = GL_POINTS,
//        MG_LINES = GL_LINES,
//        MG_LINE_STRIP = GL_LINE_STRIP,
//        MG_LINE_LOOP = GL_LINE_LOOP,
//        MG_QUADS = GL_QUADS
//    };
//
//    // Lights
//    enum LightType
//    {
//        MG_AMBIENT = GL_AMBIENT,
//        MG_DIFFUSE = GL_DIFFUSE, 
//        MG_SPECULAR = GL_SPECULAR,
//    };
//
//    // Data Types for rendering arrays
//    enum DataTypes
//    {
//        MG_SHORT = GL_SHORT,
//        MG_USHORT = GL_UNSIGNED_SHORT,
//        MG_UINT = GL_UNSIGNED_INT,
//        MG_FLOAT = GL_FLOAT,
//        MG_DOUBLE = GL_DOUBLE,
//        MG_BYTE = GL_BYTE,
//        MG_INT = GL_INT,
//        MG_UBYTE = GL_UNSIGNED_BYTE
//    };
//
//    // Viewport types supported by the engine
//    enum GLViewportType 
//    {
//        MG_ORTHOGONAL = 0,
//        MG_PERSPECTIVE = 1
//    };
//
//    // ArrayType enumeration
//    // GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER
//    enum ArrayType
//    {
//        MG_ARRAY = GL_ARRAY_BUFFER,
//        MG_ELEMENT = GL_ELEMENT_ARRAY_BUFFER
//    };
//
//    // ArrayDraw enumeration
//    // GL_STATIC_DRAW, GL_STREAM_DRAW, GL_DYNAMIC_DRAW
//    enum ArrayDraw
//    {
//        MG_STATIC = GL_STATIC_DRAW,
//        MG_STREAM = GL_STREAM_DRAW,
//        MG_DYNAMIC = GL_DYNAMIC_DRAW
//    };
//
//    // BufferType enumeration
//    // MG_VBO = VERTEX BUFFER OBJECT, 
//    // MG_CBO = COLOR BUFFER OBJECT, 
//    // MG_NBO = NORMAL BUFFER OBJECT, 
//    // MG_TBO = TEXTURE BUFFER OBJECT, 
//    // MG_EBO = ELEMENT BUFFER OBJECT
//    enum BufferType
//    {
//        MG_VBO,
//        MG_CBO,
//        MG_NBO,
//        MG_TBO,
//        MG_EBO
//    };
//}    // end of renderer namespace
//}    // end of mg namespace
//#endif