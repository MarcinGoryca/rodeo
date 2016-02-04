/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ Model3d.h ] [ mg\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_ENTITY_MODEL3D_H_
#define MG_ENTITY_MODEL3D_H_

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#ifndef MG_IO_FILE3DFACTORY_H_
#include "io\file3dfactory.h"
#endif

#ifndef MG_RENDERER_BUFFERS_H_
#include "renderer\buffers.h"
#endif

#ifndef MG_RENDERER_RENDERMODE_H_
#include "renderer\rendermode.h"
#endif

namespace mg
{
    namespace entity
    {
        class Texture;
        class Vector3;
        class Model3D : public mg::renderer::RenderMode, public Entity
        {
        public:
            Model3D()
                :Entity("", "model3d"),
                mesh_count_(model_.mesh_count_),
                material_count_(model_.material_count_),
                vertex_count_(0),
                index_count_(0),
                winding_(GL_CCW)
            {}

            Model3D(const char* filename, mg::io::File3DFactory::File3DType type);

            virtual ~Model3D();

            void load(const char* filename, mg::io::File3DFactory::File3DType type);

            void update();
            void scale(float scale_factor);

            virtual void draw();

            mg::core::ui getMeshCount()const { return mesh_count_; }
            mg::core::ui getMaterialCount()const { return material_count_; }
            mg::core::ui getVertexCount()const { return vertex_count_; }
            mg::core::ui getIndexCount()const { return index_count_; }

            void setMeshCount(mg::core::ui mc) { mesh_count_ = mc; }
            void setMaterialCount(mg::core::ui mtc) { material_count_ = mtc; }
            void setVertexCount(mg::core::ui vc) { vertex_count_ = vc; }
            void setIndexCount(mg::core::ui ic) { index_count_ = ic; }

            virtual void release();
            virtual void update(float dt);

            void setDefaults();

        protected:

            void create();
            void buildAABB();

            void render();

            void bindTexture(mg::core::ui& texture_id);

            Model model_;
            mg::renderer::Buffers buffer_;

            mg::core::ui texture_id_;
            mg::core::ui mesh_count_;
            mg::core::ui material_count_;
            mg::core::ui vertex_count_;
            mg::core::ui index_count_;

            bool has_texture_;
            bool has_material_;
            GLenum winding_;
        };
    }    // end of entity namespace
}    // end of mg  namespace
#endif