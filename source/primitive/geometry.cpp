/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "primitive\geometry.h"
#include "io\log.h"

using namespace mg::entity;
using namespace mg::math;
using namespace mg::core;

namespace mg
{
namespace primitive
{
void Line::draw()
{
}

/*
void Cube::build()
{
    Mesh mesh;
    mesh.reset();
    model_.mesh_.push_back(mesh);
    model_.mesh_count_++;
    model_.mesh_[0].vertex_count_ = 8;
    model_.mesh_[0].vertex_ = new MeshVertex[model_.mesh_[0].vertex_count_];
    ZeroMemory(model_.mesh_[0].vertex_, sizeof(model_.mesh_[0].vertex_));
}

void Cube::build(const Vector3& v1, const Vector3& v2)
{
    Mesh mesh;
    mesh.reset();
    model_.mesh_.push_back(mesh);
    model_.mesh_count_++;
    model_.mesh_[0].vertex_count_ = 8;
    model_.mesh_[0].vertex_ = new MeshVertex[model_.mesh_[0].vertex_count_];
    ZeroMemory(model_.mesh_[0].vertex_, sizeof(model_.mesh_[0].vertex_));

    model_.mesh_[0].vertex_[0].vertex_.x_ = v1.x_;
    model_.mesh_[0].vertex_[0].vertex_.y_ = v1.y_;
    model_.mesh_[0].vertex_[0].vertex_.z_ = v1.z_;

    model_.mesh_[0].vertex_[1].vertex_.x_ = v2.x_;
    model_.mesh_[0].vertex_[1].vertex_.y_ = v1.y_;
    model_.mesh_[0].vertex_[1].vertex_.z_ = v1.z_;

    model_.mesh_[0].vertex_[2].vertex_.x_ = v2.x_;
    model_.mesh_[0].vertex_[2].vertex_.y_ = v2.y_;
    model_.mesh_[0].vertex_[2].vertex_.z_ = v1.z_;

    model_.mesh_[0].vertex_[3].vertex_.x_ = v1.x_;
    model_.mesh_[0].vertex_[3].vertex_.y_ = v2.y_;
    model_.mesh_[0].vertex_[3].vertex_.z_ = v1.z_;

    model_.mesh_[0].vertex_[4].vertex_.x_ = v1.x_;
    model_.mesh_[0].vertex_[4].vertex_.y_ = v2.y_;
    model_.mesh_[0].vertex_[4].vertex_.z_ = v2.z_;

    model_.mesh_[0].vertex_[5].vertex_.x_ = v1.x_;
    model_.mesh_[0].vertex_[5].vertex_.y_ = v1.y_;
    model_.mesh_[0].vertex_[5].vertex_.z_ = v2.z_;

    model_.mesh_[0].vertex_[6].vertex_.x_ = v2.x_;
    model_.mesh_[0].vertex_[6].vertex_.y_ = v1.y_;
    model_.mesh_[0].vertex_[6].vertex_.z_ = v2.z_;

    model_.mesh_[0].vertex_[7].vertex_.x_ = v2.x_;
    model_.mesh_[0].vertex_[7].vertex_.y_ = v2.y_;
    model_.mesh_[0].vertex_[7].vertex_.z_ = v2.z_;

    Vector3 ta[8];

    for(int i=0; i < 8; ++i)
    {
        ta[i] = model_.mesh_[0].vertex_[i].vertex_;
    }

    model_.mesh_[0].face_count_ = 36;
    model_.mesh_[0].triangle_ = new MeshTriangle[model_.mesh_[0].face_count_];
    ZeroMemory(model_.mesh_[0].triangle_, sizeof(model_.mesh_[0].triangle_));

    model_.mesh_[0].triangle_[0].triangle_[0] = 0;
    model_.mesh_[0].triangle_[0].triangle_[1] = 1;
    model_.mesh_[0].triangle_[0].triangle_[2] = 2;

    model_.mesh_[0].triangle_[0].triangle_[3] = 2;
    model_.mesh_[0].triangle_[0].triangle_[4] = 3;
    model_.mesh_[0].triangle_[0].triangle_[5] = 0;

    model_.mesh_[0].triangle_[0].triangle_[6] = 4;
    model_.mesh_[0].triangle_[0].triangle_[7] = 5;
    model_.mesh_[0].triangle_[0].triangle_[8] = 6;

    model_.mesh_[0].triangle_[0].triangle_[9] = 6;
    model_.mesh_[0].triangle_[0].triangle_[10] = 7;
    model_.mesh_[0].triangle_[0].triangle_[11] = 4;

    model_.mesh_[0].triangle_[0].triangle_[12] = 1;
    model_.mesh_[0].triangle_[0].triangle_[13] = 6;
    model_.mesh_[0].triangle_[0].triangle_[14] = 7;

    model_.mesh_[0].triangle_[0].triangle_[15] = 7;
    model_.mesh_[0].triangle_[0].triangle_[16] = 2;
    model_.mesh_[0].triangle_[0].triangle_[17] = 1;

    model_.mesh_[0].triangle_[0].triangle_[18] = 4;
    model_.mesh_[0].triangle_[0].triangle_[19] = 5;
    model_.mesh_[0].triangle_[0].triangle_[20] = 0;

    model_.mesh_[0].triangle_[0].triangle_[21] = 0;
    model_.mesh_[0].triangle_[0].triangle_[22] = 3;
    model_.mesh_[0].triangle_[0].triangle_[23] = 4;

    model_.mesh_[0].triangle_[0].triangle_[24] = 5;
    model_.mesh_[0].triangle_[0].triangle_[25] = 0;
    model_.mesh_[0].triangle_[0].triangle_[26] = 1;

    model_.mesh_[0].triangle_[0].triangle_[27] = 1;
    model_.mesh_[0].triangle_[0].triangle_[28] = 6;
    model_.mesh_[0].triangle_[0].triangle_[29] = 5;

    model_.mesh_[0].triangle_[0].triangle_[30] = 4;
    model_.mesh_[0].triangle_[0].triangle_[31] = 3;
    model_.mesh_[0].triangle_[0].triangle_[32] = 2;

    model_.mesh_[0].triangle_[0].triangle_[33] = 2;
    model_.mesh_[0].triangle_[0].triangle_[34] = 7;
    model_.mesh_[0].triangle_[0].triangle_[35] = 4;

    setMeshCount(model_.mesh_count_);
    setVertexCount(model_.mesh_[0].vertex_count_);
    setIndexCount(model_.mesh_[0].face_count_);

    create();
}

void Cube::draw()
{
    face_type_ = GL_FRONT_AND_BACK;
    face_mode_ = GL_LINE;

    render();
}
*/
void Point::draw()
{
}

/* --- */
void Point::setPosition(float px, float py, float pz)
{
}

/* --- */
void Grid::draw()
{
    face_type_ = GL_FRONT_AND_BACK;
    face_mode_ = GL_LINE;
    render();
}

/* --- */
void Grid::translate(float x, float y, float z)
{

}

/* --- */
void Grid::generate(us n, us m)
{
    //w = (n-1) * dx
    //d = (m-1) * dz
    Mesh mesh;
    mesh.reset();

    model_.mesh_.push_back(mesh);
    model_.mesh_count_++;
    model_.mesh_[0].vertex_count_ = n * m;
    model_.mesh_[0].vertex_ = new MeshVertex[model_.mesh_[0].vertex_count_];
    ZeroMemory(model_.mesh_[0].vertex_, sizeof(model_.mesh_[0].vertex_));


    quad_x = 8.0f;
    quad_z = 8.0f;

    for(int i = 0; i < m; ++i)
    {

        float z = 0.5f - i * quad_z;

        for(int j = 0; j < n; ++j)
        {

            float x = -0.5f - j * quad_x;
            float y = 0.0f;

            model_.mesh_[0].vertex_[i * n + j].vertex_.x_ = x;
            model_.mesh_[0].vertex_[i * n + j].vertex_.y_ = y;
            model_.mesh_[0].vertex_[i * n + j].vertex_.z_ = z;
        }
    }

    //Generate indices for every vertex
    int k = 0;
    model_.mesh_[0].face_count_ = (m - 1) * (n -1) * 2;
    model_.mesh_[0].triangle_ = new MeshTriangle[model_.mesh_[0].face_count_];

    for(us i = 0; i < m - 1; ++i)
    {
        for(us j = 0; j < n - 1; ++j)
        {
            model_.mesh_[0].triangle_[0].triangle_[k] = i * n + j;
            model_.mesh_[0].triangle_[0].triangle_[k+1] = i * n + j + 1;
            model_.mesh_[0].triangle_[0].triangle_[k+2] = (i + 1) * n + j;
            model_.mesh_[0].triangle_[0].triangle_[k+3] = (i + 1) * n + j;
            model_.mesh_[0].triangle_[0].triangle_[k+4] = i * n + j + 1;
            model_.mesh_[0].triangle_[0].triangle_[k+5] = (i+1) * n + j + 1;
            k += 6;
        }
    }

    setMeshCount(model_.mesh_count_);
    setVertexCount(model_.mesh_[0].vertex_count_);
    setIndexCount(model_.mesh_[0].face_count_);
//Creating Axis Aligned Bounding Box
    //box_.reset();

    for(ui i=0; i<model_.mesh_[0].face_count_; ++i)
    {
        box_.add(model_.mesh_[0].vertex_[0].vertex_);
    }

    create();
}

/* --- */
void Grid::generate(us n, us m, float qw, float qh)
{
    //w = (n-1) * dx
    //d = (m-1) * dz
    Mesh mesh;
    mesh.reset();
    mesh.mesh_name_ = "JENNIE Standard Grid";
    memcpy(mesh.meshname_, mesh.mesh_name_, sizeof(mesh.meshname_));

    model_.mesh_.push_back(mesh);
    model_.mesh_count_++;
    model_.mesh_[0].vertex_count_ = n * m;
    model_.mesh_[0].vertex_ = new MeshVertex[model_.mesh_[0].vertex_count_];
    ZeroMemory(model_.mesh_[0].vertex_, sizeof(model_.mesh_[0].vertex_));

    quad_x = qw;
    quad_z = qh;

    for(us i = 0; i < m; ++i)
    {

        float z = 0.5f - i * quad_z;

        for(us j = 0; j < n; ++j)
        {

            float x = -0.5f - j * quad_x;
            float y = 0.0f;

            model_.mesh_[0].vertex_[i * n + j].vertex_.x_ = x;
            model_.mesh_[0].vertex_[i * n + j].vertex_.y_ = y;
            model_.mesh_[0].vertex_[i * n + j].vertex_.z_ = z;
        }
    }

    //Generate indices for every vertex
    us k = 0;
    model_.mesh_[0].face_count_ = (m - 1) * (n -1) * 2;
    model_.mesh_[0].triangle_ = new MeshTriangle[model_.mesh_[0].face_count_];

    for(us i = 0; i < m - 1; ++i)
    {
        for(us j = 0; j < n - 1; ++j)
        {
            model_.mesh_[0].triangle_[0].triangle_[k] = i * n + j;
            model_.mesh_[0].triangle_[0].triangle_[k+1] = i * n + j + 1;
            model_.mesh_[0].triangle_[0].triangle_[k+2] = (i + 1) * n + j;
            model_.mesh_[0].triangle_[0].triangle_[k+3] = (i + 1) * n + j;
            model_.mesh_[0].triangle_[0].triangle_[k+4] = i * n + j + 1;
            model_.mesh_[0].triangle_[0].triangle_[k+5] = (i+1) * n + j + 1;
            k += 6;
        }
    }

    setMeshCount(model_.mesh_count_);
    setVertexCount(model_.mesh_[0].vertex_count_);
    setIndexCount(model_.mesh_[0].face_count_);

    //model_.mesh_[0].has_texture_ = true;

//Creating Axis Aligned Bounding Box
    winding_ = GL_CW;
    create();
}
}    // end of primitive namespace
}    // end of mg namespace