/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "io\filetga.h"

using namespace std;
using namespace mg::core;
using namespace mg::renderer;

namespace mg
{
namespace io
{
bool FileTGA::pickFile(const char* fileName)
{
    filename_ = fileName;
    LPWSTR temp = 0;
    MultiByteToWideChar(0, 0, filename_, 0, temp, 0);
    LPCWSTR t = temp;
    hfile_ = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if(hfile_ == INVALID_HANDLE_VALUE)
    {
        MessageBox(NULL, TGA_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }
    return true;
}

//..................................//
void FileTGA::release()
{
    if(data_)
    {
        delete [] data_;
    }
}

//.................................//
bool FileTGA::open(const char* fileName)
{
    pickFile(fileName);
    DWORD bytesRead = 0;
    ReadFile(hfile_, uheader_, sizeof(uheader_), &bytesRead, NULL);
    ReadFile(hfile_, header_, sizeof(header_), &bytesRead, NULL);

    width_ = header_[1] * 256 + header_[0];
    height_ = header_[3] * 256 + header_[2];
    colordepth_ = header_[4];

    bpp_ = colordepth_ / 8;

    imagesize_ = bpp_ * width_ * height_;

    data_ = new uc[imagesize_];

    ReadFile(hfile_, data_, imagesize_, &bytesRead, NULL);

//	Swap BGR to RGB

    for(ui i=0; i < imagesize_; i += bpp_)
    {
        ui temp = data_[i];
        data_[i] = data_[i+2];
        data_[i+2] = static_cast<uc>(temp);
    }
    CloseHandle(hfile_);
    //Generate();
    return true;
}

//.........................................//
void FileTGA::draw(float x, float y)
{
    if(hfile_ == INVALID_HANDLE_VALUE)
    {
        MessageBox(NULL, TGA_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return;
    }
    
//GL_UNPACK_ALIGNMENT default value is 4, textures should be in BGRA format which is best solution for GPU's
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glRasterPos2f(x, y);
    if(bpp_ == 3)
    {
        glDrawPixels(width_, height_, GL_RGB, GL_UNSIGNED_BYTE, data_);
    }
    else if(bpp_ == 4)
    {
        glDrawPixels(width_, height_, GL_RGBA, GL_UNSIGNED_BYTE, data_);
    }
}
}    // end of io namespace
}    // end of mg namespace