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
//#ifndef LAURA_CORE_OBJECTCONTROLLER_H_
//#define LAURA_CORE_OBJECTCONTROLLER_H_
//
//#ifndef VECTOR_H_
//#include <vector>
//#endif
//
//#ifndef LAURA_CORE_SINGLETON_H_
//#include "core\singleton.h"
//#endif
//
//#ifndef LAURA_ENTITY_MODEL3D_H_
//#include "entity\model3d.h"
//#endif
//
//#ifndef LAURA_PRIMITVE_BOUNDINGVOLUME_H_
//#include "primitive\boundingvolume.h"
//#endif
//
//namespace laura
//{
//	namespace controllers
//	{
//		class ObjectController : public laura::core::Singleton<ObjectController>
//		{
//		public:
//			ObjectController();
//
//			virtual ~ObjectController() {}
//
//			//scene::Model3D* object3d_;
//			//scene::Model3D* objects_container_[MAX_OBJECTS_];
//			//geometry::BoundingVolume* bounding_volume_[MAX_OBJECTS_];
//
//			//void create(laura::entity::Model3D* object3d);
//
//			//void add(laura::entity::Model3D* object3d);
//
//			void remove(laura::entity::Model3D* object3d);
//
//			void remove();
//
//			/*
//			 * --------------------------------------------------------------
//			 *    Gets object by ID
//			 *    Returns Model3D object
//			 * --------------------------------------------------------------
//			 */
//			entity::Model3D* getObject(unsigned int id)const;
//
//		private:
//			// Container for Model3D objects
//			std::vector<laura::entity::Model3D*> _objects;
//			// Used to counting objects
//			static unsigned int _s_objects_counter;
//
//			// Copy constructor
//			ObjectController(const ObjectController& copy);
//
//			// Copy operator
//			ObjectController operator=(const ObjectController& copy);
//		};
//	}
//}
//#endif