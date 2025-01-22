/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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

#ifndef RODEO_ENTITY_MESH_H_
#define RODEO_ENTITY_MESH_H_

#ifndef RODEO_MATH_VECTOR2_H_
#include "math\vector2.h"
#endif

#ifndef RODEO_PRIMITIVE_GEOMETRYTOOLS_H_
#include "primitive\geometrytools.h"
#endif

namespace rodeo
{
namespace entity
{
struct MeshVertex;
struct MeshTriangle;
struct MeshUV;
struct MeshNormal;

struct Mesh
{
    std::vector<MeshTriangle*> _triangles;
    std::vector<MeshUV*> _coordinates;
    std::vector<rodeo::math::Vector3> _normals;
    std::vector<rodeo::math::Vector3> _vertex_normals;
    std::vector<rodeo::math::Vector3> _surface_normals;

    MeshVertex* _vertex;
    MeshTriangle* _triangle;
    MeshUV* _coordinate;
    MeshNormal* _normal;
    unsigned short _index;
    unsigned int _vertex_count;
    unsigned int _face_count;
    unsigned int _uv_count;
    unsigned int _normal_count;
    unsigned int _vertex_normal_count;
    unsigned int _surface_normal_count;
    char _meshname[255];
    const char* _mesh_name;
    int _material_id;
    bool _has_texture;

    void reset();
    void clear();
    void init();
    void generateNormals();
    void generateVertexNormals();
    void generateSurfaceNormals();
};

// MeshVertex
struct MeshVertex
{
    rodeo::math::Vector3 _vertex;
};


// MeshTriangle
struct MeshTriangle
{
    unsigned short _triangle[3];
};

// MeshUV
struct MeshUV
{
    rodeo::math::Vector2 _uv;
};

// MeshNormal
struct MeshNormal
{
    rodeo::math::Vector3 _normal;
};


// MeshMaterial
struct MeshMaterial
{
    char _name[255];
    char _file[255];
    BYTE _color[3];
    unsigned int _id;
};
}
}
#endif