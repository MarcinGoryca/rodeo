/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
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
#include "math\ray.h"

namespace rodeo
{
	namespace math
	{
		void Ray::detransform(const Matrix3& m)
		{
			Matrix3 invert;
			Matrix3 temp;
			temp = m;

			//inverse translation
			/*_origin._x -= temp._m3[12];
			_origin._y -= temp._m3[13];
			_origin._z -= temp._m3[14];*/

			_origin.setX(_origin.getX() - temp.getM3(12));

			//delete translation in the matrix
			/*temp._m3[12] = 0.0f;
			temp._m3[13] = 0.0f;
			temp._m3[14] = 0.0f;*/

			temp.setM3(12, 0.0f);
			temp.setM3(13, 0.0f);
			temp.setM3(14, 0.0f);
		}

		//--------------------------------------------------------------------------------------------------
		void Ray::set(const Vector3& org, const Vector3& dir)
		{
			_origin = org;
			_direction = dir;
		}
	}
}