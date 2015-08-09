/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_ENTITY_SPRITE_H_
#define MG_ENTITY_SPRITE_H_

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace mg
{
namespace entity
{
class Sprite : public Entity
{
public:
    Sprite()
    :Entity("", "sprite")
    {}

    virtual ~Sprite(){}
    
    virtual void render();
    virtual void update();

    // Gets Width value of the Sprite
    // Returns unsigned int width
    unsigned int getWidth() const { return width_; }

    // Gets Height value of the Sprite
    // Returns unsigned int height
    unsigned int getHeight() const { return height_; }

    // Sets Width of the Sprite
    void setWidth(unsigned int width) { width_ = width; }

    // Sets Height of the Sprite
    void setHeight(unsigned int height) { height_ = height; }

private:
    mg::core ui width_;
    mg::core ui height_;
};
}    // end of entity namespace
}    // end of mg namespace
#endif