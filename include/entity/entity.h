/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    [ Entity.h ] [ mona\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_ENTITY_ENTITY_H_
#define MONA_ENTITY_ENTITY_H_

#ifndef MONA_ENTITY_OBJECT_H_
#include "object.h"
#endif

#ifndef MONA_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef MONA_RENDERER_MATERIAL_H_
#include "renderer\material.h"
#endif

#ifndef MONA_MATH_AABB_H_
#include "math\aabb.h"
#endif

#ifndef MONA_MATH_TRANSFORM_H_
#include "math\transform.h"
#endif

namespace mona
{
    namespace entity
    {
        class Entity : public Object
        {
        public:
            Entity()
                :Object(),
                _renderable(true)
            {
                init();
            }

            // ---- //
            explicit Entity(std::string name)
                :Object(name)
            {
                init();
            }

            // ---- //
            Entity(std::string name, std::string type)
                :Object(name, type)
            {
                init();
            }

            // --- //
            virtual ~Entity()
            {
                clear();
            }

            virtual void draw();
            virtual void update(float dt);
            virtual void init();
            virtual void clear();

            virtual void release();

            //virtual void setColor(enginerenderer::Colors& rgb);

			/*
			 | ------------------------------------------------
			 |    Get AABB Box
			 |    Returns AABB object
			 | ------------------------------------------------
			 */
			mona::math::AABB getAabb() const
			{
				return _box;
			}

			/*
			 | ------------------------------------------------
			 |    Get Transform object
			 | ------------------------------------------------
			 */
			mona::math::Transform getTransform() const
			{
				return _transform;
			}

			/*
			 | ------------------------------------------------
			 |    Get Renderable
			 |    Returns bool
			 | ------------------------------------------------
			 */
			bool getRenderable() const
			{
				return _renderable;
			}

			/*
			 | ------------------------------------------------
			 |    Set AABB box
			 | ------------------------------------------------
			 */
			void setAabb(mona::math::AABB box)
			{
				_box = box;
			}

			/*
			 | ------------------------------------------------
			 |    Set Transform
			 | ------------------------------------------------
			 */
			void setTransform(mona::math::Transform transform)
			{
				_transform = transform;
			}

			/*
			 | -------------------------------------------------
			 |    Set Renderable
			 | -------------------------------------------------
			 */
			void setRenderable(bool renderable)
			{
				_renderable = renderable;
			}

        protected:
            //enginerenderer::Material material_;
            mona::math::AABB _box;

            mona::math::Transform _transform;
            bool _renderable;

            // Copy Constructor
            Entity(const Entity& copy);

            // Copy operator
            Entity operator=(const Entity& copy);
        };
    }
}
#endif