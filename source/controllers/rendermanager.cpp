/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\rendermanager.h"

namespace mg
{
namespace core
{

RenderManager::RenderManager(RendererType renderer)
{
    switch(renderer)
    {
    case MG_DX:
        {
            renderer_ = new renderer::DxRenderer;
        }
        break;

    case MG_GL:
        {
             renderer_ = new renderer::GLRenderer;
        }
        break;
    }
}

//--------------------------------------------------------------------------------------------------
RenderManager::~RenderManager()
{
    if(renderer_ != NULL)
    {
        delete renderer_;
        renderer_ = NULL;
    }
}
}    // end of core namespace
}    // end of mg namespace