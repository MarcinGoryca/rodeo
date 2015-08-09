/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_PHYSICS_PHYSICSYSTEM_H_
#define MG_PHYSICS_PHYSICSYSTEM_H_

#ifndef MG_CORE_MASTERMANAGER_H_
#include "core/mastermanager.h"
#endif

namespace mg
{
namespace physics
{
class PhysicSystem : public core::MasterManager
{
public:

    PhysicSystem()
        :MasterManager()
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
}    // end of physics namespace
}    // end of mg namespace
#endif