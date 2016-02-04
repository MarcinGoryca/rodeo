/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ Model.h ] [ mg\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 | -----------------------------------
 */

#ifndef MG_ENTITY_MODEL_H_
#define MG_ENTITY_MODEL_H_

#ifndef MG_ENTITY_MESH_H_
#include "entity\mesh.h"
#endif

namespace mg
{
    namespace entity
    {
        class Model
        {
        public:
            Model()
                :mesh_count_(0),
                material_count_(0),
                anim_key_count_(0)
            {}

            ~Model() {}

            Model operator=(const Model& copy);
            Model(const Model& copy);

            std::vector<Mesh> mesh_;
            std::vector<MeshMaterial> material_;

            mg::core::ui mesh_count_;
            mg::core::ui material_count_;
            mg::core::ui anim_key_count_;
        };
    }    // end of entity namespace
}    // end of mg namespace
#endif