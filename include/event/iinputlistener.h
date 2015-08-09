/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_EVENT_IINPUTLISTENER_H_
#define MG_EVENT_IINPUTLISTENER_H_

#include <list>

#ifndef MG_IO_IINPUT_H_
#include "io\iinput.h"
#endif

namespace mg
{
namespace event
{
class IInputListener
{
public:
    IInputListener(){}

    virtual ~IInputListener(){}

    int getInputType()const;

    void addInputListener(mg::io::InputIfc* in);

    virtual void keyUp(mg::io::InputIfc key) = 0;

    virtual void keyDown(mg::io::InputIfc key) = 0;

    virtual void mouseDblClick(mg::io::InputIfc ms) = 0;

    virtual void mouseMove(mg::io::InputIfc ms) = 0;

    virtual void mouseExit(mg::io::InputIfc ms) = 0;

    virtual void mouseScroll(mg::io::InputIfc ms) = 0;

    virtual void mouseClick(mg::io::InputIfc ms) = 0;

    virtual void mouseDrag(mg::io::InputIfc ms) = 0;

protected:
    std::list <mg::io::IInput*> input_list_;
};
}    // end of event namespace
}    // end of mg namespace
#endif