/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_MATH_VECTOR3_H_
#define LAURA_MATH_VECTOR3_H_

#ifndef LAURA_MATH_MATHTOOLS_H_
#include "mathtools.h"
#endif

namespace laura
{
	namespace math
	{
		class Vector3
		{
		public:
			Vector3()
				:_x(0.0f),
				_y(0.0f),
				_z(0.0f)
			{}

			Vector3(float x, float y, float z)
				:_x(x),
				_y(y),
				_z(z)
			{}

			/*
			 * --------------------------------------------------------------------
			 *		Copy Constructor 
			 * --------------------------------------------------------------------
			 */
			Vector3(const Vector3& v)
				:_x(v._x),
				_y(v._y),
				_z(v._z)
			{}

			~Vector3() {}

			/*
			 * --------------------------------------------------------------------
			 *      Static Vector, Vector3(0.0f, 0.0f, 0.0f);
			 *      Example: laura::math::Vector3::S_VECTOR3_ZERO_;
			 * --------------------------------------------------------------------
			 */
			static const Vector3 S_VECTOR3_ZERO_;

			/*
			 * --------------------------------------------------------------------
			 *		Gets this Vector
			 *		Returns Vector3
			 * --------------------------------------------------------------------
			 */
			Vector3 get() const { return *this; }

			/*
			 * --------------------------------------------------------------------
			 *		Length [Magnitude] = sqrt( x * x + y * y + z * z )
			 *      Returns float value - length of a vector
			 * --------------------------------------------------------------------
			 */
			float length();

			/*
			 * --------------------------------------------------------------------
			 *		Dot Product of two Vectors
			 *		Returns float scalar value 
			 * --------------------------------------------------------------------
			 */
			inline float dot(const Vector3& v1)
			{
				return _x * v1._x + _y * v1._y + _z * v1._z;
			}

			/*
			 * --------------------------------------------------------------------
			 *		Negating vector
			 *		Returns Vector3
			 * --------------------------------------------------------------------
			 */
			Vector3& negate()
			{
				_x = -_x;
				_y = -_y;
				_z = -_z;
				return *this;
			}

			/*
			 * ---------------------------------------------------------------------
			 *		Cross Product of two 3D vectors
			 *      Cross Product returns third vector perpendicular to other two\n
			 *      IF Cross AND Dot are used together, the Cross is first in equation
			 * ---------------------------------------------------------------------
			 */
			inline Vector3 cross(Vector3& v1, Vector3& v2)
			{
				return Vector3(v1._y * v2._z - v1._z * v2._y,
					v1._z * v2._x - v1._x * v2._z,
					v1._x * v2._y - v1._y * v2._x);
			}

			/*
			 * ---------------------------------------------------------------------
			 *		Overloaded Operator+
			 *		Returns Vector3
			 *		Example:
			 *		Vector3 a;
			 *		Vector3 b;
			 *		a = a + b;
			 * ---------------------------------------------------------------------
			 */
			inline Vector3 operator+(const Vector3& vector3)
			{
				Vector3 result;
				result._x = _x + vector3._x;
				result._y = _y + vector3._y;
				result._z = _z + vector3._z;
				return result;
			}

			// Overloaded Operator-
			// Returns Vector
			// Example:
			// Vector3 a;
			// Vector3 b;
			// a = a - b;
			inline Vector3 operator-(const Vector3& vector3)
			{
				Vector3 result;
				result._x = _x - vector3._x;
				result._y = _y - vector3._y;
				result._z = _z - vector3._z;
				return result;
			}

			inline const Vector3 operator-(const Vector3 vector3)const
			{
				//return Vector3(vector3._x - _x, vector3._y - _y, vector3._z - _z);
				Vector3 result;
				result._x = _x - vector3._x;
				result._y = _y - vector3._y;
				result._z = _z - vector3._z;
				return result;
			}

			// Overloaded Vector
			// Returns This Vector
			// Example:
			// Vector3 a;
			// float b;
			// a = a + b;
			inline Vector3& operator+(const float& scalar)
			{
				this->_x = this->_x + scalar;
				this->_y = this->_y + scalar;
				this->_z = this->_z + scalar;
				return *this;
			}

			// Overloaded operator- (scalar)
			// Returns This Vector
			inline Vector3& operator-(const float& scalar)
			{
				this->_x = this->_x - scalar;
				this->_y = this->_y - scalar;
				this->_z = this->_z - scalar;
				return *this;
			}

			// Overloaded operator* (scalar)
			// Returns Vector
			inline Vector3 operator*(const float& number)
			{
				return Vector3(_x * number, _y * number, _z * number);
			}

			// Overloaded operator*
			// Returns This vector
			inline Vector3& operator*(const Vector3& v)
			{
				_x = _x * v._x;
				_y = _y * v._y;
				_z = _z * v._z;
				return *this;
			}

