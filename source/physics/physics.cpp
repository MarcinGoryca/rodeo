/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "physics/physicsystem.h"

namespace mg
{
	namespace physics
	{

		void PhysicSystem::update()
		{
			//update method
		}

		void PhysicSystem::update(float delta)
		{
			//update with delta
		}

		void PhysicSystem::init()
		{
			_initstr.assign(L"Physics Module initialized");
			_module_initialized = true;
		}

		void PhysicSystem::clear()
		{
			_module_initialized = false;
			//const char* t = "Physics Module shutdown";
			_initstr.assign(L"Physics Module shutdown");
		}
	}
}