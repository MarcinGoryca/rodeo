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
//#ifndef LAURA_CONTROLLERS_TEXTURECONTROLLER_H_
//#define LAURA_CONTROLLERS_TEXTURECONTROLLER_H_
//
//#ifndef LAURA_CORE_SINGLETON_H
//#include "core\singleton.h"
//#endif
//
//#ifndef LAURA_CORE_CONSTANTS_H_
//#include "core\constants.h"
//#endif
//
//#ifndef LAURA_RENDERER_TEXTURE_H_
//#include "renderer\texture.h"
//#endif
//
//#ifndef VECTOR_H_
//#include <vector>
//#endif
//
//namespace laura
//{
//    namespace controllers
//    {
//        class TextureController : public laura::core::Singleton<TextureController>
//        {
//        public:
//            TextureController()
//            {
//                reset();
//            }
//
//            ~TextureController()
//            {
//                clean();
//            }
//
//            void bind(unsigned int& tid);
//
//            //Parameter texid is an id of actually loaded texture,
//            // from 1 to MAX_TEXTURES
//            void load(laura::renderer::Image* ilaura, const char* filename, unsigned int& tid);
//
//            void load();
//
//            unsigned int loadDDS(const char* filename);
//
//            unsigned int loadTGA(const char* filename);
//
//            laura::renderer::Texture* getTexture() const { return _texture; }
//
//            static int getTextureCount() { return _s_texture_count; }
//
//        private:
//			// Texture object 
//			laura::renderer::Texture* _texture;
//
//			// Counting How many textures are loaded
//			static int _s_texture_count;
//
//			// Maximum number of textures to load, this can be changed freely 
//			static const unsigned int _S_MAX_TEXTURES = 100;
//
//			// Unique Id of a texture
//			unsigned int _texture_id[_S_MAX_TEXTURES];
//
//			laura::renderer::Image* _image_data[_S_MAX_TEXTURES];
//
//			std::vector<unsigned int> _texObj;
//
//            void clean();
//            void reset();
//        };
//    }
//}
//#endif