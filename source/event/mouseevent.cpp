/*
----------------------------------------------
    laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\error.h"
#include "event\event.h"
#include "event\mouseevent.h"

using namespace laura::core;

namespace laura
{
namespace event
{
void MouseEvent::onMouseMove()
{
    MessageBox(NULL, L"OnMouseMove Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftButtonClick()
{
    MessageBox(NULL, L"OnLeftButtonClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftButtonDoubleClick()
{
    MessageBox(NULL, L"onLeftButtonDoubleClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onRightButtonClick()
{
    MessageBox(NULL, L"onRightButtonClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onRightButtonDoubleClick()
{
    MessageBox(NULL, L"onRightButtonDoubleClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onMiddleButtonClick()
{
    MessageBox(NULL, L"onMiddleButtonClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onMiddleButtonDoubleClick()
{
    MessageBox(NULL, L"onMiddleButtonDoubleClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftRightClick()
{
    MessageBox(NULL, L"onLeftRightClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onLeftMiddleClick()
{
    MessageBox(NULL, L"onLeftMiddleClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onRightMiddleClick()
{
    MessageBox(NULL, L"onRightMiddleClick Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

void MouseEvent::onDrag()
{
    MessageBox(NULL, L"onDrag Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
}

bool MouseEvent::onMouseDown()
{
    MessageBox(NULL, L"onMouseDown Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
    return true;
}

bool MouseEvent::onMouseUp()
{
    MessageBox(NULL, L"onMOuseUp Invoked!", LAURA_HEADER.c_str(), ERR_ICON_OK);
    return true;
}
}    // end of event namespace
}    // end of laura namespace