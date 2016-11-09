///*
// | ----------------------------------------------
// |    Laura Game Engine
// |    Copyright(c) Marcin Goryca
// |    marcin.goryca@gmail.com
// |    http://marcingoryca.pl
// | ----------------------------------------------
// */
//#ifndef LAURA_RENDERER_IRENDERER_H_
//#define LAURA_RENDERER_IRENDERER_H_
//
//#ifndef LAURA_RENDERER_GL_GLSLSHADERS_H_
//#include "renderer\gl\glslshaders.h"
//#endif
//
//namespace laura
//{
//	namespace renderer
//	{
//		class IRenderer
//		{
//		public:
//			IRenderer() {}
//			virtual ~IRenderer() {}
//
//			//virtual bool run(int w, int h) = 0;
//			//virtual void render() = 0;
//			//virtual void update() = 0;
//
//			// Enters the rendering frame
//			//virtual void enterFrame() = 0;
//
//			// Ends of the rendering frame
//			//virtual void endFrame() = 0;
//
//			// Event when the window is resized
//			//virtual void onSize(int w, int h) = 0;
//
//			// Orthographic projection
//			//virtual void enter2d() = 0;
//
//			// Perspective projection
//			//virtual void enter3d() = 0;
//			//virtual bool chooseViewportType(GLViewportType vt) = 0;
//
//			// Enables Lighting on the scene
//			/*virtual bool enableLighting() = 0;
//			virtual bool disableLighting() = 0;
//			virtual bool enableDepthTest() = 0;
//			virtual bool disableDepthTest() = 0;*/
//
//			// Changes Backgound color of the renderer 
//			/*virtual void backColor(float r, float g, float b, float a) = 0;*/
//
//			//virtual void enableShaders() = 0;
//			//virtual void disableShaders() = 0;
//			//IShaders* getShader()const { return _shader; }
//
//			//virtual void setShader(IShaders* si) = 0;
//
//			/*virtual void enableTexturing() = 0;
//			virtual void disableTexturing() = 0;
//
//			virtual void enableBlending() = 0;
//			virtual void disableBlending() = 0;*/
//
//			HWND getHWND() const { return _hwnd; }
//
//			void setHWND(HWND hwnd) { _hwnd = hwnd; }
//
//			// Checks if GL state is enabled,
//			// it can take any GL state as a parameter  
//			//virtual bool checkEnabled(GLenum state) = 0;
//
//			//virtual void enableCulling() = 0;
//			//virtual void disableCulling() = 0;
//			//virtual void cullMode(GLenum mode) = 0;
//		protected:
//			IShaders* _shader;
//			int _width;
//			int _height;
//			HWND _hwnd;
//		private:
//
//		};
//	}
//}
//#endif