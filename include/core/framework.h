/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_FRAMEWORK_H_
#define MG_CORE_FRAMEWORK_H_

#ifndef MG_CORE_OBJECTMANAGER_H_
#include "core\objectmanager.h"
#endif

#ifndef MG_CORE_AUDIOMANAGER_H_
#include "core\audiomanager.h"
#endif

#ifndef MG_CORE_SCENEMANAGER_H_
#include "core\scenemanager.h"
#endif

#ifndef MG_CORE_TIMEMANAGER_H_
#include "core\timemanager.h"
#endif

#ifndef MG_CORE_RENDERMANAGER_H_
#include "core\rendermanager.h"
#endif

//#ifndef CORE_FONTMANAGER_H_
//#include "core\fontmanager.h"
//#endif

#ifndef MG_CORE_EVENTMANAGER_H_
#include "core\eventmanager.h"
#endif

//#ifndef CORE_TEXTUREMANAGER_H_
//#include "core\texturemanager.h"
//#endif

#ifndef MG_CORE_OUTPUTMANAGER_H_
#include "core\outputmanager.h"
#endif

//#ifndef IO_MOUSE_H_
//#include "io\mouse.h"
//#endif

#ifndef MG_MATH_MATHSYSTEM_H_
#include "math\mathsystem.h"
#endif    //MATH_MATHSYSTEM_H_

//#ifndef SCENE_CAMERA_H_
//#include "scene\camera.h"
//#endif

//#ifndef SCENE_VIEWPORT_H_
//#include "scene\viewport.h"
//#endif

//#ifndef RENDERER_GLRENDERER_H_
//#include "renderer\glrenderer.h"
//#endif

#ifndef MG_TOOLS_XMLPARSER_H_
#include "tools\xmlparser.h"
#endif

#ifndef MG_PHYSICS_PHYSICSYSTEM_H_
#include "physics\physicsystem.h"
#endif

namespace mg
{
namespace core
{
class Framework : public Singleton<Framework>
{
public:
    Framework()
        :output_manager_(nullptr),
         audio_manager_(nullptr),
         mathsystem_(nullptr),
         render_manager_(nullptr),
         xml_parser_(nullptr),
         object_manager_(nullptr),
         time_manager_(nullptr),
         scene_manager_(nullptr),
         event_manager_(nullptr),
         physicsystem_(nullptr),
         width_(0),
         height_(0),
         depth_(0),
         frequency_(0),
         fullscreen_(false),
         style_(0),
         exstyles_(0),
         hwnd_(0),
         hrc_(0),
         hdc_(0),
         hinstance_(0),
         window_classname_(L"ENGINE"),
         windowname_(L"ENGINE Game Engine"),
         use_dx_(false),
         use_gl_(false)
    {
        init();
    }

    Framework(const std::wstring window_name)
        :output_manager_(nullptr),
         audio_manager_(nullptr),
         mathsystem_(nullptr),
         render_manager_(nullptr),
         xml_parser_(nullptr),
         object_manager_(nullptr),
         time_manager_(nullptr),
         scene_manager_(nullptr),
         event_manager_(nullptr),
         physicsystem_(nullptr),
         width_(0),
         height_(0),
         depth_(0),
         frequency_(0),
         fullscreen_(false),
         style_(0),
         exstyles_(0),
         hwnd_(0),
         hrc_(0),
         hdc_(0),
         hinstance_(0),
         window_classname_(L"ENGINE"),
         windowname_(window_name),
         use_dx_(false),
         use_gl_(false)
    {
        init();
    }

    virtual ~Framework()
    {
        destroy();
    }

    // Creates Framework instance
    // This method creates Win32 window class and all stuff to create window
    // Also creates OpenGL Context, and runs Renderer
    // Reads Configuration Files, .ini or xml
    // This method must be called in project
    void create();

    // Runs Framework
    // This method has real-time loop
    // Calls onInit();
    // Calls onUpdate(), update() methods
    // Calls Renderer methods for shaders, and rendering
    // This method must be called after create() method
    void run();

    // Translates all mesages
    // It must be public for access in static WindowProcedure 
    LRESULT messageProcessor(UINT msg, WPARAM wparam, LPARAM lparam);

    // Message - When mouse cursor is moving
    // This method should be overriden in derivied class
    virtual void onMouseMove(int, int);

    // Message - When left mouse button is pressed
    // This method should be overriden in derivied class
    virtual void onLeftButtonDown();

    // Message - When left button is released
    // This method should be overriden in derivied class
    virtual void onLeftButtonUp();

