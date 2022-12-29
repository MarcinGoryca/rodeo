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
//#ifndef RODEO_RENDERER_QUERYRENDERER_H_
//#define RODEO_RENDERER_QUERYRENDERER_H_
//
//#ifndef RODEO_RENDERER_GL_GLCOMMON_H_
//#include "glcommon.h"
//#endif
//
//#ifndef RODEO_CORE_CONSTANTS_H_
//#include "core\constants.h"
//#endif
//
//#ifndef RODEO_CORE_RENDEREREXCEPTION_H_
//#include "core\rendererexception.h"
//#endif
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		class QueryRenderer
//		{
//		public:
//			QueryRenderer() {  }
//			~QueryRenderer() { reset(); }
//
//			const GLubyte* getVendor()const { return _glvendor; }
//			const GLubyte* getRenderer()const { return _glrenderer; }
//			const GLubyte* getVersion()const { return _glversion; }
//			const GLubyte* getExtensions()const { return _glextensions; }
//			void run();
//
//			enum Vendor
//			{
//				NVIDIA = 1,
//				ATI = 2,
//				OTHER = 3
//			};
//
//			enum Version
//			{
//				OPENGL_1 = 1,
//				OPENGL_2 = 2,
//				OPENGL_3 = 3,
//				OPENGL_4 = 4
//			};
//
//			/**
//			 *	TODO:
//			 *	1. Check for GL_VENDOR
//			 *	2. Check for GL_VERSION
//			 *	3. Check for GL_RENDERER
//			 *	4. Check for GL_EXTENSIONS
//			 *	5. Check for Resolution
//			 * 6. Check for Color Mode
//			 */
//
//			 // Calls glGetIntegerv(GL_SAMPLE_BUFFERS)<br/>
//			 // If the returned value is 1 - there is MULTISAMPLING on this platform
//			void checkMultisampling();
//
//		private:
//			const GLubyte* _glrenderer;
//			const GLubyte* _glvendor;
//			const GLubyte* _glversion;
//			const GLubyte* _glextensions;
//
//			int _gl21supported;
//			int _gl31supported;
//			int _gl32supported;
//			int _gl33supported;
//			int _gl41supported;
//
//			std::string print(std::string s)const;
//			bool reset();
//		};
//	}
//}
//#endif