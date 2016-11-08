/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    [ TimeController.h ] [ laura\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CONTROLLERS_TIMECONTROLLER_H_
#define LAURA_CONTROLLERS_TIMECONTROLLER_H_

#ifndef LAURA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef LAURA_CORE_TIMER_H_
#include "core\Timer.h"
#endif

#ifndef LAURA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

namespace laura
{
    namespace controllers
    {
        class TimeController : public laura::core::Singleton<TimeController>, public MasterController
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
            laura::core::Timer* getTimer() const { return _time; }

            // Get FPSShow
            bool getFpsShow() const { return _fps_show; }

        private:
			laura::core::Timer* _time;
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