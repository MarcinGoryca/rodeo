/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "io\keyboard.h"

using namespace mg::core;

namespace mg
{
namespace io
{
Keyboard::Keyboard(int state)
{
    keystate_ = state;
}

//.........................................//
Keyboard::Keyboard(const Keyboard& copy)
{
    this->operator=(copy);
}

//.........................................//
Keyboard& Keyboard::operator=(const Keyboard& copy)
{
    if(this != &copy)
    {
        keystate_ = copy.keystate_;
    }
    return *this;
}
}    // end of io namespace
}    // end of mg namespace