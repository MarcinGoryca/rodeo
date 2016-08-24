/*
-----------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_EVENT_IINPUTLISTENER_H_
#define MONA_EVENT_IINPUTLISTENER_H_

#include <list>

#ifndef MONA_IO_IINPUT_H_
#include "io\iinput.h"
#endif

namespace mona
{
namespace event
{
class IInputListener
{
public:
    IInputListener(){}

    virtual ~IInputListener(){}

    int getInputType()const;

    void addInputListener(mona::io::IInput* in);

    virtual void keyUp(mona::io::IInput key) = 0;

    virtual void keyDown(mona::io::IInput key) = 0;

    virtual void mouseDblClick(mona::io::IInput ms) = 0;

    virtual void mouseMove(mona::io::IInput ms) = 0;

    virtual void mouseExit(mona::io::IInput ms) = 0;

    virtual void mouseScroll(mona::io::IInput ms) = 0;

    virtual void mouseClick(mona::io::IInput ms) = 0;

    virtual void mouseDrag(mona::io::IInput ms) = 0;

protected:
    std::list <mona::io::IInput*> _input_list;
};
}
}
#endif