    // Message - When left mouse button is clicked twice
    // This method should be overriden in derivied class
    virtual void onLeftButtonDoubleClick();

    // Message - When right mouse button is pressed
    // This method should be overriden in derivied class
    virtual void onRightButtonDown();

    // Message - When right mouse button is released
    // This method should be overriden in derivied class
    virtual void onRightButtonUp();

    // Message - When right mouse button is clicked twice
    // This method should be overriden in derivied class
    virtual void onRightButtonDoubleClick();

    // Message - When middle mouse button is pressed
    // This method should be overriden in derivied class
    virtual void onMiddleButtonDown();

    // Message - When middle mouse button is released
    // This method should be overriden in derivied class
    virtual void onMiddleButtonUp();

    // Message - When middle mouse button is scrolled
    virtual void onScroll();

    // Message - when keyboard key is pressed
    // This method should be overriden in derivied class
    virtual void onKeydown();

    // Message - when keyboard key is released
    // This method should be overriden in derivied class
    virtual void onKeyup();

    // [Pure Virtual]
    // This method is invoked when rendering takes place
    // This method must be implemented in derivied class 
    virtual void onRender() = 0;

    // [Pure Virtual]
    // This method is for initialization
    // This method must be implemented in derivied class
    virtual void onInit() = 0;

    // [Pure Virtual]
    // This method is invoked  in every frame in a loop
    // This method must be implemented in derivied class
    virtual void onUpdate() = 0;

    // [Pure Virtual]
    // float delta time - usually it will be Global Delta Time
    // This method is invoked in evewry frame in a loop
    // This method must be implemented in derivied class
    virtual void onUpdate(float dt) = 0;

    // [Optional]
    // const char* Path to cursor file
    //        e.g. "assets\\cursor.cur" 
    // This method will replace default cursor with specified one
    void loadCustomCursor(const std::wstring path);

    // [Optional]
    // This method will add menu to the main window
    // It should not be used, editor should be implemented in C# (.NET)
    void addMenu(HINSTANCE hinstance, LPCWSTR menuName);

    // Get Window Height
    const int getHeight() const
    {
        return height_;
    }

    // Get Window Width
    const int getWidth() const
    {
        return width_;
    }

    // Gets Global Delta Time
    // the same time for whole application in a frame
    float getGlobalDeltaTime() const
    {
        return global_delta_time_;
    }

    // Gets the DirectX Renderer if true 
    bool useDirectX() const { return use_dx_; }

    // Gets the OpenGL Renderer if true
    bool useOpenGL() const { return use_gl_; }

private:
    // Initializes all subsystems
    void init();

    // Cleaning up of subsystems
    void destroy();

    // Updates in the main loop
    void update();

    // Fills out Win32 Window Class
    bool createWindowClass(HINSTANCE hinstance, const std::wstring classname);

    // Calls RegisterClassEx
    bool registerClass();

    // const char* class name - it cannot contain spaces or awkward characters
    // const char* window name - this string will be displayed on the window bar (if windowed)
    // HINSTANCE instance of the window
    // int width of the window, e.g. 1024
    // int height of the window e.g. 768
    // Creates HWND structure
    // Window Handle HWND
    HWND window(const std::wstring classname, const std::wstring windowname, HINSTANCE hinstance, int w, int h);

    // this method will change screen display
    void toggleFullScreen();

    // This method calls ShowWindow(HWND), UpdateWindow(HWND), SetFocus(HWND);
    bool show();

    // This method sets up pixel format for opengl rendering
    void setupPixelFormat(HDC hdc);

    // Starts Windows opengl specific functionality
    bool startWiggle(HDC hdc);

    // Stops Windows opengl specific functionality
    bool stopWiggle();

    // Sets Window Rectangle
    bool setRect();

    // int left position of the window rectangle
    // int top position of the window rectangle
    // int right position of the window rectangle
    // int bottom position of the window rectangle
    bool setRect(int left, int top, int right, int bottom);

    // const char* Path to configuration file, (.ini file)
    // Read configuration file
    bool readConfFile(const std::wstring filePath);

    // Read Xml specifil file
    void readXMLData();

    // This method will apply default values if readConfFile() or readXmlData() failed
    void readDefaults();

    // Creates OpenGL Context for rendering
    bool createGLContext(HDC hdc);

    // WinAPI specific method, when Window is closed
    int shutdown();

