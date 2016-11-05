/*
----------------------------------------------
    laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_RENDERER_GLOBALSTATE_H_
#define LAURA_RENDERER_GLOBALSTATE_H_

namespace laura
{
namespace renderer
{
class GlobalState : public RenderState
{
public:
    virtual int getState()const { return GLOBAL; }
protected:
    GlobalState(){}
};
}    // end of renderer namespace
}    // end of laura namespace
#endif