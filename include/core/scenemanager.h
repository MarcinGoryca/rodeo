/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_SCENEMANAGER_H_
#define MG_CORE_SCENEMANAGER_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_CORE_MASTERMANAGER_H_
#include "core\mastermanager.h"
#endif

#ifndef MG_SCENE_SCENE_H_
#include "scene\scene.h"
#endif

/*
#ifndef LIST_H_
#include <list>
#endif    //LIST_H_
*/
namespace mg
{
namespace core
{
class SceneManager : public Singleton<SceneManager>, public MasterManager
{
public:
    SceneManager()
    {
        init();
    }

    virtual ~SceneManager()
    {
        clear();
    }

    virtual void render();

    virtual void update(float dt);

    //virtual void onIdle();

    //void addChild(entity::Entity* entity);

    //void removeChild(entity::Entity* entity);

    //void removeChildren();

    scene::Scene* getScene()const { return scene_; }

protected:
    void init();
    void clear();

private:
    scene::Scene* scene_;
};
}    // end of core namespace
}    // end of mg namespace
#endif