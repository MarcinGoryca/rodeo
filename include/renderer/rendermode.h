/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
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
//#ifndef LAURA_RENDERER_RENDERMODE_H_
//#define LAURA_RENDERER_RENDERMODE_H_
//
//#ifndef LAURA_RENDERER_GL_GLCOMMON_H_
//#include "renderer\gl\glcommon.h"
//#endif
//
//namespace laura
//{
//	namespace renderer
//	{
//		class RenderMode
//		{
//		public:
//			RenderMode()
//				:_face_type(GL_FRONT_AND_BACK),
//				_face_mode(GL_FILL),
//				_point_size(1.0f),
//				_line_width(1.0f)
//			{}
//			virtual ~RenderMode() {}
//
//		protected:
//			float _point_size;
//			float _line_width;
//
//			// For PolygonMode
//			// Parameter - GL_FRONT_AND_BACK
//			// Parameter - GL_FRONT
//			// Parameter - GL_BACK
//			GLenum _face_type;
//
//			// Face mode for PolygonMode
//			// Parameter - GL_LINE
//			// Parameter - GL_POINT
//			// Parameter - GL_FILL
//			GLenum _face_mode;
//		};
//	}
//}
//#endif