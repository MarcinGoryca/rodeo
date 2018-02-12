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
//#include "renderer\light.h"
//
//using namespace rodeo::math;
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		float Light::_s_array[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
//		float Light::_s_ambient[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
//		float Light::_s_diffuse[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
//		float Light::_s_specular[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
//		float Light::_s_position[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
//		int Light::_s_light_enum = 0;
//
//		/**
//		 *
//		 */
//
//		void Light::setAmbient(float r, float g, float b, float a)
//		{
//			_s_ambient[0] = r;
//			_s_ambient[1] = g;
//			_s_ambient[2] = b;
//			_s_ambient[3] = a;
//		}
//
//		/**
//		 *
//		 */
//
//		void Light::setDiffuse(float r, float g, float b, float a)
//		{
//			_s_diffuse[0] = r;
//			_s_diffuse[1] = g;
//			_s_diffuse[2] = b;
//			_s_diffuse[3] = a;
//		}
//
//		/**
//		 *
//		 */
//
//		void Light::setSpecular(float r, float g, float b, float a)
//		{
//			_s_specular[0] = r;
//			_s_specular[1] = g;
//			_s_specular[2] = b;
//			_s_specular[3] = a;
//		}
//
//		/**
//		 *
//		 */
//
//		void Light::fire(Lights l)
//		{
//			_s_light_enum = l;
//			glLightfv(l, GL_AMBIENT, getAmbient());
//			glLightfv(l, GL_DIFFUSE, getDiffuse());
//			glLightfv(l, GL_SPECULAR, getSpecular());
//			glLightfv(l, GL_POSITION, getPosition());
//			glEnable(l);
//		}
//
//		/**
//		 *
//		 */
//
//		void Light::enable()
//		{
//			glEnable(GL_LIGHTING);
//		}
//
//		/**
//		 *
//		 */
//
//		void Light::disable()
//		{
//			glDisable(GL_LIGHTING);
//		}
//
//		/**
//		 *
//		 */
//
//		void Light::setPosition(float r, float g, float b, float a)
//		{
//			_s_position[0] = r;
//			_s_position[1] = g;
//			_s_position[2] = b;
//			_s_position[3] = a;
//		}
//
//		/**
//		 *
//		 */
//
//		void Light::update()
//		{
//			int l = getLightEnum();
//			glLightfv(l, GL_AMBIENT, getAmbient());
//			glLightfv(l, GL_DIFFUSE, getDiffuse());
//			glLightfv(l, GL_SPECULAR, getSpecular());
//			glLightfv(l, GL_POSITION, getPosition());
//		}
//	}
//}