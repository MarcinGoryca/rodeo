/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_ENTITY_BOUNDINGVOLUME_H_
#define MG_ENTITY_BOUNDINGVOLUME_H_

#ifndef MG_PRIMITIVE_GEOMETRY_H_
#include "primitive\geometry.h"
#endif

namespace mg
{
namespace entity
{
class BoundingVolume
{
public:
    BoundingVolume(){}

    ~BoundingVolume(){}

    // Get Radius
    float getRadius() const
    {
        return radius_;
    }

    // Sets the radius
    void setRadius(float new_radius)
    {
        radius_ = new_radius;
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
    float radius_;
    //jennieprimitive::Cube* bounding_box_;
};
}    // end of primitive namespace
}    // end of mg namespace
#endif