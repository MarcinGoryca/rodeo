/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
//#ifndef RODEO_GLCOMMON_H_
//#define RODEO_GLCOMMON_H_
//
//#pragma comment(lib, "libs\\glew32.lib")
//#pragma comment(lib, "libs\\glu32.lib")
//#pragma comment(lib, "libs\\opengl32.lib")
//
//#ifndef RODEO_RENDERER_GL_GLEW_H_
//#include "glew.h"
//#endif
//
//#ifndef RODEO_RENDERER_GL_WGLEW_H_
//#include "wglew.h"
//#endif
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		namespace gl
//		{
//			    // ArrayType enumeration
//			    // GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER
//			    enum ArrayType
//			    {
//			        RODEO_ARRAY = GL_ARRAY_BUFFER,
//			        RODEO_ELEMENT = GL_ELEMENT_ARRAY_BUFFER
//			    };
//
//				// ArrayDraw enumeration
//				// GL_STATIC_DRAW, GL_STREAM_DRAW, GL_DYNAMIC_DRAW
//				enum ArrayDraw
//				{
//				    RODEO_STATIC = GL_STATIC_DRAW,
//				    RODEO_STREAM = GL_STREAM_DRAW,
//				    RODEO_DYNAMIC = GL_DYNAMIC_DRAW
//				};
//
//				// How to draw geometry
//				enum DrawingMode
//				{
//				    RODEO_TRIANGLES = GL_TRIANGLES,
//				    RODEO_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
//				    RODEO_TRIANGLE_FAN = GL_TRIANGLE_FAN,
//				    RODEO_POINTS = GL_POINTS,
//				    RODEO_LINES = GL_LINES,
//				    RODEO_LINE_STRIP = GL_LINE_STRIP,
//				    RODEO_LINE_LOOP = GL_LINE_LOOP,
//				    RODEO_QUADS = GL_QUADS
//				};
//				
//				// Lights
//				enum LightType
//				{
//				    RODEO_AMBIENT = GL_AMBIENT,
//				    RODEO_DIFFUSE = GL_DIFFUSE, 
//				    RODEO_SPECULAR = GL_SPECULAR,
//				};
//				
//				// Data Types for rendering arrays
//				enum DataTypes
//				{
//				    RODEO_SHORT = GL_SHORT,
//				    RODEO_USHORT = GL_UNSIGNED_SHORT,
//				    RODEO_UINT = GL_UNSIGNED_INT,
//				    RODEO_FLOAT = GL_FLOAT,
//				    RODEO_DOUBLE = GL_DOUBLE,
//				    RODEO_BYTE = GL_BYTE,
//				    RODEO_INT = GL_INT,
//				    RODEO_UBYTE = GL_UNSIGNED_BYTE
//				};
//				
//				// Viewport types supported by the engine
//				enum GLViewportType 
//				{
//				    RODEO_ORTHOGONAL = 0,
//				    RODEO_PERSPECTIVE = 1
//				};
//				
//				
//
//				
//				// BufferType enumeration
//				// RODEO_VBO = VERTEX BUFFER OBJECT, 
//				// RODEO_CBO = COLOR BUFFER OBJECT, 
//				// RODEO_NBO = NORMAL BUFFER OBJECT, 
//				// RODEO_TBO = TEXTURE BUFFER OBJECT, 
//				// RODEO_EBO = ELEMENT BUFFER OBJECT
//				enum BufferType
//				{
//				    RODEO_VBO,
//				    RODEO_CBO,
//				    RODEO_NBO,
//				    RODEO_TBO,
//				    RODEO_EBO
//				};
//		}
//	}
//}
//
//#endif