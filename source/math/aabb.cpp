/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "math\aabb.h"

namespace mona
{
	namespace math
	{
		void AABB::resize()
		{
			_min = _min * 1.2f;
			_max = _max * 1.2f;
		}
	}
}