/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\framework.h"

namespace mg
{
namespace core
{
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    static Framework* rodeo_application = 0;

    switch(msg)
    {
    case WM_CREATE:
        {
            CREATESTRUCT* cs = (CREATESTRUCT*)lparam;
            rodeo_application = (Framework*)cs->lpCreateParams;
            return 0;
        }
    }
    if(rodeo_application)
        return rodeo_application->messageProcessor(msg, wparam, lparam);
    else
        return DefWindowProc(hwnd, msg, wparam, lparam);
}

//--------------------------------------------------------------------------------------------------
void Framework::create()
{	
    output_manager_->getLog()->open(L"log.txt");
    output_manager_->getLog()->write(output_manager_->getString());
    output_manager_->getLog()->write(L"Framework created\nEngine is starting...");

    HDC hdc = GetDC(getHWND());

    //if(xml_parser_->read(/*CONFIGURATION_XML.c_str())*/L"configuration\\engine_start.xml"))
    //{
    //    readXMLData();
    //}
    if(!readConfFile(CONFIGURATION_INI.c_str()))
    {
        readDefaults();
    }

    createWindowClass(getHinstance(), getWindowClassName());

    RegisterClassEx(&wnd_);
    window(getWindowClassName(), getWindowName(), getHinstance(), getWidth(), getHeight());
    show();

    output_manager_->getLog()->write(L"Win32 Application is created");

    if(use_gl_)
    {
        render_manager_ = std::unique_ptr<RenderManager>(new RenderManager(MG_GL));
        createGLContext(GetDC(getHWND()));
    }
    if(use_dx_)
    {
        render_manager_ = std::unique_ptr<RenderManager>(new RenderManager(MG_DX));
        render_manager_->getRenderer()->setHWND(getHWND());
    }


    output_manager_->getLog()->write(L"Rendering Context is created");

    render_manager_->getRenderer()->run(getWidth(), getHeight());

    output_manager_->getLog()->write(L"Renderer is running...");

    if(physicsystem_->module_initialized_)
    {
        output_manager_->getLog()->write(physicsystem_->getString());
    }
}

//--------------------------------------------------------------------------------------------------
void Framework::run()
{
    while(true)
    {
        if(PeekMessage(&msg_, 0, 0, 0, PM_REMOVE))
        {
            if(msg_.message == WM_QUIT)
                break;
            TranslateMessage(&msg_);
            DispatchMessage(&msg_);
        }
        time_manager_->getTimer()->countFramesPerSecond();
        setGlobalDeltaTime(time_manager_->getTimer()->getDelta());

        event_manager_->getUserInput();

        //Start Physics calculations

        physicsystem_->update(getGlobalDeltaTime());
        physicsystem_->update();

        //Begin Rendering Phase

        render_manager_->getRenderer()->enterFrame();
        render_manager_->getRenderer()->enableShaders();
        
        //Override this method in your application
        onRender();

        scene_manager_->render();
        scene_manager_->update(getGlobalDeltaTime());

        //End Rendering Phase

        render_manager_->getRenderer()->disableShaders();
        render_manager_->getRenderer()->endFrame();

        onUpdate(getGlobalDeltaTime());
        onUpdate();
        
		//This method is responsible for swapping back and front buffers
        update();
    }

    output_manager_->getLog()->write(L"Engine is exiting...");

    shutdown();
}

//--------------------------------------------------------------------------------------------------
LRESULT Framework::messageProcessor(UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch(msg)
    {

    case WM_CLOSE:
        onClose();
        ShowCursor(true);
        break;

    case WM_DESTROY:
        onDestroy();
        break;

    case WM_SIZE:
        {
            int window_width = LOWORD(lparam);
            int window_height = HIWORD(lparam);
            setWindowWidth(window_width);
            setWindowHeight(window_height);
            onSize(getWidth(), getHeight());
        }
        break;

    case WM_COMMAND:
        break;


    case WM_KEYDOWN:
        {
            if(GetAsyncKeyState(VK_ESCAPE))
                onClose();

            onKeydown();
            break;
        }


    case WM_KEYUP:
        {
            break;
        }


    case WM_LBUTTONDOWN:
        {
            int x = LOWORD(lparam);
            int y = HIWORD(lparam);
            onLeftButtonDown();
        }
        break;


    case WM_LBUTTONUP:
        {
            onLeftButtonUp();
        }
        break;


    case WM_RBUTTONDOWN:
        {
            onRightButtonDown();
        }
        break;


    case WM_RBUTTONUP:
        {
            onRightButtonUp();
        }
        break;


    case WM_MBUTTONDOWN:
        {
            onMiddleButtonDown();
        }
        break;


    case WM_MBUTTONUP:
        {
            onMiddleButtonUp();
        }
        break;


    case WM_MBUTTONDBLCLK:
        {
        }
        break;


    case WM_MOUSELEAVE:
        {
            MessageBox(NULL, L"Mouse outside the framework!", MG_HEADER.c_str(), ERR_ICON_OK);
        }
        break;


    case WM_MOUSEMOVE:
        {
            onMouseMove(LOWORD(lparam), HIWORD(lparam));
            //MessageBox(NULL, "move", HEADER, errIconOK);
        }
        break;


    case WM_MOUSEWHEEL:
        {
            onScroll();
        }
        break;

    case WM_CREATE:
        {
            //create();
        }
        break;
    }
    return DefWindowProc(hwnd_, msg, wparam, lparam);
}

//--------------------------------------------------------------------------------------------------
void Framework::loadCustomCursor(const std::wstring file_path)
{
    HCURSOR custom_cursor = (HCURSOR)LoadCursorFromFile(file_path.c_str());

    SetClassLong(hwnd_, GCL_HCURSOR, (LONG)custom_cursor);
}

//--------------------------------------------------------------------------------------------------
void Framework::addMenu(HINSTANCE hinstance, LPCWSTR menuName)
{
    HMENU hmenu = LoadMenu(hinstance, menuName); 
    SetMenu(getHWND(), hmenu);
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::init()
{
    output_manager_ = std::unique_ptr<OutputManager>(new OutputManager);
    audio_manager_ = std::unique_ptr<AudioManager>(new AudioManager);
    mathsystem_ = std::unique_ptr<math::MathSystem>(new math::MathSystem);
    xml_parser_ = std::unique_ptr<tools::XmlParser>(new tools::XmlParser);
    object_manager_ = std::unique_ptr<ObjectManager>(new ObjectManager);
    time_manager_ = std::unique_ptr<TimeManager>(new TimeManager);
    scene_manager_ = std::unique_ptr<SceneManager>(new SceneManager);
    event_manager_ = std::unique_ptr<EventManager>(new EventManager);
    physicsystem_ = std::unique_ptr<physics::PhysicSystem>(new physics::PhysicSystem);
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::destroy()
{
    //delete physicsystem_;
    //delete event_manager_;
    //delete scene_manager_;
    //delete time_manager_;
    //delete object_manager_;
    //delete xml_parser_;
    //delete render_manager_;
    //delete mathsystem_;
    //delete audio_manager_;
    //delete output_manager_;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::update()
{
    SwapBuffers(GetDC(hwnd_));
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::createWindowClass(HINSTANCE hinstance, const std::wstring classname)
{
    wnd_.cbSize = sizeof(wnd_);
    wnd_.cbClsExtra = 0;
    wnd_.cbWndExtra = 0;
    wnd_.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wnd_.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
    wnd_.hIcon = (HICON)LoadImage(NULL, ICON_ASSETS_PATH.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    wnd_.hIconSm = (HICON)LoadImage(NULL, ICON_SMALL_ASSETS_PATH.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    wnd_.hInstance = hinstance;
    wnd_.lpfnWndProc = WindowProcedure;
    wnd_.lpszClassName = classname.c_str();
    wnd_.lpszMenuName = NULL;
    wnd_.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC;
    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::registerClass()
{
    ::RegisterClassEx(&wnd_);
    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
HWND Framework::window(const std::wstring classname, const std::wstring windowname, HINSTANCE hinstance, int w, int h)
{
    width_ = w;
    height_ = h;

    style_ = WS_BORDER | WS_OVERLAPPEDWINDOW | WS_VISIBLE;

    if(fullscreen_)
    {
        exstyles_ = WS_EX_APPWINDOW;
        toggleFullScreen();
        //setStyle(WS_POPUP | WS_VISIBLE);
        style_ = WS_POPUP | WS_VISIBLE;
    }
    else
    {
        exstyles_ = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
        //tStyle(style_);
    }

    setRect();

    AdjustWindowRectEx(&rect_, style_, false, exstyles_);

    hwnd_ = CreateWindowEx(exstyles_,
                           classname.c_str(),
                           windowname.c_str(),
                           style_,
                           rect_.left,
                           rect_.top,
                           rect_.right - rect_.left, 
                           rect_.bottom - rect_.top,
                           NULL,
                           NULL,
                           hinstance, 
                           this
                           );
    if(!hwnd_) return NULL;                                  //Implement Exception Handling
    return hwnd_;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::toggleFullScreen()
{
    DEVMODE dm;
    ZeroMemory(&dm, sizeof(dm));

    if(!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        MessageBox(NULL, L"Couldn't Enum Display Settings", MG_HEADER.c_str(), ERR_ICON_OK);
        return;
    }

    dm.dmSize = sizeof(DEVMODE);
    dm.dmPelsWidth = getWidth();
    dm.dmPelsHeight = getHeight();
    dm.dmBitsPerPel = getDepth();
    dm.dmDisplayFrequency = getFrequency();
    dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL | DM_DISPLAYFREQUENCY;
    
    int result = ChangeDisplaySettings(&dm, CDS_FULLSCREEN);

    if(result != DISP_CHANGE_SUCCESSFUL)
    {
        MessageBox(NULL, L"Display Mode Not Compatible", MG_HEADER.c_str(), ERR_ICON_OK);
        onDestroy();
    }
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::show()
{
    ::ShowWindow(hwnd_, SW_SHOW);
    ::UpdateWindow(hwnd_);
    ::SetFocus(hwnd_);
    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::setupPixelFormat(HDC hdc)
{
    int pixelFormat;
    PIXELFORMATDESCRIPTOR pfd = {0}; 
    
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.dwLayerMask = PFD_MAIN_PLANE;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = static_cast<BYTE>(depth_);
        pfd.cDepthBits = static_cast<BYTE>(depth_);
        pfd.cAccumBits = 0;
        pfd.cStencilBits = 0;
    
    pixelFormat = ChoosePixelFormat(hdc, &pfd);

    if(!pixelFormat)
    {
        MessageBox(NULL, L"Choose PixelFormat FAIL!", MG_HEADER.c_str(), ERR_ICON_OK);
        return;
    }
    
    if(!SetPixelFormat(hdc, pixelFormat, &pfd))
    {
        MessageBox(NULL, L"Set PixelFormat FAIL!", MG_HEADER.c_str(), ERR_ICON_OK);
        return;
    }
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::startWiggle(HDC hhdc)
{
    hdc_ = hhdc;
    setupPixelFormat(hdc_);
    hrc_ = wglCreateContext(hdc_);
    wglMakeCurrent(hdc_, hrc_);

    //Attempting to create OpenGL 3.2 rendering context
    //wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
    //wglChoosePixelFormatARB

    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::stopWiggle()
{
    wglMakeCurrent(hdc_, NULL);
    wglDeleteContext(hrc_);
    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::setRect()
{
    if(fullscreen_)
    {
        rect_.left = 0;
        rect_.top = 0;
    }
    else
    {
        rect_.left = 30;
        rect_.top = 40;
    }
    rect_.bottom = getHeight();
    rect_.right = getWidth();

    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::setRect(int left, int top, int right, int bottom)
{
    rect_.left = left;
    rect_.top = top;
    rect_.right = right;
    rect_.bottom = bottom;
    return true;
}

// -- [ PRIVATE ] ---------------------------------------------------------------------------------- 
bool Framework::readConfFile(const std::wstring filePath)
{

    ui fullscreenTemp = 0;
    if(width_ == 0)
    {
        width_ = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_WINDOW_WIDTH_KEY.c_str(), CONF_DEF_WINDOW_WIDTH, filePath.c_str());
    }
    if(height_ == 0)
    {
        height_ = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_WINDOW_HEIGHT_KEY.c_str(), CONF_DEF_WINDOW_HEIGHT, filePath.c_str());
    }

    depth_ = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_SCREEN_DEPTH_KEY.c_str(), CONF_DEF_WINDOW_DEPTH, filePath.c_str());
    frequency_ = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_SCREEN_FREQUENCY_KEY.c_str(), CONF_DEF_WINDOW_FREQUENCY, filePath.c_str());
    fullscreenTemp = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_FULLSCREEN_KEY.c_str(), fullscreen_, filePath.c_str());

    if(fullscreenTemp == 1)
    {
        fullscreen_ = true;
    }
    else
    {
        fullscreen_ = false;
    }

    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::readXMLData()
{
    //XML - based configuration

    width_ = xml_parser_->getIntMap()["width"];
    height_ = xml_parser_->getIntMap()["height"];
    depth_ = xml_parser_->getIntMap()["depth"];
    frequency_ = xml_parser_->getIntMap()["frequency"];
    use_dx_ = xml_parser_->getIntMap()["use_dx"];
    use_gl_ = xml_parser_->getIntMap()["use_gl"];

    if(xml_parser_->getStringMap()["fullscreen"] == "true")
    {
        fullscreen_ = true;
    }
    else if(xml_parser_->getStringMap()["fullscreen"] == "false")
    {
        fullscreen_ = false; 
    }

    //viewports_ = xml_parser_->getIntMap()["count"];

    //if(renderer_ != NULL)
    //{
    //    float farview = 0.0f;
    //    farview = static_cast<float>(xml_parser_.map_int_["far"]);
    //    float nearview = 0.0f;
    //    nearview = static_cast<float>(xml_parser_.map_int_["near"]);
    //    float fov = 0.0f;
    //    fov = static_cast<float>(xml_parser_.map_int_["fov"]);

    //    //renderer_->setFarview(farview);
    //    //renderer_->setNearview(nearview);
    //    //renderer_->setFov(fov);
    //}
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::readDefaults()
{
    width_ = 1600;
    height_ = 1024;
    depth_ = 32;
    frequency_ = 60;
    fullscreen_ = false;
    use_dx_ = false;
    use_gl_ = true;
    //viewports_ = 4;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::createGLContext(HDC hdc)
{
    hdc_ = hdc;
    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 32;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int pixel_format = ChoosePixelFormat(hdc_, &pfd);

    if(pixel_format == 0)
        return false;
    BOOL result = SetPixelFormat(getDeviceContext(), pixel_format, &pfd);

    if(!result)
        return false;

    HGLRC temporary_context = wglCreateContext(getDeviceContext());
    wglMakeCurrent(getDeviceContext(), temporary_context);

    int attributes[] =
    {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 2,
        WGL_CONTEXT_FLAGS_ARB, 0,
        0
    };

    if(wglewIsSupported("WGL_ARB_create_context") == 1)
    {
        hrc_ = wglCreateContextAttribsARB(getDeviceContext(), 0, attributes);
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(temporary_context);
        wglMakeCurrent(getDeviceContext(), hrc_);
    }
    else
    {
        hrc_ = temporary_context;
    }

    int opengl_version[2] = {0};
    glGetIntegerv(GL_MAJOR_VERSION, &opengl_version[0]);
    glGetIntegerv(GL_MINOR_VERSION, &opengl_version[1]);

    if(!hrc_)
        return false;

    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
int Framework::shutdown()
{
    return msg_.wParam;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::setWindow(int w, int h, int d, int f)
{
    width_ = w;
    height_ = h;
    depth_ = d;
    frequency_ = f;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::onCreate(HDC hdc)
{
    createGLContext(hdc);
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::onDestroy()
{
    PostQuitMessage(0);
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::onClose()
{
    stopWiggle();

    if(fullscreen_)
    {
        ChangeDisplaySettings(NULL, 0);
    }

    hrc_ = NULL;
    hdc_ = NULL;
    hwnd_ = NULL;
    hinstance_ = NULL;

    onDestroy();
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
void Framework::onSize(int width, int height)
{
    setWindowWidth(width);
    setWindowHeight(height);

    render_manager_->getRenderer()->onSize(getWidth(), getHeight());
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::setFullscreen()
{
    fullscreen_ = true;
    
    SetWindowLongPtr(getHWND(), GWL_STYLE, WS_SYSMENU | WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE);
    SetWindowPos(getHWND(), 0, 0, 0, rect_.right - rect_.left, rect_.bottom - rect_.top, SWP_SHOWWINDOW);

    if(fullscreen_)
    {
        toggleFullScreen();
    }

    return true;
}

// -- [ PRIVATE ] ----------------------------------------------------------------------------------
bool Framework::changeResolution(int w, int h)
{
    if(hinstance_ != NULL)
        hinstance_ = NULL;
    
    setWindow(getWidth(), getHeight(), getDepth(), getFrequency());
    
    show();

    onCreate(GetDC(getHWND()));
    render_manager_->getRenderer()->onSize(getWidth(), getHeight());
    return true;
}

/* These methods should be overriden in derivied class */
void Framework::onMouseMove(int, int){};
void Framework::onLeftButtonDown(){};
void Framework::onLeftButtonUp(){};
void Framework::onLeftButtonDoubleClick(){};
void Framework::onRightButtonDown(){};
void Framework::onRightButtonUp(){};
void Framework::onRightButtonDoubleClick(){};
void Framework::onMiddleButtonDown(){};
void Framework::onMiddleButtonUp(){};
void Framework::onScroll(){};
void Framework::onKeydown(){};
void Framework::onKeyup(){};
}    // end of core namespace
}    // end of mg namespace