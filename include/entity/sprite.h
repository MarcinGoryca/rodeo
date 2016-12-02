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
//#ifndef LAURA_ENTITY_SPRITE_H_
//#define LAURA_ENTITY_SPRITE_H_
//
//#ifndef LAURA_ENTITY_ENTITY_H_
//#include "entity\entity.h"
//#endif
//
//namespace laura
//{
//    namespace entity
//    {
//        class Sprite : public Entity
//        {
//        public:
//            Sprite()
//                :Entity("", "sprite"),
//				_width(0),
//				_height(0)
//            {}
//
//            virtual ~Sprite() {}
//
//            virtual void render();
//            virtual void update();
//
//            /*
//			 | ----------------------------------------------
//			 |    Gets Width value of the Sprite
//             |    Returns unsigned int width
//			 | ----------------------------------------------
//			 */
//            unsigned int getWidth() const { return _width; }
//
//            /*
//			 | ----------------------------------------------
//			 |    Gets Height value of the Sprite
//             |    Returns unsigned int height
//			 | ----------------------------------------------
//			 */
//            unsigned int getHeight() const { return _height; }
//
//            /*
//			 | ----------------------------------------------
//			 |    Sets Width of the Sprite
//			 | ----------------------------------------------
//			 */
//            void setWidth(unsigned int width) { _width = width; }
//
//            /*
//			 | -----------------------------------------------
//			 |    Sets Height of the Sprite
//			 | -----------------------------------------------
//			 */
//            void setHeight(unsigned int height) { _height = height; }
//
//        private:
//            unsigned int _width;
//            unsigned int _height;
//
//			void init();
//        };
//    }
//}
//#endif