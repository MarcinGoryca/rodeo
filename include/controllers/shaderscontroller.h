/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
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
//
//#ifndef LAURA_CONTROLLERS_SHADERSCONTROLLER_H_
//#define LAURA_CONTROLLERS_SHADERSCONTROLLER_H_
//
// //#include <string>
//
//#ifndef LAURA_RENDERER_GL_GLSLSHADERS_H_
//#include "renderer\gl\glslshaders.h"
//#endif
//
//namespace laura
//{
//    namespace controllers
//    {
//		enum ShadersVendor
//		{
//			LAURA_GLSL
//		};
//
//        class ShadersController
//        {
//        public:
//            ShadersController()
//                :_shader(nullptr)
//            {}
//            ~ShadersController() {}
//
//            // Creates Shaders
//            // Parameter ShadersVendor - CG, GLSL
//            // Parameter string filename of the vertex shader
//            // Parameter string filename of the fragment shader
//            // This method creates, loads and initializes Shaders,
//            //    no further operations needed
//            void create(ShadersVendor vendor, std::string vertex_shader, std::string fragment_shader);
//
//            // Loads Shaders from files
//            // Parameter string vertex_shader file name
//            // Parameter string fragment_shader file name
//            void load(std::string vertex_shader, std::string fragment_shader);
//
//        private:
//            // Inits Shaders
//            void init();
//        public:
//            std::unique_ptr<laura::renderer::IShaders> _shader;
//            std::unique_ptr<laura::renderer::GLSLShaders> _glsl_shader;
//        };
//    }
//}
//#endif