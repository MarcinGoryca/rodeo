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
#ifndef RODEO_MATH_VECTOR2_H_
#define RODEO_MATH_VECTOR2_H_

#ifndef RODEO_MATH_MATHTOOLS_H_
#include "mathtools.h"
#endif

namespace rodeo
{
	namespace math
	{
		class Vector2
		{
		public:
			/*
			 | -----------------------------------------------------------------------------------
			 |     Default Constructor
			 | -----------------------------------------------------------------------------------
			 */
			Vector2()
				:_x(0.0f),
				_y(0.0f)
			{}

			/*
			 | -----------------------------------------------------------------------------------
			 |     Constructor with two parameters
			 |     Float = X-value of a vector
			 |     Float = Y-value of a vector
			 | -----------------------------------------------------------------------------------
			 */
			Vector2(float x1, float y1)
				:_x(x1),
				_y(y1)
			{}

			/*
			 | -----------------------------------------------------------------------------------
			 |     Copy Constructor
			 | -----------------------------------------------------------------------------------
			 */
			Vector2(const Vector2& v)
				:_x(v._x),
				_y(v._y)
			{}

			/*
			 | -----------------------------------------------------------------------------------
			 |     Destructor
			 | -----------------------------------------------------------------------------------
			 */
			~Vector2() {}

			/*
			 | -----------------------------------------------------------------------------------
			 |		Gets this vector
			 |		Returns Vector2
			 | -----------------------------------------------------------------------------------
			 */
			Vector2 get() const { return *this; }

			/*
			 | -----------------------------------------------------------------------------------
			 |	   Length of a vector
			 |     Length/magnitude/norm
			 |     it can be any non-negative number 
			 | -----------------------------------------------------------------------------------
			 */
			float length();

			/*
			 | -------------------------------------------------------------------
			 |      Normalization of a vector
			 |      Normalizing a vector is dividing this vector by its length\n
			 |      v(norm) = v / ||v||\n
			 |      Normalizing a vector produces unit vector which points
			 |      in the same direction as the product vector
			 | -------------------------------------------------------------------
			 */
			void normalize();

			/*
			 | -------------------------------------------------------------------
			 |		Operator +=
             |      Vector += Vector
			 | -------------------------------------------------------------------
			 */
			Vector2& operator+=(const Vector2& v1)
			{
				this->_x += v1._x;
				this->_y += v1._y;
				return *this;
			}

			/*
			 | -------------------------------------------------------------------
			 |		Operator +=
             |      Vector += scalar
			 | -------------------------------------------------------------------
			 */
			Vector2& operator+= (const float& scalar)
			{
				this->_x += scalar;
				this->_y += scalar;
				return *this;
			}

           /*
            | ----------------------------------------------------------------------
            |		Operator +
            |       Vector + Vector
            | ----------------------------------------------------------------------
            */
            Vector2 operator+(const Vector2& v1)
            {
             return Vector2(v1._x + _x, v1._y + _y);
            }

           /*
            | --------------------------------------------------------------------
            |		Operator +
            |       Vector + scalar
            | --------------------------------------------------------------------
            */
            Vector2& operator+(const float& scalar)
            {
             this->_x = this->_x + scalar;
             this->_y = this->_y + scalar;
             return *this;
            }

            /*
             | -------------------------------------------------------------------
             |		Operator -=
             |      Vector -= Vector
             | -------------------------------------------------------------------
             */
            Vector2& operator -=(const Vector2& v1)
            {
             this->_x -= v1._x;
             this->_y -= v1._y;
             return *this;
            }

            /*
             | -------------------------------------------------------------------
             |     Operator -=
             |     Vector -= scalar
             | -------------------------------------------------------------------
             */
            Vector2& operator -= (const float& scalar)
            {
             this->_x -= scalar;
             this->_y -= scalar;
             return *this;
            }

            /*
            | ----------------------------------------------------------------------
            |		Negates a vector
            |		Returns Vector2 - negated
            | ----------------------------------------------------------------------
            */
            Vector2 operator - () const
            {
             return Vector2(-_x, -_y);
            }

            /*
             | ----------------------------------------------------------------
             |     Operator -
             |     Vector - Vector
             | ----------------------------------------------------------------
             */
            Vector2 operator - (const Vector2& v1)
            {
                  float x = this->_x - v1.getX();
                  float y = this->_y - v1.getY();
                  return Vector2(x, y);
            }

           /*
            | ----------------------------------------------------------------------
            |		Operator /=
            |       Vector /= Vector
            | ----------------------------------------------------------------------
            */
            Vector2& operator /=(const Vector2& v1)
            {
             _x /= v1._x;
             _y /= v1._y;
             return *this;
            }

			/*
			 | --------------------------------------------------------------------
			 |		Operator /=
             |      Vector /= scalar
			 | --------------------------------------------------------------------
			 */
			Vector2& operator/= (const float& scalar)
			{
				this->_x /= scalar;
				this->_y /= scalar;
				return *this;
			}

