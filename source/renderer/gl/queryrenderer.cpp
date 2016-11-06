///*
//----------------------------------------------
//    Laura Game Engine
//    Copyright(c) Marcin Goryca
//    marcin.goryca@gmail.com
//    http://marcingoryca.pl
//----------------------------------------------
//*/
//#include "renderer\gl\queryrenderer.h"
//
//using namespace std;
//using namespace laura::core;
//
//namespace laura 
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
//}    // end of laura namespace
