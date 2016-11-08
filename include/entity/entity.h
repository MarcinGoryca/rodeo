/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    [ Entity.h ] [ laura\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_ENTITY_ENTITY_H_
#define LAURA_ENTITY_ENTITY_H_

#ifndef LAURA_ENTITY_OBJECT_H_
#include "object.h"
#endif

#ifndef LAURA_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef LAURA_RENDERER_MATERIAL_H_
#include "renderer\material.h"
#endif

#ifndef LAURA_MATH_AABB_H_
#include "math\aabb.h"
#endif

#ifndef LAURA_MATH_TRANSFORM_H_
#include "math\transform.h"
#endif

namespace laura
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
			laura::math::AABB getAabb() const
			{
				return _box;
			}

			/*
			 | ------------------------------------------------
			 |    Get Transform object
			 | ------------------------------------------------
			 */
			laura::math::Transform getTransform() const
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
			void setAabb(laura::math::AABB box)
			{
				_box = box;
			}

			/*
			 | ------------------------------------------------
			 |    Set Transform
			 | ------------------------------------------------
			 */
			void setTransform(laura::math::Transform transform)
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
            laura::math::AABB _box;

            laura::math::Transform _transform;
            bool _renderable;

            // Copy Constructor
            Entity(const Entity& copy);

            // Copy operator
            Entity operator=(const Entity& copy);
        };
    }
}
#endif