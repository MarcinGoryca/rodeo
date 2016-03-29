/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_VECTOR2_H_
#define MG_MATH_VECTOR2_H_

#ifndef MG_MATH_MATHTOOLS_H_
#include "mathtools.h"
#endif

namespace mg
{
	namespace math
	{
		class Vector2
		{
		public:
			// Vector without direction, has magnitude of 0\n
			// No Displacement
			Vector2()
				:_x(0.0f),
				_y(0.0f)
			{}

			// ---- //
			Vector2(float x1, float y1)
				:_x(x1),
				_y(y1)
			{}

			// ---- //
			Vector2(const Vector2& v)
				:_x(v._x),
				_y(v._y)
			{}

			// ---- //
			~Vector2() {}

			// Gets this vector
			Vector2 get() const { return *this; }

			// Length of a vector
			// Length/magnitude/norm\n
			// it can be any non-negative number 
			float length();

			// Normalization of a vector
			// Normalizing a vector is dividing this vector by its length\n
			// v(norm) = v / ||v||\n
			// Normalizing a vector produces unit vector which points in the same direction as the product vector
			void normalize();

			// ---- //
			inline Vector2& operator+=(const Vector2& v1)
			{
				this->_x += v1._x;
				this->_y += v1._y;
				return *this;
			}

			// ----//
			inline  Vector2& operator+= (const float& scalar)
			{
				this->_x += scalar;
				this->_y += scalar;
				return *this;
			}

			// ---- //
			inline Vector2& operator/= (const float& scalar)
			{
				this->_x /= scalar;
				this->_y /= scalar;
				return *this;
			}

			// ---- //
			inline Vector2& operator *= (const float& scalar)
			{
				this->_x *= scalar;
				this->_y *= scalar;
				return *this;
			}

			// ---- //
			inline Vector2& operator-=(const Vector2& v1)
			{
				this->_x -= v1._x;
				_y -= v1._y;
				return *this;
			}

			// ---- //
			inline Vector2& operator*=(const Vector2& v1)
			{
				this->_x *= v1._x;
				this->_y *= v1._y;
				return *this;
			}

			// ---- //
			inline Vector2& operator /=(const Vector2& v1)
			{
				_x /= v1._x;
				_y /= v1._y;
				return *this;
			}

			// ---- //
			inline Vector2 operator+(const Vector2& v1)
			{
				return Vector2(v1._x + _x, v1._y + _y);
			}

			// ---- //
			inline bool operator == (const Vector2& v1) const
			{
				return (_x == v1._x && _y == v1._y);
			}

			// ---- //
			inline Vector2& operator = (const Vector2& v1)
			{
				_x = v1._x; _y = v1._y;
				return *this;
			}

			// ---- //
			inline bool operator != (const Vector2& v1) const
			{
				return (_x != v1._x || _y != v1._y);
			}

			/**
			 * @brief Negates a vector
			 * @return Vector2 - negated
			 */
			Vector2 operator - () const
			{
				return Vector2(-_x, -_y);
			}

			// ---- //
			Vector2 operator*(const float& s) const
			{
				return Vector2(_x * s, _y * s);
			}

			// ---- //
			Vector2 operator/(const float& s) const
			{
				float sc = 1.0f / s;
				return Vector2(_x * sc, _y * sc);
			}

			// ---- //
			friend std::ostream& operator<<(std::ostream& os, const Vector2& v)
			{
				return os << "Vector2(" << v._x << ", " << v._y << ")";
			}

			// ---- //
			inline Vector2& operator+(const float& scalar)
			{
				this->_x = this->_x + scalar;
				this->_y = this->_y + scalar;
				return *this;
			}

			float _x;
			float _y;

			static const Vector2 _S_VECTOR2_ZERO_;

		private:
		};

		// Helper function to print Vector to standard output
		void printV2(const Vector2& v);

		// Distance between two vectors
		// Returns float value
		float distance(const Vector2 &v1, const Vector2 &v2);

		// Dot product of two vectors
		//    if dot product of normalized vectors results:\n
		//    1 - vectors are pointing in the same direction\n
		//    0 - vectors are perpendicular\n
		//    -1 - vectors are pointing in inverse directions\n
		float dot(const Vector2& v1, const Vector2& v2);

		// Adds two vectors
		// Returns Vector2
		Vector2 add(const Vector2& v1, const Vector2& v2);

		// Substracts two vectors
		// Returns Vector2
		Vector2 subtract(const Vector2& v1, const Vector2& v2);
	}    // end of math namespace
}    // end of mg namespace
#endif