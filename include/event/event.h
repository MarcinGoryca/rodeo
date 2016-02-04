/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ Event.h ] [ mg\event ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_EVENT_EVENT_H_
#define MG_EVENT_EVENT_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace mg
{
    namespace event
    {
        class Event
        {
        public:
            Event() {}

            virtual ~Event() {}

            virtual void onMove();

            virtual void onChange();

            virtual void onUpdate();

            virtual void onDraw();

            virtual void onHit();

            virtual void addedToScene();

            virtual void removedFromScene();

        protected:
            mg::core::ui current_target_;

            mg::core::ui target_;

            std::string type_;

            std::string activate_;

            std::string cancel_;
        };
    }    // end of event namespace
}    // end of mg namespace
#endif