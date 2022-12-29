/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
//#ifndef RODEO_RENDERER_GLSLSHADERS_H_
//#define RODEO_RENDERER_GLSLSHADERS_H_
//
//#ifndef RODEO_RENDERER_GL_GLCOMMON_H_
//#include "glcommon.h"
//#endif
//
//#ifndef RODEO_RENDERER_ISHADERS_H_
//#include "renderer\ishaders.h"
//#endif
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		class GLSLShaders : public IShaders
//		{
//		public:
//			GLSLShaders()
//			{}
//
//			virtual ~GLSLShaders()
//			{}
//
//			/*
//			 |  ----------------------------------------------------
//			 |    Loads Shader from File
//			 |    Parameter const char* string of shader filename
//			 |    Parameter ShaderType - RODEO_VS, RODEO_FS
//			 |    Returns unsigned int shader program id
//			 |  ----------------------------------------------------
//			 */
//			virtual unsigned int loadShaderFromFile(const char* filename, ShaderType st);
//
//			/*
//			 |  ----------------------------------------------------
//			 |    Loads Shaders from files
//			 |  ----------------------------------------------------
//			 */
//			void loadShaders(std::string vertex_file, std::string fragment_file);
//
//			/*
//			 |  ----------------------------------------------------
//			 |    Inits Shaders
//			 |  ----------------------------------------------------
//			 */
//			virtual void init();
//
//			/*
//			 |  ----------------------------------------------------
//			 |    Uses ShaderProgram
//			 |  ----------------------------------------------------
//			 */
//			virtual void useShaderProgram(unsigned int shader_program);
//
//			virtual const char* getVertexProgramFile() const
//			{
//				return _vertex_program_file;
//			}
//
//			virtual void setVertexProgramFile(const char* vpf)
//			{
//				_vertex_program_file = vpf;
//			}
//
//			virtual const char* getFragmentProgramFile() const
//			{
//				return _fragment_program_file;
//			}
//
//			virtual void setFragmentProgramFile(const char* fpf)
//			{
//				_fragment_program_file = fpf;
//			}
//
//			virtual unsigned int getVertexShader() const
//			{
//				return _vertex_shader;
//			}
//
//			virtual void setVertexShader(core::ui id)
//			{
//				_vertex_shader = id;
//			}
//
//			virtual unsigned int getFragmentShader() const
//			{
//				return _fragment_shader;
//			}
//
//			virtual void setFragmentShader(core::ui id)
//			{
//				_fragment_shader = id;
//			}
//
//			virtual unsigned int getProgram() const { return _program; }
//
//			virtual void setProgram(unsigned int program) { _program = program; }
//
//		private:
//			unsigned int _program;
//
//			/*
//			 |  ---------------------------------
//			 |    Copy constructor
//			 |  ---------------------------------
//			 */
//			GLSLShaders(const GLSLShaders& copy);
//
//			/*
//			 |  ---------------------------------
//			 |    Copy operator
//			 |  ---------------------------------
//			 */
//			GLSLShaders operator=(const GLSLShaders& copy);
//
//			/*
//			 |  -----------------------------------
//			 |    Helper method to read shader file
//			 |  -----------------------------------
//			 */
//			char* readFile(const char* file);
//		};
//	}
//}
//#endif