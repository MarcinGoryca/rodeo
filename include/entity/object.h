/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_ENTITY_OBJECT_H_
#define MG_ENTITY_OBJECT_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef MG_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

namespace mg
{
namespace entity
{
class Event;

class Object
{
public:
    Object()
        :name_(""),
         type_("")
    { 
        init();
    }

    // ---- //
    virtual ~Object()
    { 
        clear();
    }

    // ---- //
    explicit Object(std::string name)
        :name_(name)
    {
        init();
    }

    // ---- //
    Object(std::string name, std::string type)
        :name_(name),
         type_ (type)
    {
        init();
    }

    // Copy Constructor 
    Object(Object& copy);

    // Copy operator
    Object& operator=(const Object& copy);

    // Gets Id of the Object
    // Returns unsigned int value of the id
    mg::core::ui getObjectId() const { return id_; }

    // Gets Name of the Object
    // Returns string value of the name
    std::string getObjectName() const { return name_; }

    // Gets Type of the Object
    // Returns string value of the type
    std::string getObjectType() const { return type_; }

    // Gets number of the Objects
    // Returns unsigned int value of the number
    mg::core::ui getObjectsCounter() const { return s_object_counter_; }

    // Sets type of the Object
    // Parameter string value of the type
    void setObjectType(std::string new_type)
    {
        type_ = new_type;
    }

    // Sets name of the Object
    // Parameter string value of the name
    void setObjectName(std::string new_name)
    {
        name_ = new_name;
    }

protected:
    void init();
    //virtual void setId(ui id);
    void clear();

	// Counter for every object on the scene
    static mg::core::ui s_object_counter_;

	// Identifier for every object on the scene
    mg::core::ui id_;

    std::string name_;
    std::string type_;
};
}    // end of entity namespace
}    // end of mg namespace
#endif