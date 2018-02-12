/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
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
//#ifndef RODEO_SCENE_INODE_H_
//#define RODEO_SCENE_INODE_H_
//
//#ifndef RODEO_MATH_MATRIX4_H_
//#include "math\matrix4.h"
//#endif
//
//#ifndef RODEO_SCENE_SCENE_H_
//#include "scene\scene.h"
//#endif
//
//namespace rodeo
//{
//	namespace scene
//	{
//		class INode
//		{
//		public:
//			INode() {}
//			virtual ~INode() {}
//
//			virtual void setTransform(const math::Matrix4& world, const math::Matrix4& from_world) = 0;
//			virtual void onUpdate(Scene* scene, float ms) = 0;
//			virtual void onRestore(Scene* scene) = 0;
//			virtual void preRender(Scene* scene) = 0;
//			virtual bool isVisible(Scene* scene) = 0;
//			virtual void render(Scene* scene) = 0;
//			virtual void renderChildren(Scene* scene) = 0;
//			virtual void postRender(Scene* scene) = 0;
//			//virtual bool addChild(shared_ptr<NodeIfc> kid)=0;
//		};
//	}
//}
//#endif