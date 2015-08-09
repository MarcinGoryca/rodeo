/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_MATH_QUATERNION_H_
#define MG_MATH_QUATERNION_H_

#ifndef MG_MATH_VECTOR4_H_
#include "math\vector4.h"
#endif

namespace mg
{
namespace math
{
class Quaternion
{
public:
    Quaternion()
        :x_(0.0f), y_(0.0f), z_(0.0f), w_(1.0f)
    {}

    // Constructing quaternion by vector
    Quaternion(const Vector4& v);

    // Parameter Vector3, float value
    Quaternion(const Vector3& v, float w);

    // ---- //
    Quaternion(float fx, float fy, float fz, float fw)
        :x_(fx), y_(fy), z_(fz), w_(fw)
    {}
    
    ~Quaternion(){}

    // Get the Quaternion
    const Quaternion& get() const;

    // Positive identity quaternion 
    // No angualar displacement [1, 0]
    static const void positiveIdentity();

    // Negative identity quatenion
    // No angular displacement [-1, 0]
    static const void negativeIdentity();

    // Sets Quaternion to Identity
    void identity();

    // Rotates about X-axis 
    void rotateAboutX(float angle);

    // Rotates about Y-axis 
    void rotateAboutY(float angle);

    // Rotates about Z-axis 
    void rotateAboutZ(float angle);

    // Rotates about specified axis 
    void rotateAboutAxis(const Vector3& axis, float angle);

    // Inverse quaternion q pow(-1) = [w -v] / length(q)
    void inverse(const Quaternion& q);

    // Negate vector 
    void negate();

    // Length of Quaternion 
    //	|| q || = sqrt(w^2 + x^2 + y^2 + z^2) 
    float length();

    // Cross Product 
    Quaternion operator* (const Quaternion& a)const;

    Quaternion& operator*= (const Quaternion& a);
    void normalize();
    float getRotationAngle()const;
    Vector3 getRotationAxis()const;
    inline float dot(const Quaternion& q1, const Quaternion& q2)
    {
        return q1.w_ * q2.w_ + q1.x_ * q2.x_ + q1.y_ * q2.y_ + q1.z_ * q2.z_;
    }

    float x_, y_, z_, w_;

private:
};

// Dot Product of two quaternions
// Returns float value of a dot product
float dotProduct(const Quaternion& q1, const Quaternion& q2);
Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t);

// Conjugate - negating vector part of a quaternion;
Quaternion conjugate(const Quaternion& q);
Quaternion power(const Quaternion& q, float exp);

// Multiplying quaternions
Quaternion multiply(const Quaternion& q1, const Quaternion& q2);

// Helper function - prints out Quaternion to standard output
const void printQ(const Quaternion& q);

// Helper function - prints out Quaternion to standard output
// Parameter message - Message to console
const void printQ(const char* message, const Quaternion& q);
}    // end of math namespace
}    // end of mg namespace
#endif

/*
 * NOTES:
 * Q = [w, v] == [w, (x, y, z)]
 * w - scalar
 * v - vector
 *
 * w = cos(angle(theta)/2)
 * v = sin(angle(theta)/2)
 *
 * Quaternions have a vector (x, y, z) - represents which axis the rotation occurs,
 * and a scalar - value of the angle
 * i = sqrt(-1);
 * i = j = k = sqrt(-1)
 * q = w + xi + yj + zk;
 * imaginary part (i, j, k) is not needed in programming
 * Normalizing a quaternion
 * magnitude = sqrt(w*w + x*x + y*y + z*z);
 * w = w / magnitude;
 * x = x / magnitude;
 * y = y / magnitude;
 * z = z / magnitude;
 * Multiplying quaternions
 * Q1, Q2;
 * (Q1 * Q2).w = (w1w2 - x1x2 - y1y2 - z1z2);
 * (Q1 * Q2).x = (w1x2 + x1w2 + y1z2 - z1y2);
 * (Q1 * Q2).y = (w1y2 - x1z2 + y1w2 + z1x2);
 * (Q1 * Q2).z = (w1z2 + x1y2 - y1x2 + z1w2);
 */
