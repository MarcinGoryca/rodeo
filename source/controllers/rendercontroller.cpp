/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers\rendercontroller.h"

namespace mg
{
	namespace controllers
	{

		RenderController::RenderController(RendererType renderer)
		{
			switch (renderer)
			{
			case MG_DX:
			{
				_renderer = new renderer::DxRenderer;
			}
			break;

			case MG_GL:
			{
				_renderer = new renderer::GLRenderer;
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