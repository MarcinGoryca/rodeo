/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_ENTITY_MESH_H_
#define MG_ENTITY_MESH_H_

#ifndef MG_MATH_VECTOR2_H_
#include "math\vector2.h"
#endif

#ifndef MG_PRIMITIVE_GEOMETRYTOOLS_H_
#include "primitive\geometrytools.h"
#endif

namespace mg
{
namespace entity
{
struct MeshVertex;
struct MeshTriangle;
struct MeshUV;
struct MeshNormal;

struct Mesh
{
    std::vector<MeshTriangle*> triangles_;
    std::vector<MeshUV*> coordinates_;
    std::vector<mg::math::Vector3> normals_;
    std::vector<mg::math::Vector3> vertex_normals_;
    std::vector<mg::math::Vector3> surface_normals_;

    MeshVertex* vertex_;
    MeshTriangle* triangle_;
    MeshUV* coordinate_;
    MeshNormal* normal_;
    mg::core::us index_;
    mg::core::ui vertex_count_;
    mg::core::ui face_count_;
    mg::core::ui uv_count_;
    mg::core::ui normal_count_;
    mg::core::ui vertex_normal_count_;
    mg::core::ui surface_normal_count_;
    char meshname_[255];
    const char* mesh_name_;
    int material_id_;
    bool has_texture_;

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
    mg::math::Vector3 vertex_;
};


// MeshTriangle
struct MeshTriangle
{
    mg::core::us triangle_[3];
};

// MeshUV
struct MeshUV
{
    mg::math::Vector2 uv_;
};

// MeshNormal
struct MeshNormal
{
    mg::math::Vector3 normal_;
};


// MeshMaterial
struct MeshMaterial
{
    char name_[255];
    char file_[255];
    BYTE color_[3];
    mg::core::ui id_;
};
}    // end of entity namespace
}    // end of mg namespace
#endif