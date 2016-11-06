/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_MATH_TRANSFORM_H_
#define LAURA_MATH_TRANSFORM_H_

namespace laura
{
	namespace math
	{
		class Vector2;
		class Vector3;
		class Matrix3;
		class Matrix4;

		class Transform
		{
		public:
			Transform() {}
			~Transform() {}

			// Scale Matrix
			// Parameter float x - scale in x axis
			// Parameter float y - scale in y axis
			// Parameter float z - scale in z axis
			Matrix4 scale(float x, float y, float z);

			// Rotation Matrix
			// Parameter float angle - angle of rotation, in degrees
			// Parameter float x - rotation about x axis
			// Parameter float y - rotate about y axis
			// Parameter float z - rotate about z axis
			Matrix4 rotate(float angle, float x, float y, float z);


			// Translation Matrix
			// Parameter float x - translate in x axis
			// Parameter float y - translate in y axis
			// Parameter float z - translate in z axis
			Matrix4 translate(const float x, const float y, const float z);
		};
	}
}
#endif