/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
//#include "scene\scene.h"
//#include "renderer\renderstate.h"
//
//using namespace rodeo::core;
//using namespace rodeo::entity;
//
//namespace rodeo
//{
//	namespace scene
//	{
//		ui Scene::_children = 0;
//
//		void Scene::addChild(Entity* entity)
//		{
//			_node.push_back(entity);
//			_children++;
//			_node_count = _children;
//		}
//
//		void Scene::render()
//		{
//			for (std::list<Entity*>::iterator i = _node.begin(); i != _node.end(); ++i)
//			{
//				//if((*i)->renderable_)
//				//{
//				//    (*i)->draw();
//				//}
//				//if((*i)->getType() == "camera")
//				//{
//				//    (*i)->draw();
//				//}
//			}
//		}
//
//		void Scene::update(float dt)
//		{
//			for (std::list<Entity*>::iterator i = _node.begin(); i != _node.end(); ++i)
//			{
//				(*i)->update(dt);
//			}
//		}
//
//		void Scene::removeChild(Entity* entity)
//		{
//			_node.remove(entity);
//		}
//
//		void Scene::onEvent()
//		{
//			/*for(citer_ = scene_.begin(); citer_ != scene_.end(); ++citer_)
//			{
//				(*citer_)->onEvent();
//			}*/
//		}
//
//		void Scene::removeChild()
//		{
//			_node.pop_back();
//		}
//
//		void Scene::clear()
//		{
//			std::list<Entity*>::iterator begin = _node.begin();
//			std::list<Entity*>::iterator end = _node.end();
//
//			for (begin; begin != end; ++begin)
//			{
//				(*begin)->release();
//			}
//		}
//	}
//}