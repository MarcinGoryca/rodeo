/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_MOUSE_H_
#define MG_IO_MOUSE_H_

//#include "core\framework.h"

#ifndef MG_MATH_VECTOR2_H_
#include "math\vector2.h"
#endif

namespace mg
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

    // Get Actual Position of the mouse cursor
    POINT getPosition()const
    {
        return current_position_;
    }

    // Sets Actual position of the mouse cursor
    void setPosition(int x, int y)
    {
        current_position_.x = static_cast<LONG>(x);
        current_position_.y = static_cast<LONG>(y);
    }

    //POINT getCurrent()const { return current_position_; }

    // Gets Last position of mouse cursor
    POINT getLast() const
    {
        return last_position_;
    }

    // Sets Last mouse cursor position
    void setLast(int x, int y)
    {
        last_position_.x = x;
        last_position_.y = y;
    }
    //void setCurrent(int x, int y);

    void reset();

    virtual bool onMouseMove(int x, int y);
    virtual bool onLeftButtonDown(int x, int y);
    virtual bool onRightButtonDown(int x, int y);
    virtual bool onMiddleButtonDown(){return true;}

    virtual bool onLeftButtonUp();
    virtual bool onRightButtonUp();
    virtual bool onMiddleButtonUp();

    virtual bool onDrag(){return true;}
    virtual bool onDrop(){return true;}
    bool onScroll();

    // Get Mousing
    bool getMousing() const
    {
        return mousing_;
    }

    // Set Mousing
    void setMousing(bool new_mousing)
    {
        mousing_ = new_mousing;
    }

    // Get Left Button State
    bool getLeftButton() const
    {
        return left_button_;
    }

    // Set Left Button State (true, false)
    void setLeftButton(bool new_left_button)
    {
        left_button_ = new_left_button;
    }

    // Get Right Button
    bool getRightButton() const
    {
        return right_button_;
    }

    // Set Right Button State (true, false)
    void setRightButton(bool new_right_button)
    {
        right_button_ = new_right_button;
    }

    // Get Middle Button
    bool getMiddleButton() const
    {
        return middle_button_;
    }

    // Set Middle Button State (true, false)
    void setMiddleButton(bool new_middle_button)
    {
        middle_button_ = new_middle_button;
    }

private:
    bool mousing_;
    bool left_button_;
    bool right_button_;
    bool middle_button_;

    //POINT mouse_position_;
    POINT current_position_;
    POINT last_position_;
};
}    // end of io namespace 
}    // end of mg namespace
#endif