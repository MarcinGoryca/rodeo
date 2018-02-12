/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
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
#ifndef RODEO_CORE_FRAMEWORK_H_
#define RODEO_CORE_FRAMEWORK_H_

#ifndef RODEO_CONTROLLERS_OBJECTCONTROLLER_H_
#include "controllers\objectcontroller.h"
#endif

#ifndef RODEO_CONTROLLERS_AUDIOCONTROLLER_H_
#include "controllers\audiocontroller.h"
#endif

#ifndef RODEO_CONTROLLERS_SCENECONTROLLER_H_
#include "controllers\scenecontroller.h"
#endif

#ifndef RODEO_CONTROLLERS_TIMECONTROLLER_H_
#include "controllers\timecontroller.h"
#endif

#ifndef RODEO_CONTROLLERS_RENDERCONTROLLER_H_
#include "controllers\rendercontroller.h"
#endif

 //#ifndef CORE_FONTMANAGER_H_
 //#include "core\fontmanager.h"
 //#endif

#ifndef RODEO_CONTROLLERS_EVENTCONTROLLER_H_
#include "controllers\eventcontroller.h"
#endif

//#ifndef CORE_TEXTUREMANAGER_H_
//#include "core\texturemanager.h"
//#endif

#ifndef RODEO_CONTROLLERS_OUTPUTCONTROLLER_H_
#include "controllers\outputcontroller.h"
#endif

//#ifndef IO_MOUSE_H_
//#include "io\mouse.h"
//#endif

#ifndef RODEO_MATH_MATHSYSTEM_H_
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

#ifndef RODEO_TOOLS_XMLPARSER_H_
#include "tools\xmlparser.h"
#endif

#ifndef RODEO_PHYSICS_PHYSICSYSTEM_H_
#include "physics\physicsystem.h"
#endif

namespace rodeo
{
	namespace core
	{
		class Framework : public Singleton<Framework>
		{
		public:
			Framework()
				://_output_controller(nullptr),
				//_audio_controller(nullptr),
				_mathsystem(nullptr),
				//_render_controller(nullptr),
				//_xml_parser(nullptr),
				//_object_controller(nullptr),
				_time_controller(nullptr),
				//_scene_controller(nullptr),
				//_event_controller(nullptr),
				//_physicsystem(nullptr),
				_width(0),
				_height(0),
				_depth(0),
				_frequency(0),
				_fullscreen(false),
				_style(0),
				_exstyles(0),
				_hwnd(0),
				_hrc(0),
				_hdc(0),
				_hinstance(0),
				_window_classname(L"ENGINE"),
				_windowname(L"ENGINE Game Engine"),
				_use_dx(false),
				_use_gl(false)
			{
				init();
			}

			Framework(const std::wstring window_name)
				://_output_controller(nullptr),
				//_audio_controller(nullptr),
				_mathsystem(nullptr),
				//_render_controller(nullptr),
				//_xml_parser(nullptr),
				//_object_controller(nullptr),
				_time_controller(nullptr),
				//_scene_controller(nullptr),
				//_event_controller(nullptr),
				//_physicsystem(nullptr),
				_width(0),
				_height(0),
				_depth(0),
				_frequency(0),
				_fullscreen(false),
				_style(0),
				_exstyles(0),
				_hwnd(0),
				_hrc(0),
				_hdc(0),
				_hinstance(0),
				_window_classname(L"ENGINE"),
				_windowname(window_name),
				_use_dx(false),
				_use_gl(false)
			{
				init();
			}

			virtual ~Framework()
			{
				destroy();
			}

			/*
			 |  -------------------------------------------------------------------------
			 |    Creates Framework instance
			 |    This method creates Win32 window class and all stuff to create window
			 |    Also creates OpenGL Context, and runs Renderer
			 |    Reads Configuration Files, .ini or xml
			 |    This method must be called in project
			 |  -------------------------------------------------------------------------
			 */
			void create();

