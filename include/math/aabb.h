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
    :_min(0.0f, 0.0f, 0.0f),
     _max(0.0f, 0.0f, 0.0f)
    {
        reset();
    }

    ~AABB(){}

    inline void add(const Vector3& p)
    {
        if(p._x < _min._x)_min._x = p._x;
        if(p._x > _max._x)_max._x = p._x;
        if(p._y < _min._y)_min._y = p._y;
        if(p._y > _max._y)_max._y = p._y;
        if(p._z < _min._z)_min._z = p._z;
        if(p._z > _max._z)_max._z = p._z;
    }

    void construct();
    void resize();

    Vector3 getMinimun() const { return _min; }

    Vector3 getMaximum() const { return _max; }

private:
    Vector3 _min;
    Vector3 _max;

	// Before any operations with AABB we must reset it 
	inline void reset()
	{
		const float bignumber = 1e37f;

		_min._x = _min._y = _min._z = bignumber;
		_max._x = _max._y = _max._z = -bignumber;
	}
};
}
}

#endif

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