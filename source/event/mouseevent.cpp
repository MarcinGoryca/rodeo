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
#include "event\mouseevent.h"

using namespace mona::core;

namespace mona
{
namespace event
{
void MouseEvent::onMouseMove()
{
    MessageBox(NULL, L"OnMouseMove Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftButtonClick()
{
    MessageBox(NULL, L"OnLeftButtonClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftButtonDoubleClick()
{
    MessageBox(NULL, L"onLeftButtonDoubleClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onRightButtonClick()
{
    MessageBox(NULL, L"onRightButtonClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onRightButtonDoubleClick()
{
    MessageBox(NULL, L"onRightButtonDoubleClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onMiddleButtonClick()
{
    MessageBox(NULL, L"onMiddleButtonClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onMiddleButtonDoubleClick()
{
    MessageBox(NULL, L"onMiddleButtonDoubleClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftRightClick()
{
    MessageBox(NULL, L"onLeftRightClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftMiddleClick()
{
    MessageBox(NULL, L"onLeftMiddleClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onRightMiddleClick()
{
    MessageBox(NULL, L"onRightMiddleClick Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onDrag()
{
    MessageBox(NULL, L"onDrag Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
}

bool MouseEvent::onMouseDown()
{
    MessageBox(NULL, L"onMouseDown Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
    return true;
}

bool MouseEvent::onMouseUp()
{
    MessageBox(NULL, L"onMOuseUp Invoked!", MONA_HEADER.c_str(), ERR_ICON_OK);
    return true;
}
}    // end of event namespace
}    // end of mona namespace