			/*
			 |  -------------------------------------------------------------------------
			 |    Runs Framework
			 |    This method has real-time loop
			 |    Calls onInit();
			 |    Calls onUpdate(), update() methods
			 |    Calls Renderer methods for shaders, and rendering
			 |    This method must be called after create() method
			 |  -------------------------------------------------------------------------
			 */
			void run();

			/*
			 |  -------------------------------------------------------------------------
			 |    Translates all mesages
			 |    It must be public for access in static WindowProcedure
			 |  -------------------------------------------------------------------------
			 */
			LRESULT messageProcessor(UINT msg, WPARAM wparam, LPARAM lparam);

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When mouse cursor is moving
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onMouseMove(int, int);

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When left mouse button is pressed
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onLeftButtonDown();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When left button is released
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onLeftButtonUp();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When left mouse button is clicked twice
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onLeftButtonDoubleClick();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When right mouse button is pressed
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onRightButtonDown();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When right mouse button is released
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onRightButtonUp();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When right mouse button is clicked twice
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onRightButtonDoubleClick();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When middle mouse button is pressed
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onMiddleButtonDown();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When middle mouse button is released
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onMiddleButtonUp();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - When middle mouse button is scrolled
			 |  -------------------------------------------------------------------------
			 */
			virtual void onScroll();

			/*
			 |  -------------------------------------------------------------------------
			 |    Message - when keyboard key is pressed
			 |    This method should be overriden in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onKeydown();

			/*
			 |  ------------------------------------------------------------------------
			 |    Message - when keyboard key is released
			 |    This method should be overriden in derivied class
			 |  ------------------------------------------------------------------------
			 */
			virtual void onKeyup();

			/*
			 |  ------------------------------------------------------------------------
			 |    [Pure Virtual]
			 |    This method is invoked when rendering takes place
			 |    This method must be implemented in derivied class
			 |  ------------------------------------------------------------------------
			 */
			virtual void onRender() = 0;

			/*
			 |  ------------------------------------------------------------------------
			 |    [Pure Virtual]
			 |    This method is for initialization
			 |    This method must be implemented in derivied class
			 |  ------------------------------------------------------------------------
			 */
			virtual void onInit() = 0;

			/*
			 |  ------------------------------------------------------------------------
			 |    [Pure Virtual]
			 |    This method is invoked  in every frame in a loop
			 |    This method must be implemented in derivied class
			 |  ------------------------------------------------------------------------
			 */
			virtual void onUpdate() = 0;

			/*
			 |  -------------------------------------------------------------------------
			 |    [Pure Virtual]
			 |    float delta time - usually it will be Global Delta Time
			 |    This method is invoked in evewry frame in a loop
			 |    This method must be implemented in derivied class
			 |  -------------------------------------------------------------------------
			 */
			virtual void onUpdate(float dt) = 0;

			/*
			 |  -------------------------------------------------------------------------
			 |    [Optional]
			 |    const char* Path to cursor file
			 |        e.g. "assets\\cursor.cur"
			 |    This method will replace default cursor with specified one
			 |  -------------------------------------------------------------------------
			 */
			void loadCustomCursor(const std::wstring path);

			/*
			 |  -------------------------------------------------------------------------
			 |    [Optional]
			 |    This method will add menu to the main window
			 |    It should not be used, editor should be implemented in C# (.NET)
			 |  -------------------------------------------------------------------------
			 */
			void addMenu(HINSTANCE hinstance, LPCWSTR menuName);

			/*
			 |  --------------------------------------------------------------------------
			 |    Get Window Height
			 |  --------------------------------------------------------------------------
			 */
			const int getHeight() const
			{
				return _height;
			}

			/*
			 |  -------------------------------------------------------------------------
			 |    Get Window Width
			 |  -------------------------------------------------------------------------
			 */
			const int getWidth() const
			{
				return _width;
			}

