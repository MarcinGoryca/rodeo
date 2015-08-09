/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_RENDERSTATE_H_
#define MG_RENDERER_RENDERSTATE_H_

namespace mg
{
namespace renderer
{
class RenderState : public entity::Object
{
public:
    virtual ~RenderState(){}

    virtual int getState()const = 0;

    enum State 
    {
        GLOBAL,
        LIGHT,
        EFFECT
    };
protected:
    RenderState(){}
};
}    // end of renderer namespace
}    // end of mg namespace
#endif