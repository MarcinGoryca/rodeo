/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */
#ifndef MG_CORE_RENDERCONTROLLER_H_
#define MG_CORE_RENDERCONTROLLER_H_

#ifndef MG_CORE_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif


#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_RENDERER_GL_GLRENDERER_H_
#include "renderer\gl\glrenderer.h"
#endif

#ifndef MG_RENDERER_DX_DXRENDERER_H_
#include "renderer\dx\dxrenderer.h"
#endif

namespace mg
{
	namespace core
	{
		class RenderController : public Singleton<RenderController>, public MasterController
		{
		public:
			RenderController(RendererType renderer);

			~RenderController();

			mg::renderer::IRenderer* getRenderer() const
			{
				return renderer_;
			}

		private:
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

			mg::renderer::IRenderer* renderer_;
		};
	}    // end of core namespace
}    // end of mg namespace
#endif    // MG_CORE_RENDERCONTROLLER_H_