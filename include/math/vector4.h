/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_VECTOR4_H_
#define MG_MATH_VECTOR4_H_

#ifndef MG_MATH_VECTOR3_H_
#include "vector3.h"
#endif

namespace mg
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

			// ---- //
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

			// ---- //
			~Vector4() {}

			// Returning the Vector
			Vector4 get() const { return *this; }

			// Setting the Vector
			inline void set(float x, float y, float z, float w)
			{
				_x = x; _y = y; _z = z; _w = w;
			}

			// Setting the vector
			inline void set(const Vector4& v)
			{
				_x = v._x;
				_y = v._y;
				_z = v._z;
				_w = v._w;
			}

			// ---- //
			inline void set(const Vector3& v)
			{
				_x = v._x;
				_y = v._y;
				_z = v._z;
				_w = 1.0f;
			}

			// Dot Product
			// Returns float value as dot product
			inline float dot(const Vector4& v1)
			{
				return _x * v1._x + _y * v1._y + _z * v1._z + _w * v1._w;
			}

			// Length of the Vector (Magnitude)
			// Returns float value of the Length
			float length();

			// ---- //
			inline Vector4 operator+(const Vector4& v)
			{
				return Vector4(_x + v._x, _y + v._y, _z + v._z, v._w);
			}

			// ---- //
			inline Vector4 operator-(Vector4 v)
			{
				return Vector4(_x - v._x, _y - v._y, _z - v._z, v._w);
			}

			// ---- //
			inline const Vector4 operator-(const Vector4& v)const
			{
				return Vector4(_x - v._x, _y - v._y, _z - v._z, v._w);
			}

			// ---- //
			inline Vector4 operator*(const float& number)
			{
				return Vector4(_x * number, _y * number, _z * number, _w * number);
			}

			// ---- //
			inline Vector4& operator*(const Vector4& v)
			{
				_x = _x * v._x;
				_y = _y * v._y;
				_z = _z * v._z;
				_w = _w * v._w;
				return *this;
			}

			// ---- //
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

			// ---- //
			inline Vector4& operator+=(const Vector4& v1)
			{
				this->_x += v1._x;
				this->_y += v1._y;
				this->_z += v1._z;
				this->_w += v1._w;
				return *this;
			}

			// ---- //
			inline Vector4& operator-=(const Vector4& v1)
			{
				this->_x -= v1._x;
				this->_y -= v1._y;
				this->_z -= v1._z;
				this->_w -= v1._w;
				return *this;
			}

			// ---- //
			inline Vector4& operator*=(const Vector4& v1)
			{
				this->_x *= v1._x;
				this->_y *= v1._y;
				this->_z *= v1._z;
				this->_w *= v1._w;
				return *this;
			}

			// ---- //
			inline Vector4& operator /=(const Vector4& v1)
			{
				this->_x /= v1._x;
				this->_y /= v1._y;
				this->_z /= v1._z;
				this->_w /= v1._w;
				return *this;
			}

			// ---- //
			inline Vector4& operator =(const Vector4& v1)
			{
				_x = v1._x;
				_y = v1._y;
				_z = v1._z;
				_w = v1._w;
				return *this;
			}

			// ---- //
			inline bool operator == (const Vector4& v1) const
			{
				return (_x == v1._x && _y == v1._y && _z == v1._z && _w == v1._w);
			}

			// ---- //
			inline bool operator != (const Vector4& v1) const
			{
				return (_x != v1._x || _y != v1._y || _z != v1._z);
			}

			// ---- //
			friend std::ostream& operator<<(std::ostream& os, const Vector4& v)
			{
				return os << "Vector4(" << v._x << ", " << v._y << ", " << v._z << ", " << v._w << ")";
			}

			// ---- //
			Vector4* operator&()
			{
				return this;
			}

			float _x;
			float _y;
			float _z;
			float _w;
		};

		// Helper function, prints the Vector to standard output  
		void printV4(const Vector4& v);

		// Helper function - prints out the Vector to the standard output
		// Parameter message - Message to the console
		void printV4(const char* message, const Vector4& v);
	}    // end of math namespace
}    // end of mg namespace
#endif