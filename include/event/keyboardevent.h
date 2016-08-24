/*
-----------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_EVENT_KEYBOARDEVENT_H_
#define MONA_EVENT_KEYBOARDEVENT_H_

#ifndef MONA_IO_KEYBOARD_H_
#include "io\Keyboard.h"
#endif

namespace mona
{
namespace event
{
class Event;

class KeyboardEvent : public Event
{
public:
    KeyboardEvent(){}

    virtual ~KeyboardEvent(){}

    virtual bool onKeyUp(mona::io::KeyMap key);

    virtual bool onKeyDown(mona::io::KeyMap key);
};
}
}
#endif