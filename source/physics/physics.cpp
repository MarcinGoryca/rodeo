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
    initstr_.assign(L"Physics Module initialized");
    module_initialized_ = true;
}

void PhysicSystem::clear()
{
    module_initialized_ = false;
    //const char* t = "Physics Module shutdown";
    initstr_.assign(L"Physics Module shutdown");
}
}    // end of math namespace
}    // end of mg namespace