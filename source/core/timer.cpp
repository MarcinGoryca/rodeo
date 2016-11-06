/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "core\timer.h"

namespace laura
{
	namespace core
	{
		void Timer::countFramesPerSecond()
		{
			_current_time = getSecs();
			_delta = _current_time - _last_time;

			_last_time = _current_time;

			++_frames;
			_fps_time += _delta;

			//Does a second past?
			if (_fps_time > 1.0f)
			{
				_fps = _frames / _fps_time;
				_frames = 0;
				_fps_time = 0.0f;
			}
		}

		//--------------------------------------------------------------------------------------------------
		void Timer::countFPS()
		{
			_current_time = GetTickCount() * 0.001f;
			if (_current_time - _last_time > 1.0f)
			{
				_last_time = _current_time;

				_fps = 0.0;
			}
			++_fps;
		}

		//--------------------------------------------------------------------------------------------------
		float Timer::getSecs()
		{
			_use_query_performance_frequency = (QueryPerformanceFrequency(&_frequency) != 0);
			if (!_use_query_performance_frequency)
			{
				return GetTickCount() / 1000.0f;
			}
			else
			{
				QueryPerformanceCounter(&_ticks);
				return static_cast<float>(_ticks.QuadPart / static_cast<double>(_frequency.QuadPart));
			}
		}

		//--------------------------------------------------------------------------------------------------
		void Timer::init()
		{
			_last_time = getSecs();
		}
	}
}