/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ TimeController.h ] [ mg\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CONTROLLERS_TIMECONTROLLER_H_
#define MG_CONTROLLERS_TIMECONTROLLER_H_

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_CORE_TIMER_H_
#include "core\Timer.h"
#endif

#ifndef MG_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

namespace mg
{
    namespace controllers
    {
        class TimeController : public mg::core::Singleton<TimeController>, public MasterController
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
            Timer* getTimer() const { return _time; }

            // Get FPSShow
            bool getFpsShow() const { return _fps_show; }

        private:
			Timer* _time;
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