/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_PRIMITIVE_CUBE_H_
#define MG_PRIMITIVE_CUBE_H_

#ifndef MG_PRIMITIVE_GEOMETRY_H_
#include "primitive\geometry.h"
#endif

namespace mg
{
	namespace primitive
	{
		/*
			Cube class is responsible for creating cubes.
		*/

		class Cube : public entity::Model3D
		{
			Cube() {}
			virtual ~Cube() {}

			virtual void draw();
			void build();
			void build(const math::Vector3& v1, const math::Vector3& v2);

		private:
			float _vertex_array[24];
			float _vertex_data[8];
			unsigned short _vertex_indices[24];
			float _texture_uvs_array[48];
			float _normal_array[24];
		};
	}
}
#endif