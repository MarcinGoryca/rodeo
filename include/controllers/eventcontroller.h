/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    [ EventController.h ] [ mona\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CORE_EVENTCONTROLLER_H_
#define MONA_CORE_EVENTCONTROLLER_H_

#ifndef MONA_CORE_CONSTANTS_H_
#include "constants.h"
#endif

#ifndef MONA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MONA_CORE_MASTERCONTROLLER_H_
#include "mastercontroller.h"
#endif

namespace mona
{
	namespace event
	{
		class Event;
	}

	namespace controllers
	{
		class EventController : public mona::core::Singleton<EventController>, public MasterController
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
			void translate(mona::event::Event* event);

			/*
			 |  -----------------------------------------
			 |    Dispatches the event
			 |  -----------------------------------------
			 */
			void dispatch(mona::event::Event* event);

			/*
			 |  -----------------------------------------
			 |    Sends the event
			 |  -----------------------------------------
			 */
			void send(mona::event::Event* event);

			/*
			 |  ----------------------------------------
			 |    Adds event listener
			 |    Implementing virtual method
			 |    Parameter Event* type of the event
			 |  ----------------------------------------
			 */
			virtual void addEventListener(mona::event::Event* event_type);

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
			mona::event::Event* getEvent() const
			{
				return _event;
			}

		private:
			mona::event::Event* _event;

			bool init();
			void clear();
		};
	}
}
#endif