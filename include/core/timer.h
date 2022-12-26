/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
#ifndef RODEO_CORE_TIMER_H_
#define RODEO_CORE_TIMER_H_

#ifndef RODEO_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace rodeo
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