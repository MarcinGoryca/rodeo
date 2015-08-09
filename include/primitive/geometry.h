/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_PRIMITIVE_GEOMETRY_H_
#define MG_PRIMITIVE_GEOMETRY_H_

#ifndef MG_RENDERER_RENDERMODE_H_
#include "renderer\rendermode.h"
#endif

#ifndef MG_ENTITY_MODEL3D_H_
#include "entity\model3d.h"
#endif

#ifndef MG_MATH_VECTOR3_H_
#include "math\vector3.h"
#endif

namespace mg
{
namespace primitive
{
class RenderBuffers
{
public:
    ~RenderBuffers(){}
    core::ui vb;
    core::ui nb;
    core::ui tb;
    core::ui ib;
protected:
    RenderBuffers(){}
};

// ---- LINE ---- //
struct Line : public entity::Entity
{
    Line(){}
    virtual ~Line(){}

    math::Vector3 start;
    math::Vector3 end;

    virtual void draw();
    void draw(float x, float y);
};

// ---- POINT ---- //
struct Point : public entity::Entity
{
    virtual ~Point(){}
    virtual void draw();
    virtual void setPosition(float px, float py, float pz);

    float x_;
    float y_;
    float size_;
};

// ---- SPHERE ---- //
class Sphere : public entity::Entity
{
public:
    Sphere(){}

    ~Sphere(){}

};

// ---- GRID ---- //
struct Grid : public entity::Model3D
{

    // override method from enginecore::Entity 
    virtual void draw();
    void translate(float x, float y, float z);

    //	
    // Generates grid
    // Parameter n - how many quads in x axis
    // Parameter m - how many quads in z axis
    void generate(core::us n, core::us m);

    // Generates grid 
    // Parameter qw, qh - width and height of single quad 
    void generate(core::us n, core::us m, float qw, float qh);

    // size of one quad in x 
    float quad_x;

    // size of one quad in z 
    float quad_z;

    // size of whole grid in x 
    float size_in_x;

    // size of whole grid in z 
    float size_in_z;

    // how many quads in a row (width) \n
    // width = (row_quads - 1) * quad_x
    float row_quads;

    // how many quads in a column (depth)
    //depth = (column_quads - 1) * quad_z
    float column_quads;

};

class Geometry
{
public:
    Geometry(){}

    ~Geometry(){}
};
}    // end of primitive namespace
}    // end of mg namespace
#endif