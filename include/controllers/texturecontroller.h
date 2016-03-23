/*
 |  -----------------------------------
 |     MG GAME ENGINE
 |     [ TextureManager.h ] [ mg\core ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_TEXTUREMANAGER_H_
#define MG_CORE_TEXTUREMANAGER_H_

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
    namespace core
    {
        class TextureManager : public Singleton<TextureManager>
        {
        public:
            TextureManager()
            {
                reset();
            }

            ~TextureManager()
            {
                clean();
            }

            void bind(ui& tid);

            //Parameter texid is an id of actually loaded texture,
            // from 1 to MAX_TEXTURES
            void load(mg::renderer::Image* img, const char* filename, ui& tid);

            void load();

            ui loadDDS(const char* filename);

            ui loadTGA(const char* filename);

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
            static const ui S_MAX_TEXTURES = 100;

            // Unique Id of a texture
            ui texture_id_[S_MAX_TEXTURES];

            mg::renderer::Image* image_data_[S_MAX_TEXTURES];

            std::vector<ui> texObj_;
        };
    }    // end of core namespace
}    // end of mg namespace
#endif