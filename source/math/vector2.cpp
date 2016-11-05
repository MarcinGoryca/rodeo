/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include <iostream>
#include <math.h>
#include "..\include\math\vector2.h"

using namespace std;

namespace laura
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
			std::cout << "v2(" << v.getX() << ", " << v.getY() << ")" << std::endl;
		}

		// ---- //
		float distance(const Vector2 &v1, const Vector2 &v2)
		{
			float vx = v1.getX() - v2.getX();
			float vy = v1.getY() - v2.getY();
			return sqrt(vx*vx + vy*vy);
		}

		// ---- //
		float dot(const Vector2& v1, const Vector2& v2)
		{
			return v1.getX() * v2.getX() + v1.getY() * v2.getY();
		}

		// ---- //
		Vector2 add(const Vector2& v1, const Vector2& v2)
		{
			Vector2 result;

			result.setX(v1.getX() + v2.getX());
			result.setY(v1.getY() + v2.getY());

			return result;
		}

		// ---- //
		Vector2 subtract(const Vector2& v1, const Vector2& v2)
		{
			Vector2 result;

			result.setX(v1.getX() - v2.getX());
			result.setY(v1.getY() - v2.getY());

			return result;
		}
	}
}