/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
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
//#ifndef RODEO_RENDERER_IMAGE_H
//#define RODEO_RENDERER_IMAGE_H
//
//#ifndef RODEO_CORE_RTTI_H_
//#include "core\rtti.h"
//#endif
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		class Image
//		{
//		public:
//			Image() {}
//			virtual ~Image() {}
//
//			// Opens image file (tga, bmp, dds)
//			virtual bool open(const char* fileName) = 0;
//
//			// Draw your image on the screen with arguments x, y
//			virtual void release() = 0;
//
//			// Simple Rtti system
//			// TODO: Replace with more advenced one
//			virtual const char* getClassName() const = 0;
//
//			unsigned int getWidth() const
//			{
//				return _width;
//			}
//
//			unsigned int getHeight() const
//			{
//				return _height;
//			}
//
//			unsigned char* getImageData() const
//			{
//				return _data;
//			}
//
//			unsigned int getBpp() const
//			{
//				return _bpp;
//			}
//
//			unsigned int getBlockSize() const
//			{
//				return _blocksize;
//			}
//
//			unsigned int getBitDepth() const
//			{
//				return _bitdepth;
//			}
//
//			unsigned int getMipmapCount() const
//			{
//				return _mipmapcount;
//			}
//
//			int getPixelFormat() const
//			{
//				return _pixelformat;
//			}
//
//			GLenum getCompressionFormat() const
//			{
//				return _compression_format;
//			}
//
//			GLubyte* getPixels() const
//			{
//				return _pixels;
//			}
//
//		protected:
//			unsigned char* _data;
//			unsigned int _height;
//			unsigned int _width;
//			unsigned int _bpp;
//
//			// Specific data members for DDS Files
//			unsigned int _factor;
//			unsigned int _linearsize;
//			HANDLE _hfile;
//			GLenum _compression_format;
//			char _readbuff[4];
//			unsigned int _buffersize;
//
//			// blockSize - 8 bytes for DXT1\n16 bytes for DXT3, DXT5
//			unsigned int _blocksize;
//			unsigned int _bitdepth;
//			unsigned int _mipmapcount;
//			int _pixelformat;
//
//			// Holds actual image data 
//			GLubyte* _pixels;
//		};
//	}
//}
//#endif