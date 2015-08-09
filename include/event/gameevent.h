/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_EVENT_GAMEEVENT_H_
#define MG_EVENT_GAMEEVENT_H_

#ifndef MG_EVENT_EVENT_H_
#include "event\event.h"
#endif

namespace mg
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
}    // end of mg namespace
#endif