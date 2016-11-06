/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_MATH_VECTOR4_H_
#define LAURA_MATH_VECTOR4_H_

#ifndef LAURA_MATH_VECTOR3_H_
#include "vector3.h"
#endif

namespace laura
{
	namespace math
	{
		class Vector4
		{
		public:
			Vector4()
				:_x(0.0f),
				_y(0.0f),
				_z(0.0f),
				_w(0.0f)
			{}

			Vector4(float x, float y, float z, float w)
				:_x(x),
				_y(y),
				_z(z),
				_w(w)
			{}

			// Copy constructor
			Vector4(const Vector4& v)
				:_x(v._x), _y(v._y), _z(v._z), _w(v._w)
			{}

			~Vector4() {}

			/*
			 * ----------------------------------------------------------
			 *    Returns the vector
			 *    Returns Vector4
			 * ----------------------------------------------------------
			 */
			Vector4 get() const { return *this; }

			/*
			 * ----------------------------------------------------------
			 *    Sets the vector
			 * ----------------------------------------------------------
			 */
			inline void set(float x, float y, float z, float w)
			{
				_x = x; _y = y; _z = z; _w = w;
			}

			/*
			 * ----------------------------------------------------------
			 *    Sets the vector
			 * ----------------------------------------------------------
			 */
			inline void set(const Vector4& v)
			{
				_x = v._x;
				_y = v._y;
				_z = v._z;
				_w = v._w;
			}

			/*
			 * ---------------------------------------------------------
			 *		Sets the vector
			 * ---------------------------------------------------------
			 */
			inline void set(const Vector3& v)
			{
				_x = v.getX();
				_y = v.getY();
				_z = v.getZ();
				_w = 1.0f;
			}

			/*
			 * ----------------------------------------------------------  
			 *    Dot Product
			 *    Returns float value as dot product
			 * ----------------------------------------------------------
			 */
			inline float dot(const Vector4& v1)
			{
				return _x * v1._x + _y * v1._y + _z * v1._z + _w * v1._w;
			}

			/*
			 * ---------------------------------------------------------
			 *		Length of the Vector (Magnitude)
			 *      Returns float value of the Length
			 * ---------------------------------------------------------
			 */
			float length();

			/*
			 * ---------------------------------------------------------
			 *		Operator +
			 * ---------------------------------------------------------
			 */
			inline Vector4 operator+(const Vector4& v)
			{
				return Vector4(_x + v._x, _y + v._y, _z + v._z, v._w);
			}

			/*
			 * ---------------------------------------------------------
			 *		Operator -
			 * ---------------------------------------------------------
			 */
			inline Vector4 operator-(Vector4 v)
			{
				return Vector4(_x - v._x, _y - v._y, _z - v._z, v._w);
			}

			/*
			 * ---------------------------------------------------------
			 *		Operator -
			 * ---------------------------------------------------------
			 */
			inline const Vector4 operator-(const Vector4& v)const
			{
				return Vector4(_x - v._x, _y - v._y, _z - v._z, v._w);
			}

			/*
			 * -----------------------------------------------------------
			 *		Operator *
			 * -----------------------------------------------------------
			 */
			inline Vector4 operator*(const float& number)
			{
				return Vector4(_x * number, _y * number, _z * number, _w * number);
			}

			/*
			 * -----------------------------------------------------------
			 *		Operator *
			 * -----------------------------------------------------------
			 */
			inline Vector4& operator*(const Vector4& v)
			{
				_x = _x * v._x;
				_y = _y * v._y;
				_z = _z * v._z;
				_w = _w * v._w;
				return *this;
			}

			/*
			 * ---------------------------------------------------------------
			 *		Operator /
			 * ---------------------------------------------------------------
			 */
			inline Vector4 operator/(const float& number)
			{
				if (number == 0.0f)
				{
					std::cout << "Trying to dividing by 0, resetting the vector" << std::endl;
					return Vector4(_x, _y, _z, _w);
				}
				else
				{
					return Vector4(_x / number, _y / number, _z / number, _w / number);
				}
			}

			/*
			 * ----------------------------------------------------------
			 *		Operator +=
			 * ----------------------------------------------------------
			 */
			inline Vector4& operator+=(const Vector4& v1)
			{
				this->_x += v1._x;
				this->_y += v1._y;
				this->_z += v1._z;
				this->_w += v1._w;
				return *this;
			}

			/*
			 * ------------------------------------------------------------
			 *		Opeator -=
			 * ------------------------------------------------------------
			 */
			inline Vector4& operator-=(const Vector4& v1)
			{
				this->_x -= v1._x;
				this->_y -= v1._y;
				this->_z -= v1._z;
				this->_w -= v1._w;
				return *this;
			}

