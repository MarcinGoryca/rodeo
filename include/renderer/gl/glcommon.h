/*
 |  ----------------------------------------------
 |    mona Game Engine
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
*/
#ifndef MONA_GLCOMMON_H_
#define MONA_GLCOMMON_H_

#pragma comment(lib, "libs\\glew32.lib")
#pragma comment(lib, "libs\\glu32.lib")
#pragma comment(lib, "libs\\opengl32.lib")

#ifndef MONA_RENDERER_GL_GLEW_H_
#include "glew.h"
#endif

#ifndef MONA_RENDERER_GL_WGLEW_H_
#include "wglew.h"
#endif

namespace mona
{
	namespace renderer
	{
		namespace gl
		{
			    // ArrayType enumeration
			    // GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER
			    enum ArrayType
			    {
			        MONA_ARRAY = GL_ARRAY_BUFFER,
			        MONA_ELEMENT = GL_ELEMENT_ARRAY_BUFFER
			    };

				// ArrayDraw enumeration
				// GL_STATIC_DRAW, GL_STREAM_DRAW, GL_DYNAMIC_DRAW
				enum ArrayDraw
				{
				    MONA_STATIC = GL_STATIC_DRAW,
				    MONA_STREAM = GL_STREAM_DRAW,
				    MONA_DYNAMIC = GL_DYNAMIC_DRAW
				};

				// How to draw geometry
				enum DrawingMode
				{
				    MONA_TRIANGLES = GL_TRIANGLES,
				    MONA_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
				    MONA_TRIANGLE_FAN = GL_TRIANGLE_FAN,
				    MONA_POINTS = GL_POINTS,
				    MONA_LINES = GL_LINES,
				    MONA_LINE_STRIP = GL_LINE_STRIP,
				    MONA_LINE_LOOP = GL_LINE_LOOP,
				    MONA_QUADS = GL_QUADS
				};
				
				// Lights
				enum LightType
				{
				    MONA_AMBIENT = GL_AMBIENT,
				    MONA_DIFFUSE = GL_DIFFUSE, 
				    MONA_SPECULAR = GL_SPECULAR,
				};
				
				// Data Types for rendering arrays
				enum DataTypes
				{
				    MONA_SHORT = GL_SHORT,
				    MONA_USHORT = GL_UNSIGNED_SHORT,
				    MONA_UINT = GL_UNSIGNED_INT,
				    MONA_FLOAT = GL_FLOAT,
				    MONA_DOUBLE = GL_DOUBLE,
				    MONA_BYTE = GL_BYTE,
				    MONA_INT = GL_INT,
				    MONA_UBYTE = GL_UNSIGNED_BYTE
				};
				
				// Viewport types supported by the engine
				enum GLViewportType 
				{
				    MONA_ORTHOGONAL = 0,
				    MONA_PERSPECTIVE = 1
				};
				
				

				
				// BufferType enumeration
				// MONA_VBO = VERTEX BUFFER OBJECT, 
				// MONA_CBO = COLOR BUFFER OBJECT, 
				// MONA_NBO = NORMAL BUFFER OBJECT, 
				// MONA_TBO = TEXTURE BUFFER OBJECT, 
				// MONA_EBO = ELEMENT BUFFER OBJECT
				enum BufferType
				{
				    MONA_VBO,
				    MONA_CBO,
				    MONA_NBO,
				    MONA_TBO,
				    MONA_EBO
				};
		}
	}
}

#endif