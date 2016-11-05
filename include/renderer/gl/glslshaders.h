/*
 |  ----------------------------------------------
 |    laura GAME ENGINE
 |    [ GLSLShaders.h ] [ laura\renderere\gl ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef LAURA_RENDERER_GLSLSHADERS_H_
#define LAURA_RENDERER_GLSLSHADERS_H_

#ifndef LAURA_RENDERER_GL_GLCOMMON_H_
#include "glcommon.h"
#endif

#ifndef LAURA_RENDERER_ISHADERS_H_
#include "renderer\ishaders.h"
#endif

namespace laura
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
			 |    Parameter ShaderType - LAURA_VS, LAURA_FS
			 |    Returns unsigned int shader program id
			 |  ----------------------------------------------------
			 */
			virtual unsigned int loadShaderFromFile(const char* filename, ShaderType st);

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
			virtual void useShaderProgram(unsigned int shader_program);

			virtual const char* getVertexProgramFile() const
			{
				return _vertex_program_file;
			}

			virtual void setVertexProgramFile(const char* vpf)
			{
				_vertex_program_file = vpf;
			}

			virtual const char* getFragmentProgramFile() const
			{
				return _fragment_program_file;
			}

			virtual void setFragmentProgramFile(const char* fpf)
			{
				_fragment_program_file = fpf;
			}

			virtual unsigned int getVertexShader() const
			{
				return _vertex_shader;
			}

			virtual void setVertexShader(core::ui id)
			{
				_vertex_shader = id;
			}

			virtual unsigned int getFragmentShader() const
			{
				return _fragment_shader;
			}

			virtual void setFragmentShader(core::ui id)
			{
				_fragment_shader = id;
			}

			virtual unsigned int getProgram() const { return _program; }

			virtual void setProgram(unsigned int program) { _program = program; }

		private:
			unsigned int _program;

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
		};
	}
}
#endif