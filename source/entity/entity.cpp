/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "entity\entity.h"

using namespace mg::renderer;
//using namespace enginemath;
//using namespace enginescene;

namespace mg
{
namespace entity
{
void Entity::init()
{
    //last_position_ = last_position_.S_VECTOR3_ZERO_;
    //actual_position_ = actual_position_.S_VECTOR3_ZERO_;
    //setPosition(actual_position_.x_, actual_position_.y_, actual_position_.z_);
}

//--------------------------------------------------------------------------------------------------
void Entity::clear()
{
}

//--------------------------------------------------------------------------------------------------
void Entity::draw()
{
    //glLoadIdentity();
    //glTranslatef(world_.m4_[12], world_.m4_[13], world_.m4_[14]);
}

// ---- //
void Entity::update(float dt){}

// ---- //
//void Entity::setPosition(float px, float py, float pz)
//{
//    //setLocal(px, py, pz);
//}

// ---- //
//void Entity::rotate(float angle, float rx, float ry, float rz)
//{
//    glRotatef(angle, rx, ry, rz);
//}

// ---- //
//void Entity::scale(float sx, float sy, float sz)
//{
//   /* world_.m4_[0] = sx;
//    world_.m4_[5] = sy;
//    world_.m4_[10] = sz;
//
//    glScalef(world_.m4_[0], world_.m4_[5], world_.m4_[10]);*/
//}

// ---- //
//void Entity::translate(float tx, float ty, float tz)
//{
//    /*world_.m4_[12] *= tx;
//    world_.m4_[13] *= ty;
//    world_.m4_[14] *= tz;
//
//    last_position_.x_ = actual_position_.x_;
//    last_position_.y_ = actual_position_.y_;
//    last_position_.z_ = actual_position_.z_;
//
//    actual_position_.x_ = world_.m4_[12];
//    actual_position_.y_ = world_.m4_[13];
//    actual_position_.z_ = world_.m4_[14];
//    */
//    //glTranslatef(tx, ty, tz);
//}

// ---- //
//void Entity::setColor(Colors& rgb)
//{
//    /*material_.setAmbient(rgb.r_, rgb.g_, rgb.b_, 1.0f);
//    material_.setSpecular(rgb.r_, rgb.g_, rgb.b_, 1.0f);
//    material_.setDiffuse(rgb.r_, rgb.g_, rgb.b_, 1.0f);
//
//    material_.setShininess(50.0f);
//
//    glMaterialfv(GL_FRONT, GL_SPECULAR, material_.getSpecular());
//    glMaterialfv(GL_FRONT, GL_AMBIENT, material_.getAmbient());
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_.getDiffuse());
//    glMaterialfv(GL_FRONT, GL_SHININESS, material_.getShininess());*/
//}

// ---- //
void Entity::release()
{
}
}    // end of entity namespace
}    // end of mg namespace