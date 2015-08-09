/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/

#ifndef MG_MATH_AABB_H_
#define MG_MATH_AABB_H_

#ifndef MG_MATH_VECTOR3_H_
#include "math\vector3.h"
#endif

namespace mg
{
namespace math
{
class AABB
{
public:
    AABB()
    :min_(0.0f, 0.0f, 0.0f),
     max_(0.0f, 0.0f, 0.0f)
    {
        reset();
    }

    ~AABB(){}

    inline void add(const Vector3& p)
    {
        if(p.x_ < min_.x_)min_.x_ = p.x_;
        if(p.x_ > max_.x_)max_.x_ = p.x_;
        if(p.y_ < min_.y_)min_.y_ = p.y_;
        if(p.y_ > max_.y_)max_.y_ = p.y_;
        if(p.z_ < min_.z_)min_.z_ = p.z_;
        if(p.z_ > max_.z_)max_.z_ = p.z_;
    }

    void construct();
    void resize();

    Vector3 getMinimun() const { return min_; }

    Vector3 getMaximum() const { return max_; }

private:
    // Before any operations with AABB we must reset it 
    inline void reset()
    {
        const float bignumber = 1e37f;

        min_.x_ = min_.y_ = min_.z_ = bignumber;
        max_.x_ = max_.y_ = max_.z_ = -bignumber;
    }

private:
    Vector3 min_;
    Vector3 max_;
};
}    // end of math namespace
}    // end of mg namespace

#endif    //ENGINE_MATH_AABB_H_

/*
    NOTES:
    1.
      X min  <=  X  <=  X max
      Y min  <=  Y  <=  Y max
      Z min  <=  Z  <=  Z max
    2.
      P min = [ Xmin Ymin Zmin ]
      P max = [ Xmax Ymax Zmax ]
    3. Center point
      C = (Pmin + Pmax) / 2
    4. Size vector, from Pmin to Pmax, contains width, height, length of the box
      S = Pmin - Pmax
    5. Radius vector, vector from center to Pmax
       R =  Pmax - C
       =  S / 2
    6. Computing the AABB for a set of points
      Our list of points
      const int n;
      Vector3 list[n];
      Empty the box
      AABB box;
      box.reset();
      Add each point into the box
      for(int i=0; i < n; ++i)
      {
           box.add(list[i]);
      }
*/