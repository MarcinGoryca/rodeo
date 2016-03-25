/*
 |  -----------------------------------
 |     MG GAME ENGINE
 |     [ TextureController.h ] [ mg\core ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_TEXTURECONTROLLER_H_
#define MG_CORE_TEXTURECONTROLLER_H_

#ifndef MG_CORE_SINGLETON_H
#include "core\singleton.h"
#endif

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef MG_RENDERER_TEXTURE_H_
#include "renderer\texture.h"
#endif

#ifndef VECTOR_H_
#include <vector>
#endif

namespace mg
{
    namespace controllers
    {
        class TextureController : public Singleton<TextureController>
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
            void load(mg::renderer::Image* img, const char* filename, unsigned int& tid);

            void load();

            unsigned int loadDDS(const char* filename);

            unsigned int loadTGA(const char* filename);

            mg::renderer::Texture* getTexture() const { return texture_; }

            static int getTextureCount() { return s_texture_count_; }

        private:
            void clean();

            void reset();

            // Texture object 
            mg::renderer::Texture* texture_;

            // Counting How many textures are loaded
            static int s_texture_count_;

            // Maximum number of textures to load, this can be changed freely 
            static const unsigned int S_MAX_TEXTURES = 100;

            // Unique Id of a texture
            unsigned int texture_id_[S_MAX_TEXTURES];

            mg::renderer::Image* image_data_[S_MAX_TEXTURES];

            std::vector<unsigned int> texObj_;
        };
    }    // end of core namespace
}    // end of mg namespace
#endif