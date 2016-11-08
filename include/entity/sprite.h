/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    [ Sprite.h ] [ laura\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_ENTITY_SPRITE_H_
#define LAURA_ENTITY_SPRITE_H_

#ifndef LAURA_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace laura
{
    namespace entity
    {
        class Sprite : public Entity
        {
        public:
            Sprite()
                :Entity("", "sprite"),
				_width(0),
				_height(0)
            {}

            virtual ~Sprite() {}

            virtual void render();
            virtual void update();

            /*
			 | ----------------------------------------------
			 |    Gets Width value of the Sprite
             |    Returns unsigned int width
			 | ----------------------------------------------
			 */
            unsigned int getWidth() const { return _width; }

            /*
			 | ----------------------------------------------
			 |    Gets Height value of the Sprite
             |    Returns unsigned int height
			 | ----------------------------------------------
			 */
            unsigned int getHeight() const { return _height; }

            /*
			 | ----------------------------------------------
			 |    Sets Width of the Sprite
			 | ----------------------------------------------
			 */
            void setWidth(unsigned int width) { _width = width; }

            /*
			 | -----------------------------------------------
			 |    Sets Height of the Sprite
			 | -----------------------------------------------
			 */
            void setHeight(unsigned int height) { _height = height; }

        private:
            unsigned int _width;
            unsigned int _height;

			void init();
        };
    }
}
#endif