/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "entity\model.h"

namespace mg
{
namespace entity
{
Model::Model(const Model& copy)
{
    anim_key_count_ = copy.anim_key_count_;
    material_count_ = copy.material_count_;
    mesh_count_ = copy.mesh_count_;
    material_ = copy.material_;
    mesh_ = copy.mesh_;
}

//--------------------------------------------------------------------------------------------------
Model Model::operator=(const Model& copy)
{
    anim_key_count_ = copy.anim_key_count_;
    material_count_ = copy.material_count_;
    mesh_count_ = copy.mesh_count_;
    material_ = copy.material_;
    mesh_ = copy.mesh_;
    return *this;
}
}    // end of entity namespace
}    // end of mg namespace