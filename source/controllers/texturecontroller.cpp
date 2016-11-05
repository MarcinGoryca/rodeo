﻿/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers\TextureController.h"

using namespace laura::io;
using namespace laura::renderer;

namespace laura
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
		void TextureController::load(renderer::Image* ilaura, const char* filename, unsigned int& tid)
		{
			_texture->load(ilaura, filename, tid);

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