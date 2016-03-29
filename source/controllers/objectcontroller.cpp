/*
----------------------------------------------------------------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------------------------------------------------------------
*/

#include "controllers\objectcontroller.h"

using namespace mg::entity;

namespace mg
{
	namespace controllers
	{
		unsigned int ObjectController::_s_objects_counter = 0;

		//...............................//
		ObjectController::ObjectController()
		{

		}

		//...............................//
		void ObjectController::add(Model3D* object3d)
		{
			_objects.push_back(object3d);
			_s_objects_counter++;
		}

		//...............................//
		Model3D* ObjectController::getObject(unsigned int id)const
		{
			return _objects[id];
		}

		//...............................//
		void ObjectController::remove(Model3D* object)
		{
			_objects.pop_back();
		}

		//...............................//
		void ObjectController::remove()
		{
			_objects.pop_back();
		}

		//...............................//
		void ObjectController::create(Model3D* object3d)
		{
			_objects.push_back(object3d);

			_s_objects_counter++;
		}
	}
}