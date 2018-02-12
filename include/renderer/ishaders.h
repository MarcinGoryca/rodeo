/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
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
//#ifndef RODEO_RENDERER_ISHADERS_H_
//#define RODEO_RENDERER_ISHADERS_H_
//
//#ifndef RODEO_CORE_CONSTANTS_H_
//#include "core\constants.h"
//#endif
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		enum ShaderType
//		{
//			RODEO_VS,
//			RODEO_FS
//		};
//		class IShaders
//		{
//		public:
//			IShaders() {}
//			virtual ~IShaders() {}
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Loads Shader Program from specified file
//			 |     Parameter ShaderType use: 
//			 |     RODEO_VS (VERTEX SHADER), RODEO_FS (FRAGMENT SHADER)
//			 | ---------------------------------------------------------
//			 */
//			virtual unsigned int loadShaderFromFile(const char* filename, ShaderType st) = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Inits Shaders
//			 | ---------------------------------------------------------
//			 */
//			virtual void init() = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [ Pure Virtual ]
//			 |     Which shader program to use
//			 |     Parameter unsigned int value of a shader program
//			 | ---------------------------------------------------------
//			 */
//			virtual void useShaderProgram(unsigned int shader_program) = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Gets Vertex Shader Id
//			 |     Returns unsigned int vertex shader id
//			 | ---------------------------------------------------------
//			 */
//			virtual unsigned int getVertexShader() const = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Sets Vertex Shader Id
//			 |     Parameter unsigned int new vertex shader id
//			 | ---------------------------------------------------------
//			 */
//			virtual void setVertexShader(core::ui id) = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Gets Fragment Shader Id
//			 |     Returns unsigned int fragment shader id
//			 | ---------------------------------------------------------
//			 */
//			virtual unsigned int getFragmentShader() const = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Sets Fragment Shader Id
//			 |     Parameter unsigned int new fragment shader id
//			 | ---------------------------------------------------------
//			 */
//			virtual void setFragmentShader(core::ui id) = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Gets Vertex Shader Program File
//			 |     Returns const char* string of vertex shader program file
//			 | ---------------------------------------------------------
//			 */
//			virtual const char* getVertexProgramFile() const = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Sets Vertex Shader Program File
//			 |     Parameter const char* new string of vertex shader program file
//			 | ---------------------------------------------------------
//			 */
//			virtual void setVertexProgramFile(const char* vpf) = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Gets Fragment Shader Program File
//			 |     Returns const char* string of fragment shader program file
//			 | ---------------------------------------------------------
//			 */
//			virtual const char* getFragmentProgramFile() const = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Sets Fragment Shader Program File
//			 |     Parameter const char* new string of fragment shader program file
//			 | ---------------------------------------------------------
//			 */
//			virtual void setFragmentProgramFile(const char* fpf) = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Gets Shader Program Id
//			 |     Returns unsigned int shader program id
//			 | ---------------------------------------------------------
//			 */
//			virtual unsigned int getProgram() const = 0;
//
//			/*
//			 | ---------------------------------------------------------
//			 |     [Pure Virtual]
//			 |     Sets Shader Program Id
//			 |     Parameter unsigned int new id for shader program
//			 | ---------------------------------------------------------
//			 */
//			virtual void setProgram(core::ui program) = 0;
//
//		protected:
//			unsigned int _vertex_shader;
//			unsigned int _fragment_shader;
//			unsigned int _program;
//
//			const char* _vertex_program_file;
//			const char* _fragment_program_file;
//		};
//	}
//}
//#endif