			// Overloaded operator/ (scalar)
			// Returns Vector
			inline Vector3 operator/(float number)
			{
				return Vector3(_x / number, _y / number, _z / number);
			}

			// Overloaded operator+=
			// Returns This Vector
			// Example:
			// Vector3 a;
			// Vector3 b;
			// a += b;
			inline Vector3& operator+=(const Vector3& v1)
			{
				this->_x += v1._x;
				this->_y += v1._y;
				this->_z += v1._z;
				return *this;
			}

			// Overloaded Operator -=
			// Returns this Vector
			// Example:
			// Vector3 a;
			// Vector3 b;
			// a -= b;
			inline Vector3& operator-=(const Vector3& v1)
			{
				this->_x -= v1._x;
				this->_y -= v1._y;
				this->_z -= v1._z;
				return *this;
			}

			// Overloaded operator *=
			// Returns This Vector
			inline Vector3& operator*=(const Vector3& v1)
			{
				this->_x *= v1._x;
				this->_y *= v1._y;
				this->_z *= v1._z;
				return *this;
			}

			// Overloaded Operator /=
			// Returns This Vector
			inline Vector3& operator /=(const Vector3& v1)
			{
				this->_x /= v1._x;
				this->_y /= v1._y;
				this->_z /= v1._z;
				return *this;
			}

			// Overloaded Operator =
			// Returns This Vector
			inline Vector3& operator =(const Vector3& v1)
			{
				_x = v1._x;
				_y = v1._y;
				_z = v1._z;
				return *this;
			}

			// Overloaded Operator ==
			// Returns True if Vectors are equal;
			inline bool operator == (const Vector3& v1) const
			{
				return (_x == v1._x && _y == v1._y && _z == v1._z);
			}

			// Overloaded Operator !=
			// Returns True if Vectors are NOT equal
			inline bool operator != (const Vector3& v1) const
			{
				return (_x != v1._x || _y != v1._y || _z != v1._z);
			}

			// Print out the Vector to the standard output
			friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
			{
				return os << "Vector3(" << v._x << ", " << v._y << ", " << v._z << ")";
			}

			// Assigning default values to Vector
			inline void reset()
			{
				_x = 0.0f;
				_y = 0.0f;
				_z = 0.0f;
			}

			// Cross Product
			// Parameter result - output Vector
			// Parameter v1 - first Input Vector
			// Parameter v2 - second Input Vector
			static Vector3 cross(Vector3& result, Vector3& v1, Vector3& v2)
			{
				result._x = v1._y * v2._z - v2._y * v1._z;
				result._y = v1._x * v2._z - v2._x * v1._z;
				result._z = v1._x * v2._y - v2._x * v1._y;
				return result;
			}

			// Dot Product
			// Returns float value of dot product
			static float dot(const Vector3& v1, const Vector3& v2)
			{
				float dot_product = 0.0f;
				dot_product = v1._x * v2._x + v1._y * v2._y + v1._z * v2._z;
				return dot_product;
			}

			// Normalizing the Vector
			// Returns This Vector
			Vector3& normalize()
			{
				float length = ::sqrt(this->_x * this->_x + this->_y * this->_y + this->_z * this->_z);
				if (length > 0.0f)
				{
					this->_x = this->_x / length;
					this->_y = this->_y / length;
					this->_z = this->_z / length;
				}
				return *this;
			}

			// TODO:
			// Delete this
			// Static subtracting method
			// Returns Vector3
			/*static Vector3 subtract(const Vector3& v1, const Vector3& v2)
			{
				Vector3 result(0.0f, 0.0f, 0.0f);
				result = v1 - v2;
				return result;
			}*/

			/*
			 * -----------------------------------------------------------------
			 *	Gets X Component of the Vector
			 *	Returns float value
			 * -----------------------------------------------------------------
			 */
			float getX() const { return _x; }

			/*
			 * -----------------------------------------------------------------
			 *	Get Y Component of the Vector
			 *  Returns float value
			 * -----------------------------------------------------------------
			 */
			float getY() const { return _y; }

			/*
			 * -----------------------------------------------------------------
			 *	Get Z Component of the Vector
			 *	Returns float value
			 * -----------------------------------------------------------------
			 */
			float getZ() const { return _z; }

			/*
			 * -----------------------------------------------------------------
			 *	Sets X Component of the Vector
			 *	Parameter float value of the x
			 * -----------------------------------------------------------------
			 */
			void setX(float x) { _x = x; }

			/*
			 * -----------------------------------------------------------------
			 *	Sets Y Component of the Vector
			 *	Parameter float value of the y
			 * -----------------------------------------------------------------
			 */
			void setY(float y) { _y = y; }

