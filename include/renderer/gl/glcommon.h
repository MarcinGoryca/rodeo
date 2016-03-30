/*
 |  ----------------------------------------------
 |    MG Game Engine
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
*/
#ifndef MG_GLCOMMON_H_
#define MG_GLCOMMON_H_

#pragma comment(lib, "libs\\glew32.lib")
#pragma comment(lib, "libs\\glu32.lib")
#pragma comment(lib, "libs\\opengl32.lib")

#ifndef MG_RENDERER_GL_GLEW_H_
#include "glew.h"
#endif

#ifndef MG_RENDERER_GL_WGLEW_H_
#include "wglew.h"
#endif

namespace mg
{
	namespace renderer
	{
		namespace gl
		{
			    // ArrayType enumeration
			    // GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER
			    enum ArrayType
			    {
			        MG_ARRAY = GL_ARRAY_BUFFER,
			        MG_ELEMENT = GL_ELEMENT_ARRAY_BUFFER
			    };

				// ArrayDraw enumeration
				// GL_STATIC_DRAW, GL_STREAM_DRAW, GL_DYNAMIC_DRAW
				enum ArrayDraw
				{
				    MG_STATIC = GL_STATIC_DRAW,
				    MG_STREAM = GL_STREAM_DRAW,
				    MG_DYNAMIC = GL_DYNAMIC_DRAW
				};

				// How to draw geometry
				enum DrawingMode
				{
				    MG_TRIANGLES = GL_TRIANGLES,
				    MG_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
				    MG_TRIANGLE_FAN = GL_TRIANGLE_FAN,
				    MG_POINTS = GL_POINTS,
				    MG_LINES = GL_LINES,
				    MG_LINE_STRIP = GL_LINE_STRIP,
				    MG_LINE_LOOP = GL_LINE_LOOP,
				    MG_QUADS = GL_QUADS
				};
				
				// Lights
				enum LightType
				{
				    MG_AMBIENT = GL_AMBIENT,
				    MG_DIFFUSE = GL_DIFFUSE, 
				    MG_SPECULAR = GL_SPECULAR,
				};
				
				// Data Types for rendering arrays
				enum DataTypes
				{
				    MG_SHORT = GL_SHORT,
				    MG_USHORT = GL_UNSIGNED_SHORT,
				    MG_UINT = GL_UNSIGNED_INT,
				    MG_FLOAT = GL_FLOAT,
				    MG_DOUBLE = GL_DOUBLE,
				    MG_BYTE = GL_BYTE,
				    MG_INT = GL_INT,
				    MG_UBYTE = GL_UNSIGNED_BYTE
				};
				
				// Viewport types supported by the engine
				enum GLViewportType 
				{
				    MG_ORTHOGONAL = 0,
				    MG_PERSPECTIVE = 1
				};
				
				

				
				// BufferType enumeration
				// MG_VBO = VERTEX BUFFER OBJECT, 
				// MG_CBO = COLOR BUFFER OBJECT, 
				// MG_NBO = NORMAL BUFFER OBJECT, 
				// MG_TBO = TEXTURE BUFFER OBJECT, 
				// MG_EBO = ELEMENT BUFFER OBJECT
				enum BufferType
				{
				    MG_VBO,
				    MG_CBO,
				    MG_NBO,
				    MG_TBO,
				    MG_EBO
				};
		}
	}
}

#endif