/*
-----------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef LAURA_EVENT_IINPUTLISTENER_H_
#define LAURA_EVENT_IINPUTLISTENER_H_

#include <list>

#ifndef LAURA_IO_IINPUT_H_
#include "io\iinput.h"
#endif

namespace laura
{
namespace event
{
class IInputListener
{
public:
    IInputListener(){}

    virtual ~IInputListener(){}

    int getInputType()const;

    void addInputListener(laura::io::IInput* in);

    virtual void keyUp(laura::io::IInput key) = 0;

    virtual void keyDown(laura::io::IInput key) = 0;

    virtual void mouseDblClick(laura::io::IInput ms) = 0;

    virtual void mouseMove(laura::io::IInput ms) = 0;

    virtual void mouseExit(laura::io::IInput ms) = 0;

    virtual void mouseScroll(laura::io::IInput ms) = 0;

    virtual void mouseClick(laura::io::IInput ms) = 0;

    virtual void mouseDrag(laura::io::IInput ms) = 0;

protected:
    std::list <laura::io::IInput*> _input_list;
};
}
}
#endif