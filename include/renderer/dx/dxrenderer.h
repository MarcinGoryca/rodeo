//----------------------------------------------
//    Laura Game Engine
//    Copyright(c) Marcin Goryca
//    marcin.goryca@gmail.com
//    http://marcingoryca.pl
//----------------------------------------------

#ifndef LAURA_RENDERER_DXRENDERER_H_
#define LAURA_RENDERER_DXRENDERER_H_

#ifndef LAURA_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef LAURA_CORE_EXCEPTION_H_
#include "core\exception.h"
#endif

#ifndef LAURA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef LAURA_RENDERER_IRENDERER_H_
#include "renderer\irenderer.h"
#endif

// ! DEPRECATED !
//#include <D3DX10.h>
// ! DEPRECATED !



namespace laura
{
	namespace renderer
	{
		class DxRenderer : public IRenderer, core::Singleton<DxRenderer>
		{
		public:
			//    DxRenderer()
			//    :dx_device_(0),
			//     dx_swap_chain_(0),
			//     depth_stencil_buffer_(0),
			//     target_view_(0),
			//     depth_stencil_view_(0),
			//     dx_driver_type_(D3D10_DRIVER_TYPE_HARDWARE)
			//    {}
			//
			//    virtual ~DxRenderer(){}
			//
			//    virtual bool run(int w, int h);
			//    virtual void render();
			//    virtual void update();
			//    virtual void enterFrame();
			//    virtual void endFrame();
			//    virtual void onSize(int w, int h);
			//    virtual void enter2d();
			//    virtual void enter3d();
			//    //virtual bool chooseViewportType(GLViewportType vt);
			//
			//    // Enables Lighting on the scene
			//    virtual bool enableLighting();
			//    virtual bool disableLighting();
			//    virtual bool enableDepthTest();
			//    virtual bool disableDepthTest();
			//
			//    // Changes Backgound color of the renderer 
			//    virtual void backColor(float r, float g, float b, float a);
			//
			//    virtual void enableShaders();
			//    virtual void disableShaders();
			//    //ShadersInterface* getShader()const { return shader_; }
			//
			//    virtual void setShader(IShaders* si);
			//
			//    virtual void enableTexturing();
			//    virtual void disableTexturing();
			//
			//    virtual void enableBlending();
			//    virtual void disableBlending();
			//
			//private:
			//    void init(HWND app, int w, int h);
			//	void fillViewport(D3D10_VIEWPORT v, int width, int height, float max_depth, float min_depth,
			//	                  int top_left_x, int top_left_y);
			//
			//    ID3D10Device* dx_device_;
			//    IDXGISwapChain* dx_swap_chain_;
			//    ID3D10Texture2D* depth_stencil_buffer_;
			//    ID3D10RenderTargetView* target_view_;
			//    ID3D10DepthStencilView* depth_stencil_view_;
			//    ID3DX10Font* dx_font_;
			//    D3D10_DRIVER_TYPE dx_driver_type_;
			//    D3DXCOLOR clear_color_;
			//public:
			//    ID3D10Effect* effect_;
			//    ID3D10EffectTechnique* technique_;
			//    ID3D10InputLayout* input_layout_;
			//    ID3D10Buffer* vertex_buffer_;
			//    /*	
			//     * Checks if GL state is enabled,
			//     * it can take any GL state as a parameter  
			//     */
			//    //virtual bool checkEnabled(GLenum state);
			//
			//    //virtual void enableCulling();
			//    //virtual void disableCulling();
			//    //virtual void cullMode(GLenum mode);
		};
	}
}
#endif