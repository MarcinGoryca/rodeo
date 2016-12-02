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
//#ifndef LAURA_ENTITY_MODEL3D_H_
//#define LAURA_ENTITY_MODEL3D_H_
//
//#ifndef LAURA_ENTITY_ENTITY_H_
//#include "entity\entity.h"
//#endif
//
//#ifndef LAURA_IO_FILE3DFACTORY_H_
//#include "io\file3dfactory.h"
//#endif
//
//#ifndef LAURA_RENDERER_BUFFERS_H_
//#include "renderer\buffers.h"
//#endif
//
//#ifndef LAURA_RENDERER_RENDERMODE_H_
//#include "renderer\rendermode.h"
//#endif
//
//namespace laura
//{
//    namespace entity
//    {
//        class Texture;
//        class Vector3;
//        class Model3D : public laura::renderer::RenderMode, public Entity
//        {
//        public:
//            Model3D()
//                :Entity("", "model3d"),
//                _mesh_count(_model._mesh_count),
//                _material_count(_model._material_count),
//                _vertex_count(0),
//                _index_count(0),
//                _winding(GL_CCW)
//            {}
//
//            Model3D(const char* filename, laura::io::File3DFactory::File3DType type);
//
//            virtual ~Model3D();
//
//            void load(const char* filename, laura::io::File3DFactory::File3DType type);
//
//            void update();
//            void scale(float scale_factor);
//
//            virtual void draw();
//			virtual void release();
//			virtual void update(float dt);
//			void setDefaults();
//
//            unsigned int getMeshCount()const { return _mesh_count; }
//            unsigned int getMaterialCount()const { return _material_count; }
//            unsigned int getVertexCount()const { return _vertex_count; }
//            unsigned int getIndexCount()const { return _index_count; }
//
//            void setMeshCount(unsigned int mesh_count) { _mesh_count = mesh_count; }
//            void setMaterialCount(unsigned int material_count) { _material_count = material_count; }
//            void setVertexCount(unsigned int vertex_count) { _vertex_count = vertex_count; }
//            void setIndexCount(unsigned int index_count) { _index_count = index_count; }
//
//        protected:
//			Model _model;
//			laura::renderer::Buffers _buffer;
//
//			unsigned int _texture_id;
//			unsigned int _mesh_count;
//			unsigned int _material_count;
//			unsigned int _vertex_count;
//			unsigned int _index_count;
//
//			bool _has_texture;
//			bool _has_material;
//			GLenum _winding;
//
//            void create();
//            void buildAABB();
//
//            void render();
//
//            void bindTexture(laura::core::ui& texture_id);
//
//
//        };
//    }
//}
//#endif