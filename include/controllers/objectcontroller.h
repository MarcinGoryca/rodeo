/*
 |  -----------------------------------
 |   mona GAME ENGINE
 |   [ ObjectController.h ] [ mona\controllers ]
 |   Copyright(c) Marcin Goryca
 |   marcin.goryca@gmail.com
 |   http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CORE_OBJECTCONTROLLER_H_
#define MONA_CORE_OBJECTCONTROLLER_H_

#ifndef VECTOR_H_
#include <vector>
#endif

#ifndef MONA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MONA_ENTITY_MODEL3D_H_
#include "entity\model3d.h"
#endif

#ifndef MONA_PRIMITVE_BOUNDINGVOLUME_H_
#include "primitive\boundingvolume.h"
#endif

namespace mona
{
	namespace controllers
	{
		class ObjectController : public mona::core::Singleton<ObjectController>
		{
		public:
			ObjectController();

			virtual ~ObjectController() {}

			//scene::Model3D* object3d_;
			//scene::Model3D* objects_container_[MAX_OBJECTS_];
			//geometry::BoundingVolume* bounding_volume_[MAX_OBJECTS_];

			void create(mona::entity::Model3D* object3d);

			void add(mona::entity::Model3D* object3d);

			void remove(mona::entity::Model3D* object3d);

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
			std::vector<mona::entity::Model3D*> _objects;
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