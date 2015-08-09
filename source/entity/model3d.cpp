/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "entity\model3D.h"

using namespace mg::io;
using namespace mg::core;
using namespace mg::renderer;

namespace mg
{
namespace entity
{

Model3D::Model3D(const char* filename, File3DFactory::File3DType type)
{
    winding_ = GL_CCW;
    load(filename, type);
}

//.................................//
Model3D::~Model3D()
{
    for(ui i=0; i < model_.mesh_count_; ++i)
    {
        buffer_.destroy(model_, i);
    }
}

//.................................//
void Model3D::setDefaults()
{
    ZeroMemory(this, sizeof(this));
}

//.................................//
void Model3D::load(const char* filename, File3DFactory::File3DType type)
{
  Importer* importer = NULL;

  importer = File3DFactory::create(type);
  importer->import(filename);

  //model_ = importer->model_;

  delete importer;

  buildAABB();

  create();
}

//.................................//
void Model3D::create()
{
    
    for(ui i = 0; i < model_.mesh_count_; ++i)
    {
        model_.mesh_[i].generateNormals();
        buffer_.fill(model_, i);
    }
}

//.................................//
void Model3D::render()
{
    push();
    glPolygonMode(face_type_, face_mode_);
    polygonWinding(winding_);

    for(ui i=0; i < model_.mesh_count_; ++i)
    {
        if(model_.mesh_[i].has_texture_)
        {
            bindTexture(texture_id_);
        }
        buffer_.draw(model_, i);
    }
    pop();
}

//.................................//
void Model3D::scale(float scale_factor)
{
    for(ui i=0; i < model_.mesh_count_; ++i)
    {
        buffer_.scale(model_, scale_factor, i);
    }
}

//.................................//
void Model3D::draw()
{
    render();
}

//.................................//
void Model3D::buildAABB()
{	
    //box_.reset();

    for(ui i = 0; i < model_.mesh_count_; ++i)
    {
         for(ui j = 0; j < model_.mesh_[i].vertex_count_; ++j)
         {
            box_.add(model_.mesh_[i].vertex_[j].vertex_);
         }
    }
}

//.................................//
void Model3D::bindTexture(ui& texture_id)
{
    for(ui i = 0; i < model_.mesh_count_; ++i)
    {
        if(model_.mesh_[i].has_texture_)
        {
            glBindTexture(GL_TEXTURE_2D, texture_id);
        }
    }
}

//.................................//
void Model3D::update()
{
    buffer_.reset();
    create();
}

//.................................//
void Model3D::release()
{
    for(ui i = 0; i < model_.mesh_count_; ++i)
    {
        buffer_.destroy(model_, i);
    }
}

//.................................//
void Model3D::update(float dt)
{
    //rotate(15.0f, 1.0f, 0.0f, 0.0f);
}
}    // end of entity namespace
}    // end of mg namespace