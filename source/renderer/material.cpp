/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\material.h"

namespace mg
{
namespace renderer
{
Material::Material()
{
    specular_[0] = 0.0f;
    specular_[1] = 0.0f;
    specular_[2] = 0.0f;
    specular_[3] = 0.0f;

    ambient_[0] = 0.0f;
    ambient_[1] = 0.0f;
    ambient_[2] = 0.0f;
    ambient_[3] = 0.0f;

    diffuse_[0] = 0.0f;
    diffuse_[1] = 0.0f;
    diffuse_[2] = 0.0f;
    diffuse_[3] = 0.0f;

    shininess_[0] = 0.0f;
}
}    // end of renderer namespace
}    // end of mg namespace