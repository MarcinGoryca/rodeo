/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\material.h"

namespace mg
{
	namespace renderer
	{
		Material::Material()
		{
			_specular[0] = 0.0f;
			_specular[1] = 0.0f;
			_specular[2] = 0.0f;
			_specular[3] = 0.0f;

			_ambient[0] = 0.0f;
			_ambient[1] = 0.0f;
			_ambient[2] = 0.0f;
			_ambient[3] = 0.0f;

			_diffuse[0] = 0.0f;
			_diffuse[1] = 0.0f;
			_diffuse[2] = 0.0f;
			_diffuse[3] = 0.0f;

			_shininess[0] = 0.0f;
		}
	}
}