			/*
			 * -----------------------------------------------------------------
			 *	Sets Z Component of the Vector
			 *	Parameter float value of the z
			 * -----------------------------------------------------------------
			 */
			void setZ(float z) { _z = z; }

		private:
			float _x;
			float _y;
			float _z;
		};

		// Cross product of two Vectors
		// Returns Vector3 - perpendicular to argument Vectors
		Vector3 cross(const Vector3& v1, const Vector3& v2);

		// Helper function - prints out the Vector to standard Output
		void printV3(const Vector3& v);

		// Helper function - Prints out the Vector to standard output
		// Parameter message - Message to the console
		void printV3(const char* message, const Vector3& v);

		// Parameter Vector3 result - this vector will be returned
		// Parameter Vector3 v1 - first vector to add
		// Parameter Vector3 v2 - second vector to add
		// Adds two Vectors
		// Returns product Vector of two Vectors
		inline Vector3 add(Vector3& result, const Vector3& v1, const Vector3& v2)
		{
			result.setX(v1.getX() + v2.getX());
			result.setY(v1.getY() + v2.getY());
			result.setZ(v1.getZ() + v2.getZ());
			return result;
		}

		// Divides Vector by Scalar
		// Returns product Vector of dividing
		inline Vector3 divideByScalar(const Vector3& v1, float scalar)
		{
			Vector3 result;
			result.setX(v1.getX() / scalar);
			result.setY(v1.getY() / scalar);
			result.setZ(v1.getZ() / scalar);
			return result;
		}

		/**
		 * -----------------------------------------------------------------------------------------
		 *		Linear Interpolation (LERP)
		 * 
		 *		A - first vector
		 *		B - second vector
		 *		c - number, ranges from 0 to 1
		 *		L = LERP(A, B, c) = (1 - c) * A + c * B = [(1 - c) * Ax + c * Bx, (1 - c) * Ay + c * By, (1 - c) * Az + c * Bz]
		 *		Result position is determined by c
		 *		if c = 0.0, position = start (first vector A)
		 *		if c = 1.0, position = end (second vector B)
		 *		if c = 0.5, position = middle point between A and B
		 * -----------------------------------------------------------------------------------------
		 */
		inline Vector3 interpolate(Vector3 start, Vector3 end, float range = 0.5f)
		{
			Vector3 middle;

			middle.setX((1 - range) * start.getX() + range * end.getX());
			middle.setY((1 - range) * start.getY() + range * end.getY());
			middle.setZ((1 - range) * start.getZ() + range * end.getZ());

			return middle;
		}

		/** */
		inline Vector3 computeNormals(const Vector3& v1, const Vector3& v2, const Vector3& v3, Vector3 out)
		{
			Vector3 edge1(0.0f, 0.0f, 0.0f);
			Vector3 edge2(0.0f, 0.0f, 0.0f);

			edge1 = v2 - v1;
			edge2 = v3 - v1;

			out = Vector3::cross(out, edge1, edge2);
			out.normalize();

			return out;
		}

		/** */
		inline Vector3 vertexNormal(const Vector3& v1)
		{
			Vector3 result(0.0f, 0.0f, 0.0f);

			result = v1;
			result.normalize();
			return result;
		}

		/** Normalization */
		inline void norm(Vector3& v)
		{
			float length = ::sqrt(v.getX() * v.getX() + v.getY() * v.getY() + v.getZ() * v.getZ());
			if (length > 0.0f)
			{
				v.setX(v.getX() / length);
				v.setY(v.getY() / length);
				v.setZ(v.getZ() / length);
			}
		}

		/** Normalization */
		inline Vector3 normalize(Vector3& v)
		{
			Vector3 result;
			float length = ::sqrt(v.getX() * v.getX() + v.getY() * v.getY() + v.getZ() * v.getZ());
			if (length > 0.0f)
			{
				v.setX(v.getX() / length);
				v.setY(v.getY() / length);
				v.setZ(v.getZ() / length);
				result = v;
			}
			return result;
		}
		/**
		 * @details Distance between two vectors
		 * @return float value of the distance
		 */
		inline float distance(const Vector3 &v1, const Vector3 &v2)
		{
			float vx = v1.getX() - v2.getX();
			float vy = v1.getY() - v2.getY();
			float vz = v1.getZ() - v2.getZ();
			return sqrt(vx*vx + vy*vy + vz*vz);
		}

		/**
		 * @details Dividing Vectors
		 * @return Vector3 - this vector
		 */
		inline Vector3 subtract(Vector3& result, const Vector3& v1, const Vector3& v2)
		{
			result.setX(v1.getX() - v2.getX());
			result.setY(v1.getY() - v2.getY());
			result.setZ(v1.getZ() - v2.getZ());

			return result;
		}
	}    // end of math namespace
}    // end of laura namespace
#endif