/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_LIGHT_H_
#define MG_RENDERER_LIGHT_H_

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "gl\glcommon.h"
#endif

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace mg
{
namespace renderer
{
class Light : public entity::Entity
{
public:
    Light()
        :enable_lighting_(false){}
    ~Light(){}

    enum Lights
    {
        MG_LIGHT_0 = GL_LIGHT0,
        MG_LIGHT_1 = GL_LIGHT1,
        MG_LIGHT_2 = GL_LIGHT2,
        MG_LIGHT_3 = GL_LIGHT3,
        MG_LIGHT_4 = GL_LIGHT4,
        MG_LIGHT_5 = GL_LIGHT5,
        MG_LIGHT_6 = GL_LIGHT6,
        MG_LIGHT_7 = GL_LIGHT7
    };

    // For OpenGL it calls glEnable(GL_LIGHTING) 
    void enable();
    void disable();

    // Fire Up specified light, from Light0 to Light7 
    void fire(Lights l);

    // Sets all necessary Lights, Materials 
    void set();

    void setAmbient(float r, float g, float b, float a);
    void setDiffuse(float r, float g, float b, float a);
    void setSpecular(float r, float g, float b, float a);
    void setPosition(float r, float g, float b, float a);

    static float* getArray(){ return s_array_; }
    static float* getAmbient() { return s_ambient_; }
    static float* getDiffuse() { return s_diffuse_; }
    static float* getSpecular() { return s_specular_; } 
    static float* getPosition() { return s_position_; }

    static int getLightEnum() { return s_light_enum_; }

    static float s_array_[4];
    static float s_ambient_[4];
    static float s_diffuse_[4];
    static float s_specular_[4];
    static float s_position_[4];

    // Used to Enable Lighting 
    bool enable_lighting_;

    // Methods derivied from Entity 
    virtual void update();

private:
    static int s_light_enum_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif