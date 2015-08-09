/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\light.h"

using namespace mg::math;

namespace mg
{
namespace renderer
{
float Light::s_array_[4] = {0.0f, 0.0f, 0.0f, 0.0f};
float Light::s_ambient_[4] = {0.0f, 0.0f, 0.0f, 0.0f};
float Light::s_diffuse_[4] = {0.0f, 0.0f, 0.0f, 0.0f};
float Light::s_specular_[4] = {0.0f, 0.0f, 0.0f, 0.0f};
float Light::s_position_[4] = {0.0f, 0.0f, 0.0f, 0.0f};
int Light::s_light_enum_ = 0;

/**
 * 
 */

void Light::setAmbient(float r, float g, float b, float a)
{
    s_ambient_[0] = r;
    s_ambient_[1] = g;
    s_ambient_[2] = b;
    s_ambient_[3] = a;
}

/**
 *
 */

void Light::setDiffuse(float r, float g, float b, float a)
{
    s_diffuse_[0] = r;
    s_diffuse_[1] = g;
    s_diffuse_[2] = b;
    s_diffuse_[3] = a;
}

/**
 *
 */

void Light::setSpecular(float r, float g, float b, float a)
{
    s_specular_[0] = r;
    s_specular_[1] = g;
    s_specular_[2] = b;
    s_specular_[3] = a;
}

/**
 *
 */

void Light::fire(Lights l)
{
    s_light_enum_ = l;
    glLightfv(l, GL_AMBIENT, getAmbient());
    glLightfv(l, GL_DIFFUSE, getDiffuse());
    glLightfv(l, GL_SPECULAR, getSpecular());
    glLightfv(l, GL_POSITION, getPosition());
    glEnable(l);
}

/**
 *
 */

void Light::enable()
{
    glEnable(GL_LIGHTING);
}

/**
 *
 */

void Light::disable()
{
    glDisable(GL_LIGHTING);
}

/**
 *
 */

void Light::setPosition(float r, float g, float b, float a)
{
    s_position_[0] = r;
    s_position_[1] = g;
    s_position_[2] = b;
    s_position_[3] = a;
}

/**
 *
 */

void Light::update()
{
    int l = getLightEnum();
    glLightfv(l, GL_AMBIENT, getAmbient());
    glLightfv(l, GL_DIFFUSE, getDiffuse());
    glLightfv(l, GL_SPECULAR, getSpecular());
    glLightfv(l, GL_POSITION, getPosition());
}
}    // end of renderer namespace
}    // end of mg namespace