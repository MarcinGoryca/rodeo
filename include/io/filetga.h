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
#ifndef RODEO_IO_FILETGA_H_
#define RODEO_IO_FILETGA_H_

#ifndef RODEO_RENDERER_GL_GLCOMMON_H_
#include "..\renderer\gl\glcommon.h"
#endif

#ifndef RODEO_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef RODEO_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef RODEO_RENDERER_COLORS_H_
#include "renderer\colors.h"
#endif

#ifndef RODEO_RENDERER_IMAGE_H_
#include "renderer\image.h"
#endif

#ifndef RODEO_RENDERER_FONT_H_
#include "renderer\font.h"
#endif

namespace rodeo
{
namespace io
{
class FileTGA : public renderer::Image
{
public:
    FileTGA()
        :_filename(""),
         _colordepth(0),
         _imagesize(0),
         _hfile(NULL),
         _texture_id(0)
    {}
    
    FileTGA(const char* new_filename)
        :_filename(new_filename),
         _colordepth(0),
         _imagesize(0),
         _hfile(NULL),
         _texture_id(0)
    {}
    
    virtual ~FileTGA()
    {}

    virtual bool open(const char* fileName);


    unsigned int getColorDepth()const { return _colordepth; }
    unsigned int getTextureId()const { return _texture_id; }

private :
	const char* _filename;
	BYTE _uheader[12];
	BYTE _cheader[12];
	BYTE _header[6];
	unsigned int _colordepth;

	unsigned long _imagesize;
	HANDLE _hfile;
	unsigned int _texture_id;

    bool pickFile(const char* fileName);
    void swapRedBlue();
    void flipVertically();
    void convertRGBAToRGB();
    void convertRGBToRGBA();
    void draw(float x, float y);
    void release();
    virtual const char* getClassName()const{ return "FileTGA"; }


};
}
}
#endif