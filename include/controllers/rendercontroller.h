/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */
#ifndef LAURA_CONTROLLERS_RENDERCONTROLLER_H_
#define LAURA_CONTROLLERS_RENDERCONTROLLER_H_

#ifndef LAURA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif


#ifndef LAURA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef LAURA_RENDERER_GL_GLRENDERER_H_
#include "renderer\gl\glrenderer.h"
#endif

#ifndef LAURA_RENDERER_DX_DXRENDERER_H_
#include "renderer\dx\dxrenderer.h"
#endif

namespace laura
{
	namespace controllers
	{
		enum RendererType
		{
			// DirectX
			LAURA_DX,
			// OpenGL
			LAURA_GL,
			// Vulcan
			LAURA_VC
		};

		class RenderController : public laura::core::Singleton<RenderController>, public MasterController
		{
		public:
			RenderController(RendererType renderer);

			~RenderController();

			laura::renderer::IRenderer* getRenderer() const
			{
				return _renderer;
			}

		private:
			laura::renderer::IRenderer* _renderer;

			RenderController() {}

			/*
			 |  ------------------------------------------------------
			 |    COPY CONSTRUCTOR
			 |  ------------------------------------------------------
			 */
			RenderController(RenderController& copy);

			/*
			 |  ------------------------------------------------------
			 |    COPY OPERATOR
			 |  ------------------------------------------------------
			 */
			RenderController operator=(RenderController& copy);


		};
	}
}
#endif