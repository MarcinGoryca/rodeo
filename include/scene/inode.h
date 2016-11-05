/*
-----------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
-----------------------------------
*/
#ifndef LAURA_SCENE_INODE_H_
#define LAURA_SCENE_INODE_H_

#ifndef LAURA_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

#ifndef LAURA_SCENE_SCENE_H_
#include "scene\scene.h"
#endif

namespace laura
{
	namespace scene
	{
		class INode
		{
		public:
			INode() {}
			virtual ~INode() {}

			virtual void setTransform(const math::Matrix4& world, const math::Matrix4& from_world) = 0;
			virtual void onUpdate(Scene* scene, float ms) = 0;
			virtual void onRestore(Scene* scene) = 0;
			virtual void preRender(Scene* scene) = 0;
			virtual bool isVisible(Scene* scene) = 0;
			virtual void render(Scene* scene) = 0;
			virtual void renderChildren(Scene* scene) = 0;
			virtual void postRender(Scene* scene) = 0;
			//virtual bool addChild(shared_ptr<NodeIfc> kid)=0;
		};
	}
}
#endif