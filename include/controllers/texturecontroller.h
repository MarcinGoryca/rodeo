/*
 |  -----------------------------------
 |     LAURA GAME ENGINE
 |     [ TextureController.h ] [ laura\controllers ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CONTROLLERS_TEXTURECONTROLLER_H_
#define LAURA_CONTROLLERS_TEXTURECONTROLLER_H_

#ifndef LAURA_CORE_SINGLETON_H
#include "core\singleton.h"
#endif

#ifndef LAURA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef LAURA_RENDERER_TEXTURE_H_
#include "renderer\texture.h"
#endif

#ifndef VECTOR_H_
#include <vector>
#endif

namespace laura
{
    namespace controllers
    {
        class TextureController : public laura::core::Singleton<TextureController>
        {
        public:
            TextureController()
            {
                reset();
            }

            ~TextureController()
            {
                clean();
            }

            void bind(unsigned int& tid);

            //Parameter texid is an id of actually loaded texture,
            // from 1 to MAX_TEXTURES
            void load(laura::renderer::Image* ilaura, const char* filename, unsigned int& tid);

            void load();

            unsigned int loadDDS(const char* filename);

            unsigned int loadTGA(const char* filename);

            laura::renderer::Texture* getTexture() const { return _texture; }

            static int getTextureCount() { return _s_texture_count; }

        private:
			// Texture object 
			laura::renderer::Texture* _texture;

			// Counting How many textures are loaded
			static int _s_texture_count;

			// Maximum number of textures to load, this can be changed freely 
			static const unsigned int _S_MAX_TEXTURES = 100;

			// Unique Id of a texture
			unsigned int _texture_id[_S_MAX_TEXTURES];

			laura::renderer::Image* _image_data[_S_MAX_TEXTURES];

			std::vector<unsigned int> _texObj;

            void clean();
            void reset();
        };
    }
}
#endif