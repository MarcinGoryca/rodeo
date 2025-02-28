﻿/*
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
#ifndef RODEO_RENDERER_LIGHT_H_
#define RODEO_RENDERER_LIGHT_H_

#ifndef RODEO_RENDERER_GL_GLCOMMON_H_
#include "gl\glcommon.h"
#endif

#ifndef RODEO_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace rodeo
{
	namespace renderer
	{
		class Light : public entity::Entity
		{
		public:
			Light()
				:_enable_lighting(false) {}
			~Light() {}

			enum Lights
			{
				RODEO_LIGHT_0 = GL_LIGHT0,
				RODEO_LIGHT_1 = GL_LIGHT1,
				RODEO_LIGHT_2 = GL_LIGHT2,
				RODEO_LIGHT_3 = GL_LIGHT3,
				RODEO_LIGHT_4 = GL_LIGHT4,
				RODEO_LIGHT_5 = GL_LIGHT5,
				RODEO_LIGHT_6 = GL_LIGHT6,
				RODEO_LIGHT_7 = GL_LIGHT7
			};

			// For OpenGL it calls glEnable(GL_LIGHTING) 
			void enable();
			void disable();

			// Fire Up specified light, from Light0 to Light7 
			void fire(Lights l);

			// Sets all necessary Lights, Materials 
			void set();

			void setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
			void setDiffuse(float r, float g, float b, float a);
			void setSpecular(float r, float g, float b, float a);
			void setPosition(float r, float g, float b, float a);

			static float* getArray() { return _s_array; }
			static float* getAmbient() { return _s_ambient; }
			static float* getDiffuse() { return _s_diffuse; }
			static float* getSpecular() { return _s_specular; }
			static float* getPosition() { return _s_position; }

			static int getLightEnum() { return _s_light_enum; }

			static float _s_array[4];
			static float _s_ambient[4];
			static float _s_diffuse[4];
			static float _s_specular[4];
			static float _s_position[4];



			// Methods derivied from Entity 
			virtual void update();

		private:
			static int _s_light_enum;

			// Used to Enable Lighting 
			bool _enable_lighting;
		};
	}
}
#endif