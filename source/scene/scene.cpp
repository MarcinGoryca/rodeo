/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "scene\scene.h"
#include "renderer\renderstate.h"

using namespace laura::core;
using namespace laura::entity;

namespace laura
{
	namespace scene
	{
		ui Scene::_children = 0;

		void Scene::addChild(Entity* entity)
		{
			_node.push_back(entity);
			_children++;
			_node_count = _children;
		}

		void Scene::render()
		{
			for (std::list<Entity*>::iterator i = _node.begin(); i != _node.end(); ++i)
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
			for (std::list<Entity*>::iterator i = _node.begin(); i != _node.end(); ++i)
			{
				(*i)->update(dt);
			}
		}

		void Scene::removeChild(Entity* entity)
		{
			_node.remove(entity);
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
			_node.pop_back();
		}

		void Scene::clear()
		{
			std::list<Entity*>::iterator begin = _node.begin();
			std::list<Entity*>::iterator end = _node.end();

			for (begin; begin != end; ++begin)
			{
				(*begin)->release();
			}
		}
	}
}