/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_IMAGE_H
#define MG_RENDERER_IMAGE_H

#ifndef MG_CORE_RTTI_H_
#include "core\rtti.h"
#endif

namespace mg
{
namespace renderer
{
class Image
{
public:
    Image(){}
    virtual ~Image(){}

    // Opens image file (tga, bmp, dds)
    virtual bool open(const char* fileName)=0;

    // Draw your image on the screen with arguments x, y
    virtual void release()=0;

    // Simple Rtti system
    // TODO: Replace with more advenced one
    virtual const char* getClassName() const =0;

    core::ui getWidth() const
    {
        return width_;
    }

    core::ui getHeight() const
    {
        return height_;
    }

    core::ucp getImageData() const
    {
        return data_;
    }

    core::ui getBpp() const
    {
        return bpp_;
    }

    core::ui getBlockSize() const
    {
         return blocksize_;
    }

    core::ui getBitDepth() const
    {
        return bitdepth_;
    }

    core::ui getMipmapCount() const
    {
        return mipmapcount_;
    }

    int getPixelFormat() const
    {
        return pixelformat_;
    }

    GLenum getCompressionFormat() const
    {
        return compression_format_;
    }

    GLubyte* getPixels() const
    {
        return pixels_;
    }

protected:
    core::ucp data_;
    core::ui height_;
    core::ui width_;
    core::ui bpp_;

    // Specific data members for DDS Files
    core::ui factor_;
    core::ui linearsize_;
    HANDLE hfile_;
    GLenum compression_format_;
    char readbuff_[4];
    core::ui buffersize_;

    // blockSize - 8 bytes for DXT1\n16 bytes for DXT3, DXT5
    core::ui blocksize_;
    core::ui bitdepth_;
    core::ui mipmapcount_;
    int pixelformat_;

    // Holds actual image data 
    GLubyte* pixels_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif