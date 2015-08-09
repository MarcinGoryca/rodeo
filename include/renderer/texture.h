/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_TEXTURE_H_
#define MG_RENDERER_TEXTURE_H_

#ifndef MG_IO_FILEDDS_H_
#include "io\filedds.h"
#endif

#ifndef MG_IO_FILETGA_H_
#include "io\filetga.h"
#endif

namespace mg
{
namespace renderer
{
class Texture
{
public:
    Texture(){}

    ~Texture()
    {
        reset();
    }

    virtual bool load(Image* image, const char* filename, core::ui& tid);
    //virtual void load(Image* image, std::string filename, ui numberOfTextures);
    virtual void release(Image* image);
    virtual void bind(Image* image, core::ui& tid);

    // This will clean up all generated textures 
    bool reset();

    core::ui texture_id_;
private:
    virtual void build(Image* image, core::ui& tid);

    // Used for counting number of generated textures 
    static int s_texture_count_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif