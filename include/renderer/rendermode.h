/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_RENDERMODE_H_
#define MG_RENDERER_RENDERMODE_H_

#ifndef MG_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

namespace mg
{
	namespace renderer
	{
		class RenderMode
		{
		public:
			RenderMode()
				:_face_type(GL_FRONT_AND_BACK),
				_face_mode(GL_FILL),
				_point_size(1.0f),
				_line_width(1.0f)
			{}
			virtual ~RenderMode() {}

		protected:
			float _point_size;
			float _line_width;

			// For PolygonMode
			// Parameter - GL_FRONT_AND_BACK
			// Parameter - GL_FRONT
			// Parameter - GL_BACK
			GLenum _face_type;

			// Face mode for PolygonMode
			// Parameter - GL_LINE
			// Parameter - GL_POINT
			// Parameter - GL_FILL
			GLenum _face_mode;
		};
	}
}
#endif