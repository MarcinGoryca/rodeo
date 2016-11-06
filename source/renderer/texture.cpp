/*
----------------------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\texture.h"

using namespace std;
using namespace laura::core;

namespace laura
{
	namespace renderer
	{
		int Texture::_s_texture_count = 0;

		bool Texture::load(Image* image, const char* fileName, ui& tid)
		{
			if (image->open(fileName))
			{
				build(image, tid);
				return true;
			}
			else
				return false;
		}
		//void Texture::load(Image* image, string filename, ui numberOfTextures)
		//{
		//	image->open(filename.c_str());
		//}


		void Texture::release(Image* image)
		{
			image->release();
		}

		/**
		 *
		 */

		void Texture::build(Image* image, ui& tid)
		{
			//Code For TGAFile
			if (image->getClassName() == "TGAFile")
			{
				glGenTextures(1, &tid);
				_s_texture_count += 1;
				glBindTexture(GL_TEXTURE_2D, tid);

				glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				//use GL_NEAREST, GL_LINEAR, GL_NEAREST_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_NEAREST,
				//GL_NEAREST_MIPMAP_LINEAR
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

				//glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_ALPHA);
				//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_LOD, 2.5);
				//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_LOD, 4.5);
		//Mipmap Automatic Generation
				glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
				//glGenerateMipmap(GL_TEXTURE_2D);
				//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD); 

				if (image->getBpp() == 3)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->getWidth(), image->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image->getImageData());


				}
				else if (image->getBpp() == 4)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->getWidth(), image->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->getImageData());
				}
			}
			//Code For DDSFile	
			if (image->getClassName() == "DDSFile")
			{
				int size = 0;
				int offset = 0;

				int tmpWidth = image->getWidth();
				int tmpHeight = image->getHeight();

				glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, image->getMipmapCount() - 1);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				//glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);

				glGenerateMipmap(GL_TEXTURE_2D);
				//	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_SUBTRACT);

				glGenTextures(1, &tid);
				_s_texture_count += 1;
				glBindTexture(GL_TEXTURE_2D, tid);

				for (ui i = 0; i < image->getMipmapCount(); ++i)
				{

					if (tmpWidth == 0) tmpWidth = 1;
					if (tmpHeight == 0) tmpHeight = 1;
					size = ((tmpWidth + 3) / 4 * ((tmpHeight + 3) / 4)) * image->getBlockSize();
					glCompressedTexImage2D(GL_TEXTURE_2D, i, image->getCompressionFormat(), tmpWidth, tmpHeight, 0, size, image->getPixels() + offset);

					offset += size;
					tmpWidth = tmpWidth >> 1;
					tmpHeight = tmpHeight >> 1;
				}
			}
		}

		/**
		 *
		 */

		bool Texture::reset()
		{
			if (_texture_id)
			{
				//glDeleteTextures(1, &texture_id_);
				_texture_id = 0;
				return true;
			}
			return false;
		}

		/**
		 *
		 */

		void Texture::bind(Image* image, ui& tid)
		{
			glBindTexture(GL_TEXTURE_2D, tid);
		}
	}
}