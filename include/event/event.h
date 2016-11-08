/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    [ Event.h ] [ laura\event ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_EVENT_EVENT_H_
#define LAURA_EVENT_EVENT_H_

#ifndef LAURA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace laura
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

			/*
			 | ------------------------------------------------
			 |    Gets Current Target
		     | ------------------------------------------------
			 */
			unsigned int getCurrentTarget() const { return _current_target; }

			/*
			 | ------------------------------------------------
			 |    Gets target
			 | ------------------------------------------------
			 */
			unsigned int getTarget() const { return _target; }

			/*
			 | ------------------------------------------------
			 |    Get Type
			 | ------------------------------------------------
			 */
			std::string getType() const { return _type; }

			/*
			 | ------------------------------------------------
			 |    Get Activate
			 | ------------------------------------------------
			 */
			std::string getActivate() const { return _activate; }

			/*
			 | ------------------------------------------------
			 |    Get Cancel
			 | ------------------------------------------------
			 */
			std::string getCancel() const { return _cancel; }

			/*
			 | ------------------------------------------------
			 |    Set Current Target
			 | ------------------------------------------------
			 */
			void setCurrentTarget(unsigned int current_target) { _current_target = current_target; }

			/*
			 | ------------------------------------------------
			 |    Set Target
			 | ------------------------------------------------
			 */
			void setTarget(unsigned int target) { _target = target; }

			/*
			 | ------------------------------------------------
			 |    Set Type
			 | ------------------------------------------------
			 */
			void setType(std::string type) { _type = type; }

			/*
			 | ------------------------------------------------
			 |    Set Activate
			 | ------------------------------------------------
			 */
			void setActivate(std::string activate) { _activate = activate; }

			/*
			 | ------------------------------------------------
			 |    Set Cancel
			 | ------------------------------------------------
			 */
			void setCancel(std::string cancel) { _cancel = cancel; }

        protected:
            unsigned int _current_target;

            unsigned int _target;

            std::string _type;

            std::string _activate;

            std::string _cancel;
        };
    }
}
#endif