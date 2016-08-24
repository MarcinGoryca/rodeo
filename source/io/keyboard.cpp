/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "io\keyboard.h"

using namespace mona::core;

namespace mona
{
	namespace io
	{
		Keyboard::Keyboard(int state)
		{
			_keystate = state;
		}

		//.........................................//
		Keyboard::Keyboard(const Keyboard& copy)
		{
			this->operator=(copy);
		}

		//.........................................//
		Keyboard& Keyboard::operator=(const Keyboard& copy)
		{
			if (this != &copy)
			{
				_keystate = copy._keystate;
			}
			return *this;
		}
	}
}