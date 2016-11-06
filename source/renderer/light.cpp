/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\light.h"

using namespace laura::math;

namespace laura
{
	namespace renderer
	{
		float Light::_s_array[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		float Light::_s_ambient[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		float Light::_s_diffuse[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		float Light::_s_specular[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		float Light::_s_position[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		int Light::_s_light_enum = 0;

		/**
		 *
		 */

		void Light::setAmbient(float r, float g, float b, float a)
		{
			_s_ambient[0] = r;
			_s_ambient[1] = g;
			_s_ambient[2] = b;
			_s_ambient[3] = a;
		}

		/**
		 *
		 */

		void Light::setDiffuse(float r, float g, float b, float a)
		{
			_s_diffuse[0] = r;
			_s_diffuse[1] = g;
			_s_diffuse[2] = b;
			_s_diffuse[3] = a;
		}

		/**
		 *
		 */

		void Light::setSpecular(float r, float g, float b, float a)
		{
			_s_specular[0] = r;
			_s_specular[1] = g;
			_s_specular[2] = b;
			_s_specular[3] = a;
		}

		/**
		 *
		 */

		void Light::fire(Lights l)
		{
			_s_light_enum = l;
			glLightfv(l, GL_AMBIENT, getAmbient());
			glLightfv(l, GL_DIFFUSE, getDiffuse());
			glLightfv(l, GL_SPECULAR, getSpecular());
			glLightfv(l, GL_POSITION, getPosition());
			glEnable(l);
		}

		/**
		 *
		 */

		void Light::enable()
		{
			glEnable(GL_LIGHTING);
		}

		/**
		 *
		 */

		void Light::disable()
		{
			glDisable(GL_LIGHTING);
		}

		/**
		 *
		 */

		void Light::setPosition(float r, float g, float b, float a)
		{
			_s_position[0] = r;
			_s_position[1] = g;
			_s_position[2] = b;
			_s_position[3] = a;
		}

		/**
		 *
		 */

		void Light::update()
		{
			int l = getLightEnum();
			glLightfv(l, GL_AMBIENT, getAmbient());
			glLightfv(l, GL_DIFFUSE, getDiffuse());
			glLightfv(l, GL_SPECULAR, getSpecular());
			glLightfv(l, GL_POSITION, getPosition());
		}
	}
}