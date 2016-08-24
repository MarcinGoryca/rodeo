/*
-----------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_EVENT_GAMEEVENT_H_
#define MONA_EVENT_GAMEEVENT_H_

#ifndef MONA_EVENT_EVENT_H_
#include "event\event.h"
#endif

namespace mona
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
}    // end of mona namespace
#endif