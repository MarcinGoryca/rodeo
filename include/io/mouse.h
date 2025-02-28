﻿/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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
#ifndef RODEO_IO_MOUSE_H_
#define RODEO_IO_MOUSE_H_

//#include "core\framework.h"

#ifndef RODEO_MATH_VECTOR2_H_
#include "math\vector2.h"
#endif

namespace rodeo
{
namespace io
{

enum ClickState
{
    LBUTTON = VK_LBUTTON,
    RBUTTON = VK_RBUTTON,
    MBUTTON = VK_MBUTTON
};

class Mouse
{
public:
    Mouse();
    ~Mouse(){}

    void init();

    virtual bool hide();
    virtual bool show();
    virtual void setCursorInMiddle();
	void reset();

	virtual bool onMouseMove(int x, int y);
	virtual bool onLeftButtonDown(int x, int y);
	virtual bool onRightButtonDown(int x, int y);
	virtual bool onMiddleButtonDown() { return true; }

	virtual bool onLeftButtonUp();
	virtual bool onRightButtonUp();
	virtual bool onMiddleButtonUp();

	virtual bool onDrag() { return true; }
	virtual bool onDrop() { return true; }
	bool onScroll();

    // Get Actual Position of the mouse cursor
    POINT getPosition()const
    {
        return _current_position;
    }

    // Sets Actual position of the mouse cursor
    void setPosition(int x, int y)
    {
        _current_position.x = static_cast<LONG>(x);
        _current_position.y = static_cast<LONG>(y);
    }

    //POINT getCurrent()const { return current_position_; }

    // Gets Last position of mouse cursor
    POINT getLast() const
    {
        return _last_position;
    }

    // Sets Last mouse cursor position
    void setLast(int x, int y)
    {
        _last_position.x = x;
        _last_position.y = y;
    }
    //void setCurrent(int x, int y);



    // Get Mousing
    bool getMousing() const
    {
        return _mousing;
    }

    // Set Mousing
    void setMousing(bool new_mousing)
    {
        _mousing = new_mousing;
    }

    // Get Left Button State
    bool getLeftButton() const
    {
        return _left_button;
    }

    // Set Left Button State (true, false)
    void setLeftButton(bool new_left_button)
    {
        _left_button = new_left_button;
    }

    // Get Right Button
    bool getRightButton() const
    {
        return _right_button;
    }

    // Set Right Button State (true, false)
    void setRightButton(bool new_right_button)
    {
        _right_button = new_right_button;
    }

    // Get Middle Button
    bool getMiddleButton() const
    {
        return _middle_button;
    }

    // Set Middle Button State (true, false)
    void setMiddleButton(bool new_middle_button)
    {
        _middle_button = new_middle_button;
    }

private:
    bool _mousing;
    bool _left_button;
    bool _right_button;
    bool _middle_button;
	bool _scroll;
	bool _dpi;
	bool _add_button1;
	bool _add_button2;

    //POINT mouse_position_;
    POINT _current_position;
    POINT _last_position;
};
}
}
#endif