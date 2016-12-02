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
//#ifndef LAURA_RENDERER_IRENDERER_H_
//#define LAURA_RENDERER_IRENDERER_H_
//
//#ifndef LAURA_RENDERER_GL_GLSLSHADERS_H_
//#include "renderer\gl\glslshaders.h"
//#endif
//
//namespace laura
//{
//	namespace renderer
//	{
//		class IRenderer
//		{
//		public:
//			IRenderer() {}
//			virtual ~IRenderer() {}
//
//			//virtual bool run(int w, int h) = 0;
//			//virtual void render() = 0;
//			//virtual void update() = 0;
//
//			// Enters the rendering frame
//			//virtual void enterFrame() = 0;
//
//			// Ends of the rendering frame
//			//virtual void endFrame() = 0;
//
//			// Event when the window is resized
//			//virtual void onSize(int w, int h) = 0;
//
//			// Orthographic projection
//			//virtual void enter2d() = 0;
//
//			// Perspective projection
//			//virtual void enter3d() = 0;
//			//virtual bool chooseViewportType(GLViewportType vt) = 0;
//
//			// Enables Lighting on the scene
//			/*virtual bool enableLighting() = 0;
//			virtual bool disableLighting() = 0;
//			virtual bool enableDepthTest() = 0;
//			virtual bool disableDepthTest() = 0;*/
//
//			// Changes Backgound color of the renderer 
//			/*virtual void backColor(float r, float g, float b, float a) = 0;*/
//
//			//virtual void enableShaders() = 0;
//			//virtual void disableShaders() = 0;
//			//IShaders* getShader()const { return _shader; }
//
//			//virtual void setShader(IShaders* si) = 0;
//
//			/*virtual void enableTexturing() = 0;
//			virtual void disableTexturing() = 0;
//
//			virtual void enableBlending() = 0;
//			virtual void disableBlending() = 0;*/
//
//			HWND getHWND() const { return _hwnd; }
//
//			void setHWND(HWND hwnd) { _hwnd = hwnd; }
//
//			// Checks if GL state is enabled,
//			// it can take any GL state as a parameter  
//			//virtual bool checkEnabled(GLenum state) = 0;
//
//			//virtual void enableCulling() = 0;
//			//virtual void disableCulling() = 0;
//			//virtual void cullMode(GLenum mode) = 0;
//		protected:
//			IShaders* _shader;
//			int _width;
//			int _height;
//			HWND _hwnd;
//		private:
//
//		};
//	}
//}
//#endif