			/*
			 |  -------------------------------------------------------------------------
			 |    Gets Global Delta Time
			 |    the same time for whole application in a frame
			 |  -------------------------------------------------------------------------
			 */
			float getGlobalDeltaTime() const
			{
				return _global_delta_time;
			}

			/*
			 |  --------------------------------------------------------------------------
			 |    Gets the DirectX Renderer if true
			 |  --------------------------------------------------------------------------
			 */
			bool useDirectX() const { return _use_dx; }

			/*
			 |  --------------------------------------------------------------------------
			 |    Gets the OpenGL Renderer if true
			 |  --------------------------------------------------------------------------
			 */
			bool useOpenGL() const { return _use_gl; }

		private:
			/*
			 |  ----------------------------------------------------------------
			 |    Initializes all subsystems
			 |  ----------------------------------------------------------------
			 */
			void init();

			/*
			 |  ----------------------------------------------------------------
			 |    Cleaning up of subsystems
			 |  ----------------------------------------------------------------
			 */
			void destroy();

			/*
			 |  -----------------------------------------------------------------
			 |    Updates in the main loop
			 |  -----------------------------------------------------------------
			 */
			void update();

			/*
			 |  -----------------------------------------------------------------
			 |    Fills out Win32 Window Class
			 |  -----------------------------------------------------------------
			 */
			bool createWindowClass(HINSTANCE hinstance, const std::wstring classname);

			/*
			 |  -----------------------------------------------------------------
			 |    Calls RegisterClassEx
			 |  -----------------------------------------------------------------
			 */
			bool registerClass();

			/*
			 |  ----------------------------------------------------------------------------------------
			 |    const char* class name - it cannot contain spaces or awkward characters
			 |    const char* window name - this string will be displayed on the window bar (if windowed)
			 |    HINSTANCE instance of the window
			 |    int width of the window, e.g. 1024
			 |    int height of the window e.g. 768
			 |    Creates HWND structure
			 |    Window Handle HWND
			 |  -----------------------------------------------------------------------------------------
			 */
			HWND window(const std::wstring classname, const std::wstring windowname, HINSTANCE hinstance, int w, int h);

			/*
			 |  -------------------------------------------------------------------------------------
			 |    this method will change screen display
			 |  -------------------------------------------------------------------------------------
			 */
			void toggleFullScreen();

			/*
			 |  ---------------------------------------------------------------------------------------
			 |    This method calls ShowWindow(HWND), UpdateWindow(HWND), SetFocus(HWND);
			 |  ---------------------------------------------------------------------------------------
			 */
			bool show();

			/*
			 |  -----------------------------------------------------------------------------
			 |    This method sets up pixel format for opengl rendering
			 |  -----------------------------------------------------------------------------
			 */
			void setupPixelFormat(HDC hdc);

			/*
			 |  -----------------------------------------------------------------------------
			 |    Starts Windows opengl specific functionality
			 |  -----------------------------------------------------------------------------
			 */
			bool startWiggle(HDC hdc);

			/*
			 |  -----------------------------------------------------------------------------
			 |    Stops Windows opengl specific functionality
			 |  -----------------------------------------------------------------------------
			 */
			bool stopWiggle();

			/*
			 |  ------------------------------------------------------------------------
			 |    Sets Window Rectangle
			 |  ------------------------------------------------------------------------
			 */
			bool setRect();

			/*
			 |  -----------------------------------------------------------------------
			 |    int left position of the window rectangle
			 |    int top position of the window rectangle
			 |    int right position of the window rectangle
			 |    int bottom position of the window rectangle
			 |  -----------------------------------------------------------------------
			 */
			bool setRect(int left, int top, int right, int bottom);

			/*
			 |  -----------------------------------------------------------------------
			 |    const char* Path to configuration file, (.ini file)
			 |    Read configuration file
			 |  -----------------------------------------------------------------------
			 */
			bool readConfFile(const std::wstring filePath);

			/*
			 |  -----------------------------------------------------------------------
			 |    Read Xml specific file
			 |  -----------------------------------------------------------------------
			 */
			void readXMLData();

