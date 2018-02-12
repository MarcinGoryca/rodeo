/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
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
//#include "io\mouse.h"
//
////using namespace enginecore;
//
//namespace rodeo
//{
//	namespace io
//	{
//		Mouse::Mouse()
//		{
//			//GetCursorPos(&mouse_position_);
//			//ScreenToClient(Window::getInstance().getHWND(), &mouse_position_); 
//
//			//current_position_.x = mouse_position_.x;
//			//current_position_.y = mouse_position_.y;
//			reset();
//		}
//
//		//.....................................//
//		bool Mouse::hide()
//		{
//			::ShowCursor(false);
//			return true;
//		}
//
//		//....................................//
//		void Mouse::setCursorInMiddle()
//		{
//
//		}
//
//		//...................................//
//		bool Mouse::onMouseMove(int x, int y)
//		{
//			setPosition(x, y);
//			return true;
//		}
//
//		//..................................//
//		bool Mouse::show()
//		{
//			::ShowCursor(true);
//			return true;
//		}
//
//		//.................................//
//		bool Mouse::onLeftButtonDown(int x, int y)
//		{
//			_mousing = true;
//
//			//POINT mouse_position;
//
//			//GetCursorPos(&mouse_position);
//			//ScreenToClient(Window::getInstance().getHWND(), &mouse_position);
//
//			_last_position.x = _current_position.x = static_cast<LONG>(x);
//			_last_position.y = _current_position.y = static_cast<LONG>(y);
//			_left_button = true;
//			return true;
//		}
//
//		//...........................................//
//		bool Mouse::onRightButtonDown(int x, int y)
//		{
//			_last_position.x = _current_position.x = static_cast<LONG>(x);
//			_last_position.y = _current_position.y = static_cast<LONG>(y);
//			_right_button = true;
//			return true;
//		}
//
//		//.........................................//
//		void Mouse::reset()
//		{
//			_left_button = false;
//			_right_button = false;
//			_middle_button = false;
//			_mousing = false;
//		}
//
//		//.......................................//
//		void Mouse::init()
//		{
//			_mousing = false;
//			_left_button = false;
//			_right_button = false;
//			_middle_button = false;
//		}
//
//		//......................................//
//		bool Mouse::onLeftButtonUp()
//		{
//			_mousing = false;
//
//			return true;
//		}
//
//		//.....................................//
//		bool Mouse::onRightButtonUp()
//		{
//			_mousing = false;
//
//			return true;
//		}
//
//		//...................................//
//		bool Mouse::onMiddleButtonUp()
//		{
//			_mousing = false;
//
//			return true;
//		}
//	}
//}