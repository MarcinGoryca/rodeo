/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ Entity.h ] [ mg\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_ENTITY_ENTITY_H_
#define MG_ENTITY_ENTITY_H_

#ifndef MG_ENTITY_OBJECT_H_
#include "object.h"
#endif

#ifndef MG_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef MG_RENDERER_MATERIAL_H_
#include "renderer\material.h"
#endif

#ifndef MG_MATH_AABB_H_
#include "math\aabb.h"
#endif

#ifndef MG_MATH_TRANSFORM_H_
#include "math\transform.h"
#endif

namespace mg
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
			mg::math::AABB getAabb() const
			{
				return _box;
			}

			/*
			 | ------------------------------------------------
			 |    Get Transform object
			 | ------------------------------------------------
			 */
			mg::math::Transform getTransform() const
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
			void setAabb(mg::math::AABB box)
			{
				_box = box;
			}

			/*
			 | ------------------------------------------------
			 |    Set Transform
			 | ------------------------------------------------
			 */
			void setTransform(mg::math::Transform transform)
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
            mg::math::AABB _box;

            mg::math::Transform _transform;
            bool _renderable;

            // Copy Constructor
            Entity(const Entity& copy);

            // Copy operator
            Entity operator=(const Entity& copy);
        };
    }
}
#endif