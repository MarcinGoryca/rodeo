/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_RENDERER_MATERIAL_H_
#define LAURA_RENDERER_MATERIAL_H_

namespace laura
{
	namespace renderer
	{
		class Material
		{
		public:
			Material();
			~Material() {}

			inline void setSpecular(float r, float g, float b, float a)
			{
				_specular[0] = r;
				_specular[1] = g;
				_specular[2] = b;
				_specular[3] = a;
			}

			inline void setAmbient(float r, float g, float b, float a)
			{
				_ambient[0] = r;
				_ambient[1] = g;
				_ambient[2] = b;
				_ambient[3] = a;
			}

			inline void setDiffuse(float r, float g, float b, float a)
			{
				_diffuse[0] = r;
				_diffuse[1] = g;
				_diffuse[2] = b;
				_diffuse[3] = a;
			}

			inline void setShininess(float ns)
			{
				_shininess[0] = ns;
			}

			const float* getSpecular()const { return &_specular[0]; }
			const float* getAmbient()const { return &_ambient[0]; }
			const float* getDiffuse()const { return &_diffuse[0]; }
			const float* getShininess()const { return &_shininess[0]; }

		private:
			float _specular[4];
			float _ambient[4];
			float _diffuse[4];
			float _shininess[1];
		};
	}
}
#endif