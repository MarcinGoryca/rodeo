/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ TimeController.h ] [ mg\core ]
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
        class TimeController : public Singleton<TimeController>, public MasterController
        {
        public:
            TimeController()
                :time_(NULL),
                fps_show_(false)
            {
                init();
            }

            ~TimeController()
            {
                clean();
            }

            // Get pointer to Timer Object
            Timer* getTimer() const { return time_; }

            // Get FPSShow
            bool getFpsShow() const { return fps_show_; }

        private:
            // This method is responsible for initiliazation of member objects
            void init();

            // This method is responsible for cleaning of member obejcts
            void clean();
            bool toggleFPS();
            float showFPS();

            Timer* time_;
            bool fps_show_;
        };
    }    // end of core namespace
}    // end of mg namespace
#endif