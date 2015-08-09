/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_SHADERSMANAGER_H_
#define MG_CORE_SHADERSMANAGER_H_

//#include <string>

#ifndef MG_RENDERER_GL_GLSLSHADERS_H_
#include "renderer\gl\glslshaders.h"
#endif

namespace mg
{
namespace core
{
class ShadersManager
{
public: 
    ShadersManager()
    :shader_(nullptr)
    {}
    ~ShadersManager(){}

    // Creates Shaders
    // Parameter ShadersVendor - CG, GLSL
    // Parameter string filename of the vertex shader
    // Parameter string filename of the fragment shader
    // This method creates, loads and initializes Shaders,
    //    no further operations needed
    void create(ShadersVendor vendor, std::string vertex_shader, std::string fragment_shader);

    // Loads Shaders from files
    // Parameter string vertex_shader file name
    // Parameter string fragment_shader file name
    void load(std::string vertex_shader, std::string fragment_shader);

private:
    // Inits Shaders
    void init();
public: 
    std::unique_ptr<mg::renderer::IShaders> shader_;
    std::unique_ptr<mg::renderer::GLSLShaders >glsl_shader_;
};
}    // end of core namespace
}    // end of mg namespace
#endif