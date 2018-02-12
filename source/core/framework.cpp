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
#include "core\framework.h"
using namespace rodeo::controllers;

namespace rodeo
{
	namespace core
	{
		LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			static Framework* rodeo = 0;

			switch (msg)
			{
			case WM_CREATE:
			{
				CREATESTRUCT* cs = (CREATESTRUCT*)lparam;
				rodeo = (Framework*)cs->lpCreateParams;
				return 0;
			}
			}
			if (rodeo)
				return rodeo->messageProcessor(msg, wparam, lparam);
			else
				return DefWindowProc(hwnd, msg, wparam, lparam);
		}

		//--------------------------------------------------------------------------------------------------
		void Framework::create()
		{
			//output_manager_->getLog()->open(L"log.txt");
			//output_manager_->getLog()->write(output_manager_->getString());
			//output_manager_->getLog()->write(L"Framework created\nEngine is starting...");

			HDC hdc = GetDC(getHwnd());

			//if(_xml_parser->read(CONFIGURATION_XML.c_str()))
			//{
			//    readXMLData();
			//}
			if (!readConfFile(CONFIGURATION_INI.c_str()))
			{
				readDefaults();
			}

			createWindowClass(getHinstance(), getWindowClassName());

			RegisterClassEx(&_wnd);
			window(getWindowClassName(), getWindowName(), getHinstance(), getWidth(), getHeight());
			show();

			//output_manager_->getLog()->write(L"Win32 Application is created");

			/*if (_use_gl)
			{
				_render_controller = std::unique_ptr<RenderController>(new RenderController(RODEO_GL));
				createGLContext(GetDC(getHwnd()));
			}
			if (_use_dx)
			{
				_render_controller = std::unique_ptr<RenderController>(new RenderController(RODEO_DX));
				_render_controller->getRenderer()->setHWND(getHwnd());
			}*/

			//output_manager_->getLog()->write(L"Rendering Context is created");
			//_render_controller->getRenderer()->run(getWidth(), getHeight());
			//output_manager_->getLog()->write(L"Renderer is running...");

			//if (_physicsystem->_module_initialized)
			//{
			//	//output_manager_->getLog()->write(physicsystem_->getString());
			//}
		}

		//--------------------------------------------------------------------------------------------------
		void Framework::run()
		{
			while (true)
			{
				if (PeekMessage(&_msg, 0, 0, 0, PM_REMOVE))
				{
					if (_msg.message == WM_QUIT)
						break;
					TranslateMessage(&_msg);
					DispatchMessage(&_msg);
				}
				_time_controller->getTimer()->countFramesPerSecond();
				setGlobalDeltaTime(_time_controller->getTimer()->getDelta());

				//_event_controller->getUserInput();

				//Start Physics calculations
				//physicsystem_->update(getGlobalDeltaTime());
				//physicsystem_->update();

				//Begin Rendering Phase
				//_render_controller->getRenderer()->enterFrame();
				//_render_controller->getRenderer()->enableShaders();

				//Override this method in your application
				onRender();

				//_scene_controller->render();
				//_scene_controller->update(getGlobalDeltaTime());

				//End Rendering Phase
				//_render_controller->getRenderer()->disableShaders();
				//_render_controller->getRenderer()->endFrame();

				onUpdate(getGlobalDeltaTime());
				onUpdate();

				//This method is responsible for swapping back and front buffers
				update();
			}

			//_output_controller->getLog()->write(L"Engine is exiting...");

			shutdown();
		}

