/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "io\mouse.h"

//using namespace enginecore;

namespace mg
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
    mousing_ = true;
    
    //POINT mouse_position;
    
    //GetCursorPos(&mouse_position);
    //ScreenToClient(Window::getInstance().getHWND(), &mouse_position);

    last_position_.x = current_position_.x = static_cast<LONG>(x);
    last_position_.y = current_position_.y = static_cast<LONG>(y);
    left_button_ = true;
    return true;
}

//...........................................//
bool Mouse::onRightButtonDown(int x, int y)
{
    last_position_.x = current_position_.x = static_cast<LONG>(x);
    last_position_.y = current_position_.y = static_cast<LONG>(y);
    right_button_ = true;
    return true;
}

//.........................................//
void Mouse::reset()
{
    left_button_ = false;
    right_button_ = false;
    middle_button_ = false;
    mousing_ = false;
}

//.......................................//
void Mouse::init()
{
    mousing_ = false;
    left_button_ = false;
    right_button_ = false;
    middle_button_ = false;
}

//......................................//
bool Mouse::onLeftButtonUp()
{
    mousing_ = false;

    return true;
}

//.....................................//
bool Mouse::onRightButtonUp()
{
    mousing_ = false;	

    return true;
}

//...................................//
bool Mouse::onMiddleButtonUp()
{
    mousing_ = false;

    return true;
}
}    // end of io namespace
}    // end of mg namespace