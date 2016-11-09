///*
//----------------------------------------------
//    Laura Game Engine
//    Copyright(c) Marcin Goryca
//    marcin.goryca@gmail.com
//    http://marcingoryca.pl
//----------------------------------------------
//*/
//#include "entity\object.h"
//#include "event\event.h"
//
//using namespace std;
//using namespace laura::core;
//
//namespace laura 
//{
//namespace entity
//{
//ui Object::_s_object_counter = 0;
//
////Object* Object::getObjectById(enginecore::ui id)
////{
////    if(this->id_ == id)
////        return this;
////    else
////    {
////        return NULL;
////    }
////}
//
////.................................//
//void Object::init()
//{
//    _s_object_counter++;
////    setId(s_object_counter_);
////    renderable_ = true;
//}
//
////.................................//
//void Object::clear()
//{
//    while(_s_object_counter > 0)
//    {
//        _s_object_counter--;
//    }
//}
//
////-------------------------------
//
////void Object::setId(enginecore::ui id)
////{
////    this->id_ = id;
////}
//
////.................................//
//Object::Object(Object& copy)
//{
//    this->_id = copy._id;
////    this->renderable_ = copy.renderable_;
//    //this->has_material_ = copy.has_material_;
//    //this->has_color_ = copy.has_color_;
////    this->world_ = copy.world_;
////    this->local_ = copy.local_;
////    this->translation_ = copy.translation_;
////    this->scale_ = copy.scale_;
//    //this->has_texture_ = copy.has_texture_;
////    this->setType(copy.getType());
//}
//
////---------------------------------
//
////void Object::remove()
////{
////    if(this != NULL)
////    {
////        delete this;
////    }
////    s_object_counter_--;
////}
//
////---------------------------------
//
////void Object::onEvent(){}
//
////---------------------------------
//
////Object& Object::getObjectByName(string searchName)
////{
////    if(this->name_ == searchName)
////    {
////        return *this;
////    }
////}
//
////----------------------------------
//
////void Object::addEventListener(Event* event_type)
////{
////	event_type->current_target_ = this->id_;
////}
//
////---------------------------------
//
////Object& Object::getObjectByType(string searchType)
////{
////    if(this->type_ == searchType)
////        return *this;
////}
//
////---------------------------------
//
////Object& Object::operator=(const Object& copy)
////{
////    this->renderable_ = copy.renderable_;
////    //this->has_color_ = copy.has_color_;
////    //this->has_material_ = copy.has_material_;
////    //this->has_texture_ = copy.has_texture_;
////    this->setType(copy.getType());
////    return *this;
////}
//
////------------------------------------------
//
////void Object::setLocal(float x, float y, float z)
////{
////    local_.m4_[12] = x;
////    local_.m4_[13] = y;
////    local_.m4_[14] = z;
////
////    setWorld();
////    //updateWorld();
////}
////
//////------------------------------------------
////
////void Object::setWorld()
////{
////    world_.m4_[12] = getLocal().m4_[12];
////    world_.m4_[13] = getLocal().m4_[13];
////    world_.m4_[14] = getLocal().m4_[14];
////}
////
//////-----------------------------------------
////
////void Object::updateLocal()
////{
////
////}
////
//////------------------------------------------
////
////void Object::updateWorld()
////{
////    for(int i = 0; i < 16; ++i)
////    {
////        world_.m4_[i] = getLocal().m4_[i];
////    }
////}
//}    // end of entity namespace
//}    // end of laura namespace
