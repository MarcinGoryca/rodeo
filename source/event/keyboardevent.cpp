/*
----------------------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\error.h"
#include "event\event.h"
#include "event\keyboardevent.h"
#include "tools\xmlparser.h"

using namespace mona::tools;
using namespace mona::io;
using namespace mona::core;

namespace mona
{
namespace event
{
bool KeyboardEvent::onKeyDown(KeyMap key)
{
    switch(key)
    {
    case KEYF1:
        {
            MessageBox(NULL, L"F1!", MONA_HEADER.c_str(), ERR_ICON_OK);
            return true;
        }
        break;
    case KEYF2:
        {
            MessageBox(NULL, L"F2!", MONA_HEADER.c_str(), ERR_ICON_OK);
            return true;
        }
    }
    return true;
}

bool KeyboardEvent::onKeyUp(KeyMap key)
{
    MessageBox(NULL, L"Key Released!", MONA_HEADER.c_str(), ERR_ICON_OK);
    return true;
}
}    // end of event namespace
}    // end of mona namespace