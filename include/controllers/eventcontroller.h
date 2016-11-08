/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    [ EventController.h ] [ laura\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CORE_EVENTCONTROLLER_H_
#define LAURA_CORE_EVENTCONTROLLER_H_

#ifndef LAURA_CORE_CONSTANTS_H_
#include "constants.h"
#endif

#ifndef LAURA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef LAURA_CORE_MASTERCONTROLLER_H_
#include "mastercontroller.h"
#endif

namespace laura
{
	namespace event
	{
		class Event;
	}

	namespace controllers
	{
		class EventController : public laura::core::Singleton<EventController>, public MasterController
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
			void translate(laura::event::Event* event);

			/*
			 |  -----------------------------------------
			 |    Dispatches the event
			 |  -----------------------------------------
			 */
			void dispatch(laura::event::Event* event);

			/*
			 |  -----------------------------------------
			 |    Sends the event
			 |  -----------------------------------------
			 */
			void send(laura::event::Event* event);

			/*
			 |  ----------------------------------------
			 |    Adds event listener
			 |    Implementing virtual method
			 |    Parameter Event* type of the event
			 |  ----------------------------------------
			 */
			virtual void addEventListener(laura::event::Event* event_type);

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
			laura::event::Event* getEvent() const
			{
				return _event;
			}

		private:
			laura::event::Event* _event;

			bool init();
			void clear();
		};
	}
}
#endif