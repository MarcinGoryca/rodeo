/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_PRIMITIVE_CUBE_H_
#define MG_PRIMITIVE_CUBE_H_

#ifndef MG_PRIMITIVE_GEOMETRY_H_
#include "primitive\geometry.h"
#endif

namespace mg
{
namespace primitive
{
/*
    Cube class is responsible for creating cubes.
*/

class Cube : public entity::Model3D
{
    Cube(){}
    virtual ~Cube(){}

    virtual void draw();
    void build();
    void build(const math::Vector3& v1, const math::Vector3& v2);

private:
    float vertex_array_[24];
    float vertex_data_[8];
    core::us vertex_indices_[24];
    float texture_uvs_array_[48];
    float normal_array_[24];
};
}    // end of primitive namespace
}    // end of mg namespace
#endif