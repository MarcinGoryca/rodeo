/*
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
                :use_query_performance_frequency_(false),
                current_time_(0.0f),
                last_time_(0.0f),
                fps_(0.0f),
                fps_time_(0.0f),
                delta_(0.0f),
                frames_(0)
            {}

            ~Timer() {}

            void countFPS();

            // Gets Current Time Value
            float getCurrentTime() const { return current_time_; }

            // Gets Last Time Value
            float getLastTime() const { return last_time_; }

            // Gets Frames Per Second
            float getFps() { return fps_; }

            // Gets Time Frames per second
            float getFpsTime() const { return fps_time_; }

            // Gets Delta Time
            float getDelta()const { return delta_; }

            // Gets Frames
            unsigned int getFrames() const { return frames_; }

            void countFramesPerSecond();

        private:
            float getSecs();

            // Before using CountFramesPerSecond call this method!
            void init();

            bool use_query_performance_frequency_;
            float current_time_;
            float last_time_;
            float fps_;
            float fps_time_;
            float delta_;
            unsigned int frames_;

            LARGE_INTEGER frequency_;
            LARGE_INTEGER ticks_;
        };
    }    // end of core namespace
}    // end of mg namespace
#endif