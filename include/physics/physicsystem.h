/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MONA_PHYSICS_PHYSICSYSTEM_H_
#define MONA_PHYSICS_PHYSICSYSTEM_H_

#ifndef MONA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers/mastercontroller.h"
#endif

namespace mona
{
	namespace physics
	{
		class PhysicSystem : public controllers::MasterController
		{
		public:

			PhysicSystem()
				:MasterController()
			{
				init();
			}

			~PhysicSystem()
			{
				clear();
			}

			// Implement this method in your application
			virtual void update();

			// Implement this method in your application
			virtual void update(float delta);

		private:
			void init();
			void clear();
		};
	}
}
#endif