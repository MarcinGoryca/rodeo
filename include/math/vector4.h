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
        :x_(0.0f),
         y_(0.0f),
         z_(0.0f),
         w_(0.0f)
    {}

    // ---- //
    Vector4(float x, float y, float z, float w)
       :x_(x),
        y_(y),
        z_(z),
        w_(w)
    {}

    // Copy constructor
    Vector4(const Vector4& v)
        :x_(v.x_), y_(v.y_), z_(v.z_), w_(v.w_)
    {}

    // ---- //
    ~Vector4(){}

    // Returning the Vector
    Vector4 get() const { return *this; }

    // Setting the Vector
    inline void set(float x, float y, float z, float w)
    { 
        x_ = x; y_ = y; z_ = z; w_ = w; 
    }

    // Setting the vector
    inline void set(const Vector4& v)
    {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
        w_ = v.w_;
    }

    // ---- //
    inline void set(const Vector3& v)
    {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
        w_ = 1.0f;
    }

    // Dot Product
    // Returns float value as dot product
    inline float dot(const Vector4& v1)
    {
        return x_ * v1.x_ + y_ * v1.y_ + z_ * v1.z_ + w_ * v1.w_;
    }

    // Length of the Vector (Magnitude)
    // Returns float value of the Length
    float length();

    // ---- //
    inline Vector4 operator+(const Vector4& v)
    {
        return Vector4(x_ + v.x_, y_ + v.y_, z_ + v.z_, v.w_);
    }

    // ---- //
    inline Vector4 operator-(Vector4 v)
    {
        return Vector4(x_ - v.x_, y_ - v.y_, z_ - v.z_, v.w_);
    }

    // ---- //
    inline const Vector4 operator-(const Vector4& v)const
    {
        return Vector4(x_ - v.x_, y_ - v.y_, z_ - v.z_, v.w_);
    }

    // ---- //
    inline Vector4 operator*(const float& number)
    {
        return Vector4(x_ * number, y_ * number, z_ * number, w_ * number);
    }

    // ---- //
    inline Vector4& operator*(const Vector4& v)
    {
        x_ = x_ * v.x_;
        y_ = y_ * v.y_;
        z_ = z_ * v.z_;
        w_ = w_ * v.w_;
        return *this;
    }

    // ---- //
    inline Vector4 operator/(const float& number)
    {
        if(number == 0.0f)
        {
            std::cout << "Trying to dividing by 0, resetting the vector" << std::endl;
            return Vector4(x_, y_, z_, w_);
        }
        else
        {
            return Vector4(x_ / number, y_ / number, z_ / number, w_ / number);
        }
    }

    // ---- //
    inline Vector4& operator+=(const Vector4& v1)
    {
        this->x_ += v1.x_;
        this->y_ += v1.y_;
        this->z_ += v1.z_;
        this->w_ += v1.w_;
        return *this;
    }

    // ---- //
    inline Vector4& operator-=(const Vector4& v1)
    {
        this->x_ -= v1.x_;
        this->y_ -= v1.y_;
        this->z_ -= v1.z_;
        this->w_ -= v1.w_;
        return *this;
    }

    // ---- //
    inline Vector4& operator*=(const Vector4& v1)
    {
        this->x_ *= v1.x_;
        this->y_ *= v1.y_;
        this->z_ *= v1.z_;
        this->w_ *= v1.w_;
        return *this;
    }

    // ---- //
    inline Vector4& operator /=(const Vector4& v1)
    {
        this->x_ /= v1.x_;
        this->y_ /= v1.y_;
        this->z_ /= v1.z_;
        this->w_ /= v1.w_;
        return *this;
    }

    // ---- //
    inline Vector4& operator =(const Vector4& v1)
    {
        x_ = v1.x_;
        y_ = v1.y_;
        z_ = v1.z_;
        w_ = v1.w_;
        return *this;
    }

    // ---- //
    inline bool operator == (const Vector4& v1) const
    {
        return (x_ == v1.x_ && y_ == v1.y_ && z_ == v1.z_ && w_ == v1.w_);
    }

    // ---- //
    inline bool operator != (const Vector4& v1) const
    {
        return (x_ != v1.x_ || y_ != v1.y_ || z_ != v1.z_);
    }

    // ---- //
    friend std::ostream& operator<<(std::ostream& os, const Vector4& v)
    {
        return os << "Vector4(" << v.x_ << ", " << v.y_ << ", " << v.z_ << ", " << v.w_ << ")"; 
    }

    // ---- //
    Vector4* operator&()
    {
        return this;
    }

    float x_;
    float y_;
    float z_;
    float w_;
};

    // Helper function, prints the Vector to standard output  
    void printV4(const Vector4& v);

    // Helper function - prints out the Vector to the standard output
    // Parameter message - Message to the console
    void printV4(const char* message, const Vector4& v);
}    // end of math namespace
}    // end of mg namespace
#endif