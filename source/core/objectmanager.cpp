/*
----------------------------------------------------------------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------------------------------------------------------------
*/

#include "core\objectmanager.h"

using namespace mg::entity;

namespace mg
{
namespace core
{
ui ObjectManager::s_objects_counter_ = 0;

//...............................//
ObjectManager::ObjectManager()
{

}

//...............................//
void ObjectManager::add(Model3D* object3d)
{
    objects_.push_back(object3d);
    s_objects_counter_++;
}

//...............................//
Model3D* ObjectManager::getObject(ui id)const
{
    return objects_[id];
}

//...............................//
void ObjectManager::remove(Model3D* object)
{
    objects_.pop_back();
}

//...............................//
void ObjectManager::remove()
{
    objects_.pop_back();
}

//...............................//
void ObjectManager::create(Model3D* object3d)
{
    objects_.push_back(object3d);

    s_objects_counter_++;
}
}    // end of core namespace
}    // end of mg namespace