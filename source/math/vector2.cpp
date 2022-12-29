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
#include <iostream>
#include <math.h>
#include "..\include\math\vector2.h"

using namespace std;

namespace rodeo
{
	namespace math
	{
		const Vector2 Vector2::_S_VECTOR2_ZERO(0.0f, 0.0f);
//-----------------------------------------------------------------------------------------//
		float Vector2::length()
		{
			float length;
			length = sqrt(_x * _x + _y * _y);
			return length;
		}
//-----------------------------------------------------------------------------------------//
		void Vector2::normalize()
		{
			float length = 0.0f;
			float temp_length = sqrt(_x * _x + _y * _y);
			if (temp_length > 0.0f)
			{
				length = 1.0f / temp_length;
				_x *= length;
				_y *= length;
			}
		}
//-----------------------------------------------------------------------------------------//
		void printV2(const Vector2& v)
		{
			std::cout << "v2(" << v.getX() << ", " << v.getY() << ")" << std::endl;
		}
//-----------------------------------------------------------------------------------------//
		float distance(const Vector2 &v1, const Vector2 &v2)
		{
			float vx = v1.getX() - v2.getX();
			float vy = v1.getY() - v2.getY();
			return sqrt(vx*vx + vy*vy);
		}
//-----------------------------------------------------------------------------------------//
		float dot(const Vector2& v1, const Vector2& v2)
		{
			return v1.getX() * v2.getX() + v1.getY() * v2.getY();
		}
//-----------------------------------------------------------------------------------------//
		Vector2 add(const Vector2& v1, const Vector2& v2)
		{
			Vector2 result;

			result.setX(v1.getX() + v2.getX());
			result.setY(v1.getY() + v2.getY());

			return result;
		}
//-----------------------------------------------------------------------------------------//
		Vector2 subtract(const Vector2& v1, const Vector2& v2)
		{
			Vector2 result;

			result.setX(v1.getX() - v2.getX());
			result.setY(v1.getY() - v2.getY());

			return result;
		}
//-----------------------------------------------------------------------------------------//
	}
}