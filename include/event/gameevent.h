/*
-----------------------------------
    laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef LAURA_EVENT_GAMEEVENT_H_
#define LAURA_EVENT_GAMEEVENT_H_

#ifndef LAURA_EVENT_EVENT_H_
#include "event\event.h"
#endif

namespace laura
{
namespace event
{
class GameEvent : public Event
{
public:
    GameEvent(){}
    virtual ~GameEvent(){}
};
}    // end of event namespace
}    // end of laura namespace
#endif