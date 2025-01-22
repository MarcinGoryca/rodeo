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
#ifndef RODEO_RENDERER_DXRENDERER_H_
#define RODEO_RENDERER_DXRENDERER_H_

#ifndef RODEO_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef RODEO_CORE_EXCEPTION_H_
#include "core\exception.h"
#endif

#ifndef RODEO_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef RODEO_RENDERER_IRENDERER_H_
#include "renderer\irenderer.h"
#endif
#endif
// ! DEPRECATED !
//#include <D3DX10.h>
// ! DEPRECATED !

//#include <microsoft\ddraw.h>
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		class DxRenderer : public IRenderer, core::Singleton<DxRenderer>
//		{
//		public:
//			    DxRenderer()
//			    :dx_device_(0),
//			     dx_swap_chain_(0),
//			     depth_stencil_buffer_(0),
//			     target_view_(0),
//			     depth_stencil_view_(0),
//			     dx_driver_type_(D3D10_DRIVER_TYPE_HARDWARE)
//			    {}
//			
//			    virtual ~DxRenderer(){}
//			
//			    virtual bool run(int w, int h);
//			    virtual void render();
//			    virtual void update();
//			    virtual void enterFrame();
//			    virtual void endFrame();
//			    virtual void onSize(int w, int h);
//			    virtual void enter2d();
//			    virtual void enter3d();
//			    //virtual bool chooseViewportType(GLViewportType vt);
//			
//			    // Enables Lighting on the scene
//			    virtual bool enableLighting();
//			    virtual bool disableLighting();
//			    virtual bool enableDepthTest();
//			    virtual bool disableDepthTest();
//			
//			    // Changes Backgound color of the renderer 
//			    virtual void backColor(float r, float g, float b, float a);
//			
//			    virtual void enableShaders();
//			    virtual void disableShaders();
//			    //ShadersInterface* getShader()const { return shader_; }
//			
//			    virtual void setShader(IShaders* si);
//			
//			    virtual void enableTexturing();
//			    virtual void disableTexturing();
//			
//			    virtual void enableBlending();
//			    virtual void disableBlending();
//			
//			private:
//			    void init(HWND app, int w, int h);
//				void fillViewport(D3D10_VIEWPORT v, int width, int height, float max_depth, float min_depth,
//				                  int top_left_x, int top_left_y);
//			
//			    ID3D10Device* dx_device_;
//			    IDXGISwapChain* dx_swap_chain_;
//			    ID3D10Texture2D* depth_stencil_buffer_;
//			    ID3D10RenderTargetView* target_view_;
//			    ID3D10DepthStencilView* depth_stencil_view_;
//			    ID3DX10Font* dx_font_;
//			    D3D10_DRIVER_TYPE dx_driver_type_;
//			    D3DXCOLOR clear_color_;
//			public:
//			    ID3D10Effect* effect_;
//			    ID3D10EffectTechnique* technique_;
//			    ID3D10InputLayout* input_layout_;
//			    ID3D10Buffer* vertex_buffer_;
//			    /*	
//			     * Checks if GL state is enabled,
//			     * it can take any GL state as a parameter  
//			     */
//			    //virtual bool checkEnabled(GLenum state);
//			
//			    //virtual void enableCulling();
//			    //virtual void disableCulling();
//			    //virtual void cullMode(GLenum mode);
//		};
//	}
//}
//#endif