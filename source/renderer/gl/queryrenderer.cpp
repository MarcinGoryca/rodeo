/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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
//#include "renderer\gl\queryrenderer.h"
//
//using namespace std;
//using namespace rodeo::core;
//
//namespace rodeo 
//{
//namespace renderer
//{
//void QueryRenderer::run()
//{
////Simple Exception Handling
//    try
//    {
//        gl21supported_ = ::atof((const char*)glGetString(GL_VERSION)) >= 2.1;
//        if(!gl21supported_)
//            throw RendererException(L"Sorry, your GPU doesn't support OpenGL 2.1");
//        
//        gl31supported_ = ::atof((const char*)glGetString(GL_VERSION)) >= 3.1;
//        if(!gl31supported_)
//            throw RendererException(L"Sorry, your GPU doesn't support OpenGL 3.1");
//    
//        gl32supported_ = ::atof((const char*)glGetString(GL_VERSION)) >= 3.2; 
//        if(!gl32supported_)
//            throw RendererException(L"Sorry, your GPU doesn't support OpenGL 3.2");
//        
//        gl33supported_ = ::atof((const char*)glGetString(GL_VERSION)) >= 3.3;
//        if(!gl33supported_)
//            throw RendererException(L"Sorry, your GPU doesn't support OpenGL 3.3");
//
//        gl41supported_ = ::atof((const char*)glGetString(GL_VERSION)) >= 4.1;
//        if(!gl41supported_)
//            throw RendererException(L"Sorry, your GPU doesn't support OpenGL 4.1");
//    }
//    catch(RendererException& renderer_exception)
//    {
//        //Exception handling code 
//        renderer_exception.getExceptionString();
//    }
//}
//
//
//string QueryRenderer::print(string s)const
//{	
//	return s;
//}
//
///**
// *
// */
//
//bool QueryRenderer::reset()
//{
//	glvendor_ = 0;
//	glrenderer_ = 0;
//	glversion_ = 0;
//	return true;
//}
//
///**
// *
// */
//
//void QueryRenderer::checkMultisampling()
//{
//    int result=0;
//    glGetIntegerv(GL_SAMPLE_BUFFERS, &result);
//    
//    if(result == 1)
//    {
//        //Print appropriate message
//    }
//    else
//    {
//        //Throw an exception
//    }
//}
//}    // end of renderer namespace
//}    // end of rodeo namespace
