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
    _winding = GL_CCW;
    load(filename, type);
}

//.................................//
Model3D::~Model3D()
{
    for(ui i=0; i < _model._mesh_count; ++i)
    {
        _buffer.destroy(_model, i);
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

  //_model = importer->_model;

  delete importer;

  buildAABB();

  create();
}

//.................................//
void Model3D::create()
{
    
    for(unsigned int i = 0; i < _model._mesh_count; ++i)
    {
        _model._mesh[i].generateNormals();
        _buffer.fill(_model, i);
    }
}

//.................................//
void Model3D::render()
{
    //push();
    glPolygonMode(_face_type, _face_mode);
    //polygonWinding(_winding);

    for(unsigned int i=0; i < _model._mesh_count; ++i)
    {
        if(_model._mesh[i]._has_texture)
        {
            bindTexture(_texture_id);
        }
        _buffer.draw(_model, i);
    }
    //pop();
}

//.................................//
void Model3D::scale(float scale_factor)
{
    for(ui i=0; i < _model._mesh_count; ++i)
    {
        _buffer.scale(_model, scale_factor, i);
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

    for(ui i = 0; i < _model._mesh_count; ++i)
    {
         for(ui j = 0; j < _model._mesh[i]._vertex_count; ++j)
         {
            _box.add(_model._mesh[i]._vertex[j]._vertex);
         }
    }
}

//.................................//
void Model3D::bindTexture(ui& texture_id)
{
    for(ui i = 0; i < _model._mesh_count; ++i)
    {
        if(_model._mesh[i]._has_texture)
        {
            glBindTexture(GL_TEXTURE_2D, texture_id);
        }
    }
}

//.................................//
void Model3D::update()
{
    _buffer.reset();
    create();
}

//.................................//
void Model3D::release()
{
    for(ui i = 0; i < _model._mesh_count; ++i)
    {
        _buffer.destroy(_model, i);
    }
}

//.................................//
void Model3D::update(float dt)
{
    //rotate(15.0f, 1.0f, 0.0f, 0.0f);
}
}    // end of entity namespace
}    // end of mg namespace