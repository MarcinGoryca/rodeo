/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_LIGHT_H_
#define MG_RENDERER_LIGHT_H_

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "gl\glcommon.h"
#endif

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace mg
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
				MG_LIGHT_0 = GL_LIGHT0,
				MG_LIGHT_1 = GL_LIGHT1,
				MG_LIGHT_2 = GL_LIGHT2,
				MG_LIGHT_3 = GL_LIGHT3,
				MG_LIGHT_4 = GL_LIGHT4,
				MG_LIGHT_5 = GL_LIGHT5,
				MG_LIGHT_6 = GL_LIGHT6,
				MG_LIGHT_7 = GL_LIGHT7
			};

			// For OpenGL it calls glEnable(GL_LIGHTING) 
			void enable();
			void disable();

			// Fire Up specified light, from Light0 to Light7 
			void fire(Lights l);

			// Sets all necessary Lights, Materials 
			void set();

			void setAmbient(float r, float g, float b, float a);
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