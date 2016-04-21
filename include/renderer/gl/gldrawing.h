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

			// glPointSize(GLfloat size)
			// Sets the fixed size, in pixels, that will be used for points
			// when GL_PROGRAM_POINT_SIZE is not enabled

			// glLineWidth(GLfloat width)
			// Sets the fixed width of lines. The default value is 1.0. 
			// width is the new value of line width and must be 
            // greater than 0.0

			// glPolygonMode(GLenum face, GLenum mode)
			// face = GL_FRONT_AND_BACK
			// mode = GL_POINT / GL_LINE / GL_FILL

			// Wraps glFrontFace(GLenum mode)
            // mode = GL_CCW / GL_CW

			// glCullFace(GLenum mode)
			// mode = GL_FRONT / GL_BACK / GL_FRONT_AND_BACK
            // Culling must be enabled by glEnable(GL_CULL_FACE)
            // and can be disabled by glDisable(GL_CULL_FACE)

			// void glBuffers(GLsizei n, GLuint* buffers)
			// Returns n currently unused names for buffer objects in the array buffers


		};
	}
}