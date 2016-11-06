﻿/*
----------------------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_RENDERER_RENDERSTATE_H_
#define LAURA_RENDERER_RENDERSTATE_H_

namespace laura
{
	namespace renderer
	{
		class RenderState : public entity::Object
		{
		public:
			virtual ~RenderState() {}

			virtual int getState()const = 0;

			enum State
			{
				GLOBAL,
				LIGHT,
				EFFECT
			};
		protected:
			RenderState() {}
		};
	}
}
#endif