		//--------------------------------------------------------------------------------------------------
		LRESULT Framework::messageProcessor(UINT msg, WPARAM wparam, LPARAM lparam)
		{
			switch (msg)
			{
            // Message when application is closing
			case WM_CLOSE:
				onClose();
				ShowCursor(true);
				break;
            // Message when application is removed from memory    
			case WM_DESTROY:
				onDestroy();
				break;

            // Message when application changes its size
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
				if (GetAsyncKeyState(VK_ESCAPE))
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
				//MessageBox(NULL, L"Mouse outside the framework!", RODEO_HEADER.c_str(), ERR_ICON_OK);
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
			return DefWindowProc(_hwnd, msg, wparam, lparam);
		}

		//--------------------------------------------------------------------------------------------------
		void Framework::loadCustomCursor(const std::wstring file_path)
		{
			HCURSOR custom_cursor = (HCURSOR)LoadCursorFromFile(file_path.c_str());

			SetClassLong(_hwnd, GCL_HCURSOR, (LONG)custom_cursor);
		}

		//--------------------------------------------------------------------------------------------------
		void Framework::addMenu(HINSTANCE hinstance, LPCWSTR menuName)
		{
			HMENU hmenu = LoadMenu(hinstance, menuName);
			SetMenu(getHwnd(), hmenu);
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::init()
		{
			//output_manager_ = std::unique_ptr<OutputManager>(new OutputManager);
			//audio_manager_ = std::unique_ptr<AudioManager>(new AudioManager);
			//mathsystem_ = std::unique_ptr<math::MathSystem>(new math::MathSystem);
			//_xml_parser = std::unique_ptr<tools::XmlParser>(new tools::XmlParser);
			//object_manager_ = std::unique_ptr<ObjectManager>(new ObjectManager);
			_time_controller = std::unique_ptr<TimeController>(new TimeController);
			//scene_manager_ = std::unique_ptr<SceneManager>(new SceneManager);
			//event_manager_ = std::unique_ptr<EventManager>(new EventManager);
			//physicsystem_ = std::unique_ptr<physics::PhysicSystem>(new physics::PhysicSystem);
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::destroy()
		{
			//delete physicsystem_;
			//delete event_manager_;
			//delete scene_manager_;
			//delete time_manager_;
			//delete object_manager_;
			//delete _xml_parser;
			//delete render_manager_;
			//delete mathsystem_;
			//delete audio_manager_;
			//delete output_manager_;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::update()
		{
			SwapBuffers(GetDC(getHwnd()));
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::createWindowClass(HINSTANCE hinstance, const std::wstring classname)
		{
			_wnd.cbSize = sizeof(_wnd);
			_wnd.cbClsExtra = 0;
			_wnd.cbWndExtra = 0;
			_wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
			_wnd.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
			_wnd.hIcon = (HICON)LoadImage(NULL, ICON_ASSETS_PATH.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
			_wnd.hIconSm = (HICON)LoadImage(NULL, ICON_SMALL_ASSETS_PATH.c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
			_wnd.hInstance = hinstance;
			_wnd.lpfnWndProc = WindowProcedure;
			_wnd.lpszClassName = classname.c_str();
			_wnd.lpszMenuName = NULL;
			_wnd.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC;
			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::registerClass()
		{
			::RegisterClassEx(&_wnd);
			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		HWND Framework::window(const std::wstring classname, const std::wstring windowname, HINSTANCE hinstance, int w, int h)
		{
			_width = w;
			_height = h;

			_style = WS_BORDER | WS_OVERLAPPEDWINDOW | WS_VISIBLE;

			if (_fullscreen)
			{
				_exstyles = WS_EX_APPWINDOW;
				toggleFullScreen();
				//setStyle(WS_POPUP | WS_VISIBLE);
				_style = WS_POPUP | WS_VISIBLE;
			}
			else
			{
				_exstyles = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
				//tStyle(style_);
			}

			setRect();

			AdjustWindowRectEx(&_rect, _style, false, _exstyles);

			_hwnd = CreateWindowEx(_exstyles,
				classname.c_str(),
				windowname.c_str(),
				_style,
				_rect.left,
				_rect.top,
				_rect.right - _rect.left,
				_rect.bottom - _rect.top,
				NULL,
				NULL,
				hinstance,
				this
				);
			if (!_hwnd) return NULL;                                  //Implement Exception Handling
			return _hwnd;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::toggleFullScreen()
		{
			DEVMODE dm;
			ZeroMemory(&dm, sizeof(dm));

			if (!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
			{
				//MessageBox(NULL, L"Couldn't Enum Display Settings", RODEO_HEADER.c_str(), ERR_ICON_OK);
				return;
			}

			dm.dmSize = sizeof(DEVMODE);
			dm.dmPelsWidth = getWidth();
			dm.dmPelsHeight = getHeight();
			dm.dmBitsPerPel = getDepth();
			dm.dmDisplayFrequency = getFrequency();
			dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL | DM_DISPLAYFREQUENCY;

			int result = ChangeDisplaySettings(&dm, CDS_FULLSCREEN);

			if (result != DISP_CHANGE_SUCCESSFUL)
			{
				//MessageBox(NULL, L"Display Mode Not Compatible", RODEO_HEADER.c_str(), ERR_ICON_OK);
				onDestroy();
			}
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::show()
		{
			::ShowWindow(getHwnd(), SW_SHOW);
			::UpdateWindow(getHwnd());
			::SetFocus(getHwnd());
			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::setupPixelFormat(HDC hdc)
		{
			int pixelFormat;
			PIXELFORMATDESCRIPTOR pfd = { 0 };

			pfd.nSize = sizeof(pfd);
			pfd.nVersion = 1;
			pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pfd.dwLayerMask = PFD_MAIN_PLANE;
			pfd.iPixelType = PFD_TYPE_RGBA;
			pfd.cColorBits = static_cast<BYTE>(_depth);
			pfd.cDepthBits = static_cast<BYTE>(_depth);
			pfd.cAccumBits = 0;
			pfd.cStencilBits = 0;

			pixelFormat = ChoosePixelFormat(hdc, &pfd);

			if (!pixelFormat)
			{
				//MessageBox(NULL, L"Choose PixelFormat FAIL!", RODEO_HEADER.c_str(), ERR_ICON_OK);
				return;
			}

			if (!SetPixelFormat(hdc, pixelFormat, &pfd))
			{
				//MessageBox(NULL, L"Set PixelFormat FAIL!", RODEO_HEADER.c_str(), ERR_ICON_OK);
				return;
			}
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::startWiggle(HDC hhdc)
		{
			//_hdc = hhdc;
			setHdc(hhdc);
			setupPixelFormat(getHdc());
			setHrc(wglCreateContext(getHdc()));
			wglMakeCurrent(getHdc(), getHrc());

			//Attempting to create OpenGL 3.2 rendering context
			//wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
			//wglChoosePixelFormatARB

			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::stopWiggle()
		{
			wglMakeCurrent(getHdc(), NULL);
			wglDeleteContext(getHrc());
			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::setRect()
		{
			if (_fullscreen)
			{
				_rect.left = 0;
				_rect.top = 0;
			}
			else
			{
				_rect.left = 30;
				_rect.top = 40;
			}
			_rect.bottom = getHeight();
			_rect.right = getWidth();

			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::setRect(int left, int top, int right, int bottom)
		{
			_rect.left = left;
			_rect.top = top;
			_rect.right = right;
			_rect.bottom = bottom;
			return true;
		}

		// -- [ PRIVATE ] ---------------------------------------------------------------------------------- 
		bool Framework::readConfFile(const std::wstring filePath)
		{

			ui fullscreenTemp = 0;
			if (_width == 0)
			{
				_width = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_WINDOW_WIDTH_KEY.c_str(), CONF_DEF_WINDOW_WIDTH, filePath.c_str());
			}
			if (_height == 0)
			{
				_height = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_WINDOW_HEIGHT_KEY.c_str(), CONF_DEF_WINDOW_HEIGHT, filePath.c_str());
			}

			_depth = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_SCREEN_DEPTH_KEY.c_str(), CONF_DEF_WINDOW_DEPTH, filePath.c_str());
			_frequency = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_SCREEN_FREQUENCY_KEY.c_str(), CONF_DEF_WINDOW_FREQUENCY, filePath.c_str());
			fullscreenTemp = GetPrivateProfileInt(CONF_DEF_WINDOW_STRING.c_str(), CONF_DEF_FULLSCREEN_KEY.c_str(), _fullscreen, filePath.c_str());

			if (fullscreenTemp == 1)
			{
				_fullscreen = true;
			}
			else
			{
				_fullscreen = false;
			}

			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::readXMLData()
		{
			//XML - based configuration

			/*_width = _xml_parser->getIntMap()["width"];
			_height = _xml_parser->getIntMap()["height"];
			_depth = _xml_parser->getIntMap()["depth"];
			_frequency = _xml_parser->getIntMap()["frequency"];
			_use_dx = _xml_parser->getIntMap()["use_dx"];
			_use_gl = _xml_parser->getIntMap()["use_gl"];

			if (_xml_parser->getStringMap()["fullscreen"] == "true")
			{
				_fullscreen = true;
			}
			else if (_xml_parser->getStringMap()["fullscreen"] == "false")
			{
				_fullscreen = false;
			}*/

			//viewports_ = _xml_parser->getIntMap()["count"];

			//if(renderer_ != NULL)
			//{
			//    float farview = 0.0f;
			//    farview = static_cast<float>(_xml_parser.map_int_["far"]);
			//    float nearview = 0.0f;
			//    nearview = static_cast<float>(_xml_parser.map_int_["near"]);
			//    float fov = 0.0f;
			//    fov = static_cast<float>(_xml_parser.map_int_["fov"]);

			//    //renderer_->setFarview(farview);
			//    //renderer_->setNearview(nearview);
			//    //renderer_->setFov(fov);
			//}
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::readDefaults()
		{
			_width = 1600;
			_height = 1024;
			_depth = 32;
			_frequency = 60;
			_fullscreen = false;
			_use_dx = false;
			_use_gl = true;
			//viewports_ = 4;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::createGLContext(HDC hdc)
		{
			setHdc(hdc);
			PIXELFORMATDESCRIPTOR pfd;
			ZeroMemory(&pfd, sizeof(pfd));

			pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			pfd.nVersion = 1;
			pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pfd.iPixelType = PFD_TYPE_RGBA;
			pfd.cColorBits = 32;
			pfd.cDepthBits = 32;
			pfd.iLayerType = PFD_MAIN_PLANE;

			int pixel_format = ChoosePixelFormat(getHdc(), &pfd);

			if (pixel_format == 0)
				return false;
			BOOL result = SetPixelFormat(getHdc(), pixel_format, &pfd);

			if (!result)
				return false;

			HGLRC temporary_context = wglCreateContext(getHdc());
			wglMakeCurrent(getHdc(), temporary_context);

			//int attributes[] =
			//{
			//	/*WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
			//	WGL_CONTEXT_MINOR_VERSION_ARB, 2,
			//	WGL_CONTEXT_FLAGS_ARB, 0,
			//	0*/
			//};

			/*if (glewIsSupported("WGL_ARB_create_context") == 1)
			{
				setHrc(wglCreateContextAttribsARB(getHdc(), 0, attributes));
				wglMakeCurrent(NULL, NULL);
				wglDeleteContext(temporary_context);
				wglMakeCurrent(getHdc(), getHrc());
			}
			else
			{
				setHrc(temporary_context);
			}*/

			/*int opengl_version[2] = { 0 };
			glGetIntegerv(GL_MAJOR_VERSION, &opengl_version[0]);
			glGetIntegerv(GL_MINOR_VERSION, &opengl_version[1]);

			if (!getHdc())
				return false;
*/
			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		int Framework::shutdown()
		{
			return _msg.wParam;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::setWindow(int w, int h, int d, int f)
		{
			_width = w;
			_height = h;
			_depth = d;
			_frequency = f;
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

			if (_fullscreen)
			{
				ChangeDisplaySettings(NULL, 0);
			}

			setHrc(NULL);
			setHdc(NULL);
			setHwnd(NULL);
			setHinstance(NULL);

			onDestroy();
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		void Framework::onSize(int width, int height)
		{
			setWindowWidth(width);
			setWindowHeight(height);

			//_render_controller->getRenderer()->onSize(getWidth(), getHeight());
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::setFullscreen()
		{
			_fullscreen = true;

			SetWindowLongPtr(getHwnd(), GWL_STYLE, WS_SYSMENU | WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE);
			SetWindowPos(getHwnd(), 0, 0, 0, _rect.right - _rect.left, _rect.bottom - _rect.top, SWP_SHOWWINDOW);

			if (_fullscreen)
			{
				toggleFullScreen();
			}

			return true;
		}

		// -- [ PRIVATE ] ----------------------------------------------------------------------------------
		bool Framework::changeResolution(int w, int h)
		{
			if (_hinstance != NULL)
				_hinstance = NULL;

			setWindow(getWidth(), getHeight(), getDepth(), getFrequency());

			show();

			onCreate(GetDC(getHwnd()));
			//_render_controller->getRenderer()->onSize(getWidth(), getHeight());
			return true;
		}

		/* These methods should be overriden in derivied class */
		void Framework::onMouseMove(int, int) {};
		void Framework::onLeftButtonDown() {};
		void Framework::onLeftButtonUp() {};
		void Framework::onLeftButtonDoubleClick() {};
		void Framework::onRightButtonDown() {};
		void Framework::onRightButtonUp() {};
		void Framework::onRightButtonDoubleClick() {};
		void Framework::onMiddleButtonDown() {};
		void Framework::onMiddleButtonUp() {};
		void Framework::onScroll() {};
		void Framework::onKeydown() {};
		void Framework::onKeyup() {};
	}
}