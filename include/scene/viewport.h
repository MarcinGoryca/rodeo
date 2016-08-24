/*
-----------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_SCENE_VIEWPORT_H_
#define MONA_SCENE_VIEWPORT_H_

#ifndef MONA_RENDERER_GL_GLRENDERER_H_
#include "renderer\gl\glrenderer.h"
#endif

namespace mona
{
	namespace scene
	{
		enum ViewportType
		{
			PERSPECTIVE=1,
			ORTHOGONAL=0
		};
		class Viewport
		{
		public:
			Viewport() {}
			~Viewport() {}

			// Sets viewport to width and height \n
			// Parameter x, y - starting points
			// Parameter w, h - width, height respectively
			// Parameter GLViewportType - RODEO_ORTHOGONAL, RODEO_PERSPECTIVE
			void set(int x, int y, int w, int h, ViewportType vt);
			//virtual void update();
			//virtual void draw();

			// Starts Viewport 
			void begin();

			// Ends Viewport 
			void end();
		};
	}
}
#endif