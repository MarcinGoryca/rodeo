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
			_filename = fileName;
			LPWSTR temp = 0;
			MultiByteToWideChar(0, 0, _filename, 0, temp, 0);
			LPCWSTR t = temp;
			_hfile = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

			if (_hfile == INVALID_HANDLE_VALUE)
			{
				MessageBox(NULL, TGA_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
				return false;
			}
			return true;
		}

		//..................................//
		void FileTGA::release()
		{
			if (_data)
			{
				delete[] _data;
			}
		}

		//.................................//
		bool FileTGA::open(const char* fileName)
		{
			pickFile(fileName);
			DWORD bytesRead = 0;
			ReadFile(_hfile, _uheader, sizeof(_uheader), &bytesRead, NULL);
			ReadFile(_hfile, _header, sizeof(_header), &bytesRead, NULL);

			_width = _header[1] * 256 + _header[0];
			_height = _header[3] * 256 + _header[2];
			_colordepth = _header[4];

			_bpp = _colordepth / 8;

			_imagesize = _bpp * _width * _height;

			_data = new unsigned char[_imagesize];

			ReadFile(_hfile, _data, _imagesize, &bytesRead, NULL);

			//	Swap BGR to RGB

			for (ui i = 0; i < _imagesize; i += _bpp)
			{
				ui temp = _data[i];
				_data[i] = _data[i + 2];
				_data[i + 2] = static_cast<unsigned char>(temp);
			}
			CloseHandle(_hfile);
			//Generate();
			return true;
		}

		//.........................................//
		void FileTGA::draw(float x, float y)
		{
			if (_hfile == INVALID_HANDLE_VALUE)
			{
				MessageBox(NULL, TGA_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
				return;
			}

			//GL_UNPACK_ALIGNMENT default value is 4, textures should be in BGRA format which is best solution for GPU's
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			glRasterPos2f(x, y);
			if (_bpp == 3)
			{
				glDrawPixels(_width, _height, GL_RGB, GL_UNSIGNED_BYTE, _data);
			}
			else if (_bpp == 4)
			{
				glDrawPixels(_width, _height, GL_RGBA, GL_UNSIGNED_BYTE, _data);
			}
		}
	}
}