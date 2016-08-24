/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "core\timer.h"
#include "controllers\timecontroller.h"

namespace mona
{
	namespace controllers
	{
		void TimeController::init()
		{
			_time = new mona::core::Timer;
		}

		//--------------------------------------------------------------------------------------------------
		void TimeController::clean()
		{
			delete _time;
		}

		//--------------------------------------------------------------------------------------------------
		bool TimeController::toggleFPS()
		{
			if (!_fps_show)
			{
				_fps_show = true;
			}
			else
			{
				_fps_show = false;
			}
			return true;
		}

		//--------------------------------------------------------------------------------------------------
		float TimeController::showFPS()
		{
			//return time_.getFPS();
			return 1;
		}
	}
}