			/*
			 * ------------------------------------------------------------
			 *		Operator *= 
			 * ------------------------------------------------------------
			 */
			inline Vector4& operator*=(const Vector4& v1)
			{
				this->_x *= v1._x;
				this->_y *= v1._y;
				this->_z *= v1._z;
				this->_w *= v1._w;
				return *this;
			}

			/*
			 * -------------------------------------------------------
			 *		Operator /=
			 * -------------------------------------------------------
			 */
			inline Vector4& operator /=(const Vector4& v1)
			{
				this->_x /= v1._x;
				this->_y /= v1._y;
				this->_z /= v1._z;
				this->_w /= v1._w;
				return *this;
			}

			/*
			 * ------------------------------------------------------------------
			 *		Operator = 
			 * ------------------------------------------------------------------
			 */
			inline Vector4& operator =(const Vector4& v1)
			{
				_x = v1._x;
				_y = v1._y;
				_z = v1._z;
				_w = v1._w;
				return *this;
			}

			/*
			 * ---------------------------------------------------------------
			 *		Operator ==
			 * ---------------------------------------------------------------
			 */
			inline bool operator == (const Vector4& v1) const
			{
				return (_x == v1._x && _y == v1._y && _z == v1._z && _w == v1._w);
			}

			/*
			 * ----------------------------------------------------------------
			 *		Operator !=
			 * ----------------------------------------------------------------
			 */
			inline bool operator != (const Vector4& v1) const
			{
				return (_x != v1._x || _y != v1._y || _z != v1._z);
			}

			/*
			 * -----------------------------------------------------------------
			 *		Operator << 
			 * -----------------------------------------------------------------
			 */
			friend std::ostream& operator<<(std::ostream& os, const Vector4& v)
			{
				return os << "Vector4(" << v._x << ", " << v._y << ", " << v._z << ", " << v._w << ")";
			}

			/*
			 * -----------------------------------------------------------------
			 *		Operator &
			 * -----------------------------------------------------------------
			 */
			Vector4* operator&()
			{
				return this;
			}

			/*
			 * ---------------------------------------------------------------------------
			 *		Gets X Component of the Vector
			 *		Returns float value
			 * ---------------------------------------------------------------------------
			 */
			float getX() const { return _x; }

			/*
			 * ---------------------------------------------------------------------------
			 *		Gets Y Component of the Vector
			 *		Returns float value
			 * ---------------------------------------------------------------------------
			 */
			float getY() const { return _y; }

			/*
			 * ---------------------------------------------------------------------------
			 *		Gets Z Component of the Vector
			 *		Returns float value
			 * ---------------------------------------------------------------------------
			 */
			float getZ() const { return _z; }

			/*
			 * ---------------------------------------------------------------------------
			 *		Gets W Component of the Vector
			 *		Returns float value
			 * ---------------------------------------------------------------------------
			 */
			float getW() const { return _w; }

			/* 
			 * --------------------------------------------------------------------------
			 *		Sets X Component of the Vector
			 *		Parameter float value of the x
			 * --------------------------------------------------------------------------
			 */
			void setX(float x) { _x = x; }

			/*
			 * --------------------------------------------------------------------------
			 *		Sets Y Component of the Vector
			 *		Parameter float value of the y
			 * --------------------------------------------------------------------------
			 */
			void setY(float y) { _y = y; }

			/*
			 * --------------------------------------------------------------------------
			 *		Sets Z Component of the Vector
			 *		Parameter float value of the z
			 * --------------------------------------------------------------------------
			 */
			void setZ(float z) { _z = z; }

			/*
			 * --------------------------------------------------------------------------
			 *		Sets W Component of the Vector
			 *		Parameter float value of the w
			 * --------------------------------------------------------------------------
			 */
			void setW(float w) { _w = w; }
			
		private:
			float _x;
			float _y;
			float _z;
			float _w;
		};

		/*
		 * -----------------------------------------------------------------------
		 *       Helper function, prints the Vector to standard output  
		 *		 Parameter Vector4 - vector to print
		 * -----------------------------------------------------------------------
		 */
		void printV4(const Vector4& v);

		/*
		 * -----------------------------------------------------------------------
		 *		Helper function - prints out the Vector to the standard output
		 *      Parameter message - Message to the console
		 *		Parameter Vector4 - vector to print
		 * -----------------------------------------------------------------------
		 */
		void printV4(const char* message, const Vector4& v);
	}    // end of math namespace
}    // end of laura namespace
#endif