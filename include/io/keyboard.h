/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_KEYBOARD_H_
#define MG_IO_KEYBOARD_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_IO_IINPUT_H_
#include "io\iinput.h"
#endif

namespace mg 
{
namespace io
{
enum KeyMap
{
    KEYUP = VK_UP,
    KEYDOWN = VK_DOWN,
    KEYLEFT = VK_LEFT,
    KEYRIGHT = VK_RIGHT,

    KEY0 = 48,
    KEY1,
    KEY2,
    KEY3,
    KEY4,
    KEY5,
    KEY6,
    KEY7,
    KEY8,
    KEY9,

    KEYA = 65,
    KEYB,
    KEYC,
    KEYD,
    KEYE,
    KEYF,
    KEYG,
    KEYH,
    KEYI,
    KEYJ,
    KEYK,
    KEYL,
    KEYM,
    KEYN,
    KEYO,
    KEYP,
    KEYQ,
    KEYR,
    KEYS,
    KEYT,
    KEYU,
    KEYV,
    KEYW,
    KEYX,
    KEYY,
    KEYZ,

    KEYNUM0 = 96,
    KEYNUM1,
    KEYNUM2,
    KEYNUM3,
    KEYNUM4,
    KEYNUM5,
    KEYNUM6,
    KEYNUM7,
    KEYNUM8,
    KEYNUM9,

    KEYF1 = VK_F1,
    KEYF2 = VK_F2,
    KEYF3 = VK_F3,
    KEYF4 = VK_F4,
    KEYF5 = VK_F5,
    KEYF6 = VK_F6,
    KEYF7 = VK_F7,
    KEYF8 = VK_F8,
    KEYF9 = VK_F9,
    KEYF10 = VK_F10,
    KEYF11 = VK_F11,
    KEYF12 = VK_F12,

    KEYENTER = VK_RETURN,
    KEYESCAPE = VK_ESCAPE,
    KEYTAB = VK_TAB,
    KEYBACKSPACE = VK_BACK,
    KEYSPACE = VK_SPACE,
    KEYSHIFT = VK_SHIFT,
    KEYALT = VK_MENU,
    KEYCTRL = VK_CONTROL,
    KEYCAPS = VK_CAPITAL,
    KEYPAGEUP = VK_PRIOR,
    KEYPAGEDOWN = VK_NEXT,
    KEYEND = VK_END,
    KEYHOME = VK_HOME,
    KEYINSERT = VK_INSERT,
    KEYDELETE = VK_DELETE,
    KEYNUMMINUS = VK_SUBTRACT,
    KEYNUMPLUS = VK_ADD,
    KEYPLUS = VK_OEM_PLUS,
    KEYMINUS = VK_OEM_MINUS,
};

class Keyboard : public IInput
{
public:
    Keyboard()
        :_keystate(-1)
    {}
    Keyboard(int state);
    Keyboard(const Keyboard& copy);
    Keyboard &operator= (const Keyboard& copy);

    virtual ~Keyboard(){}

    //virtual bool onInputEvent();

    //virtual void keyDown(KeyMap id);

    int getKeyState() const
    {
        return _keystate;
    }

    void setKeyState(int new_keystate)
    {
        _keystate = new_keystate;
    }

protected:
    int _keystate;

private:
};
}
}
#endif