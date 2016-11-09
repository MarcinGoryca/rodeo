///*
// |  ----------------------------------------------
// |    Laura Game Engine
// |    Copyright(c) Marcin Goryca
// |    marcin.goryca@gmail.com
// |    http://marcingoryca.pl
// |  ----------------------------------------------
//*/
//#ifndef LAURA_GLCOMMON_H_
//#define LAURA_GLCOMMON_H_
//
//#pragma comment(lib, "libs\\glew32.lib")
//#pragma comment(lib, "libs\\glu32.lib")
//#pragma comment(lib, "libs\\opengl32.lib")
//
//#ifndef LAURA_RENDERER_GL_GLEW_H_
//#include "glew.h"
//#endif
//
//#ifndef LAURA_RENDERER_GL_WGLEW_H_
//#include "wglew.h"
//#endif
//
//namespace laura
//{
//	namespace renderer
//	{
//		namespace gl
//		{
//			    // ArrayType enumeration
//			    // GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER
//			    enum ArrayType
//			    {
//			        LAURA_ARRAY = GL_ARRAY_BUFFER,
//			        LAURA_ELEMENT = GL_ELEMENT_ARRAY_BUFFER
//			    };
//
//				// ArrayDraw enumeration
//				// GL_STATIC_DRAW, GL_STREAM_DRAW, GL_DYNAMIC_DRAW
//				enum ArrayDraw
//				{
//				    LAURA_STATIC = GL_STATIC_DRAW,
//				    LAURA_STREAM = GL_STREAM_DRAW,
//				    LAURA_DYNAMIC = GL_DYNAMIC_DRAW
//				};
//
//				// How to draw geometry
//				enum DrawingMode
//				{
//				    LAURA_TRIANGLES = GL_TRIANGLES,
//				    LAURA_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
//				    LAURA_TRIANGLE_FAN = GL_TRIANGLE_FAN,
//				    LAURA_POINTS = GL_POINTS,
//				    LAURA_LINES = GL_LINES,
//				    LAURA_LINE_STRIP = GL_LINE_STRIP,
//				    LAURA_LINE_LOOP = GL_LINE_LOOP,
//				    LAURA_QUADS = GL_QUADS
//				};
//				
//				// Lights
//				enum LightType
//				{
//				    LAURA_AMBIENT = GL_AMBIENT,
//				    LAURA_DIFFUSE = GL_DIFFUSE, 
//				    LAURA_SPECULAR = GL_SPECULAR,
//				};
//				
//				// Data Types for rendering arrays
//				enum DataTypes
//				{
//				    LAURA_SHORT = GL_SHORT,
//				    LAURA_USHORT = GL_UNSIGNED_SHORT,
//				    LAURA_UINT = GL_UNSIGNED_INT,
//				    LAURA_FLOAT = GL_FLOAT,
//				    LAURA_DOUBLE = GL_DOUBLE,
//				    LAURA_BYTE = GL_BYTE,
//				    LAURA_INT = GL_INT,
//				    LAURA_UBYTE = GL_UNSIGNED_BYTE
//				};
//				
//				// Viewport types supported by the engine
//				enum GLViewportType 
//				{
//				    LAURA_ORTHOGONAL = 0,
//				    LAURA_PERSPECTIVE = 1
//				};
//				
//				
//
//				
//				// BufferType enumeration
//				// LAURA_VBO = VERTEX BUFFER OBJECT, 
//				// LAURA_CBO = COLOR BUFFER OBJECT, 
//				// LAURA_NBO = NORMAL BUFFER OBJECT, 
//				// LAURA_TBO = TEXTURE BUFFER OBJECT, 
//				// LAURA_EBO = ELEMENT BUFFER OBJECT
//				enum BufferType
//				{
//				    LAURA_VBO,
//				    LAURA_CBO,
//				    LAURA_NBO,
//				    LAURA_TBO,
//				    LAURA_EBO
//				};
//		}
//	}
//}
//
//#endif