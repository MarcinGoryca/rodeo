/*
-----------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_SCENE_ISCENENODE_H_
#define MONA_SCENE_ISCENENODE_H_

namespace mona
{
	namespace scene
	{
		class ISceneNode
		{
		public:
			ISceneNode() {};

			virtual ~ISceneNode() {}

			virtual void update(float dt) = 0;

			virtual void render() = 0;

			//virtual void addChild(shared_ptr<SceneNodeIfc> child) = 0;
		};
	}
}
#endif