///*
//-----------------------------------
//    Laura Game Engine
//    Copyright(c) Marcin Goryca
//    marcin.goryca@gmail.com
//    http://marcingoryca.pl
//-----------------------------------
//*/
//#ifndef LAURA_IO_FILETGA_H_
//#define LAURA_IO_FILETGA_H_
//
//#ifndef LAURA_RENDERER_GL_GLCOMMON_H_
//#include "..\renderer\gl\glcommon.h"
//#endif
//
//#ifndef LAURA_CORE_CONSTANTS_H_
//#include "core\constants.h"
//#endif
//
//#ifndef LAURA_CORE_ERROR_H_
//#include "core\error.h"
//#endif
//
//#ifndef LAURA_RENDERER_COLORS_H_
//#include "renderer\colors.h"
//#endif
//
//#ifndef LAURA_RENDERER_IMAGE_H_
//#include "renderer\image.h"
//#endif
//
//#ifndef LAURA_RENDERER_FONT_H_
//#include "renderer\font.h"
//#endif
//
//namespace laura
//{
//namespace io
//{
//class FileTGA : public renderer::Image
//{
//public:
//    FileTGA()
//        :_filename(""),
//         _colordepth(0),
//         _imagesize(0),
//         _hfile(NULL),
//         _texture_id(0)
//    {}
//    
//    FileTGA(const char* new_filename)
//        :_filename(new_filename),
//         _colordepth(0),
//         _imagesize(0),
//         _hfile(NULL),
//         _texture_id(0)
//    {}
//    
//    virtual ~FileTGA()
//    {}
//
//    virtual bool open(const char* fileName);
//
//
//    unsigned int getColorDepth()const { return _colordepth; }
//    unsigned int getTextureId()const { return _texture_id; }
//
//private :
//	const char* _filename;
//	BYTE _uheader[12];
//	BYTE _cheader[12];
//	BYTE _header[6];
//	unsigned int _colordepth;
//
//	unsigned long _imagesize;
//	HANDLE _hfile;
//	unsigned int _texture_id;
//
//    bool pickFile(const char* fileName);
//    void swapRedBlue();
//    void flipVertically();
//    void convertRGBAToRGB();
//    void convertRGBToRGBA();
//    void draw(float x, float y);
//    void release();
//    virtual const char* getClassName()const{ return "FileTGA"; }
//
//
//};
//}
//}
//#endif