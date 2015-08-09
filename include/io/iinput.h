/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_IINPUT_H_
#define MG_IO_IINPUT_H_

namespace mg
{
namespace io
{
enum InputType
{
    MG_KEYBOARD_INPUT = 1,
    MG_MOUSE_INPUT = 2,
	MG_JOY_INPUT = 3,
	MG_GAMEPAD_INPUT = 4,
	MG_WHEEL_INPUT = 5,
	MG_TOUCH_INPUT = 6
};

class IInput
{
public:
    IInput(){}
    virtual ~IInput(){}
};
}    // end of io namespace
}    // end of mg namespace
#endif