    // int new width for the Window
    // int new height dor the Window
    // int new depth for the Window
    // int new frequency value for the Window
    // Allows set basic Window values
    void setWindow(int width, int height, int depth, int frequency);

    // Calls createGLContext();
    void onCreate(HDC hdc);

    // Calls WinAPI's PostQuitMessage(0);
    void onDestroy();

    // Clears HWND, HINSTANCE, HRC, HDC objects,
    //       Calls stopWiggle() and onDestrpy()
    void onClose();

    // Sets Window width and height, 
    //          Also it will change renderer width/height ratio
    void onSize(int width, int height);

    // Sets Fullscreen mode
    bool setFullscreen();

    // Changes resolution of the screen
    bool changeResolution(int w, int h);
 
    // Sets Rendering Context
    void setHRC(HGLRC hrc) { hrc_ = hrc; }
 
    // Sets Width of the Window
    void setWindowWidth(int width) { width_ = width; }

    // Sets Height of the Window
    void setWindowHeight(int height) { height_ = height; }

    // Sets Depth of the Window
    void setDepth(int depth) { depth_ = depth; }

    // Sets Frequency of the Window
    void setFrequency(int freq) { frequency_ = freq; }

    // Sets Class name of the Window
    void setClassName(std::wstring cn){ window_classname_ = cn; }

    // Sets Name of the Window
    void setWindowName(const std::wstring wn){ windowname_ = wn; }

    // Gets Handle to the Window
    const HWND getHWND()const { return hwnd_; }

    // Gets Handle to the Instance of the Window
    const HINSTANCE getHinstance()const { return hinstance_; }

    // Gets Handle to Rendering Context
    const HGLRC getHRC()const { return hrc_; }

    // Gets Handle to Device Context
    const HDC getDeviceContext()const { return hdc_; }

    // Gets Window Class name
    std::wstring getWindowClassName() const { return window_classname_; }

    // Gets Window name
    // Returns const char* - the name of the window
    std::wstring getWindowName() const { return windowname_; }

    // Gets Depth of the Window
    // Returns int value of the depth
    int getDepth()const { return depth_; }

    // Gets Frequency of the Window
    // Returnsint value of the frequency
    int getFrequency()const { return frequency_; }

    // Sets Global Delta Time
    void setGlobalDeltaTime(float delta)
    {
        global_delta_time_ = delta;
    }
public:
    std::unique_ptr<OutputManager> output_manager_;
    std::unique_ptr<AudioManager> audio_manager_;

    //io::Mouse mouse_;

    std::unique_ptr<mg::math::MathSystem> mathsystem_;

    std::unique_ptr<RenderManager> render_manager_;

    //renderer::RendererInterface* renderer_;

    //scene::Camera camera_;

    std::unique_ptr<mg::tools::XmlParser> xml_parser_;

    std::unique_ptr<ObjectManager> object_manager_;

    std::unique_ptr<TimeManager> time_manager_;

    std::unique_ptr<SceneManager> scene_manager_;

    //FontManager fontMgr_;

    std::unique_ptr<EventManager> event_manager_;

    //TextureManager textureMgr_;

    //scene::Viewport viewport_;

    std::unique_ptr<mg::physics::PhysicSystem> physicsystem_;

    // Global Delta Time,
    // value for entire engine, 
    // e.g. for updating individual subsystems
    float global_delta_time_; 
    
private:
    // Win32 Window structure
    WNDCLASSEX wnd_;

    // Width of the Window
    int width_;

    // Height of the Window
    int height_;

    // Depth of the Window
    int depth_;

    // Frequency of the Window
    int frequency_;

    // Fullscreen mode of the window
    bool fullscreen_;

    // Styles of the Window
    //    WS_BORDER | WS_OVERLAPPEDWINDOW | WS_VISIBLE
    int style_;

    // Extended styles of the Window
    //    WS_EX_APPWINDOW | WS_EX_WINDOWEDGE
    int exstyles_;

    // Window Handle
    HWND hwnd_;

    // Rendering Context Handle
    HGLRC hrc_;

    // Device Context Handle
    HDC hdc_;

    // Instance of the Window
    HINSTANCE hinstance_;

    // Classname for the Window
    //    it must not contain spaces
    std::wstring window_classname_;

    // Window Name
    //    It is displayed on the titlebar
    std::wstring windowname_;

    // Message structure
    MSG msg_;

    // Window Rectangle structure
    RECT rect_;

    // 
    bool use_dx_;

    //
    bool use_gl_;
};
}    // end of core namespace
}    // end of mg namespace
#endif