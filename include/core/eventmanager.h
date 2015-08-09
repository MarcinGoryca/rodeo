/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_EVENTMANAGER_H_
#define MG_CORE_EVENTMANAGER_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "constants.h"
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "singleton.h"
#endif

#ifndef MG_CORE_MASTERMANAGER_H_
#include "mastermanager.h"
#endif

namespace mg
{
namespace event 
{
class Event;
}

namespace core
{
class EventManager : public Singleton<EventManager>, public MasterManager
{
public:
    EventManager()
    {
        init();
    }

    virtual ~EventManager()
    {
        clear();
    }

    void translate(mg::event::Event* event);

    void dispatch(mg::event::Event* event);

    void send(mg::event::Event* event);

    virtual void addEventListener(mg::event::Event* event_type);

    void removeEventListener();

    // Overload this method in game class
    virtual void getUserInput();

    // Gets Event object pointer
    mg::event::Event* getEvent() const
    {
        return event_;
    }

private:
    bool init();
    void clear();

    mg::event::Event* event_;
};
}    // end of core namespace
}    // end of mg namespace
#endif