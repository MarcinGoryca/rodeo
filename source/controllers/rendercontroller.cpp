/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers\rendercontroller.h"

namespace mona
{
	namespace controllers
	{

		RenderController::RenderController(RendererType renderer)
		{
			switch (renderer)
			{
			case MONA_DX:
			{
				_renderer = new mona::renderer::DxRenderer;
			}
			break;

			case MONA_GL:
			{
				_renderer = new mona::renderer::GLRenderer;
			}
			break;
			}
		}

		//--------------------------------------------------------------------------------------------------
		RenderController::~RenderController()
		{
			if (_renderer != nullptr)
			{
				delete _renderer;
				_renderer = nullptr;
			}
		}
	}
}