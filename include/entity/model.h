/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    [ Model.h ] [ laura\entity ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 | -----------------------------------
 */

#ifndef LAURA_ENTITY_MODEL_H_
#define LAURA_ENTITY_MODEL_H_

#ifndef LAURA_ENTITY_MESH_H_
#include "entity\mesh.h"
#endif

namespace laura
{
    namespace entity
    {
        class Model
        {
        public:
            Model()
                :_mesh_count(0),
                _material_count(0),
                _anim_key_count(0)
            {}

            ~Model() {}

            Model operator=(const Model& copy);
            Model(const Model& copy);

            std::vector<Mesh> _mesh;
            std::vector<MeshMaterial> _material;

            unsigned int _mesh_count;
            unsigned int _material_count;
            unsigned int _anim_key_count;
        };
    }
}
#endif