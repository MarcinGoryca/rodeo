/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "event\event.h"
#include "core\eventmanager.h"

using namespace mg::event;

namespace mg
{
namespace core
{
bool EventManager::init()
{
    event_ = new event::Event;
    return true;
}

// -------------------------------------------------------------------------------------------------
void EventManager::addEventListener(event::Event* event_type)
{

}

// -------------------------------------------------------------------------------------------------
void EventManager::clear()
{
    if(event_ != NULL)
    {
        delete event_;
        event_ = NULL;
    }
}

/**
void EventManager::getUserInput()
{
}
*/
}    // end of core namespace
}    // end of mg namespace