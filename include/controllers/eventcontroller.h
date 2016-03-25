/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ EventController.h ] [ mg\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_EVENTCONTROLLER_H_
#define MG_CORE_EVENTCONTROLLER_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "constants.h"
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "singleton.h"
#endif

#ifndef MG_CORE_MASTERCONTROLLER_H_
#include "mastercontroller.h"
#endif

namespace mg
{
	namespace event
	{
		class Event;
	}

	namespace core
	{
		class EventController : public Singleton<EventController>, public MasterController
		{
		public:
			/*
			 |  ------------------------------------------
			 |    Constructor
			 |  ------------------------------------------
			 */
			EventController()
			{
				init();
			}

			/*
			|  ------------------------------------------
			|    Destructor
			|  ------------------------------------------
			*/
			virtual ~EventController()
			{
				clear();
			}

			/*
			 |  -----------------------------------------
			 |    Translates the event
			 |  -----------------------------------------
			 */
			void translate(mg::event::Event* event);

			/*
			 |  -----------------------------------------
			 |    Dispatches the event
			 |  -----------------------------------------
			 */
			void dispatch(mg::event::Event* event);

			/*
			 |  -----------------------------------------
			 |    Sends the event
			 |  -----------------------------------------
			 */
			void send(mg::event::Event* event);

			/*
			 |  ----------------------------------------
			 |    Adds event listener
			 |    Implementing virtual method
			 |    Parameter Event* type of the event
			 |  ----------------------------------------
			 */
			virtual void addEventListener(mg::event::Event* event_type);

			/*
			 |  ---------------------------------------
			 |    Removes an event listener
			 |  ---------------------------------------
			 */
			void removeEventListener();

			/*
			 |  ---------------------------------------
			 |    Overload this method in game class
			 |  ---------------------------------------
			 */
			virtual void getUserInput();

			/*
			 |  ---------------------------------------
			 |    Gets Event object pointer
			 |  ---------------------------------------
			 */
			mg::event::Event* getEvent() const
			{
				return event_;
			}

		private:
			mg::event::Event* event_;

			bool init();
			void clear();
		};
	}    // end of core namespace
}    // end of mg namespace
#endif    // MG_CORE_EVENTCONTROLLER_H_