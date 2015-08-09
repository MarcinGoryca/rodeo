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
     :x_(0.0f),
      y_(0.0f)
    {}
    
    // ---- //
    Vector2(float x1, float y1)
        :x_(x1),
         y_(y1)
    {}
    
    // ---- //
    Vector2(const Vector2& v)
        :x_(v.x_),
         y_(v.y_)
    {}
    
    // ---- //
    ~Vector2(){}

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
        this->x_ += v1.x_;
        this->y_ += v1.y_;
        return *this;
    }

    // ----//
    inline  Vector2& operator+= (const float& scalar)
    {
        this->x_ += scalar;
        this->y_ += scalar;
        return *this;
    }

    // ---- //
    inline Vector2& operator/= (const float& scalar)
    {
        this->x_ /= scalar;
        this->y_ /= scalar;
        return *this;
    }

    // ---- //
    inline Vector2& operator *= (const float& scalar)
    {
        this->x_ *= scalar;
        this->y_ *= scalar;
        return *this; 
    }

    // ---- //
    inline Vector2& operator-=(const Vector2& v1)
    {
        this->x_ -= v1.x_;
        y_ -= v1.y_;
        return *this;
    }

    // ---- //
    inline Vector2& operator*=(const Vector2& v1)
    {
        this->x_ *= v1.x_;
        this->y_ *= v1.y_;
        return *this;
    }

    // ---- //
    inline Vector2& operator /=(const Vector2& v1)
    {
        x_ /= v1.x_;
        y_ /= v1.y_;
        return *this;
    }

    // ---- //
    inline Vector2 operator+(const Vector2& v1)
    {
        return Vector2(v1.x_ + x_,	v1.y_ + y_); 
    }

    // ---- //
    inline bool operator == (const Vector2& v1) const 
    { 
        return (x_ == v1.x_ && y_ == v1.y_); 
    }

    // ---- //
    inline Vector2& operator = (const Vector2& v1)
    { 
        x_ = v1.x_; y_ = v1.y_;
        return *this;
    }

    // ---- //
    inline bool operator != (const Vector2& v1) const
    {
        return (x_ != v1.x_ || y_ != v1.y_);
    }

    /**
     * @brief Negates a vector
     * @return Vector2 - negated
     */
    Vector2 operator - () const
    {
        return Vector2(-x_, -y_);
    }

    // ---- //
    Vector2 operator*(const float& s) const
    {
        return Vector2(x_ * s, y_ * s);
    }

    // ---- //
    Vector2 operator/(const float& s) const
    {
        float sc = 1.0f / s;
        return Vector2(x_ * sc, y_ * sc);
    }

    // ---- //
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v)
    {
        return os << "Vector2(" << v.x_ << ", " << v.y_ << ")";
    }

    // ---- //
    inline Vector2& operator+(const float& scalar)
    {
        this->x_ = this->x_ + scalar;
        this->y_ = this->y_ + scalar;
        return *this;
    }

    float x_;
    float y_;

    static const Vector2 S_VECTOR2_ZERO_;

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