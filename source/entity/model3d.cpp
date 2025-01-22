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
#include "entity\model3D.h"

using namespace rodeo::io;
using namespace rodeo::core;
using namespace rodeo::renderer;

namespace rodeo
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
    for(unsigned int i=0; i < _model._mesh_count; ++i)
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
    for(unsigned int i=0; i < _model._mesh_count; ++i)
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

    for(unsigned int i = 0; i < _model._mesh_count; ++i)
    {
         for(unsigned int j = 0; j < _model._mesh[i]._vertex_count; ++j)
         {
            _box.add(_model._mesh[i]._vertex[j]._vertex);
         }
    }
}

//.................................//
void Model3D::bindTexture(unsigned int& texture_id)
{
    for(unsigned int i = 0; i < _model._mesh_count; ++i)
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
    for(unsigned int i = 0; i < _model._mesh_count; ++i)
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
}    // end of rodeo namespace
