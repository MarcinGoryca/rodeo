/*
 |  ----------------------------------------------
 |    laura GAME ENGINE
 |    [ QueryRenderer.h ] [ laura\renderer\gl ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef LAURA_RENDERER_QUERYRENDERER_H_
#define LAURA_RENDERER_QUERYRENDERER_H_

#ifndef LAURA_RENDERER_GL_GLCOMMON_H_
#include "glcommon.h"
#endif

#ifndef LAURA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef LAURA_CORE_RENDEREREXCEPTION_H_
#include "core\rendererexception.h"
#endif

namespace laura
{
	namespace renderer
	{
		class QueryRenderer
		{
		public:
			QueryRenderer() {  }
			~QueryRenderer() { reset(); }

			const GLubyte* getVendor()const { return _glvendor; }
			const GLubyte* getRenderer()const { return _glrenderer; }
			const GLubyte* getVersion()const { return _glversion; }
			const GLubyte* getExtensions()const { return _glextensions; }
			void run();

			enum Vendor
			{
				NVIDIA = 1,
				ATI = 2,
				OTHER = 3
			};

			enum Version
			{
				OPENGL_1 = 1,
				OPENGL_2 = 2,
				OPENGL_3 = 3,
				OPENGL_4 = 4
			};

			/**
			 *	TODO:
			 *	1. Check for GL_VENDOR
			 *	2. Check for GL_VERSION
			 *	3. Check for GL_RENDERER
			 *	4. Check for GL_EXTENSIONS
			 *	5. Check for Resolution
			 * 6. Check for Color Mode
			 */

			 // Calls glGetIntegerv(GL_SAMPLE_BUFFERS)<br/>
			 // If the returned value is 1 - there is MULTISAMPLING on this platform
			void checkMultisampling();

		private:
			const GLubyte* _glrenderer;
			const GLubyte* _glvendor;
			const GLubyte* _glversion;
			const GLubyte* _glextensions;

			int _gl21supported;
			int _gl31supported;
			int _gl32supported;
			int _gl33supported;
			int _gl41supported;

			std::string print(std::string s)const;
			bool reset();
		};
	}
}
#endif