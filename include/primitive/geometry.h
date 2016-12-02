/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
//#ifndef LAURA_PRIMITIVE_GEOMETRY_H_
//#define LAURA_PRIMITIVE_GEOMETRY_H_
//
//#ifndef LAURA_RENDERER_RENDERMODE_H_
//#include "renderer\rendermode.h"
//#endif
//
//#ifndef LAURA_ENTITY_MODEL3D_H_
//#include "entity\model3d.h"
//#endif
//
//#ifndef LAURA_MATH_VECTOR3_H_
//#include "math\vector3.h"
//#endif
//
//namespace laura
//{
//namespace primitive
//{
//class RenderBuffers
//{
//public:
//    ~RenderBuffers(){}
//    unsigned int _vertex_buffer;
//    unsigned int _normal_buffer;
//    unsigned int _texture_buffer;
//    unsigned int _index_buffer;
//protected:
//    RenderBuffers(){}
//};
//
//// ---- LINE ---- //
//struct Line : public entity::Entity
//{
//    Line(){}
//    virtual ~Line(){}
//
//    math::Vector3 start;
//    math::Vector3 end;
//
//    virtual void draw();
//    void draw(float x, float y);
//};
//
//// ---- POINT ---- //
//struct Point : public entity::Entity
//{
//    virtual ~Point(){}
//    virtual void draw();
//    virtual void setPosition(float px, float py, float pz);
//
//    float _x;
//    float _y;
//    float _size;
//};
//
//// ---- SPHERE ---- //
//class Sphere : public entity::Entity
//{
//public:
//    Sphere(){}
//
//    ~Sphere(){}
//
//};
//
//// ---- GRID ---- //
//struct Grid : public entity::Model3D
//{
//	// size of one quad in x 
//	float _quad_x;
//
//	// size of one quad in z 
//	float _quad_z;
//
//	// size of whole grid in x 
//	float _size_in_x;
//
//	// size of whole grid in z 
//	float _size_in_z;
//
//	// how many quads in a row (width) \n
//	// width = (row_quads - 1) * quad_x
//	float _row_quads;
//
//	// how many quads in a column (depth)
//	//depth = (column_quads - 1) * quad_z
//	float _column_quads;
//
//    // override method from enginecore::Entity 
//    virtual void draw();
//    void translate(float x, float y, float z);
//
//    //	
//    // Generates grid
//    // Parameter n - how many quads in x axis
//    // Parameter m - how many quads in z axis
//    void generate(unsigned short n, unsigned short m);
//
//    // Generates grid 
//    // Parameter qw, qh - width and height of single quad 
//    void generate(unsigned short n, unsigned short m, float qw, float qh);
//};
//
//class Geometry
//{
//public:
//    Geometry(){}
//
//    ~Geometry(){}
//};
//}
//}
//#endif