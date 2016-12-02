/*
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