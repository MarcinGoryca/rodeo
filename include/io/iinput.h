/*
-----------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_IO_IINPUT_H_
#define MONA_IO_IINPUT_H_

namespace mona
{
namespace io
{
enum InputType
{
    MONA_KEYBOARD_INPUT = 1,
    MONA_MOUSE_INPUT = 2,
	MONA_JOY_INPUT = 3,
	MONA_GAMEPAD_INPUT = 4,
	MONA_WHEEL_INPUT = 5,
	MONA_TOUCH_INPUT = 6
};

class IInput
{
public:
    IInput(){}
    virtual ~IInput(){}
};
}
}
#endif