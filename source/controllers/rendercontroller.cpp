/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers\rendercontroller.h"

namespace laura
{
	namespace controllers
	{

		RenderController::RenderController(RendererType renderer)
		{
			switch (renderer)
			{
			case LAURA_DX:
			{
				_renderer = new laura::renderer::DxRenderer;
			}
			break;

			case LAURA_GL:
			{
				_renderer = new laura::renderer::GLRenderer;
			}
			break;
			}
			case LAURA_VC:
			{
				_renderer = new laura::renderer::VcRenderer;
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