			/*
			 |  ----------------------------------------------------------------------------------
			 |    This method will apply default values if readConfFile() or readXmlData() failed
			 |  ----------------------------------------------------------------------------------
			 */
			void readDefaults();

			/*
			 |  ---------------------------------------------------------------
			 |    Creates OpenGL Context for rendering
			 |  ---------------------------------------------------------------
			 */
			bool createGLContext(HDC hdc);

			/*
			 |  ----------------------------------------------------------------------
			 |    WinAPI specific method, when Window is closed
			 |  ----------------------------------------------------------------------
			 */
			int shutdown();

			/*
			 |  ----------------------------------------------------------------------
			 |    int new width for the Window
			 |    int new height dor the Window
			 |    int new depth for the Window
			 |    int new frequency value for the Window
			 |    Allows set basic Window values
			 |  ----------------------------------------------------------------------
			 */
			void setWindow(int width, int height, int depth, int frequency);

			/*
			 |  ----------------------------------------------------------------------
			 |    Calls createGLContext();
			 |  ----------------------------------------------------------------------
			 */
			void onCreate(HDC hdc);

			/*
			 |  ----------------------------------------------------------------------
			 |    Calls WinAPI's PostQuitMessage(0);
			 |  ----------------------------------------------------------------------
			 */
			void onDestroy();

			/*
			 |  -----------------------------------------------------------------------
			 |    Clears HWND, HINSTANCE, HRC, HDC objects,
			 |       Calls stopWiggle() and onDestrpy()
			 |  -----------------------------------------------------------------------
			 */
			void onClose();

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Window width and height,
			 |           Also it will change renderer width/height ratio
			 |  -----------------------------------------------------------------------
			 */
			void onSize(int width, int height);

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Fullscreen mode
			 |  -----------------------------------------------------------------------
			 */
			bool setFullscreen();

