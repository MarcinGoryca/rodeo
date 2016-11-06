/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "io\mouse.h"

//using namespace enginecore;

namespace laura
{
	namespace io
	{
		Mouse::Mouse()
		{
			//GetCursorPos(&mouse_position_);
			//ScreenToClient(Window::getInstance().getHWND(), &mouse_position_); 

			//current_position_.x = mouse_position_.x;
			//current_position_.y = mouse_position_.y;
			reset();
		}

		//.....................................//
		bool Mouse::hide()
		{
			::ShowCursor(false);
			return true;
		}

		//....................................//
		void Mouse::setCursorInMiddle()
		{

		}

		//...................................//
		bool Mouse::onMouseMove(int x, int y)
		{
			setPosition(x, y);
			return true;
		}

		//..................................//
		bool Mouse::show()
		{
			::ShowCursor(true);
			return true;
		}

		//.................................//
		bool Mouse::onLeftButtonDown(int x, int y)
		{
			_mousing = true;

			//POINT mouse_position;

			//GetCursorPos(&mouse_position);
			//ScreenToClient(Window::getInstance().getHWND(), &mouse_position);

			_last_position.x = _current_position.x = static_cast<LONG>(x);
			_last_position.y = _current_position.y = static_cast<LONG>(y);
			_left_button = true;
			return true;
		}

		//...........................................//
		bool Mouse::onRightButtonDown(int x, int y)
		{
			_last_position.x = _current_position.x = static_cast<LONG>(x);
			_last_position.y = _current_position.y = static_cast<LONG>(y);
			_right_button = true;
			return true;
		}

		//.........................................//
		void Mouse::reset()
		{
			_left_button = false;
			_right_button = false;
			_middle_button = false;
			_mousing = false;
		}

		//.......................................//
		void Mouse::init()
		{
			_mousing = false;
			_left_button = false;
			_right_button = false;
			_middle_button = false;
		}

		//......................................//
		bool Mouse::onLeftButtonUp()
		{
			_mousing = false;

			return true;
		}

		//.....................................//
		bool Mouse::onRightButtonUp()
		{
			_mousing = false;

			return true;
		}

		//...................................//
		bool Mouse::onMiddleButtonUp()
		{
			_mousing = false;

			return true;
		}
	}
}