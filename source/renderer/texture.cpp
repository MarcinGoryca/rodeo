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
//#include "renderer\texture.h"
//
//using namespace std;
//using namespace rodeo::core;
//
//namespace rodeo
//{
//	namespace renderer
//	{
//		int Texture::_s_texture_count = 0;
//
//		bool Texture::load(Image* image, const char* fileName, ui& tid)
//		{
//			if (image->open(fileName))
//			{
//				build(image, tid);
//				return true;
//			}
//			else
//				return false;
//		}
//		//void Texture::load(Image* image, string filename, ui numberOfTextures)
//		//{
//		//	image->open(filename.c_str());
//		//}
//
//
//		void Texture::release(Image* image)
//		{
//			image->release();
//		}
//
//		/**
//		 *
//		 */
//
//		void Texture::build(Image* image, ui& tid)
//		{
//			//Code For TGAFile
//			if (image->getClassName() == "TGAFile")
//			{
//				glGenTextures(1, &tid);
//				_s_texture_count += 1;
//				glBindTexture(GL_TEXTURE_2D, tid);
//
//				glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
//
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//				//use GL_NEAREST, GL_LINEAR, GL_NEAREST_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_NEAREST,
//				//GL_NEAREST_MIPMAP_LINEAR
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//
//				//glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_ALPHA);
//				//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_LOD, 2.5);
//				//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_LOD, 4.5);
//		//Mipmap Automatic Generation
//				glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
//				//glGenerateMipmap(GL_TEXTURE_2D);
//				//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD); 
//
//				if (image->getBpp() == 3)
//				{
//					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->getWidth(), image->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image->getImageData());
//
//
//				}
//				else if (image->getBpp() == 4)
//				{
//					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->getWidth(), image->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->getImageData());
//				}
//			}
//			//Code For DDSFile	
//			if (image->getClassName() == "DDSFile")
//			{
//				int size = 0;
//				int offset = 0;
//
//				int tmpWidth = image->getWidth();
//				int tmpHeight = image->getHeight();
//
//				glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, image->getMipmapCount() - 1);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//				//glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
//
//				glGenerateMipmap(GL_TEXTURE_2D);
//				//	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_SUBTRACT);
//
//				glGenTextures(1, &tid);
//				_s_texture_count += 1;
//				glBindTexture(GL_TEXTURE_2D, tid);
//
//				for (ui i = 0; i < image->getMipmapCount(); ++i)
//				{
//
//					if (tmpWidth == 0) tmpWidth = 1;
//					if (tmpHeight == 0) tmpHeight = 1;
//					size = ((tmpWidth + 3) / 4 * ((tmpHeight + 3) / 4)) * image->getBlockSize();
//					glCompressedTexImage2D(GL_TEXTURE_2D, i, image->getCompressionFormat(), tmpWidth, tmpHeight, 0, size, image->getPixels() + offset);
//
//					offset += size;
//					tmpWidth = tmpWidth >> 1;
//					tmpHeight = tmpHeight >> 1;
//				}
//			}
//		}
//
//		/**
//		 *
//		 */
//
//		bool Texture::reset()
//		{
//			if (_texture_id)
//			{
//				//glDeleteTextures(1, &texture_id_);
//				_texture_id = 0;
//				return true;
//			}
//			return false;
//		}
//
//		/**
//		 *
//		 */
//
//		void Texture::bind(Image* image, ui& tid)
//		{
//			glBindTexture(GL_TEXTURE_2D, tid);
//		}
//	}
//}