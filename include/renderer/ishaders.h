/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_ISHADERS_H_
#define MG_RENDERER_ISHADERS_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace mg
{
namespace renderer
{
class IShaders
{
public:
    IShaders(){}
    virtual ~IShaders(){}

    // [Pure Virtual]
    // Loads Shader Program from specified file
    // Parameter ShaderType use JENNIE_VS (VERTEX SHADER), JENNIE_FS (FRAGMENT SHADER)
    virtual core::ui loadShaderFromFile(const char* filename, core::ShaderType st) = 0;

    // [Pure Virtual]
    // Inits Shaders
    virtual void init() = 0;

    virtual void useShaderProgram(core::ui shader_program) = 0;

    // [Pure Virtual]
    // Gets Vertex Shader Id
    // Returns unsigned int vertex shader id
    virtual core::ui getVertexShader() const = 0;

    // [Pure Virtual]
    // Sets Vertex Shader Id
    // Parameter unsigned int new vertex shader id
    virtual void setVertexShader(core::ui id) = 0;

    // [Pure Virtual]
    // Gets Fragment Shader Id
    // Returns unsigned int fragment shader id
    virtual core::ui getFragmentShader() const = 0;

    // [Pure Virtual]
    // Sets Fragment Shader Id
    // Parameter unsigned int new fragment shader id
    virtual void setFragmentShader(core::ui id) = 0;

    // [Pure Virtual]
    // Gets Vertex Shader Program File
    // Returns const char* string of vertex shader program file
    virtual const char* getVertexProgramFile() const = 0;

    // [Pure Virtual]
    // Sets Vertex Shader Program File
    // Parameter const char* new string of vertex shader program file
    virtual void setVertexProgramFile(const char* vpf) = 0;

    // [Pure Virtual]
    // Gets Fragment Shader Program File
    // Returns const char* string of fragment shader program file
    virtual const char* getFragmentProgramFile() const = 0;

    // [Pure Virtual]
    // Sets Fragment Shader Program File
    // Parameter const char* new string of fragment shader program file
    virtual void setFragmentProgramFile(const char* fpf) = 0;

    // [Pure Virtual]
    // Gets Shader Program Id
    // Returns unsigned int shader program id
    virtual core::ui getProgram() const = 0;

    // [Pure Virtual]
    // Sets Shader Program Id
    // Parameter unsigned int new id for shader program
    virtual void setProgram(core::ui program) = 0;

protected:
    core::ui vertex_shader_;
    core::ui fragment_shader_;
    core::ui program_;

    const char* vertex_program_file_;
    const char* fragment_program_file_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif