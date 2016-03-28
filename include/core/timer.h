﻿/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ Timer.h ] [ mg\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_TIMER_H_
#define MG_CORE_TIMER_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace mg
{
    namespace core
    {
        class Timer
        {
        public:
            Timer()
                :_use_query_performance_frequency(false),
                _current_time(0.0f),
                _last_time(0.0f),
                _fps(0.0f),
                _fps_time(0.0f),
                _delta(0.0f),
                _frames(0)
            {}

            ~Timer() {}

            void countFPS();

            // Gets Current Time Value
            float getCurrentTime() const { return _current_time; }

            // Gets Last Time Value
            float getLastTime() const { return _last_time; }

            // Gets Frames Per Second
            float getFps() { return _fps; }

            // Gets Time Frames per second
            float getFpsTime() const { return _fps_time; }

            // Gets Delta Time
            float getDelta()const { return _delta; }

            // Gets Frames
            unsigned int getFrames() const { return _frames; }

            void countFramesPerSecond();

        private:
			bool _use_query_performance_frequency;
			float _current_time;
			float _last_time;
			float _fps;
			float _fps_time;
			float _delta;
			unsigned int _frames;

			LARGE_INTEGER _frequency;
			LARGE_INTEGER _ticks;
            float getSecs();

            // Before using CountFramesPerSecond call this method!
            void init();


        };
    }
}
#endif