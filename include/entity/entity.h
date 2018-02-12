/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
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
//#ifndef RODEO_ENTITY_ENTITY_H_
//#define RODEO_ENTITY_ENTITY_H_
//
//#ifndef RODEO_ENTITY_OBJECT_H_
//#include "object.h"
//#endif
//
//#ifndef RODEO_RENDERER_GL_GLLIBRARY_H_
//#include "renderer\gl\gllibrary.h"
//#endif
//
//#ifndef RODEO_RENDERER_MATERIAL_H_
//#include "renderer\material.h"
//#endif
//
//#ifndef RODEO_MATH_AABB_H_
//#include "math\aabb.h"
//#endif
//
//#ifndef RODEO_MATH_TRANSFORM_H_
//#include "math\transform.h"
//#endif
//
//namespace rodeo
//{
//    namespace entity
//    {
//        class Entity : public Object
//        {
//        public:
//            Entity()
//                :Object(),
//                _renderable(true)
//            {
//                init();
//            }
//
//            // ---- //
//            explicit Entity(std::string name)
//                :Object(name)
//            {
//                init();
//            }
//
//            // ---- //
//            Entity(std::string name, std::string type)
//                :Object(name, type)
//            {
//                init();
//            }
//
//            // --- //
//            virtual ~Entity()
//            {
//                clear();
//            }
//
//            virtual void draw();
//            virtual void update(float dt);
//            virtual void init();
//            virtual void clear();
//
//            virtual void release();
//
//            //virtual void setColor(enginerenderer::Colors& rgb);
//
//			/*
//			 | ------------------------------------------------
//			 |    Get AABB Box
//			 |    Returns AABB object
//			 | ------------------------------------------------
//			 */
//			rodeo::math::AABB getAabb() const
//			{
//				return _box;
//			}
//
//			/*
//			 | ------------------------------------------------
//			 |    Get Transform object
//			 | ------------------------------------------------
//			 */
//			rodeo::math::Transform getTransform() const
//			{
//				return _transform;
//			}
//
//			/*
//			 | ------------------------------------------------
//			 |    Get Renderable
//			 |    Returns bool
//			 | ------------------------------------------------
//			 */
//			bool getRenderable() const
//			{
//				return _renderable;
//			}
//
//			/*
//			 | ------------------------------------------------
//			 |    Set AABB box
//			 | ------------------------------------------------
//			 */
//			void setAabb(rodeo::math::AABB box)
//			{
//				_box = box;
//			}
//
//			/*
//			 | ------------------------------------------------
//			 |    Set Transform
//			 | ------------------------------------------------
//			 */
//			void setTransform(rodeo::math::Transform transform)
//			{
//				_transform = transform;
//			}
//
//			/*
//			 | -------------------------------------------------
//			 |    Set Renderable
//			 | -------------------------------------------------
//			 */
//			void setRenderable(bool renderable)
//			{
//				_renderable = renderable;
//			}
//
//        protected:
//            //enginerenderer::Material material_;
//            rodeo::math::AABB _box;
//
//            rodeo::math::Transform _transform;
//            bool _renderable;
//
//            // Copy Constructor
//            Entity(const Entity& copy);
//
//            // Copy operator
//            Entity operator=(const Entity& copy);
//        };
//    }
//}
//#endif