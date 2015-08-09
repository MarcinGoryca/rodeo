/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\timer.h"

namespace mg
{
namespace core
{
void Timer::countFramesPerSecond()
{
    current_time_ = getSecs();
    delta_ = current_time_ - last_time_;

    last_time_ = current_time_;

    ++frames_;
    fps_time_ += delta_;

//Does a second past?
    if(fps_time_ > 1.0f)
    {
        fps_ = frames_ / fps_time_;
        frames_ = 0;
        fps_time_ = 0.0f;
    }
}

//--------------------------------------------------------------------------------------------------
void Timer::countFPS()
{
    current_time_ = GetTickCount() * 0.001f;
    if(current_time_ - last_time_ > 1.0f)
    {
        last_time_ = current_time_;
        
        fps_ = 0.0;
    }
    ++fps_;
}

//--------------------------------------------------------------------------------------------------
float Timer::getSecs()
{
    use_query_performance_frequency_ = (QueryPerformanceFrequency(&frequency_) != 0);
    if(!use_query_performance_frequency_)
    {
        return GetTickCount() / 1000.0f;
    }
    else
    {
        QueryPerformanceCounter(&ticks_);
        return static_cast<float>(ticks_.QuadPart / static_cast<double>(frequency_.QuadPart));
    }
}

//--------------------------------------------------------------------------------------------------
void Timer::init()
{
    last_time_ = getSecs();
}
}    // end of core namespace
}    // end of mg namespace