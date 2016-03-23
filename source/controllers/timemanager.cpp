/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\timer.h"
#include "core\timemanager.h"

namespace mg
{
namespace core
{
void TimeManager::init()
{
    time_ = new Timer;
}

//--------------------------------------------------------------------------------------------------
void TimeManager::clean()
{
    delete time_;
}

//--------------------------------------------------------------------------------------------------
bool TimeManager::toggleFPS()
{
    if(!fps_show_)
    {
        fps_show_ = true;
    }
    else
    {
        fps_show_ = false;
    }
    return true;
}

//--------------------------------------------------------------------------------------------------
float TimeManager::showFPS()
{
    //return time_.getFPS();
    return 1;
}
}    // end of core namespace
}    // end of mg namespace