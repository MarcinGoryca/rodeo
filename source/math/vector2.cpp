/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include <iostream>
#include <math.h>
#include "..\include\math\vector2.h"

using namespace std;

namespace mg
{
namespace math
{

const Vector2 Vector2::S_VECTOR2_ZERO_(0.0f, 0.0f);

// ---- //
float Vector2::length()
{
	float length;
	length = sqrt(x_ * x_ + y_ * y_);
	return length;
}

// ---- //
void Vector2::normalize()
{
	float length;
	float temp = sqrt(x_ * x_ + y_ * y_);
	if(temp > 0.0f)
	{
		length = 1.0f / temp;
		x_ *= length;
		y_ *= length;
	}
}

// ---- //
void printV2(const Vector2& v)
{
	std::cout << "v2(" << v.x_ << ", " << v.y_ << ")" << std::endl;
}

// ---- //
float distance(const Vector2 &v1, const Vector2 &v2)
{
    float vx = v1.x_ - v2.x_;
    float vy = v1.y_ - v2.y_;
    return sqrt(vx*vx + vy*vy);
}

// ---- //
float dot(const Vector2& v1, const Vector2& v2)
{
    return v1.x_ * v2.x_ + v1.y_ * v2.y_; 
}

// ---- //
Vector2 add(const Vector2& v1, const Vector2& v2)
{
    Vector2 result;

    result.x_ = v1.x_ + v2.x_;
    result.y_ = v1.y_ + v2.y_;

    return result;
}

// ---- //
Vector2 subtract(const Vector2& v1, const Vector2& v2)
{
    Vector2 result;

    result.x_ = v1.x_ - v2.x_;
    result.y_ = v1.y_ - v2.y_;

    return result;
}
}    // end of math namespace
}    // end of mg namespace