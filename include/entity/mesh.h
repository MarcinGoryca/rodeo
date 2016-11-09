///*
// |  -----------------------------------
// |    LAURA GAME ENGINE
// |    [ Mesh.h ] [ laura\entity ]
// |    Copyright(c) Marcin Goryca
// |    marcin.goryca@gmail.com
// |    http://marcingoryca.pl
// |  -----------------------------------
// */
//
//#ifndef LAURA_ENTITY_MESH_H_
//#define LAURA_ENTITY_MESH_H_
//
//#ifndef LAURA_MATH_VECTOR2_H_
//#include "math\vector2.h"
//#endif
//
//#ifndef LAURA_PRIMITIVE_GEOMETRYTOOLS_H_
//#include "primitive\geometrytools.h"
//#endif
//
//namespace laura
//{
//namespace entity
//{
//struct MeshVertex;
//struct MeshTriangle;
//struct MeshUV;
//struct MeshNormal;
//
//struct Mesh
//{
//    std::vector<MeshTriangle*> _triangles;
//    std::vector<MeshUV*> _coordinates;
//    std::vector<laura::math::Vector3> _normals;
//    std::vector<laura::math::Vector3> _vertex_normals;
//    std::vector<laura::math::Vector3> _surface_normals;
//
//    MeshVertex* _vertex;
//    MeshTriangle* _triangle;
//    MeshUV* _coordinate;
//    MeshNormal* _normal;
//    unsigned short _index;
//    unsigned int _vertex_count;
//    unsigned int _face_count;
//    unsigned int _uv_count;
//    unsigned int _normal_count;
//    unsigned int _vertex_normal_count;
//    unsigned int _surface_normal_count;
//    char _meshname[255];
//    const char* _mesh_name;
//    int _material_id;
//    bool _has_texture;
//
//    void reset();
//    void clear();
//    void init();
//    void generateNormals();
//    void generateVertexNormals();
//    void generateSurfaceNormals();
//};
//
//// MeshVertex
//struct MeshVertex
//{
//    laura::math::Vector3 _vertex;
//};
//
//
//// MeshTriangle
//struct MeshTriangle
//{
//    unsigned short _triangle[3];
//};
//
//// MeshUV
//struct MeshUV
//{
//    laura::math::Vector2 _uv;
//};
//
//// MeshNormal
//struct MeshNormal
//{
//    laura::math::Vector3 _normal;
//};
//
//
//// MeshMaterial
//struct MeshMaterial
//{
//    char _name[255];
//    char _file[255];
//    BYTE _color[3];
//    unsigned int _id;
//};
//}
//}
//#endif