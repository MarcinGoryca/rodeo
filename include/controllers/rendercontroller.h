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
//#ifndef RODEO_CONTROLLERS_RENDERCONTROLLER_H_
//#define RODEO_CONTROLLERS_RENDERCONTROLLER_H_
//
//#ifndef RODEO_CONTROLLERS_MASTERCONTROLLER_H_
//#include "controllers\mastercontroller.h"
//#endif
//
//
//#ifndef RODEO_CORE_SINGLETON_H_
//#include "core\singleton.h"
//#endif
//
//#ifndef RODEO_RENDERER_GL_GLRENDERER_H_
//#include "renderer\gl\glrenderer.h"
//#endif
//
//#ifndef RODEO_RENDERER_DX_DXRENDERER_H_
//#include "renderer\dx\dxrenderer.h"
//#endif
//
//namespace rodeo
//{
//	namespace controllers
//	{
//		enum RendererType
//		{
//			// DirectX
//			RODEO_DX,
//			// OpenGL
//			RODEO_GL,
//			// Vulcan
//			RODEO_VC
//		};
//
//		class RenderController : public rodeo::core::Singleton<RenderController>, public MasterController
//		{
//		public:
//			RenderController(RendererType renderer);
//
//			~RenderController();
//
//			rodeo::renderer::IRenderer* getRenderer() const
//			{
//				return _renderer;
//			}
//
//		private:
//			rodeo::renderer::IRenderer* _renderer;
//
//			RenderController() {}
//
//			/*
//			 |  ------------------------------------------------------
//			 |    COPY CONSTRUCTOR
//			 |  ------------------------------------------------------
//			 */
//			RenderController(RenderController& copy);
//
//			/*
//			 |  ------------------------------------------------------
//			 |    COPY OPERATOR
//			 |  ------------------------------------------------------
//			 */
//			RenderController operator=(RenderController& copy);
//
//
//		};
//	}
//}
//#endif