﻿/*
 |  -----------------------------------
 |   MG GAME ENGINE
 |   [ ObjectController.h ] [ mg\controllers ]
 |   Copyright(c) Marcin Goryca
 |   marcin.goryca@gmail.com
 |   http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_OBJECTCONTROLLER_H_
#define MG_CORE_OBJECTCONTROLLER_H_

#ifndef VECTOR_H_
#include <vector>
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_ENTITY_MODEL3D_H_
#include "entity\model3d.h"
#endif

#ifndef MG_PRIMITVE_BOUNDINGVOLUME_H_
#include "primitive\boundingvolume.h"
#endif

namespace mg
{
	namespace controllers
	{
		class ObjectController : public mg::core::Singleton<ObjectController>
		{
		public:
			ObjectController();

			virtual ~ObjectController() {}

			//scene::Model3D* object3d_;
			//scene::Model3D* objects_container_[MAX_OBJECTS_];
			//geometry::BoundingVolume* bounding_volume_[MAX_OBJECTS_];

			void create(mg::entity::Model3D* object3d);

			void add(mg::entity::Model3D* object3d);

			void remove(mg::entity::Model3D* object3d);

			void remove();

			/*
			 * --------------------------------------------------------------
			 *    Gets object by ID
			 *    Returns Model3D object
			 * --------------------------------------------------------------
			 */
			entity::Model3D* getObject(unsigned int id)const;

		private:
			// Container for Model3D objects
			std::vector<mg::entity::Model3D*> _objects;
			// Used to counting objects
			static unsigned int _s_objects_counter;

			// Copy constructor
			ObjectController(const ObjectController& copy);

			// Copy operator
			ObjectController operator=(const ObjectController& copy);
		};
	}
}
#endif