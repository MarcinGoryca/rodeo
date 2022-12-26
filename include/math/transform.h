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
#ifndef RODEO_MATH_TRANSFORM_H_
#define RODEO_MATH_TRANSFORM_H_

namespace rodeo
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