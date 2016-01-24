/*
 |  ------------------------------------------------------
 |    MG GAME ENGINE
 |    [ GLDrawing.h ] / [ renderer/gl ]
 |    Copyright (c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ------------------------------------------------------
 */

#pragma once

#ifndef MG_RENDERER_GL_GLDRAWINGENUMS_H_
#include "gldrawingenums.h"
#endif

namespace mg {
	namespace renderer {
		class GLDrawing {
		public:
			GLDrawing() {}

			~GLDrawing() {}

			/*
             |  ---------------------------------------------------------------
			 |    Wraps glPointSize(GLfloat size)
			 |    Sets the fixed size, in pixels, that will be used for points
			 |    when GL_PROGRAM_POINT_SIZE is not enabled
             |  ---------------------------------------------------------------
			 */
			void pointSize(float point_size);

			/*
             |  --------------------------------------------------------------
			 |    Wraps glLineWidth(GLfloat width)
			 |    Sets the fixed width of lines. The default value is 1.0. 
			 |    width is the new value of line width and must be 
             |    greater than 0.0
             |  --------------------------------------------------------------
			 */
			void lineWidth(float line_width);

			/*
             |  --------------------------------------------------------------
             |    Wraps glPolygonMode(GLenum face, GLenum mode)
			 |    face = GL_FRONT_AND_BACK
			 |    mode = GL_POINT / GL_LINE / GL_FILL
             |  --------------------------------------------------------------
			 */
			void polygonMode(PolygonFace, PolygonMode);

			/*
             |  --------------------------------------------------------------
			 |    Wraps glFrontFace(GLenum mode)
             |    mode = GL_CCW / GL_CW
             |  --------------------------------------------------------------
			 */
			void frontFace(FrontFaceMode);

			/*
             |  --------------------------------------------------------------
             |    Wraps glCullFace(GLenum mode)
			 |    mode = GL_FRONT / GL_BACK / GL_FRONT_AND_BACK
             |    Culling must be enabled by glEnable(GL_CULL_FACE)
             |    and can be disabled by glDisable(GL_CULL_FACE)
             |  --------------------------------------------------------------
			 */
			void cullFace(CullFaceMode);


			void generateBuffers(int size, uint* buffers);

			void bindBuffer(enum target, uint buffer);

			void bufferData(enum target, int* size, const void* data, enum usage);

			void bufferSubData(enum target, int* offset, int* size, const void* data);

		};


	}

}