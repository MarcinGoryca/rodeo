/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_RENDERER_IMAGE_H
#define LAURA_RENDERER_IMAGE_H

#ifndef LAURA_CORE_RTTI_H_
#include "core\rtti.h"
#endif

namespace laura
{
	namespace renderer
	{
		class Image
		{
		public:
			Image() {}
			virtual ~Image() {}

			// Opens image file (tga, bmp, dds)
			virtual bool open(const char* fileName) = 0;

			// Draw your image on the screen with arguments x, y
			virtual void release() = 0;

			// Simple Rtti system
			// TODO: Replace with more advenced one
			virtual const char* getClassName() const = 0;

			unsigned int getWidth() const
			{
				return _width;
			}

			unsigned int getHeight() const
			{
				return _height;
			}

			unsigned char* getImageData() const
			{
				return _data;
			}

			unsigned int getBpp() const
			{
				return _bpp;
			}

			unsigned int getBlockSize() const
			{
				return _blocksize;
			}

			unsigned int getBitDepth() const
			{
				return _bitdepth;
			}

			unsigned int getMipmapCount() const
			{
				return _mipmapcount;
			}

			int getPixelFormat() const
			{
				return _pixelformat;
			}

			GLenum getCompressionFormat() const
			{
				return _compression_format;
			}

			GLubyte* getPixels() const
			{
				return _pixels;
			}

		protected:
			unsigned char* _data;
			unsigned int _height;
			unsigned int _width;
			unsigned int _bpp;

			// Specific data members for DDS Files
			unsigned int _factor;
			unsigned int _linearsize;
			HANDLE _hfile;
			GLenum _compression_format;
			char _readbuff[4];
			unsigned int _buffersize;

			// blockSize - 8 bytes for DXT1\n16 bytes for DXT3, DXT5
			unsigned int _blocksize;
			unsigned int _bitdepth;
			unsigned int _mipmapcount;
			int _pixelformat;

			// Holds actual image data 
			GLubyte* _pixels;
		};
	}
}
#endif