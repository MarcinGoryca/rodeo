/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\shadersmanager.h"

namespace mg
{
namespace core
{
void ShadersManager::create(ShadersVendor vendor, std::string vertex_shader, std::string fragment_shader)
{
    switch(vendor)
    {
    case MG_GLSL:
        {
            glsl_shader_ = std::unique_ptr<renderer::GLSLShaders>(new renderer::GLSLShaders);
            glsl_shader_->setVertexShader(glsl_shader_->loadShaderFromFile(vertex_shader.c_str(), MG_VS));
            glsl_shader_->setFragmentShader(glsl_shader_->loadShaderFromFile(fragment_shader.c_str(), MG_FS));
            glsl_shader_->init();
        }
    }
}

//--------------------------------------------------------------------------------------------------
void ShadersManager::load(std::string vertex_shader, std::string fragment_shader)
{

}
}    // end of core namespace
}    // end of mg namespace