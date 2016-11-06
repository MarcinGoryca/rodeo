/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "scene\viewport.h"

using namespace laura::renderer;

namespace laura
{
	namespace scene
	{
		void Viewport::set(int x, int y, int w, int h, ViewportType vt)
		{
			switch (vt)
			{
				//PERSPECTIVE VIEWPORT	
			case 1:
			{
				glViewport(x, y, w, h);
				//glMatrixMode(GL_PROJECTION);
				//glLoadIdentity();
				float fov = 60.0f;
				float nearview = 1.0f;
				float farview = 100.0f;
				//gluPerspective(fov, (float)w / (float)h, nearview, farview);
				break;
			}
			//ORTHOGONAL VIEWPORT
			case 0:
			{
				glViewport(x, y, w, h);
				//glMatrixMode(GL_PROJECTION);
				//glLoadIdentity();
				//gluOrtho2D(x, (float)w/2, (float)h/2, y);
				//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
				break;
			}
			}
		}

		void Viewport::begin()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

		void Viewport::end()
		{
			glFlush();
		}
	}
}