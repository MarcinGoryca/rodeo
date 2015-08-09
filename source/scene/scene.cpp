/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "scene\scene.h"
#include "renderer\renderstate.h"

using namespace mg::core;
using namespace mg::entity;

namespace mg
{
namespace scene
{
ui Scene::children_ = 0;

void Scene::addChild(Entity* entity)
{
    node_.push_back(entity);
    children_++;
    node_count_ = children_;
}

void Scene::render()
{
    for(std::list<Entity*>::iterator i = node_.begin(); i != node_.end(); ++i)
    {
        //if((*i)->renderable_)
        //{
        //    (*i)->draw();
        //}
        //if((*i)->getType() == "camera")
        //{
        //    (*i)->draw();
        //}
    }
}

void Scene::update(float dt)
{
    for(std::list<Entity*>::iterator i = node_.begin(); i != node_.end(); ++i)
    {
        (*i)->update(dt);
    }
}

void Scene::removeChild(Entity* entity)
{
    node_.remove(entity);
}

void Scene::onEvent()
{
    /*for(citer_ = scene_.begin(); citer_ != scene_.end(); ++citer_)
    {
        (*citer_)->onEvent();
    }*/
}

void Scene::removeChild()
{
    node_.pop_back();
}

void Scene::clear()
{
    std::list<Entity*>::iterator begin = node_.begin();
    std::list<Entity*>::iterator end = node_.end();

    for(begin; begin != end; ++begin)
    {
        (*begin)->release();
    }
}
}    // end of renderer namespace
}    // end of mg namespace