/*
 |  -----------------------------------
 |    LAURA GAME ENGINE
 |    [ Window.h ] [ laura\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CORE_WINDOW_H_
#define LAURA_CORE_WINDOW_H_

#ifndef LAURA_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef LAURA_RENDERER_GL_GLCOMMON_H_
#include "..\renderer\gl\glcommon.h"
#endif

namespace laura
{
    namespace core
    {
        class Window
        {
        public:
            Window()
                :hwnd_(0),
                hrc_(0),
                hdc_(0),
                hinstance_(NULL),
                width_(0),
                height_(0),
                depth_(0),
                freq_(0),
                style_(-1),
                exstyles_(-1),
                fullscreen_(false),
                window_classname_(L"engine"),
                windowname_(L"Laura Game Engine")
            {
            }

            ~Window() {}

            // Initializes the Window object
            void init();

            // Loads custom cursor from specified location
            void loadCustomCursor(const std::wstring file_path);

            // This method will add menu to the window
            // Call this method ONLY if you want some editor
            // in pure Win32
            void addMenu(HINSTANCE hinstance, LPCWSTR menuName);

            // This method will process every message
            // This is equivalent to Win32 Callback function LRESULT WindowProcess;
            virtual LRESULT messageProcessor(UINT msg, WPARAM wparam, LPARAM lparam);

            // This method checks and translates all messages
            //void translateMessages();
            void loop();

            // Creates OpenGL Context for Windows
            bool createGLContext(HDC hdc);

            virtual void onMouseMove(int, int);
            virtual void onLeftButtonDown();
            virtual void onLeftButtonUp();
            virtual void onLeftButtonDoubleClick();
            virtual void onRightButtonDown();
            virtual void onRightButtonUp();
            virtual void onRightButtonDoubleClick();
            virtual void onMiddleButtonDown();
            virtual void onMiddleButtonUp();
            virtual void onScroll();
            virtual void onKeydown();
            virtual void onKeyup();
            virtual void onRender();
            virtual void onInit();
            virtual void onUpdate();
            void onCreate(HDC hdc);
            void onDestroy();
            void onClose();
            void onSize(int width, int height);
            virtual void onUpdate(float dt);
            void update();

            const int getHeight()const
            {
                return height_;
            }

            const int getWidth()const
            {
                return width_;
            }
            int getDepth()const { return depth_; }

            int getFrequency()const { return freq_; }

            HWND getWindowHandle()const { return hwnd_; }

            const HINSTANCE getHinstance()const { return hinstance_; }

            const HGLRC getHRC()const { return hrc_; }

            const HDC getDeviceContext()const { return hdc_; }

            std::wstring getWindowClassName() const { return window_classname_; }

            std::wstring getWindowName() const { return windowname_; }

            MSG getMessage() const
            {
                return msg_;
            }

            RECT getRect() const
            {
                return rect_;
            }

            void setWindowWidth(int width) { width_ = width; }

            void setWindowHeight(int height) { height_ = height; }

            void setDepth(int depth) { depth_ = depth; }

            void setFrequency(int freq) { freq_ = freq; }

            bool getFullscreen() const
            {
                return fullscreen_;
            }

            void setFullscreen(bool fullscreen)
            {
                fullscreen_ = fullscreen;
            }

            WNDCLASSEX getWindowClass()
            {
                return wnd_;
            }
            // Fills out Window Class (WNDCLASSEX)
            // Parameter HINSTANCE - GetModuleHandle(NULL)
            // Parameter const char* - getWindowClassName()
            bool createWindowClass(HINSTANCE hinstance, std::wstring classname);

            // This method calls CreateWindowEx(), applies styles, 
            //    and checks if window is in fullscreen mode
            HWND window(const std::wstring classname, const std::wstring windowname, HINSTANCE hinstance, int w, int h);

            // This method calls Win32 RegisterClassEx()
            bool registerClass();

            // This method calls Win32 ShowWindow(), UpdateWindow(), SetFocus();
            bool show();

            void toggleFullScreen();

            void setupPixelFormat(HDC hdc);

            bool startWiggle(HDC hdc);

            bool stopWiggle();

            bool setRect();

            bool setRect(int left, int top, int right, int bottom);
            int shutdown();

            void setWindow(int width, int height, int depth, int frequency);

            bool checkFullscreen();

            bool changeResolution(int w, int h);

            void setHRC(HGLRC hrc) { hrc_ = hrc; }


            void setClassName(const std::wstring cn) { window_classname_ = cn; }

            void setWindowName(const std::wstring wn) { windowname_ = wn; }

            WNDCLASSEX wnd_;
            HWND hwnd_;
            HGLRC hrc_;
            HDC hdc_;
            HINSTANCE hinstance_;
            MSG msg_;
            RECT rect_;

            int width_;
            int height_;
            int depth_;
            int freq_;

            // WS_BORDER | WS_OVERLAPPEDWINDOW | WS_VISIBLE
            int style_;

            // WS_EX_APPWINDOW | WS_EX_WINDOWEDGE
            int exstyles_;

            bool fullscreen_;

            std::wstring window_classname_;
            std::wstring windowname_;
        };
    }    // end of core namespace
}    // end of laura namespace
#endif