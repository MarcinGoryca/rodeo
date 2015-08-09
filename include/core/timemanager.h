/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_TIMEMANAGER_H_
#define MG_CORE_TIMEMANAGER_H_

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_CORE_TIMER_H_
#include "core\Timer.h"
#endif

#ifndef MG_CORE_MASTERMANAGER_H_
#include "core\mastermanager.h"
#endif

namespace mg
{
namespace core
{
class TimeManager : public Singleton<TimeManager>, public MasterManager
{
public:
    TimeManager()
        :time_(NULL),
         fps_show_(false)
    {
        init();
    }

    ~TimeManager()
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