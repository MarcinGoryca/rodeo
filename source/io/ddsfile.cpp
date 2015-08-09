/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "io\filedds.h"

using namespace mg::renderer;
using namespace mg::core;
using namespace std;

namespace mg
{
namespace io
{
FileDDS::~FileDDS()
{
//	Release();
}

bool FileDDS::open(const char *filename)
{
    LPWSTR temp = 0;
    MultiByteToWideChar(0, 0, filename, 0, temp, 0);
    LPCWSTR t = temp;
    hfile_ = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if(hfile_ == INVALID_HANDLE_VALUE)
    {
        MessageBox(NULL, DDS_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }
    read(filename);
    return true;
}

//..................................//
void FileDDS::release()
{
    if(pixels_)
    {
        delete [] pixels_;
    }
    pixels_ = NULL;
}

//...................................//
void FileDDS::read(const char* fileName)
{
    if(hfile_ == INVALID_HANDLE_VALUE)
    {
        MessageBox(NULL, DDS_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return;
    }

    DWORD bytesRead = 0;
    ReadFile(hfile_, readbuff_, 4, &bytesRead, NULL);
    ReadFile(hfile_, &dds_, sizeof(dds_), &bytesRead, NULL);

    switch(dds_.ddspf.fourCC)
    {
    case FOURCC_DXT1:
        compression_format_ = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        blocksize_ = 8;
        factor_ = 2;
        break;
    case FOURCC_DXT3:
        compression_format_ = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        blocksize_ = 16;
        factor_ = 4;
        break;
    case FOURCC_DXT5:
        compression_format_ = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        blocksize_ = 16;
        factor_ = 4;
        break;
    }

    linearsize_ = dds_.pitchOrLinearSize;
    buffersize_ = linearsize_ * factor_;
    pixels_ = new GLubyte[buffersize_];
    
    ReadFile(hfile_, pixels_, buffersize_, &bytesRead, NULL);
    CloseHandle(hfile_);

    width_ = dds_.width;
    height_ = dds_.height;
    pixelformat_ = dds_.ddspf.size;
    bitdepth_ = pixelformat_ /8;
    mipmapcount_ = dds_.mipMapCount;
}

//.....................................//
void FileDDS::draw(float x, float y)
{
    glWindowPos2f(x, y);
}

//....................................//
void FileDDS::flipColorBlock(GLubyte* data)
{
    for(int i=0; i < pixelformat_; ++i)
    {
        GLubyte temp;

        temp = data[4];
        data[4] = data[7];
        data[7] = temp;

        temp = data[5];
        data[5] = data[6];
        data[6] = temp;

        data += 8;
    }
}

//-----------------------------------
//!IMPORTANT NOTES - NOT IMPLEMENTED!
//This solution comes from Devil library for OpenGL
/*void DDSFile::flipDXT1(GLubyte* data)
{
	*///GLubyte* tempData;
	//ui x, y, z, i, j, k, select;
	//us c1, c2;
	//GLubyte r, g, b;
	//DXTColors colors[4];
	//DXTColors* tmpColor;
	//DXTColors* col;
	//ui bitmask;
	//ui offset;

	//if(!data)
	//	return;
	//
	//tempData = data;
	//colors[0].a = 0xFF;
	//colors[1].a = 0xFF;
	//colors[2].a = 0xFF;
	//
	//for(z = 0; z < bitDepth; ++z)
	//{
	//	for(y = 0; y < height; y += 4)
	//	{
	//		for(x = 0; x < width; x += 4)
	//		{
	//			c1 = *((us*)tempData);
	//			(us)(&c1);
	//			c2 = *((us*)tempData+2);
	//			(us)(&c2);

	//			b = c1 & 0x1f;
	//			g = (c1 & 0x7E0) >> 5;
	//			r = (c1 & 0xF800) >> 11;

	//			tmpColor = colors;

	//			tmpColor->r = r << 3;
	//			tmpColor->g = g << 2;
	//			tmpColor->b = b << 3;

	//			b = c2 & 0x1f;
	//			g = (c2 & 0x7E0) >> 5;
	//			r = (c2 & 0xF800) >> 11;

	//			tmpColor = colors + 1;

	//			tmpColor->r = r << 3;
	//			tmpColor->g = g << 2;
	//			tmpColor->b = b << 3;

	//			bitmask = ((ui*)tempData)[1];
	//			(ui)(&bitmask);
	//			tempData += 8;

	//			if(c1 > c2)
	//			{
	//				tmpColor[2].b = (2 * tmpColor[0].b + tmpColor[1].b + 1) / 3;
	//				tmpColor[2].g = (2 * tmpColor[0].g + tmpColor[1].g + 1) / 3;
	//				tmpColor[2].r = (2 * tmpColor[0].r + tmpColor[1].r + 1) / 3;

	//				tmpColor[3].b = (tmpColor[0].b + 2 * tmpColor[1].b + 1) / 3;
	//				tmpColor[3].g = (tmpColor[0].g + 2 * tmpColor[1].g + 1) / 3;
	//				tmpColor[3].r = (tmpColor[0].r + 2 * tmpColor[1].r + 1) / 3;
	//				tmpColor[3].a = 0xFF;
	//			}
	//			else
	//			{
	//				tmpColor[2].b = (tmpColor[0].b + tmpColor[1].b) / 2;
	//				tmpColor[2].g = (tmpColor[0].g + tmpColor[1].g) / 2;
	//				tmpColor[2].r = (tmpColor[0].r + tmpColor[1].r) / 2;

	//				tmpColor[3].b = (tmpColor[0].b + 2 * tmpColor[1].b + 1) / 3;
	//				tmpColor[3].g = (tmpColor[0].g + 2 * tmpColor[1].g + 1) / 3;
	//				tmpColor[3].r = (tmpColor[0].r + 2 * tmpColor[1].r + 1) / 3;
	//				tmpColor[3].a = 0x00;
	//			}
	//			for(j=0, k=0; j<4; ++j)
	//			{
	//				for(i = 0; i < 4; ++i, ++k)
	//				{
	//					select = (bitmask & (0x03 << k * 2)) >> k * 2;
	//					col = &tmpColor[select];

	//					if(((x + i) < width) && (y + j) < height)
	//					{
	//						offset = z * sizeOfPlane + (y + j) * bps  + (x  + i) * bitDepth;
	//						pixels[offset + 0] = col->r;
	//						pixels[offset + 1] = col->g;
	//						pixels[offset + 2] = col->b;
	//						pixels[offset + 3] = col->a;
	//					}
	//				}
	//			}
	//		} 
	//	}
	//}

//}
}    // end of io namespace
}    // end of mg namespace