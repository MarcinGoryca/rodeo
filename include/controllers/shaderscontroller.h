/*
 |  -----------------------------------
 |     MG Game Engine
 |     [ ShadersController.h ] [ mg\controllers ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CONTROLLERS_SHADERSCONTROLLER_H_
#define MG_CONTROLLERS_SHADERSCONTROLLER_H_

 //#include <string>

#ifndef MG_RENDERER_GL_GLSLSHADERS_H_
#include "renderer\gl\glslshaders.h"
#endif

namespace mg
{
    namespace controllers
    {
		enum ShadersVendor
		{
			MG_GLSL
		};

        class ShadersController
        {
        public:
            ShadersController()
                :_shader(nullptr)
            {}
            ~ShadersController() {}

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
            std::unique_ptr<mg::renderer::IShaders> _shader;
            std::unique_ptr<mg::renderer::GLSLShaders> _glsl_shader;
        };
    }
}
#endif