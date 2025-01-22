/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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
#ifndef RODEO_RENDERER_GLRENDERER_H_
#define RODEO_RENDERER_GLRENDERER_H_

#ifndef RODEO_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef RODEO_CORE_EXCEPTION_H_
#include "core\exception.h"
#endif

#ifndef RODEO_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef RODEO_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

#ifndef RODEO_RENDERER_GL_GLCOMMON_H_
#include "renderer\gl\glcommon.h"
#endif

#ifndef RODEO_RENDERERGL_GL_QUERYRENDERER_H_
#include "renderer\gl\queryrenderer.h"
#endif

#ifndef RODEO_RENDERER_IRENDERER_H_
#include "renderer\irenderer.h"
#endif

namespace rodeo
{
	namespace renderer
	{
		class GLRenderer : public core::Singleton<GLRenderer>, public IRenderer
		{
		public:
			GLRenderer();

			virtual ~GLRenderer();

			/*
			 |  ------------------------------------------------------
			 |    Parameter w - width of the scene
			 |    Parameter h - height of the scene
			 |    Runs renderer
			 |    Calls glewInit(), QueryRenderer.run()
			 |  ------------------------------------------------------
			 */
			virtual bool run(int w, int h);

			/*
			 |  ------------------------------------------------------
			 |    Render to the screen,
			 |  ------------------------------------------------------
			 */
			virtual void render();

			virtual void update();

			// For Orthographic projection 
			virtual void enter2d();

			// For Perspective projection
			virtual void enter3d();

			/*
			 |  ---------------------------------------------------------------------------------
			 |    Parameter r - red value of the color [range 0.0f - 1.0f]
			 |    Parameter g - green value of the color [range 0.0f - 1.0f]
			 |    Parameter b - blue value of the color [range 0.0f - 1.0f]
			 |    Use it to Change Background Color of the rendering window
			 |    Using Colors from rodeo
			 |    backColor(darkgreen, 1.0f)
			 |    You must specify your alfa argument [range 0.0f[transparent] - 1.0f[opacity]]
			 |    Colors in float manner are defined with only three values red, green, blue
			 |    like that: #define white 1.0f, 1.0f, 1.0f
			 |  ---------------------------------------------------------------------------------
			 */
			virtual void backColor(float r, float g, float b, float a);

			/*
			 | ----------------------------------------------------------------------------------
			 |     Change Size if it receives WM_SIZE MSG
			 |     Parameter w - width of the scene
			 |     Parameter h - height of the scene
			 |     Calls SetGL(int, int)
			 | ----------------------------------------------------------------------------------
			 */
			virtual void onSize(int w, int h);

			// ChooseViewportType(GLViewportType type) --
			bool chooseViewportType(gl::GLViewportType type);

			/*
			 | ----------------------------------------------------------------------------------
			 |    Enter the frame of rendering, 
			 |    it should initialize OpenGL pipeline, clear all buffers
			 |    Calls glClearColor(), glClearDepth(), glClear()
			 | ----------------------------------------------------------------------------------
			 */
			virtual void enterFrame();

			/*
			 | ----------------------------------------------------------------------------------
			 |    End the frame of rendering, 
			 |    it should do double buffering at the end
			 |    Calls glFlush();
			 | ----------------------------------------------------------------------------------
			 */
			virtual void endFrame();

			// LIGHTING METHODS
			//virtual bool enableLighting();
			//virtual bool disableLighting();

			// DEPTH TESTING

			//virtual bool enableDepthTest();
			//virtual bool disableDepthTest();

			// SHADERS

			//virtual void enableShaders();
			//virtual void disableShaders();

			//virtual ShadersInterface* shaderFactory(enginecore::ShadersVendor sv);
			virtual void setShader(IShaders* si) { _shader = si; }

			// TEXTURING

			//virtual void enableTexturing();
			//virtual void disableTexturing();

			// BLENDING

			//virtual void enableBlending();
			//virtual void disableBlending();

			//virtual bool checkEnabled(GLenum state);

			// CULLING

			// Calls glEnable(GL_CULL_FACE)
			//virtual void enableCulling();

			// Calls glDisable(GL_CULL_FACE)
			//virtual void disableCulling();

			//virtual void cullMode(GLenum mode);

			int getWidth()const { return _width; }
			int getHeight()const { return _height; }
			void setWidth(int w) { _width = w; }
			void setHeight(int h) { _height = h; }


		private:
			QueryRenderer* _query_renderer;

			/*
			|  ----------------------------------
			|    Copy Constructor
			|  ----------------------------------
			*/
			GLRenderer(const GLRenderer& glrenderer);

			/*
			|  ----------------------------------
			|    Copy operator
			|  ----------------------------------
			*/
			GLRenderer operator=(const GLRenderer& glrenderer);

			/*
			|  ----------------------------------------
			|    Sets OpenGL Renderer
			|    Parameter w - width of the scene
			|    Parameter h - height of the scene
			|    This method calls
			|  ----------------------------------------
			*/
			void setGL(int w, int h);

			/*
			|  ------------------------------------------
			|    Calls glClearColor(r, g, b, a)
			|    In rodeo it's value is glClearColor(black, 1.0) but it is NOT called!
			|  -------------------------------------------
			*/
			bool initGL();

			/*
			|  -----------------------------------------------------------
			|    Initializes Background color for GL
			|    Parameter float red - red value from RGB - MUST BE in <0.0, 1.0> !
			|    Parameter float green - green value from RGB - MUST BE  in <0.0, 1.0> !
			|    Parameter float blue - blue value form RGB - MUST BE in <0.0, 1.0> !
			|    Calls SetGL(int, int), glClearColor(float, float, float, float), glClearDepth(float)
			|  ---------------------------------------------------------------
			*/
			bool initGL(int w, int h, float r, float g, float b, float a);

			/*
			|  -------------------------------------------------------
			|    Calls glFlush()
			|  -------------------------------------------------------
			*/
			//void flush();

			QueryRenderer* getQueryRenderer() const { return _query_renderer; }
		};
	}
}
#endif