/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_ENTITY_ENTITY_H_
#define MG_ENTITY_ENTITY_H_

#ifndef MG_ENTITY_OBJECT_H_
#include "object.h"
#endif

#ifndef MG_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef MG_RENDERER_MATERIAL_H_
#include "renderer\material.h"
#endif

#ifndef MG_MATH_AABB_H_
#include "math\aabb.h"
#endif

#ifndef MG_MATH_TRANSFORM_H_
#include "math\transform.h"
#endif

namespace mg 
{
namespace entity
{
class Entity : public Object
{
public:
    Entity()
        :Object(),
        renderable_(true)
    { 
        init();
    }

    // ---- //
    explicit Entity(std::string name)
        :Object(name)
    {
        init();
    }

    // ---- //
    Entity(std::string name, std::string type)
        :Object(name, type)
    {
        init();
    }
    
    // --- //
    virtual ~Entity()
    { 
        clear();
    }

    virtual void draw();
    virtual void update(float dt);
    virtual void init();
    virtual void clear();

    virtual void release();

    //virtual void setColor(enginerenderer::Colors& rgb);

protected:
    //enginerenderer::Material material_;
    mg::math::AABB box_;

    mg::math::Transform transform_;
    bool renderable_;

    // Copy Constructor
    Entity(const Entity& copy);

    // Copy operator
    Entity operator=(const Entity& copy);
};
}    // end of entity namespace
}    // end of mg namespace
#endif