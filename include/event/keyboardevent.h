/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_EVENT_KEYBOARDEVENT_H_
#define MG_EVENT_KEYBOARDEVENT_H_

#ifndef MG_IO_KEYBOARD_H_
#include "io\Keyboard.h"
#endif

namespace mg
{
namespace event
{
class Event;

class KeyboardEvent : public Event
{
public:
    KeyboardEvent(){}

    virtual ~KeyboardEvent(){}

    virtual bool onKeyUp(mg::io::KeyMap key);

    virtual bool onKeyDown(mg::io::KeyMap key);
};
}
}
#endif