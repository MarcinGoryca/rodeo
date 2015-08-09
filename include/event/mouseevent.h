/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_EVENT_MOUSEEVENT_H_
#define MG_EVENT_MOUSEEVENT_H_

namespace mg
{
namespace event
{
class Event;

class MouseEvent : public Event
{
public:
    MouseEvent(){}

    virtual ~MouseEvent(){}

    virtual void onMouseMove();

    virtual void onLeftButtonClick();

    virtual void onLeftButtonDoubleClick();

    virtual void onRightButtonClick();

    virtual void onRightButtonDoubleClick();

    virtual void onMiddleButtonClick();

    virtual void onMiddleButtonDoubleClick();

    virtual void onLeftRightClick();

    virtual void onLeftMiddleClick();

    virtual void onRightMiddleClick();

    virtual void onDrag();

    virtual bool onMouseDown();

    virtual bool onMouseUp();
};
}    // end of event namespace
}    // end of mg namespace
#endif