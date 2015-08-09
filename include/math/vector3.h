/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_VECTOR3_H_
#define MG_MATH_VECTOR3_H_

#ifndef MG_MATH_MATHTOOLS_H_
#include "mathtools.h"
#endif

namespace mg
{
namespace math
{
class Vector3
{
public:
    Vector3()
        :x_(0.0f),
         y_(0.0f),
         z_(0.0f)
    {}
    
    // ---- //
    Vector3(float x, float y, float z)
        :x_(x),
         y_(y),
         z_(z)
    {}

    // Copy Constructor 
    Vector3(const Vector3& v)
        :x_(v.x_),
         y_(v.y_),
         z_(v.z_)
    {}

    // ---- //
    ~Vector3(){}

    // Static Vector, Vector3(0.0f, 0.0f, 0.0f);
    // Example: enginemath::Vector3::S_VECTOR3_ZERO_;
    static const Vector3 S_VECTOR3_ZERO_;

    // Returns this Vector
    Vector3 get() const { return *this; }

    // Length [Magnitude] = sqrt( x * x + y * y + z * z )
    // Returns float value - length of a vector
    float length();

    // Dot Product of two Vectors
    // Returns float scalar value 
    inline float dot(const Vector3& v1)
    {
         return x_ * v1.x_ + y_ * v1.y_ + z_ * v1.z_; 
    }

    // Negating vector
    // Returns Vector3
    Vector3& negate()
    {
        x_ = - x_;
        y_ = - y_;
        z_ = - z_;
        return *this;
    }

    // Cross Product of two 3D vectors
    // Cross Product returns third vector perpendicular to other two\n
    //   IF Cross AND Dot are used together, the Cross is first in equation
    inline Vector3 cross(Vector3& v1, Vector3& v2)
    {
        return Vector3(v1.y_ * v2.z_ - v1.z_ * v2.y_,
                       v1.z_ * v2.x_ - v1.x_ * v2.z_,
                       v1.x_ * v2.y_ - v1.y_ * v2.x_);
    }

    // Overloaded Operator+
    // Returns Vector3
    // Example:
    // Vector3 a;
    // Vector3 b;
    // a = a + b;
    inline Vector3 operator+(const Vector3& vector3)
    {
        Vector3 result;
        result.x_ = x_ + vector3.x_;
        result.y_ = y_ + vector3.y_;
        result.z_ = z_ + vector3.z_;
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
        result.x_ = x_ - vector3.x_;
        result.y_ = y_ - vector3.y_;
        result.z_ = z_ - vector3.z_;
        return result; 
    }

    inline const Vector3 operator-(const Vector3 vector3)const
    {
        //return Vector3(vector3.x_ - x_, vector3.y_ - y_, vector3.z_ - z_);
        Vector3 result;
        result.x_ = x_ - vector3.x_;
        result.y_ = y_ - vector3.y_;
        result.z_ = z_ - vector3.z_;
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
        this->x_ = this->x_ + scalar;
        this->y_ = this->y_ + scalar;
        this->z_ = this->z_ + scalar;
        return *this;
    }

    // Overloaded operator- (scalar)
    // Returns This Vector
    inline Vector3& operator-(const float& scalar)
    {
        this->x_ = this->x_ - scalar;
        this->y_ = this->y_ - scalar;
        this->z_ = this->z_ - scalar;
        return *this;
    }

    // Overloaded operator* (scalar)
    // Returns Vector
    inline Vector3 operator*(const float& number)
    {
        return Vector3(x_ * number, y_ * number, z_ * number);
    }

    // Overloaded operator*
    // Returns This vector
    inline Vector3& operator*(const Vector3& v)
    {
        x_ = x_ * v.x_;
        y_ = y_ * v.y_;
        z_ = z_ * v.z_;
        return *this;
    }

    // Overloaded operator/ (scalar)
    // Returns Vector
    inline Vector3 operator/(float number)
    {
        return Vector3(x_ / number, y_ / number, z_ / number);
    }

    // Overloaded operator+=
    // Returns This Vector
    // Example:
    // Vector3 a;
    // Vector3 b;
    // a += b;
    inline Vector3& operator+=(const Vector3& v1)
    {
        this->x_ += v1.x_;
        this->y_ += v1.y_;
        this->z_ += v1.z_;
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
        this->x_ -= v1.x_;
        this->y_ -= v1.y_;
        this->z_ -= v1.z_;
        return *this;
    }

    // Overloaded operator *=
    // Returns This Vector
    inline Vector3& operator*=(const Vector3& v1)
    {
        this->x_ *= v1.x_;
        this->y_ *= v1.y_;
        this->z_ *= v1.z_;
        return *this;
    }

    // Overloaded Operator /=
    // Returns This Vector
    inline Vector3& operator /=(const Vector3& v1)
    {
        this->x_ /= v1.x_;
        this->y_ /= v1.y_;
        this->z_ /= v1.z_;
        return *this;
    }

