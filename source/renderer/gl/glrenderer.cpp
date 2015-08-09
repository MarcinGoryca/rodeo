/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "..\include\renderer\gl\glrenderer.h"

using namespace std;
using namespace mg::core;

namespace mg
{
namespace renderer
{
GLRenderer::GLRenderer()
{
    shader_ = NULL;
    width_ = 0;
    height_ = 0;
    query_renderer_ = new QueryRenderer;
}

//--------------------------------------------------------------------------------------------------
GLRenderer::~GLRenderer()
{
    height_ = 0;
    width_ = 0;

    if(shader_)
    {
        delete shader_;
        shader_ = NULL;
    }
    delete query_renderer_;
}

//--------------------------------------------------------------------------------------------------
bool GLRenderer::run(int w, int h)
{
    initGL(w, h, 0.0f, 0.0f, 0.0f, 1.0f);

    glewExperimental = GL_TRUE;
    glewInit();
    if(!GLEW_VERSION_3_0)
    {
        MessageBox(NULL, OPENGL_VERSION_NOT_SUPPORTED.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }
    query_renderer_->run();
    return true;
}

//--------------------------------------------------------------------------------------------------
void GLRenderer::render()
{
}

//--------------------------------------------------------------------------------------------------
void GLRenderer::update()
{
}

//--------------------------------------------------------------------------------------------------
void GLRenderer::enter2d()
{
    double ortho_left = floor(sqrt(static_cast<double>(getWidth())) / 2);
    double ortho_bottom = floor(sqrt(static_cast<double>(getHeight())) / 2);
}

void GLRenderer::enter3d()
{
    setWidth(getWidth());
    setHeight(getHeight());
    glViewport(0, 0, getWidth(), getHeight());
}

void GLRenderer::backColor(float r, float g, float b, float a)
{
    gl_red_ = r;
    gl_green_ = g;
    gl_blue_ = b;
    gl_alpha_ = a;
}

void GLRenderer::onSize(int w, int h)
{
    setGL(w, h);
}

bool GLRenderer::chooseViewportType(GLViewportType type)
{
    switch(type)
    {
    case MG_ORTHOGONAL:
        {
            enter2d();
        }
        break;
    case MG_PERSPECTIVE:
        {
            enter3d();
        }
        break;
    }
    return true;
}

void GLRenderer::enterFrame()
{
    glClearColor(gl_red_, gl_green_, gl_blue_, gl_alpha_);
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glViewport(0, 0, width_, height_);
}

void GLRenderer::endFrame()
{
    glFlush();
}

void GLRenderer::setGL(int w, int h)
{
    width_ = w;
    height_ = h;
    if(height_ == 0)
    {
        height_ = 1;
    }
    
    //chooseViewportType(RODEO_PERSPECTIVE);
}

bool GLRenderer::initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    return true;
}

bool GLRenderer::initGL(int w, int h, float r, float g, float b, float a)
{
    backColor(r, g, b, a);
    setGL(w, h);
    return true;
}

void GLRenderer::flush()
{
    glFlush();
}

bool GLRenderer::enableLighting()
{
    lightingOn();
    return true;
}

bool GLRenderer::disableLighting()
{
    lightingOff();
    return true;
}

bool GLRenderer::enableDepthTest()
{
    depthTestOn();
    return true;
}

bool GLRenderer::disableDepthTest()
{
    depthTestOff();
    return true;
}

void GLRenderer::enableShaders()
{
    //shader_->loadShaderFromFile("", enginecore::RODEO_VS);
    /**
    shader_->bindCG(shader_->getCGVertexShaderProgram());
    shader_->enableCG(shader_->getCGVertexShaderProfile());

    shader_->bindCG(shader_->getCGFragmentShaderProgram());
    shader_->enableCG(shader_->getCGFragmentShaderProfile());

    shader_->enableTextureParameter(shader_->parameter_);
    */
}

void GLRenderer::disableShaders()
{
    /**
    shader_->disableCG(shader_->getCGVertexShaderProfile());
    shader_->disableCG(shader_->getCGFragmentShaderProfile());
    shader_->disableTextureParameter(shader_->parameter_);
    */
}

void GLRenderer::enableTexturing()
{
    glEnable(GL_TEXTURE_2D);
}

void GLRenderer::disableTexturing()
{
    glDisable(GL_TEXTURE_2D);
}

void GLRenderer::enableBlending()
{
    glEnable(GL_BLEND);
}

void GLRenderer::disableBlending()
{
    glDisable(GL_BLEND);
}

bool GLRenderer::checkEnabled(GLenum state)
{
    if(glIsEnabled(state))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GLRenderer::enableCulling()
{
    glEnable(GL_CULL_FACE);
}

void GLRenderer::disableCulling()
{
    glDisable(GL_CULL_FACE);
}

void GLRenderer::cullMode(GLenum mode)
{
    switch(mode)
    {
    case GL_FRONT:
        cullFrontOn();
        break;

    case GL_BACK:
        cullBackOn();
        break;

    case GL_FRONT_AND_BACK:
        cullFrontBackOn();
        break;
    }
}
}    // end of renderer namespace
}    // end of mg namespace