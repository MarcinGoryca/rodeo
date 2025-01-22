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
#include "controllers\TextureController.h"

using namespace rodeo::io;
using namespace rodeo::renderer;

namespace rodeo
{
	namespace controllers
	{
		int TextureController::_s_texture_count = 0;

		void TextureController::bind(unsigned int& tid)
		{
			//glBindTexture(GL_TEXTURE_2D, tid);
		}

		//--------------------------------------------------------------------------------------------------
		void TextureController::clean()
		{
			_texture->reset();
		}

		//--------------------------------------------------------------------------------------------------
		void TextureController::load(renderer::Image* irodeo, const char* filename, unsigned int& tid)
		{
			_texture->load(irodeo, filename, tid);

			_s_texture_count += 1;

			bind(tid);
		}

		//--------------------------------------------------------------------------------------------------
		void TextureController::reset()
		{
			_texture->reset();
		}

		//--------------------------------------------------------------------------------------------------
		void TextureController::load()
		{

		}

		//--------------------------------------------------------------------------------------------------
		unsigned int TextureController::loadDDS(const char* filename)
		{
			_texObj.push_back(1);

			unsigned int index = _texObj[0];

			_image_data[index] = new FileDDS;
			_texture->load(_image_data[index], filename, _texture_id[index]);

			_s_texture_count += 1;

			delete _image_data[index];

			return _texture_id[index];
		}

		//--------------------------------------------------------------------------------------------------
		unsigned int TextureController::loadTGA(const char* filename)
		{
			unsigned int index = _s_texture_count;
			_image_data[index] = new FileTGA;
			_texture->load(_image_data[index], filename, _texture_id[index]);

			_s_texture_count += 1;

			delete _image_data[index];

			return _texture_id[index];
		}
	}
}