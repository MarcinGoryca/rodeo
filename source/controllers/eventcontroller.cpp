/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "event\event.h"
#include "controllers\eventcontroller.h"

using namespace laura::event;

namespace laura
{
	namespace controllers
	{
		bool EventController::init()
		{
			_event = new event::Event;
			return true;
		}

		// -------------------------------------------------------------------------------------------------
		void EventController::addEventListener(event::Event* event_type)
		{

		}

		// -------------------------------------------------------------------------------------------------
		void EventController::clear()
		{
			if (_event != nullptr)
			{
				delete _event;
				_event = nullptr;
			}
		}

		/**
		void EventManager::getUserInput()
		{
		}
		*/
	}
}