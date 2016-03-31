/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include <iostream>
#include <math.h>
#include "..\include\math\vector2.h"

using namespace std;

namespace mg
{
	namespace math
	{

		const Vector2 Vector2::_S_VECTOR2_ZERO(0.0f, 0.0f);

		// ---- //
		float Vector2::length()
		{
			float length;
			length = sqrt(_x * _x + _y * _y);
			return length;
		}

		// ---- //
		void Vector2::normalize()
		{
			float length;
			float temp = sqrt(_x * _x + _y * _y);
			if (temp > 0.0f)
			{
				length = 1.0f / temp;
				_x *= length;
				_y *= length;
			}
		}

		// ---- //
		void printV2(const Vector2& v)
		{
			std::cout << "v2(" << v._x << ", " << v._y << ")" << std::endl;
		}

		// ---- //
		float distance(const Vector2 &v1, const Vector2 &v2)
		{
			float vx = v1._x - v2._x;
			float vy = v1._y - v2._y;
			return sqrt(vx*vx + vy*vy);
		}

		// ---- //
		float dot(const Vector2& v1, const Vector2& v2)
		{
			return v1._x * v2._x + v1._y * v2._y;
		}

		// ---- //
		Vector2 add(const Vector2& v1, const Vector2& v2)
		{
			Vector2 result;

			result._x = v1._x + v2._x;
			result._y = v1._y + v2._y;

			return result;
		}

		// ---- //
		Vector2 subtract(const Vector2& v1, const Vector2& v2)
		{
			Vector2 result;

			result._x = v1._x - v2._x;
			result._y = v1._y - v2._y;

			return result;
		}
	}
}