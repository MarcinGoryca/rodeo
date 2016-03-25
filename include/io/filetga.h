/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_FILETGA_H_
#define MG_IO_FILETGA_H_

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "..\renderer\gl\glcommon.h"
#endif

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_RENDERER_COLORS_H_
#include "renderer\colors.h"
#endif

#ifndef MG_RENDERER_IMAGE_H_
#include "renderer\image.h"
#endif

#ifndef MG_RENDERER_FONT_H_
#include "renderer\font.h"
#endif

namespace mg
{
namespace io
{
class FileTGA : public renderer::Image
{
public:
    FileTGA()
        :filename_(""),
         colordepth_(0),
         imagesize_(0),
         hfile_(NULL),
         texture_id_(0)
    {}
    
    FileTGA(const char* new_filename)
        :filename_(new_filename),
         colordepth_(0),
         imagesize_(0),
         hfile_(NULL),
         texture_id_(0)
    {}
    
    virtual ~FileTGA()
    {}

    virtual bool open(const char* fileName);


    unsigned int getColorDepth()const { return colordepth_; }
    unsigned int getTextureId()const { return texture_id_; }

private :
    bool pickFile(const char* fileName);
    void swapRedBlue();
    void flipVertically();
    void convertRGBAToRGB();
    void convertRGBToRGBA();
    void draw(float x, float y);
    void release();
    virtual const char* getClassName()const{ return "FileTGA"; }

    const char* filename_;
    BYTE uheader_[12];
    BYTE cheader_[12];
    BYTE header_[6];
    unsigned int colordepth_;

    unsigned long imagesize_;
    HANDLE hfile_;
    unsigned int texture_id_;
};
}    // end of io namespace
}    // end of mg namespace
#endif