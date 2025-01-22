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
#include "entity\object.h"
#include "event\event.h"

using namespace std;
using namespace rodeo::core;

namespace rodeo 
{
namespace entity
{
unsigned int Object::_s_object_counter = 0;

//Object* Object::getObjectById(enginecore::ui id)
//{
//    if(this->id_ == id)
//        return this;
//    else
//    {
//        return NULL;
//    }
//}

//.................................//
void Object::init()
{
    _s_object_counter++;
//    setId(s_object_counter_);
//    renderable_ = true;
}

//.................................//
void Object::clear()
{
    while(_s_object_counter > 0)
    {
        _s_object_counter--;
    }
}

//-------------------------------

//void Object::setId(enginecore::ui id)
//{
//    this->id_ = id;
//}

//.................................//
Object::Object(Object& copy)
{
    this->_id = copy._id;
//    this->renderable_ = copy.renderable_;
    //this->has_material_ = copy.has_material_;
    //this->has_color_ = copy.has_color_;
//    this->world_ = copy.world_;
//    this->local_ = copy.local_;
//    this->translation_ = copy.translation_;
//    this->scale_ = copy.scale_;
    //this->has_texture_ = copy.has_texture_;
//    this->setType(copy.getType());
}

//---------------------------------

//void Object::remove()
//{
//    if(this != NULL)
//    {
//        delete this;
//    }
//    s_object_counter_--;
//}

//---------------------------------

//void Object::onEvent(){}

//---------------------------------

//Object& Object::getObjectByName(string searchName)
//{
//    if(this->name_ == searchName)
//    {
//        return *this;
//    }
//}

//----------------------------------

//void Object::addEventListener(Event* event_type)
//{
//	event_type->current_target_ = this->id_;
//}

//---------------------------------

//Object& Object::getObjectByType(string searchType)
//{
//    if(this->type_ == searchType)
//        return *this;
//}

//---------------------------------

//Object& Object::operator=(const Object& copy)
//{
//    this->renderable_ = copy.renderable_;
//    //this->has_color_ = copy.has_color_;
//    //this->has_material_ = copy.has_material_;
//    //this->has_texture_ = copy.has_texture_;
//    this->setType(copy.getType());
//    return *this;
//}

//------------------------------------------

//void Object::setLocal(float x, float y, float z)
//{
//    local_.m4_[12] = x;
//    local_.m4_[13] = y;
//    local_.m4_[14] = z;
//
//    setWorld();
//    //updateWorld();
//}
//
////------------------------------------------
//
//void Object::setWorld()
//{
//    world_.m4_[12] = getLocal().m4_[12];
//    world_.m4_[13] = getLocal().m4_[13];
//    world_.m4_[14] = getLocal().m4_[14];
//}
//
////-----------------------------------------
//
//void Object::updateLocal()
//{
//
//}
//
////------------------------------------------
//
//void Object::updateWorld()
//{
//    for(int i = 0; i < 16; ++i)
//    {
//        world_.m4_[i] = getLocal().m4_[i];
//    }
//}
}    // end of entity namespace
}    // end of rodeo namespace
