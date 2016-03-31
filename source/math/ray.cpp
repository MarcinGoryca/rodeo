/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "math\ray.h"

namespace mg
{
	namespace math
	{
		void Ray::detransform(const Matrix3& m)
		{
			Matrix3 invert;
			Matrix3 temp;
			temp = m;

			//inverse translation
			_origin._x -= temp._m3[12];
			_origin._y -= temp._m3[13];
			_origin._z -= temp._m3[14];

			//delete translation in the matrix
			temp._m3[12] = 0.0f;
			temp._m3[13] = 0.0f;
			temp._m3[14] = 0.0f;
		}

		//--------------------------------------------------------------------------------------------------
		void Ray::set(const Vector3& org, const Vector3& dir)
		{
			_origin = org;
			_direction = dir;
		}
	}
}