			/*
			 |  -----------------------------------------------------------------------
			 |    Changes resolution of the screen
			 |  -----------------------------------------------------------------------
			 */
			bool changeResolution(int w, int h);

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Rendering Context
			 |  -----------------------------------------------------------------------
			 */
			void setHrc(HGLRC hrc) { _hrc = hrc; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Width of the Window
			 |  -----------------------------------------------------------------------
			 */
			void setWindowWidth(int width) { _width = width; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Height of the Window
			 |  -----------------------------------------------------------------------
			 */
			void setWindowHeight(int height) { _height = height; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Depth of the Window
			 |  -----------------------------------------------------------------------
			 */
			void setDepth(int depth) { _depth = depth; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Frequency of the Window
			 |  -----------------------------------------------------------------------
			 */
			void setFrequency(int freq) { _frequency = freq; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Class name of the Window
			 |  -----------------------------------------------------------------------
			 */
			void setClassName(std::wstring cn) { _window_classname = cn; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Sets Name of the Window
			 |  -----------------------------------------------------------------------
			 */
			void setWindowName(const std::wstring wn) { _windowname = wn; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Gets Handle to the Window
			 |  -----------------------------------------------------------------------
			 */
			const HWND getHwnd()const { return _hwnd; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Gets Handle to the Instance of the Window
			 |  -----------------------------------------------------------------------
			 */
			const HINSTANCE getHinstance()const { return _hinstance; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Gets Handle to Rendering Context
			 |  -----------------------------------------------------------------------
			 */
			const HGLRC getHrc()const { return _hrc; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Gets Handle to Device Context
			 |  -----------------------------------------------------------------------
			 */
			const HDC getHdc()const { return _hdc; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Gets Window Class name
			 |  -----------------------------------------------------------------------
			 */
			std::wstring getWindowClassName() const { return _window_classname; }

			/*
			 |  -----------------------------------------------------------------------
			 |    Gets Window name
			 |    Returns const char* - the name of the window
			 |  -----------------------------------------------------------------------
			 */
			std::wstring getWindowName() const { return _windowname; }

			/*
			 |  ------------------------------------------------------------------------
			 |    Gets Depth of the Window
			 |    Returns int value of the depth
			 |  ------------------------------------------------------------------------
			 */
			int getDepth()const { return _depth; }

			/*
			 |  ------------------------------------------------------------------------
			 |    Gets Frequency of the Window
			 |    Returns int value of the frequency
			 |  ------------------------------------------------------------------------
			 */
			int getFrequency()const { return _frequency; }

			/*
			 |  ------------------------------------------------------------------------
			 |    Sets Global Delta Time
			 |  ------------------------------------------------------------------------
			 */
			void setGlobalDeltaTime(float delta)
			{
				_global_delta_time = delta;
			}

			/*
			 |  -----------------------------------------------------------------
			 |     Sets Device Context
			 |  -----------------------------------------------------------------
			 */
			void setHdc(HDC dc)
			{
				_hdc = dc;
			}

			/*
			 |  --------------------------------------------------------------
			 |    Sets Window Handle
			 |  --------------------------------------------------------------
			 */
			void setHwnd(HWND hwnd)
			{
				_hwnd = hwnd;
			}

			/*
			 |  --------------------------------------------------------------
			 |    Sets Instance of the Window
			 |  --------------------------------------------------------------
			 */
			void setHinstance(HINSTANCE hinstance)
			{
				_hinstance = hinstance;
			}

		public:
			//std::unique_ptr<rodeo::controllers::OutputController> _output_controller;
			//std::unique_ptr<rodeo::controllers::AudioController> _audio_controller;

			//io::Mouse mouse_;

			std::unique_ptr<rodeo::math::MathSystem> _mathsystem;

			//std::unique_ptr<rodeo::controllers::RenderController> _render_controller;

			//renderer::RendererInterface* renderer_;

			//scene::Camera camera_;

			//std::unique_ptr<rodeo::tools::XmlParser> _xml_parser;

			//std::unique_ptr<rodeo::controllers::ObjectController> _object_controller;

			std::unique_ptr<rodeo::controllers::TimeController> _time_controller;

			//std::unique_ptr<rodeo::controllers::SceneController> _scene_controller;

			//FontManager fontrodeor_;

			//std::unique_ptr<rodeo::controllers::EventController> _event_controller;

			//TextureManager texturerodeor_;

			//scene::Viewport viewport_;

			//std::unique_ptr<rodeo::physics::PhysicSystem> _physicsystem;

		private:
			// Global Delta Time,
			// value for entire engine, 
			// e.g. for updating individual subsystems
			float _global_delta_time;

			// Win32 Window structure
			WNDCLASSEX _wnd;

			// Width of the Window
			int _width;

			// Height of the Window
			int _height;

			// Depth of the Window
			int _depth;

			// Frequency of the Window
			int _frequency;

			// Fullscreen mode of the window
			bool _fullscreen;

			// Styles of the Window
			//    WS_BORDER | WS_OVERLAPPEDWINDOW | WS_VISIBLE
			int _style;

			// Extended styles of the Window
			//    WS_EX_APPWINDOW | WS_EX_WINDOWEDGE
			int _exstyles;

			// Window Handle
			HWND _hwnd;

			// Rendering Context Handle
			HGLRC _hrc;

			// Device Context Handle
			HDC _hdc;

			// Instance of the Window
			HINSTANCE _hinstance;

			// Classname for the Window
			//    it must not contain spaces
			std::wstring _window_classname;

			// Window Name
			//    It is displayed on the titlebar
			std::wstring _windowname;

			// Message structure
			MSG _msg;

			// Window Rectangle structure
			RECT _rect;

			// Power on DirectX
			bool _use_dx;

			// Power on OpenGL
			bool _use_gl;
		};
	}    // end of core namespace
}    // end of rodeo namespace
#endif    // RODEO_CORE_FRAMEWORK_H_