            /*
             | ---------------------------------------------------------------------
             |		Operator /
             |      Vector / scalar
             | ---------------------------------------------------------------------
             */
            Vector2 operator / (const float& scalar) const
            {
                 float tmp = 1.0f;
                 if (scalar == 0.0f) {
                     tmp = 0.1f;
                 }
                 else {
                     tmp = scalar;
                 }
                 float sc = 1.0f / tmp;
                 return Vector2(_x * sc, _y * sc);
            }

			/*
			 | --------------------------------------------------------------------
			 |		Operator *=
             |      Vector *= scalar
			 | --------------------------------------------------------------------
			 */
			Vector2& operator *= (const float& scalar)
			{
				this->_x *= scalar;
				this->_y *= scalar;
				return *this;
			}

			/*
			 | -------------------------------------------------------------------
			 |		Operator *=
             |      Vector *= Vector
			 | -------------------------------------------------------------------
			 */
			Vector2& operator*=(const Vector2& v1)
			{
				this->_x *= v1._x;
				this->_y *= v1._y;
				return *this;
			}

           /*
            | ---------------------------------------------------------------------
            |		Operator *
            |       Vector * scalar
            | ---------------------------------------------------------------------
            */
            Vector2 operator*(const float& s) const
            {
                return Vector2(_x * s, _y * s);
            }

            /*
             | ---------------------------------------------------------------------
             |     Operator *
             |     Vector * Vector
             | ---------------------------------------------------------------------
             */
            Vector2 operator *(const Vector2& v) const
            {
                 return Vector2(_x * v.getX(), _y * v.getY());
            }

			/*
			 | ---------------------------------------------------------------------
			 |		Operator ==
			 | ---------------------------------------------------------------------
			 */
			bool operator == (const Vector2& v1) const
			{
				return (_x == v1._x && _y == v1._y);
			}

			/*
			 | ---------------------------------------------------------------------
			 |		Operator =
			 | ---------------------------------------------------------------------
			 */
			Vector2& operator = (const Vector2& v1)
			{
				_x = v1._x; _y = v1._y;
				return *this;
			}

			/*
			 | ---------------------------------------------------------------------
			 |		Operator !=
			 | ---------------------------------------------------------------------
			 */
			bool operator != (const Vector2& v1) const
			{
				return (_x != v1._x || _y != v1._y);
			}



			/*
			 * --------------------------------------------------------------------
			 *		Operator <<
			 * --------------------------------------------------------------------
			 */
			friend std::ostream& operator<<(std::ostream& os, const Vector2& v)
			{
				return os << "Vector2(" << v._x << ", " << v._y << ")";
			}


			/*
			 * ------------------------------------------------------------------
			 *		Gets X Component of the Vector
			 *		Returns float value
			 * ------------------------------------------------------------------
			 */
			float getX() const { return _x; }

			/*
			 * ------------------------------------------------------------------
			 *		Gets Y Component of the Vector
			 *		Returns float value
			 * ------------------------------------------------------------------
			 */
			float getY() const { return _y; }

			/*
			 * ------------------------------------------------------------------
			 *		Sets X Component of the Vector
			 *		Parameter float value of the Vector
			 * ------------------------------------------------------------------
			 */
			void setX(float x) { _x = x; }

			/*
			 * ------------------------------------------------------------------
			 *		Sets Y Component of the Vector
			 *		Parameter float value of the Vector
			 * ------------------------------------------------------------------
			 */
			void setY(float y) { _y = y; }

			static const Vector2 _S_VECTOR2_ZERO;

		private:
			float _x;
			float _y;
		};

		/*
		 * ------------------------------------------------------------------
		 *		Helper function to print Vector to standard output
		 * ------------------------------------------------------------------
		 */
		void printV2(const Vector2& v);

		/*
		 * ------------------------------------------------------------------
		 *		Distance between two vectors
		 *		Returns float value
		 * ------------------------------------------------------------------
		 */
		float distance(const Vector2 &v1, const Vector2 &v2);

		/*
		 * --------------------------------------------------------------------
		 *		Dot product of two vectors
		 *	    if dot product of normalized vectors results:\n
		 *      1 - vectors are pointing in the same direction\n
		 *	    0 - vectors are perpendicular\n
		 *     -1 - vectors are pointing in inverse directions\n
		 * --------------------------------------------------------------------
		 */
		float dot(const Vector2& v1, const Vector2& v2);

		/*
		 * --------------------------------------------------------------------
		 *		Adds two vectors
		 *		Returns Vector2
		 * --------------------------------------------------------------------
		 */
		Vector2 add(const Vector2& v1, const Vector2& v2);

		/*
		 * -------------------------------------------------------------------
		 *		Substracts two vectors
		 *		Returns Vector2
		 * -------------------------------------------------------------------
		 */
		Vector2 subtract(const Vector2& v1, const Vector2& v2);
	}    // end of math namespace
}    // end of rodeo namespace
#endif