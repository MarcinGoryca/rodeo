/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    [ Model3d.h ] [ mona\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_ENTITY_MODEL3D_H_
#define MONA_ENTITY_MODEL3D_H_

#ifndef MONA_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#ifndef MONA_IO_FILE3DFACTORY_H_
#include "io\file3dfactory.h"
#endif

#ifndef MONA_RENDERER_BUFFERS_H_
#include "renderer\buffers.h"
#endif

#ifndef MONA_RENDERER_RENDERMODE_H_
#include "renderer\rendermode.h"
#endif

namespace mona
{
    namespace entity
    {
        class Texture;
        class Vector3;
        class Model3D : public mona::renderer::RenderMode, public Entity
        {
        public:
            Model3D()
                :Entity("", "model3d"),
                _mesh_count(_model._mesh_count),
                _material_count(_model._material_count),
                _vertex_count(0),
                _index_count(0),
                _winding(GL_CCW)
            {}

            Model3D(const char* filename, mona::io::File3DFactory::File3DType type);

            virtual ~Model3D();

            void load(const char* filename, mona::io::File3DFactory::File3DType type);

            void update();
            void scale(float scale_factor);

            virtual void draw();
			virtual void release();
			virtual void update(float dt);
			void setDefaults();

            unsigned int getMeshCount()const { return _mesh_count; }
            unsigned int getMaterialCount()const { return _material_count; }
            unsigned int getVertexCount()const { return _vertex_count; }
            unsigned int getIndexCount()const { return _index_count; }

            void setMeshCount(unsigned int mesh_count) { _mesh_count = mesh_count; }
            void setMaterialCount(unsigned int material_count) { _material_count = material_count; }
            void setVertexCount(unsigned int vertex_count) { _vertex_count = vertex_count; }
            void setIndexCount(unsigned int index_count) { _index_count = index_count; }

        protected:
			Model _model;
			mona::renderer::Buffers _buffer;

			unsigned int _texture_id;
			unsigned int _mesh_count;
			unsigned int _material_count;
			unsigned int _vertex_count;
			unsigned int _index_count;

			bool _has_texture;
			bool _has_material;
			GLenum _winding;

            void create();
            void buildAABB();

            void render();

            void bindTexture(mona::core::ui& texture_id);


        };
    }
}
#endif