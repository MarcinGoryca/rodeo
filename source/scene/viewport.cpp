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
//#include "scene\viewport.h"
//
//using namespace laura::renderer;
//
//namespace laura
//{
//	namespace scene
//	{
//		void Viewport::set(int x, int y, int w, int h, ViewportType vt)
//		{
//			switch (vt)
//			{
//				//PERSPECTIVE VIEWPORT	
//			case 1:
//			{
//				glViewport(x, y, w, h);
//				//glMatrixMode(GL_PROJECTION);
//				//glLoadIdentity();
//				float fov = 60.0f;
//				float nearview = 1.0f;
//				float farview = 100.0f;
//				//gluPerspective(fov, (float)w / (float)h, nearview, farview);
//				break;
//			}
//			//ORTHOGONAL VIEWPORT
//			case 0:
//			{
//				glViewport(x, y, w, h);
//				//glMatrixMode(GL_PROJECTION);
//				//glLoadIdentity();
//				//gluOrtho2D(x, (float)w/2, (float)h/2, y);
//				//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//				break;
//			}
//			}
//		}
//
//		void Viewport::begin()
//		{
//			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//			glMatrixMode(GL_MODELVIEW);
//			glLoadIdentity();
//		}
//
//		void Viewport::end()
//		{
//			glFlush();
//		}
//	}
//}