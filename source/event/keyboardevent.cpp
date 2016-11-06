/*
----------------------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\error.h"
#include "event\event.h"
#include "event\keyboardevent.h"
#include "tools\xmlparser.h"

using namespace laura::tools;
using namespace laura::io;
using namespace laura::core;

namespace laura
{
namespace event
{
bool KeyboardEvent::onKeyDown(KeyMap key)
{
    switch(key)
    {
    case KEYF1:
        {
            MessageBox(NULL, L"F1!", LAURA_HEADER.c_str(), ERR_ICON_OK);
            return true;
        }
        break;
    case KEYF2:
        {
            MessageBox(NULL, L"F2!", LAURA_HEADER.c_str(), ERR_ICON_OK);
            return true;
        }
    }
    return true;
}

bool KeyboardEvent::onKeyUp(KeyMap key)
{
    MessageBox(NULL, L"Key Released!", LAURA_HEADER.c_str(), ERR_ICON_OK);
    return true;
}
}    // end of event namespace
}    // end of laura namespace