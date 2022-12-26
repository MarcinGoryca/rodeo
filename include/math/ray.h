/*
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
#ifndef RODEO_MATH_RAY_H_
#define RODEO_MATH_RAY_H_

#ifndef RODEO_MATH_MATRIX3_H_
#include "math\matrix3.h"
#endif

#ifndef RODEO_MATH_VECTOR4_H_
#include "math\vector4.h"
#endif

namespace rodeo
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
