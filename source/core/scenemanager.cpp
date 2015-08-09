/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\scenemanager.h"
#include "entity\entity.h"

using namespace mg::renderer;
using namespace mg::entity;
using namespace mg::scene;

namespace mg
{
namespace core
{
void SceneManager::init()
{
    scene_ = new Scene;
}

//--------------------------------------------------------------------------------------------------
void SceneManager::clear()
{
    delete scene_;
}

//--------------------------------------------------------------------------------------------------
void SceneManager::render()
{
    if(scene_ != NULL)
    {
        scene_->render();
    }
}

//--------------------------------------------------------------------------------------------------
void SceneManager::update(float dt)
{
    if(scene_ != NULL)
    {
        scene_->update(dt);
    }
}
/*
void SceneManager::onIdle()
{
}
*/
/**
 *
 */
/*
void SceneManager::addChild(Entity* entity)
{

}
*/
/**
 *
 */
/*
void SceneManager::removeChildren()
{
    if(scene_ != NULL)
    {
        scene_->clear();
    }
}
*/
}    // end of core namespace
}    // enf of mg namespace