/*
----------------------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MONA_RENDERER_GLOBALSTATE_H_
#define MONA_RENDERER_GLOBALSTATE_H_

namespace mona
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
}    // end of mona namespace
#endif