/*
-----------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
-----------------------------------
*/
#ifndef LAURA_SCENE_SCENE_H_
#define LAURA_SCENE_SCENE_H_

#ifndef LAURA_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef LAURA_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#ifndef LAURA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef LIST_H_
#include <list>
#endif

namespace laura
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

			core::ui getNodeCount()const { return _node_count; }

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