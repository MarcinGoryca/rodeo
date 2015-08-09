/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_QUERYRENDERER_H_
#define MG_RENDERER_QUERYRENDERER_H_

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "glcommon.h"
#endif

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef MG_CORE_RENDEREREXCEPTION_H_
#include "core\rendererexception.h"
#endif

namespace mg
{
namespace renderer
{
class QueryRenderer
{
public:
    QueryRenderer(){  }
    ~QueryRenderer(){ reset();}

    const GLubyte* getVendor()const{ return glvendor_; }
    const GLubyte* getRenderer()const{ return glrenderer_; }
    const GLubyte* getVersion()const { return glversion_; }
    const GLubyte* getExtensions()const { return glextensions_; }
    void run();

    enum Vendor
    {
        NVIDIA = 1,
        ATI = 2,
        OTHER = 3
    };

    enum Version
    {
        OPENGL_1 = 1,
        OPENGL_2 = 2,
        OPENGL_3 = 3,
        OPENGL_4 = 4
    };

/**
 *	TODO:
 *	1. Check for GL_VENDOR
 *	2. Check for GL_VERSION
 *	3. Check for GL_RENDERER
 *	4. Check for GL_EXTENSIONS
 *	5. Check for Resolution
 * 6. Check for Color Mode
 */

    // Calls glGetIntegerv(GL_SAMPLE_BUFFERS)<br/>
    // If the returned value is 1 - there is MULTISAMPLING on this platform
    void checkMultisampling();

private:
    std::string print(std::string s)const;
    bool reset();

    const GLubyte* glrenderer_;
    const GLubyte* glvendor_;
    const GLubyte* glversion_;
    const GLubyte* glextensions_;
    
    int gl21supported_;
    int gl31supported_;
    int gl32supported_;
    int gl33supported_;
    int gl41supported_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif