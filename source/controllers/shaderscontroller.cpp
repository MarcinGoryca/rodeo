/*
----------------------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers\ShadersController.h"

namespace laura
{
	namespace controllers
	{
		void ShadersController::create(ShadersVendor vendor, std::string vertex_shader, std::string fragment_shader)
		{
			switch (vendor)
			{
			case LAURA_GLSL:
			{
				_glsl_shader = std::unique_ptr<renderer::GLSLShaders>(new renderer::GLSLShaders);
				_glsl_shader->setVertexShader(_glsl_shader->loadShaderFromFile(vertex_shader.c_str(), laura::renderer::LAURA_VS));
				_glsl_shader->setFragmentShader(_glsl_shader->loadShaderFromFile(fragment_shader.c_str(), laura::renderer::LAURA_FS));
				_glsl_shader->init();
			}
			}
		}

		//--------------------------------------------------------------------------------------------------
		void ShadersController::load(std::string vertex_shader, std::string fragment_shader)
		{

		}
	}
}