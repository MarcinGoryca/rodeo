///*
//----------------------------------------------
//    MG Game Engine
//    Copyright(c) Marcin Goryca
//    marcin.goryca@gmail.com
//    http://marcingoryca.pl
//----------------------------------------------
//*/
//#include "core\window.h"
//
//using namespace std;
//
//namespace mg
//{
//namespace core
//{
////LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
////{
////    static Window* rodeo_application = 0;
////
////    switch(msg)
////    {
////    case WM_CREATE:
////        {
////            CREATESTRUCT* cs = (CREATESTRUCT*)lparam;
////            rodeo_application = (Window*)cs->lpCreateParams;
////            return 0;
////        }
////    }
////    if(rodeo_application)
////        return rodeo_application->messageProcessor(msg, wparam, lparam);
////    else
////        return DefWindowProc(hwnd, msg, wparam, lparam);
////}
//
///**
// * 
// */
//
//void Window::init()
//{
//    createWindowClass(GetModuleHandle(NULL), getWindowClassName());
//    registerClass();
//    window(getWindowClassName(), getWindowName(), getHinstance(), getWidth(), getHeight());
//    show();
//    createGLContext(GetDC(getWindowHandle()));
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::createWindowClass(HINSTANCE hinstance, std::wstring classname)
//{
//    //wnd_.cbSize = sizeof(wnd_);
//    //wnd_.cbClsExtra = 0;
//    //wnd_.cbWndExtra = 0;
//    //wnd_.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//    //wnd_.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
//    //wnd_.hIcon = (HICON)LoadImage(NULL, iconAssetPath.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
//    //wnd_.hIconSm = (HICON)LoadImage(NULL, iconSmAssetPath.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
//    //wnd_.hInstance = GetModuleHandle(NULL);
//    //wnd_.lpfnWndProc = WindowProcedure;
//    //wnd_.lpszClassName = classname;
//    //wnd_.lpszMenuName = NULL;
//    //wnd_.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC;
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//HWND Window::window(const wstring classname, const wstring windowname, HINSTANCE hinstance, int w, int h)
//{
//    setWindowWidth(w);
//    setWindowHeight(h);
//
//    style_ = WS_BORDER | WS_OVERLAPPEDWINDOW | WS_VISIBLE;
//
//    if(fullscreen_)
//    {
//        exstyles_ = WS_EX_APPWINDOW;
//        toggleFullScreen();
//        //setStyle(WS_POPUP | WS_VISIBLE);
//        style_ = WS_POPUP | WS_VISIBLE;
//    }
//    else
//    {
//        exstyles_ = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
//        //tStyle(style_);
//    }
//
//    setRect();
//
//    AdjustWindowRectEx(&rect_, style_, false, exstyles_);
//
//    hwnd_ = CreateWindowEx(exstyles_,
//                           classname.c_str(),
//                           windowname.c_str(),
//                           style_,
//                           rect_.left,
//                           rect_.top,
//                           rect_.right - rect_.left,
//                           rect_.bottom - rect_.top,
//                           NULL,
//                           NULL,
//                           hinstance,
//                           this
//                           );
//
//    if(!hwnd_)
//        return NULL;
//
//    return hwnd_;
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::registerClass()
//{
//    if(!::RegisterClassEx(&getWindowClass()))
//        return false;
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::show()
//{
//    ::ShowWindow(getWindowHandle(), SW_SHOW);
//    ::UpdateWindow(getWindowHandle());
//    ::SetFocus(getWindowHandle());
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::loop()
//{
//    while(true)
//    {
//        if(PeekMessage(&getMessage(), 0, 0, 0, PM_REMOVE))
//        {
//            if(getMessage().message == WM_QUIT) break;
//            TranslateMessage(&getMessage());
//            DispatchMessage(&getMessage());
//        }
//    }
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::toggleFullScreen()
//{
//    DEVMODE dm;
//    ZeroMemory(&dm, sizeof(dm));
//
//    if(!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
//    {
//        MessageBox(NULL, L"Couldn't Enum Display Settings", MG_HEADER.c_str(), ERR_ICON_OK);
//        return;
//    }
//
//    dm.dmSize = sizeof(DEVMODE);
//    dm.dmPelsWidth = getWidth();
//    dm.dmPelsHeight = getHeight();
//    dm.dmBitsPerPel = getDepth();
//    dm.dmDisplayFrequency = getFrequency();
//    dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL | DM_DISPLAYFREQUENCY;
//    
//    int result = ChangeDisplaySettings(&dm, CDS_FULLSCREEN);
//        
//    if(result != DISP_CHANGE_SUCCESSFUL)
//    {
//        MessageBox(NULL, L"Display Mode Not Compatible", MG_HEADER.c_str(), ERR_ICON_OK);
//        onDestroy();
//    }
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::setupPixelFormat(HDC hdc)
//{
//    int pixelFormat;
//    PIXELFORMATDESCRIPTOR pfd = {0}; 
//
//    pfd.nSize = sizeof(pfd);
//    pfd.nVersion = 1;
//    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
//    pfd.dwLayerMask = PFD_MAIN_PLANE;
//    pfd.iPixelType = PFD_TYPE_RGBA;
//    pfd.cColorBits = static_cast<BYTE>(depth_);
//    pfd.cDepthBits = static_cast<BYTE>(depth_);
//    pfd.cAccumBits = 0;
//    pfd.cStencilBits = 0;
//
//    pixelFormat = ChoosePixelFormat(hdc, &pfd);
//
//    if(!pixelFormat)
//    {
//        MessageBox(NULL, L"Choose PixelFormat FAIL!", MG_HEADER.c_str(), ERR_ICON_OK);
//        return;
//    }
//
//    if(!SetPixelFormat(hdc, pixelFormat, &pfd))
//    {
//        MessageBox(NULL, L"Set PixelFormat FAIL!", MG_HEADER.c_str(), ERR_ICON_OK);
//        return;
//    }
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onDestroy()
//{
//    PostQuitMessage(0);
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onClose()
//{
//    stopWiggle();
//
//    if(fullscreen_)
//    {
//        ChangeDisplaySettings(NULL, 0);
//    }
//
//    hrc_ = NULL;
//    hdc_ = NULL;
//    hwnd_ = NULL;
//    hinstance_ = NULL;
//
//    onDestroy();
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onSize(int width, int height)
//{
//    setWindowWidth(width);
//    setWindowHeight(height);
//}
//
////--------------------------------------------------------------------------------------------------
//int Window::shutdown()
//{
//    //if(timeMgr_ != NULL)
//    //{
//    //    delete timeMgr_;
//    //    timeMgr_ = NULL;
//    //}
//
//    /*if(renderer_ != NULL)
//    {
//        delete renderer_;
//        renderer_ = NULL;
//    }*/
//    return msg_.wParam;
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::addMenu(HINSTANCE hinstance, LPCWSTR menuName)
//{
//    HMENU hmenu = LoadMenu(hinstance, menuName); 
//    SetMenu(getWindowHandle(), hmenu);
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::update()
//{
//    SwapBuffers(GetDC(getWindowHandle()));
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::checkFullscreen()
//{
//    fullscreen_ = true;
//
//    SetWindowLongPtr(getWindowHandle(), GWL_STYLE, WS_SYSMENU | WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE);
//    SetWindowPos(getWindowHandle(), 0, 0, 0, rect_.right - rect_.left, rect_.bottom - rect_.top, SWP_SHOWWINDOW);
//
//    if(fullscreen_)
//    {
//        toggleFullScreen();
//    }
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::changeResolution(int w, int h)
//{
//    if(hinstance_ != NULL)
//        hinstance_ = NULL;
//    
//    setWindow(getWidth(), getHeight(), getDepth(), getFrequency());
//    
//    show();
//
//    onCreate(GetDC(getWindowHandle()));
//    //renderer_->onSize(getWidth(), getHeight());
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::setRect()
//{
//    if(fullscreen_)
//    {
//        rect_.left = 0;
//        rect_.top = 0;
//    }
//    else
//    {
//        rect_.left = 30;
//        rect_.top = 40;
//    }
//    rect_.bottom = getHeight();
//    rect_.right = getWidth();
//
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::setRect(int left, int top, int right, int bottom)
//{
//    rect_.left = left;
//    rect_.top = top;
//    rect_.right = right;
//    rect_.bottom = bottom;
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::loadCustomCursor(const std::wstring file_path)
//{
//    HCURSOR custom_cursor = (HCURSOR)LoadCursorFromFile(file_path.c_str());
//
//    SetClassLong(hwnd_, GCL_HCURSOR, (LONG)custom_cursor);
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::createGLContext(HDC hdc)
//{
//    hdc_ = hdc;
//    PIXELFORMATDESCRIPTOR pfd;
//    ZeroMemory(&pfd, sizeof(pfd));
//
//    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
//    pfd.nVersion = 1;
//    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
//    pfd.iPixelType = PFD_TYPE_RGBA;
//    pfd.cColorBits = 32;
//    pfd.cDepthBits = 32;
//    pfd.iLayerType = PFD_MAIN_PLANE;
//
//    int pixel_format = ChoosePixelFormat(hdc_, &pfd);
//
//    if(pixel_format == 0)
//        return false;
//    BOOL result = SetPixelFormat(getDeviceContext(), pixel_format, &pfd);
//
//    if(!result)
//        return false;
//
//    HGLRC temporary_context = wglCreateContext(getDeviceContext());
//    wglMakeCurrent(getDeviceContext(), temporary_context);
//
//    int attributes[] =
//    {
//        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
//        WGL_CONTEXT_MINOR_VERSION_ARB, 3,
//        WGL_CONTEXT_FLAGS_ARB, 0,
//        0
//    };
//
//    if(wglewIsSupported("WGL_ARB_create_context") == 1)
//    {
//        hrc_ = wglCreateContextAttribsARB(getDeviceContext(), 0, attributes);
//        wglMakeCurrent(NULL, NULL);
//        wglDeleteContext(temporary_context);
//        wglMakeCurrent(getDeviceContext(), hrc_);
//    }
//    else
//    {
//        hrc_ = temporary_context;
//    }
//
//    int opengl_version[2] = {0};
//    glGetIntegerv(GL_MAJOR_VERSION, &opengl_version[0]);
//    glGetIntegerv(GL_MINOR_VERSION, &opengl_version[1]);
//
//    if(!hrc_)
//        return false;
//
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::setWindow(int w, int h, int d, int f)
//{
//    width_ = w;
//    height_ = h;
//    depth_ = d;
//    freq_ = f;
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::startWiggle(HDC hhdc)
//{
//    hdc_ = hhdc;
//    setupPixelFormat(hdc_);
//    hrc_ = wglCreateContext(hdc_);
//    wglMakeCurrent(hdc_, hrc_);
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//bool Window::stopWiggle()
//{
//    wglMakeCurrent(hdc_, NULL);
//    wglDeleteContext(hrc_);
//    return true;
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onCreate(HDC hdc)
//{
//    createGLContext(hdc);
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onUpdate()
//{
//    //Implement your onUpdate() method in derivied class 
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onUpdate(float dt)
//{
//    //Implement your onUpdate(float dt) method in derivied class
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onRender()
//{
//
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onMouseMove(int x, int y)
//{
//    //Implement your onMouseMove(int x, int y) method in derivied class
//    MessageBox(NULL, L"mc", MG_HEADER.c_str(), ERR_ICON_OK);
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onLeftButtonDoubleClick()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onKeydown()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onInit()
//{
//    //time_manager_->time_.init();
//    //mathcore_->init();
//    //fontMgr_.init();
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onLeftButtonDown()
//{
//    //mouse_.mousing_ = true;
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onRightButtonDoubleClick()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onRightButtonDown()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onKeyup()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onLeftButtonUp()
//{
//   // mouse_.mousing_ = false;
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onMiddleButtonDown()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onMiddleButtonUp()
//{
//}
//
////--------------------------------------------------------------------------------------------------
///*void Window::onRender()
//{
//}*/
//
////--------------------------------------------------------------------------------------------------
//void Window::onRightButtonUp()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//void Window::onScroll()
//{
//}
//
////--------------------------------------------------------------------------------------------------
//LRESULT Window::messageProcessor(UINT msg, WPARAM wparam, LPARAM lparam)
//{
//    switch(msg)
//    {
//
//    case WM_CLOSE:
//        onClose();
//        ShowCursor(true);
//        break;
//
//    case WM_DESTROY:
//        onDestroy();
//        break;
//
//    case WM_SIZE:
//        {
//            int window_width = LOWORD(lparam);
//            int window_height = HIWORD(lparam);
//            setWindowWidth(window_width);
//            setWindowHeight(window_height);
//            onSize(getWidth(), getHeight());
//        }
//        break;
//
//    case WM_COMMAND:
//        break;
//
//
//    case WM_KEYDOWN:
//        {
//            if(GetAsyncKeyState(VK_ESCAPE))
//                onClose();
//
//            onKeydown();
//            break;
//        }
//
//
//    case WM_KEYUP:
//        {
//            break;
//        }
//
//
//    case WM_LBUTTONDOWN:
//        {
//            int x = LOWORD(lparam);
//            int y = HIWORD(lparam);
//            onLeftButtonDown();
//        }
//        break;
//
//
//    case WM_LBUTTONUP:
//        {
//            onLeftButtonUp();
//        }
//        break;
//
//
//    case WM_RBUTTONDOWN:
//        {
//            onRightButtonDown();
//        }
//        break;
//
//
//    case WM_RBUTTONUP:
//        {
//            onRightButtonUp();
//        }
//        break;
//
//
//    case WM_MBUTTONDOWN:
//        {
//            onMiddleButtonDown();
//        }
//        break;
//
//
//    case WM_MBUTTONUP:
//        {
//            onMiddleButtonUp();
//        }
//        break;
//
//
//    case WM_MBUTTONDBLCLK:
//        {
//        }
//        break;
//
//
//    case WM_MOUSELEAVE:
//        {
//            MessageBox(NULL, L"Mouse outside the framework!", MG_HEADER.c_str(), ERR_ICON_OK);
//        }
//        break;
//
//
//    case WM_MOUSEMOVE:
//        {
//            onMouseMove(LOWORD(lparam), HIWORD(lparam));
//            //MessageBox(NULL, "move", HEADER, errIconOK);
//        }
//        break;
//
//
//    case WM_MOUSEWHEEL:
//        {
//            onScroll();
//        }
//        break;
//
//    case WM_CREATE:
//        {
//            //create();
//        }
//        break;
//    }
//    return DefWindowProc(hwnd_, msg, wparam, lparam);
//}
//}    // end of core namespace
//}    // end of mg namespace