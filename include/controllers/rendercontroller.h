/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */
#ifndef MONA_CONTROLLERS_RENDERCONTROLLER_H_
#define MONA_CONTROLLERS_RENDERCONTROLLER_H_

#ifndef MONA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif


#ifndef MONA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MONA_RENDERER_GL_GLRENDERER_H_
#include "renderer\gl\glrenderer.h"
#endif

#ifndef MONA_RENDERER_DX_DXRENDERER_H_
#include "renderer\dx\dxrenderer.h"
#endif

namespace mona
{
	namespace controllers
	{
		enum RendererType
		{
			MONA_DX,
			MONA_GL
		};

		class RenderController : public mona::core::Singleton<RenderController>, public MasterController
		{
		public:
			RenderController(RendererType renderer);

			~RenderController();

			mona::renderer::IRenderer* getRenderer() const
			{
				return _renderer;
			}

		private:
			mona::renderer::IRenderer* _renderer;

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