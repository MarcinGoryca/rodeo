﻿/*
| --------------------------------------------------------------------------------------------------
|     Laura Project
|
|     marcin.goryca@gmail.com
|     http://marcingoryca.pl
|
|     License Information
|
|     The MIT License (MIT)
|     Copyright (c) 2016 Marcin Goryca
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
//
//#ifndef LAURA_CORE_EVENTCONTROLLER_H_
//#define LAURA_CORE_EVENTCONTROLLER_H_
//
//#ifndef LAURA_CORE_CONSTANTS_H_
//#include "constants.h"
//#endif
//
//#ifndef LAURA_CORE_SINGLETON_H_
//#include "core\singleton.h"
//#endif
//
//#ifndef LAURA_CORE_MASTERCONTROLLER_H_
//#include "mastercontroller.h"
//#endif
//
//namespace laura
//{
//	namespace event
//	{
//		class Event;
//	}
//
//	namespace controllers
//	{
//		class EventController : public laura::core::Singleton<EventController>, public MasterController
//		{
//		public:
//			/*
//			 |  ------------------------------------------
//			 |    Constructor
//			 |  ------------------------------------------
//			 */
//			EventController()
//			{
//				init();
//			}
//
//			/*
//			|  ------------------------------------------
//			|    Destructor
//			|  ------------------------------------------
//			*/
//			virtual ~EventController()
//			{
//				clear();
//			}
//
//			/*
//			 |  -----------------------------------------
//			 |    Translates the event
//			 |  -----------------------------------------
//			 */
//			void translate(laura::event::Event* event);
//
//			/*
//			 |  -----------------------------------------
//			 |    Dispatches the event
//			 |  -----------------------------------------
//			 */
//			void dispatch(laura::event::Event* event);
//
//			/*
//			 |  -----------------------------------------
//			 |    Sends the event
//			 |  -----------------------------------------
//			 */
//			void send(laura::event::Event* event);
//
//			/*
//			 |  ----------------------------------------
//			 |    Adds event listener
//			 |    Implementing virtual method
//			 |    Parameter Event* type of the event
//			 |  ----------------------------------------
//			 */
//			virtual void addEventListener(laura::event::Event* event_type);
//
//			/*
//			 |  ---------------------------------------
//			 |    Removes an event listener
//			 |  ---------------------------------------
//			 */
//			void removeEventListener();
//
//			/*
//			 |  ---------------------------------------
//			 |    Overload this method in game class
//			 |  ---------------------------------------
//			 */
//			virtual void getUserInput();
//
//			/*
//			 |  ---------------------------------------
//			 |    Gets Event object pointer
//			 |  ---------------------------------------
//			 */
//			laura::event::Event* getEvent() const
//			{
//				return _event;
//			}
//
//		private:
//			laura::event::Event* _event;
//
//			bool init();
//			void clear();
//		};
//	}
//}
//#endif