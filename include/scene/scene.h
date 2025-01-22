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
#ifndef RODEO_SCENE_SCENE_H_
#define RODEO_SCENE_SCENE_H_

#ifndef RODEO_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef RODEO_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#ifndef RODEO_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef LIST_H_
#include <list>
#endif

namespace rodeo
{
	namespace renderer
	{
		class RenderState;
	}
	namespace scene
	{
		class Scene
		{
		public:
			Scene()
				:_node_count(0)
			{}

			~Scene() {}

			void addChild(entity::Entity* entity);
			void removeChild(entity::Entity* entity);
			void removeChild();

			// Allows clear entire scene
			void clear();

			void render();
			void update(float dt);

			void onEvent();

			renderer::RenderState* getState()const { return _render_state; }

			unsigned int getNodeCount()const { return _node_count; }

		protected:
			renderer::RenderState* _render_state;
			std::list<entity::Entity*> _node;
		private:
			unsigned int _node_count;
			static unsigned int _children;
		};
	}
}
#endif