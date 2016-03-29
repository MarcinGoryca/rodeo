//#include "renderer\dx\dxrenderer.h"
//
//using namespace mg::core;
//
//namespace mg
//{
//namespace renderer
//{
//bool DxRenderer::run(int w, int h)
//{
//    init(hwnd_, w, h);
//    return true;
//}
//
//// ---- //
//void DxRenderer::render()
//{
//    const float clear_color[4] = { 0.15f, 0.15f, 0.15f, 1.0f };
//    dx_device_->ClearRenderTargetView(target_view_, clear_color);
//    dx_swap_chain_->Present(0, 0);
//}
//
//// ---- //
//void DxRenderer::update()
//{
//}
//
//// ---- //
//void DxRenderer::enterFrame()
//{
//}
//
//// ---- //
//void DxRenderer::endFrame()
//{
//}
//
//// ---- //
//void DxRenderer::onSize(int w, int h)
//{
//    if(FAILED(dx_swap_chain_->ResizeBuffers(1, w, h, DXGI_FORMAT_R8G8B8A8_UNORM, 0)))
//    {
//        //return FALSE;
//    }
//    ID3D10Texture2D* back_buffer;
//
//    if(FAILED(dx_swap_chain_->GetBuffer(0, __uuidof(ID3D10Texture2D), reinterpret_cast<void**>(&back_buffer))))
//    {
//        //return FALSE;
//    }
//
//    if(FAILED(dx_device_->CreateRenderTargetView(back_buffer, 0, &target_view_)))
//    {
//        //return FALSE;
//    }
//
//    back_buffer->Release();
//
//    D3D10_TEXTURE2D_DESC depth_stencil;
//    depth_stencil.Width = w;
//    depth_stencil.Height = h;
//    depth_stencil.MipLevels = 1;
//    depth_stencil.ArraySize = 1;
//    depth_stencil.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
//    depth_stencil.SampleDesc.Count= 1;
//    depth_stencil.SampleDesc.Quality = 0;
//    depth_stencil.Usage = D3D10_USAGE_DEFAULT;
//    depth_stencil.BindFlags = D3D10_BIND_DEPTH_STENCIL;
//    depth_stencil.CPUAccessFlags = 0;
//    depth_stencil.MiscFlags = 0;
//
//    if(FAILED(dx_device_->CreateTexture2D(&depth_stencil, 0, &depth_stencil_buffer_)))
//    {
//        // return FALSE;
//    }
//
//    if(FAILED(dx_device_->CreateDepthStencilView(depth_stencil_buffer_, 0, &depth_stencil_view_)))
//    {
//        //return FALSE;
//    }
//
//    dx_device_->OMSetRenderTargets(1, &target_view_, depth_stencil_view_);
//
//    D3D10_VIEWPORT viewport;
//	fillViewport(viewport, h, w, 1.0f, 0.0f, 0, 0);
//    /*
//	viewport.Height = h;
//    viewport.Width = w;
//    viewport.MaxDepth = 1.0f;
//    viewport.MinDepth = 0.0f;
//    viewport.TopLeftX = 0;
//    viewport.TopLeftY = 0;
//	*/
//
//    dx_device_->RSSetViewports(1, &viewport);
//
//    effect_ = NULL;
//    technique_ = NULL;
//    input_layout_ = NULL;
//    vertex_buffer_ = NULL;
//
//    struct DxVertex
//    {
//        D3DXVECTOR3 position_;
//    };
//
//    //Define the input layout
//    D3D10_INPUT_ELEMENT_DESC layout[] =
//    {
//       {"Position", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0}
//    };
//
//    UINT num_of_elements = sizeof(layout) / sizeof(layout[0]);
//
//    //Create the input layout
//    D3D10_PASS_DESC pass_desc;
//
//    //technique_ = effect_->GetTechniqueByName("Render");
//
//    //technique_->GetPassByIndex(0)->GetDesc(&pass_desc);
//
//    //if(FAILED(dx_device_->CreateInputLayout(layout, num_of_elements, pass_desc.pIAInputSignature, 
//    //    pass_desc.IAInputSignatureSize, &input_layout_)))
//    //{
//    //    //return FALSE
//    //}
//    ////Set the input layout
//    //dx_device_->IASetInputLayout(input_layout_);
//}
//
//// ---- //
//void DxRenderer::enter2d()
//{
//}
//
//// ---- //
//void DxRenderer::enter3d()
//{
//}
//
//// ---- //
//bool DxRenderer::enableLighting()
//{
//    return true;
//}
//
//// ---- //
//bool DxRenderer::disableLighting()
//{
//    return true;
//}
//
//// ---- //
//bool DxRenderer::enableDepthTest()
//{
//    return true;
//}
//
//// ---- //
//bool DxRenderer::disableDepthTest()
//{
//    return true;
//}
//
//// ---- //
//void DxRenderer::backColor(float r, float g, float b, float a)
//{
//}
//
//// ---- //
//void DxRenderer::enableShaders()
//{
//}
//
//// ---- //
//void DxRenderer::disableShaders()
//{
//}
//
//// ---- //
//void DxRenderer::setShader(IShaders* shader)
//{
//}
//
//// ---- //
//void DxRenderer::enableTexturing()
//{
//}
//
//// ---- //
//void DxRenderer::disableTexturing()
//{
//
//}
//
//// ---- //
//void DxRenderer::enableBlending()
//{
//}
//
//// ---- //
//void DxRenderer::disableBlending()
//{
//}
//
//// [private] //
//void DxRenderer::init(HWND app, int w, int h)
//{
//    DXGI_SWAP_CHAIN_DESC swap_desc;
//    swap_desc.BufferDesc.Height = h;
//    swap_desc.BufferDesc.Width = w;
//    swap_desc.BufferDesc.RefreshRate.Numerator = 60;
//    swap_desc.BufferDesc.RefreshRate.Denominator = 1;
//    swap_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//    swap_desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
//    swap_desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
//    swap_desc.SampleDesc.Count = 1;
//    swap_desc.SampleDesc.Quality = 0;
//    swap_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//    swap_desc.BufferCount = 1;
//    swap_desc.OutputWindow = app;
//    swap_desc.Windowed = true;
//    swap_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
//    swap_desc.Flags = 0;
//
//    ui create_device_flags = 0;
//
//    //HRESULT hr = S_OK;
//
//    //if(FAILED(D3D10CreateDeviceAndSwapChain(
//    //    0,
//    //    dx_driver_type_,
//    //    0,
//    //    create_device_flags,
//    //    D3D10_SDK_VERSION,
//    //    &swap_desc,
//    //    &dx_swap_chain_,
//    //    &dx_device_)))
//    //{
//    //    //return FALSE;
//    //}
//
//    onSize(w, h);
//}
//// [private]
//void fillViewport(D3D10_VIEWPORT v, int width, int height, float max_depth, float min_depth,
//int top_left_x, int top_left_y)
//{
//	v.Height = height;
//	v.Width = width;
//	v.MaxDepth = max_depth;
//	v.MinDepth = min_depth;
//	v.TopLeftX = top_left_x;
//	v.TopLeftY = top_left_y;
//}
//}    // end of renderer namespace
//}    // end of mg namespace