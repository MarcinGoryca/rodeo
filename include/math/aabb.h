/*
----------------------------------------------
    laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/

#ifndef LAURA_MATH_AABB_H_
#define LAURA_MATH_AABB_H_

#ifndef LAURA_MATH_VECTOR3_H_
#include "math\vector3.h"
#endif

namespace laura
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

	/*
	 * --------------------------------------------------------------------------
	 *
	 * --------------------------------------------------------------------------
	 */
    inline void add(const Vector3& p)
    {
        if(p.getX() < _min.getX())_min.setX(p.getX());
        if(p.getX() > _max.getX())_max.setX(p.getX());
        if(p.getY() < _min.getY())_min.setY(p.getY());
        if(p.getY() > _max.getY())_max.setY(p.getY());
        if(p.getZ() < _min.getZ())_min.setZ(p.getZ());
        if(p.getZ() > _max.getZ())_max.setZ(p.getZ());
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

		_min.setX(bignumber);
		_min.setY(bignumber);
		_min.setZ(bignumber);
		_max.setX(-bignumber);
		_max.setY(-bignumber);
		_max.setZ(-bignumber);
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