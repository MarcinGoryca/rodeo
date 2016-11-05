/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_MATH_RAY_H_
#define LAURA_MATH_RAY_H_

#ifndef LAURA_MATH_MATRIX3_H_
#include "math\matrix3.h"
#endif

#ifndef LAURA_MATH_VECTOR4_H_
#include "math\vector4.h"
#endif

namespace laura
{
	namespace math
	{
		class Ray
		{
		public:
			Ray()
				:_origin(0.0f, 0.0f, 0.0f),
				_direction(0.0f, 0.0f, 0.0f)
			{
			}

			~Ray() {}

			// Transforms model from its coordinate space
			// With using Rays it's not necessary to transform whole model
			// by multiplying its vertices by transform matrix
			// on the CPU, this operation is very slow. 
			void detransform(const Matrix3& m);
			bool intersects(const Vector3& v0, const Vector3& v1, const Vector3& v2, bool cull, float* t);

			// Sets new Ray
			void set(const Vector3& org, const Vector3& dir);

			// Gets the Ray
			Ray& get() { return *this; };

			// Gets the Origin of the Ray
			Vector3 getOrigin()const { return _origin; }

			// Sets the Origin of the Ray
			void setOrigin(Vector3 new_origin) { _origin = new_origin; }

			// Gets the Direction of the Ray
			Vector3 getDirection() const { return _direction; }

			// Sets the Direction of the Ray
			void setDirection(Vector3 new_direction) { _direction = new_direction; }

		private:
			// Origin Point of a Ray
			Vector3 _origin;

			// Direction which Ray is running
			// Normalized is better
			Vector3 _direction;

			// Copy Constructor
			Ray(const Ray& copy);

			// Copy operator
			Ray operator=(const Ray& copy);
		};
	}
}
#endif

/*
Parametric line:
P(t) = origin + t * direction

for every pixel
	construct a ray from the eye
	for every object in the scene
		find intersection with the ray
		keep it closest
	shade depending on light and normal vector
*/
