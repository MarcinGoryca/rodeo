/*
 |  ----------------------------------------------
 |    MG GAME ENGINE 
 |    [ GLSLShaders.h ] [ mg\renderere\gl ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef MG_RENDERER_GLSLSHADERS_H_
#define MG_RENDERER_GLSLSHADERS_H_

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "glcommon.h"
#endif

#ifndef MG_RENDERER_ISHADERS_H_
#include "renderer\ishaders.h"
#endif

namespace mg
{
namespace renderer
{
class GLSLShaders : public IShaders
{
public:
    GLSLShaders()
    {}

    virtual ~GLSLShaders()
    {}

    /*
	 |  ----------------------------------------------------
	 |    Loads Shader from File
     |    Parameter const char* string of shader filename
     |    Parameter ShaderType - MG_VS, MG_FS
     |    Returns unsigned int shader program id
	 |  ----------------------------------------------------
	 */
    virtual core::ui loadShaderFromFile(const char* filename, core::ShaderType st);

    /*
	 |  ----------------------------------------------------
	 |    Loads Shaders from files
	 |  ----------------------------------------------------
	 */
    void loadShaders(std::string vertex_file, std::string fragment_file);

    /*
	 |  ----------------------------------------------------
	 |    Inits Shaders
	 |  ----------------------------------------------------
	 */
    virtual void init();

    /*
	 |  ----------------------------------------------------
	 |    Uses ShaderProgram
	 |  ----------------------------------------------------
	 */
    virtual void useShaderProgram(core::ui shader_program);
  
    virtual const char* getVertexProgramFile() const 
    {
        return vertex_program_file_;
    }

    virtual void setVertexProgramFile(const char* vpf)
    {
        vertex_program_file_ = vpf;
    }

    virtual const char* getFragmentProgramFile() const
    {
        return fragment_program_file_;
    }

    virtual void setFragmentProgramFile(const char* fpf)
    {
        fragment_program_file_ = fpf;
    }

    virtual core::ui getVertexShader() const
    {
        return vertex_shader_;
    }

    virtual void setVertexShader(core::ui id)
    {
        vertex_shader_ = id;
    }

    virtual core::ui getFragmentShader() const
    {
        return fragment_shader_;
    }

    virtual void setFragmentShader(core::ui id)
    {
        fragment_shader_ = id;
    }

    virtual core::ui getProgram() const { return program_; }

    virtual void setProgram(core::ui program) { program_ = program; }

private:
    /*
	 |  ---------------------------------
	 |    Copy constructor
	 |  ---------------------------------
	 */
    GLSLShaders(const GLSLShaders& copy);

    /*
	 |  ---------------------------------
	 |    Copy operator
	 |  ---------------------------------
	 */
    GLSLShaders operator=(const GLSLShaders& copy);

    /*
	 |  -----------------------------------
	 |    Helper method to read shader file
	 |  -----------------------------------
	 */
    char* readFile(const char* file);

    core::ui program_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif