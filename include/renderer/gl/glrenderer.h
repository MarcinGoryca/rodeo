// TODO
// THIS FILE MUST BE CLEARED,
// IT SHOULD NOT CONTAIN ENABLING/DISABLING METHODS


/*
 |  ----------------------------------------------
 |    MG Game Engine
 |    [ GLRenderer.h ] / [ renderer/gl ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef MG_RENDERER_GLRENDERER_H_
#define MG_RENDERER_GLRENDERER_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_CORE_EXCEPTION_H_
#include "core\exception.h"
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

#ifndef MG_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef MG_RENDERERGL_GL_QUERYRENDERER_H_
#include "renderer\gl\queryrenderer.h"
#endif

#ifndef MG_RENDERER_IRENDERER_H_
#include "renderer\irenderer.h"
#endif

namespace mg
{
namespace renderer
{
class GLRenderer :  public core::Singleton<GLRenderer>, public IRenderer
{
public:
    GLRenderer();
   
    virtual ~GLRenderer();

	/*
	 |  ------------------------------------------------------
     |    Parameter w - width of the scene
     |    Parameter h - height of the scene
     |    Runs renderer
     |    Calls glewInit(), QueryRenderer.run()
	 |  ------------------------------------------------------
	 */
    virtual bool run(int w, int h);

    /*
	 |  ------------------------------------------------------
	 |    Render to the screen, 
	 |  ------------------------------------------------------
	 */
    virtual void render();

    virtual void update();

    // For Orthographic projection 
    virtual void enter2d();

    // For Perspective projection
    virtual void enter3d();

	/*
	 |  ---------------------------------------------------------------------------------
     |    Parameter r - red value of the color [range 0.0f - 1.0f]
     |    Parameter g - green value of the color [range 0.0f - 1.0f]
     |    Parameter b - blue value of the color [range 0.0f - 1.0f]
     |    Use it to Change Background Color of the rendering window
     |    Using Colors from MG
     |    backColor(darkgreen, 1.0f)
     |    You must specify your alfa argument [range 0.0f[transparent] - 1.0f[opacity]]
     |    Colors in float manner are defined with only three values red, green, blue
     |    like that: #define white 1.0f, 1.0f, 1.0f
	 |  ---------------------------------------------------------------------------------
	 */
    virtual void backColor(float r, float g, float b, float a);

    // Change Size if it receives WM_SIZE MSG
    // Parameter w - width of the scene
    // Parameter h - height of the scene
    // Calls SetGL(int, int)
    virtual void onSize(int w, int h);

    // ChooseViewportType(GLViewportType type) --
    bool chooseViewportType(GLViewportType type);
 
    // Enter the frame of rendering, 
    // it should initialize OpenGL pipeline, clear all buffers
    // Calls glClearColor(), glClearDepth(), glClear()
    virtual void enterFrame();

    // End the frame of rendering, 
    // it should do double buffering at the end
    //Calls glFlush();
    virtual void endFrame();

    // LIGHTING METHODS
    virtual bool enableLighting();
    virtual bool disableLighting();

    // DEPTH TESTING

    virtual bool enableDepthTest();
    virtual bool disableDepthTest();

    // SHADERS

    virtual void enableShaders();
    virtual void disableShaders();

    //virtual ShadersInterface* shaderFactory(enginecore::ShadersVendor sv);
    virtual void setShader(IShaders* si) { shader_ = si; } 
    
    // TEXTURING

    virtual void enableTexturing();
    virtual void disableTexturing();

    // BLENDING
    
    virtual void enableBlending();
    virtual void disableBlending();

    virtual bool checkEnabled(GLenum state);

    // CULLING

    // Calls glEnable(GL_CULL_FACE)
    virtual void enableCulling();
    
    // Calls glDisable(GL_CULL_FACE)
    virtual void disableCulling();
    
    virtual void cullMode(GLenum mode);

    int getWidth()const { return width_; }
    int getHeight()const { return height_; }
    void setWidth(int w){ width_ = w; }
    void setHeight(int h) { height_ = h; }

 
private:
    /* 
	 |  ----------------------------------
	 |    Copy Constructor
	 |  ----------------------------------
	 */
    GLRenderer(const GLRenderer& glrenderer);

    /*
	 |  ----------------------------------
	 |    Copy operator
	 |  ----------------------------------
	 */
    GLRenderer operator=(const GLRenderer& glrenderer);

    /*
	 |  ----------------------------------------
	 |    Sets OpenGL Renderer
     |    Parameter w - width of the scene
     |    Parameter h - height of the scene
     |    This method calls
	 |  ----------------------------------------
	 */
    void setGL(int w, int h);

    /*
	 |  ------------------------------------------
	 |    Calls glClearColor(r, g, b, a)
     |    In MG it's value is glClearColor(black, 1.0) but it is NOT called!
	 |  -------------------------------------------
	 */
    bool initGL();

    /*
	 |  -----------------------------------------------------------
	 |    Initializes Background color for GL
     |    Parameter float red - red value from RGB - MUST BE in <0.0, 1.0> !
     |    Parameter float green - green value from RGB - MUST BE  in <0.0, 1.0> !
     |    Parameter float blue - blue value form RGB - MUST BE in <0.0, 1.0> !
     |    Calls SetGL(int, int), glClearColor(float, float, float, float), glClearDepth(float)
	 |  ---------------------------------------------------------------
	 */
    bool initGL(int w, int h, float r, float g, float b, float a);

    /*
	 |  -------------------------------------------------------
	 |    Calls glFlush()
	 |  -------------------------------------------------------
	 */
    void flush();

    QueryRenderer* getQueryRenderer() const { return query_renderer_; }

private:
    QueryRenderer* query_renderer_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif