/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_GLOBALSTATE_H_
#define MG_RENDERER_GLOBALSTATE_H_

namespace mg
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
}    // end of mg namespace
#endif