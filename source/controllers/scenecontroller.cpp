/*
----------------------------------------------
    laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers\scenecontroller.h"
#include "entity\entity.h"

using namespace laura::renderer;
using namespace laura::entity;
using namespace laura::scene;

namespace laura
{
namespace controllers
{
void SceneController::init()
{
    _scene = new Scene;
}

//--------------------------------------------------------------------------------------------------
void SceneController::clear()
{
    delete _scene;
}

//--------------------------------------------------------------------------------------------------
void SceneController::render()
{
    if(_scene != nullptr)
    {
        _scene->render();
    }
}

//--------------------------------------------------------------------------------------------------
void SceneController::update(float dt)
{
	if (_scene != nullptr)
    {
        _scene->update(dt);
    }
}
/*
void SceneController::onIdle()
{
}
*/
/**
 *
 */
/*
void SceneController::addChild(Entity* entity)
{

}
*/
/**
 *
 */
/*
void SceneController::removeChildren()
{
    if(scene_ != NULL)
    {
        scene_->clear();
    }
}
*/
}
}