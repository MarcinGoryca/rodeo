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
#ifndef RODEO_CONTROLLERS_TIMECONTROLLER_H_
#define RODEO_CONTROLLERS_TIMECONTROLLER_H_

#ifndef RODEO_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef RODEO_CORE_TIMER_H_
#include "core\Timer.h"
#endif

#ifndef RODEO_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

namespace rodeo
{
    namespace controllers
    {
        class TimeController : public rodeo::core::Singleton<TimeController>, public MasterController
        {
        public:
            TimeController()
                :_time(nullptr),
                _fps_show(false)
            {
                init();
            }

            ~TimeController()
            {
                clean();
            }

            // Get pointer to Timer Object
            rodeo::core::Timer* getTimer() const { return _time; }

            // Get FPSShow
            bool getFpsShow() const { return _fps_show; }

        private:
			rodeo::core::Timer* _time;
			bool _fps_show;

            // This method is responsible for initiliazation of member objects
            void init();

            // This method is responsible for cleaning of member obejcts
            void clean();
            bool toggleFPS();
            float showFPS();
        };
    }
}
#endif