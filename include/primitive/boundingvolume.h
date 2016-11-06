/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_ENTITY_BOUNDINGVOLUME_H_
#define LAURA_ENTITY_BOUNDINGVOLUME_H_

#ifndef LAURA_PRIMITIVE_GEOMETRY_H_
#include "primitive\geometry.h"
#endif

namespace laura
{
	namespace entity
	{
		class BoundingVolume
		{
		public:
			BoundingVolume() {}

			~BoundingVolume() {}

			// Get Radius
			float getRadius() const
			{
				return _radius;
			}

			// Sets the radius
			void setRadius(float new_radius)
			{
				_radius = new_radius;
			}

			// Get the Cube (bounding box)
			//jennieprimitive::Cube* getBoundingBox() const
			//{
			//    return bounding_box_;
			//}

			//// Sets Bounding Box
			//void setBoundingBox(jennieprimitive::Cube* new_cube)
			//{
			//    bounding_box_ = new_cube;
			//}

		private:
			float _radius;
		};
	}
}
#endif