    // Overloaded Operator =
    // Returns This Vector
    inline Vector3& operator =(const Vector3& v1)
    {
        x_ = v1.x_;
        y_ = v1.y_;
        z_ = v1.z_;
        return *this;
    }

    // Overloaded Operator ==
    // Returns True if Vectors are equal;
    inline bool operator == (const Vector3& v1) const
    {
        return (x_ == v1.x_ && y_ == v1.y_ && z_ == v1.z_);
    }

    // Overloaded Operator !=
    // Returns True if Vectors are NOT equal
    inline bool operator != (const Vector3& v1) const
    {
        return (x_ != v1.x_ || y_ != v1.y_ || z_ != v1.z_);
    }

    // Print out the Vector to the standard output
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
    {
        return os << "Vector3(" << v.x_ << ", " << v.y_ << ", " << v.z_ << ")"; 
    }

    // Assigning default values to Vector
    inline void reset()
    {
        x_ = 0.0f;
        y_ = 0.0f;
        z_ = 0.0f;
    }

    // Cross Product
    // Parameter result - output Vector
    // Parameter v1 - first Input Vector
    // Parameter v2 - second Input Vector
    static Vector3 cross(Vector3& result, Vector3& v1, Vector3& v2)
    {
        result.x_ = v1.y_ * v2.z_ - v2.y_ * v1.z_;
        result.y_ = v1.x_ * v2.z_ - v2.x_ * v1.z_;
        result.z_ = v1.x_ * v2.y_ - v2.x_ * v1.y_;
        return result;
    }

    // Dot Product
    // Returns float value of dot product
    static float dot(const Vector3& v1, const Vector3& v2)
    {
        float dot_product = 0.0f;
        dot_product = v1.x_ * v2.x_ + v1.y_ * v2.y_ + v1.z_ * v2.z_;
        return dot_product;
    }

    // Normalizing the Vector
    // Returns This Vector
    Vector3& normalize()
    {
        float length = ::sqrt(this->x_ * this->x_ + this->y_ * this->y_ + this->z_ * this->z_);
        if(length > 0.0f)
        {
            this->x_ = this->x_ / length;
            this->y_ = this->y_ / length;
            this->z_ = this->z_ / length;
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

    float x_;
    float y_;
    float z_;
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
   result.x_ = v1.x_ + v2.x_;
   result.y_ = v1.y_ + v2.y_;
   result.z_ = v1.z_ + v2.z_;
   return result;
}

// Divides Vector by Scalar
// Returns product Vector of dividing
inline Vector3 divideByScalar(const Vector3& v1, float scalar)
{
   Vector3 result;
   result.x_ = v1.x_ / scalar;
   result.y_ = v1.y_ / scalar;
   result.z_ = v1.z_ / scalar;
   return result;
}

 /**
  * -- Linear Interpolation (LERP)
  * <ul>
  * <li>A - first vector</li>
  * <li>B - second vector</li>
  * <li>c - number, ranges from 0 to 1</li>
  * </ul>
  * <h3>L = LERP(A, B, c) = (1 - c) * A + c * B = [(1 - c) * Ax + c * Bx, (1 - c) * Ay + c * By, (1 - c) * Az + c * Bz]</h3>
  * Result position is determined by c
  * <ul>
  * <li>if c = 0.0, position = start (first vector A)</li>
  * <li>if c = 1.0, position = end (second vector B)</li>
  * <li>if c = 0.5, position = middle point between A and B</li>
  * </ul>
  */
inline Vector3 interpolate(Vector3 start, Vector3 end, float range=0.5f)
{
    Vector3 middle;

    middle.x_ = (1 - range) * start.x_ + range * end.x_;
    middle.y_ = (1 - range) * start.y_ + range * end.y_;
    middle.z_ = (1 - range) * start.z_ + range * end.z_;

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
    float length = ::sqrt(v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_);
    if(length > 0.0f)
    {
        v.x_ = v.x_ / length;
        v.y_ = v.y_ / length;
        v.z_ = v.z_ / length;
    }
}

/** Normalization */
inline Vector3 normalize(Vector3& v)
{
    Vector3 result;
    float length = ::sqrt(v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_);
    if(length > 0.0f)
    {
        v.x_ = v.x_ / length;
        v.y_ = v.y_ / length;
        v.z_ = v.z_ / length;
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
    float vx = v1.x_ - v2.x_;
    float vy = v1.y_ - v2.y_;
    float vz = v1.z_ - v2.z_;
    return sqrt(vx*vx + vy*vy + vz*vz);
}

/**
 * @details Dividing Vectors
 * @return Vector3 - this vector
 */
inline Vector3 subtract(Vector3& result, const Vector3& v1, const Vector3& v2)
{
    result.x_ = v1.x_ - v2.x_;
    result.y_ = v1.y_ - v2.y_;
    result.z_ = v1.z_ - v2.z_;

    return result;
}
}    // end of math namespace
}    // end of mg namespace
#endif