/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\gl\glslshaders.h"

using namespace mona::core;

namespace mona
{
	namespace renderer
	{
		ui GLSLShaders::loadShaderFromFile(const char* file, ShaderType st)
		{
			switch (st)
			{
			case 0: // VERTEX_SHADER (RODEO_VS)
			{
				setVertexProgramFile(file);
				const char* source = readFile(file);
				if (source == NULL)
				{
					//TODO
					//Exception Handling
					return 0;
				}
				else
				{
					_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
					glShaderSource(_vertex_shader, 1, &source, NULL);
					free((void*)source);
					glCompileShader(_vertex_shader);
					GLint compile_ok = GL_FALSE;
					glGetShaderiv(_vertex_shader, GL_COMPILE_STATUS, &compile_ok);

					if (compile_ok == GL_FALSE)
					{
						//TODO
						//Exception Handling
						glDeleteShader(_vertex_shader);
						return 0;
					}
					return _vertex_shader;
				}
			}
			break;

			case 1: //FRAGMENT_SHADER (RODEO_FS)
			{
				setFragmentProgramFile(file);
				const char* source = readFile(file);
				if (source == NULL)
				{
					//TODO
					//Exception Handling
					return 0;
				}
				else
				{
					_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
					glShaderSource(_fragment_shader, 1, &source, NULL);
					free((void*)source);
					glCompileShader(_fragment_shader);
					GLint compile_ok = GL_FALSE;
					glGetShaderiv(_fragment_shader, GL_COMPILE_STATUS, &compile_ok);

					if (compile_ok == GL_FALSE)
					{
						glDeleteShader(_fragment_shader);
						return 0;
					}
					return _fragment_shader;
				}
			}
			break;

			default:
				//TODO 
				//Exception Handling
				return 0;
				break;
			}
		}

		// ---- //
		void GLSLShaders::loadShaders(std::string vertex_file, std::string fragment_file)
		{
			setVertexProgramFile(vertex_file.c_str());
			try {
				const char* source = readFile(vertex_file.c_str());
				if (source == NULL)
				{
					throw - 1;
				}
				else {
					_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
					glShaderSource(_vertex_shader, 1, &source, NULL);
					free((void*)source);
					glCompileShader(_vertex_shader);
					GLint compile_ok = GL_FALSE;
					glGetShaderiv(_vertex_shader, GL_COMPILE_STATUS, &compile_ok);
					if (compile_ok == GL_FALSE)
					{
						glDeleteShader(_vertex_shader);
					}
				}
			}
			catch (...) {}
			setFragmentProgramFile(fragment_file.c_str());
			try {
				const char* source = readFile(fragment_file.c_str());
				if (source == NULL)
				{
					throw - 1;
				}
				else
				{
					_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
					glShaderSource(_fragment_shader, 1, &source, NULL);
					free((void*)source);
					glCompileShader(_fragment_shader);
					GLint compile_ok = GL_FALSE;
					glGetShaderiv(_fragment_shader, GL_COMPILE_STATUS, &compile_ok);

					if (compile_ok == GL_FALSE)
					{
						glDeleteShader(_fragment_shader);
					}
				}
			}
			catch (...) {}
		}

		/**
		 *
		 */

		void GLSLShaders::init()
		{
			GLint link_ok = GL_FALSE;
			_program = glCreateProgram();
			glAttachShader(_program, getVertexShader());
			glAttachShader(_program, getFragmentShader());
			glLinkProgram(_program);
			glGetProgramiv(_program, GL_LINK_STATUS, &link_ok);

			if (!link_ok)
			{
				MessageBox(NULL, L"GLRenderer: LinkProgram failed...", L"JENNIE GAME ENGINE", MB_OK);
			}
		}

		// ---- //
		void GLSLShaders::useShaderProgram(ui shader_program)
		{
			glUseProgram(shader_program);
		}

		// ---- [ private ] --- //
		char* GLSLShaders::readFile(const char* file)
		{
			FILE* input = NULL;
			fopen_s(&input, file, "rb");
			if (input == NULL)
				return NULL;

			if (fseek(input, 0, SEEK_END) == -1) return NULL;
			long size = ftell(input);
			if (size == -1) return NULL;
			if (fseek(input, 0, SEEK_SET) == -1) return NULL;

			char* content = new char[size + 1];
			if (content == NULL) return NULL;

			fread(content, 1, (size_t)size, input);
			if (ferror(input))
			{
				delete content;
				return NULL;
			}
			fclose(input);
			content[size] = '\0';
			return content;
		}
	}
}