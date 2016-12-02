/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
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
//#ifndef LAURA_EVENT_IINPUTLISTENER_H_
//#define LAURA_EVENT_IINPUTLISTENER_H_
//
//#include <list>
//
//#ifndef LAURA_IO_IINPUT_H_
//#include "io\iinput.h"
//#endif
//
//namespace laura
//{
//namespace event
//{
//class IInputListener
//{
//public:
//    IInputListener(){}
//
//    virtual ~IInputListener(){}
//
//    int getInputType()const;
//
//    void addInputListener(laura::io::IInput* in);
//
//    virtual void keyUp(laura::io::IInput key) = 0;
//
//    virtual void keyDown(laura::io::IInput key) = 0;
//
//    virtual void mouseDblClick(laura::io::IInput ms) = 0;
//
//    virtual void mouseMove(laura::io::IInput ms) = 0;
//
//    virtual void mouseExit(laura::io::IInput ms) = 0;
//
//    virtual void mouseScroll(laura::io::IInput ms) = 0;
//
//    virtual void mouseClick(laura::io::IInput ms) = 0;
//
//    virtual void mouseDrag(laura::io::IInput ms) = 0;
//
//protected:
//    std::list <laura::io::IInput*> _input_list;
//};
//}
//}
//#endif