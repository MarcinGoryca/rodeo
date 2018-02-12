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
//#include "io\filetga.h"
//
//using namespace std;
//using namespace rodeo::core;
//using namespace rodeo::renderer;
//
//namespace rodeo
//{
//	namespace io
//	{
//		bool FileTGA::pickFile(const char* fileName)
//		{
//			_filename = fileName;
//			LPWSTR temp = 0;
//			MultiByteToWideChar(0, 0, _filename, 0, temp, 0);
//			LPCWSTR t = temp;
//			_hfile = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//
//			if (_hfile == INVALID_HANDLE_VALUE)
//			{
//				MessageBox(NULL, TGA_LOAD_FAIL.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
//				return false;
//			}
//			return true;
//		}
//
//		//..................................//
//		void FileTGA::release()
//		{
//			if (_data)
//			{
//				delete[] _data;
//			}
//		}
//
//		//.................................//
//		bool FileTGA::open(const char* fileName)
//		{
//			pickFile(fileName);
//			DWORD bytesRead = 0;
//			ReadFile(_hfile, _uheader, sizeof(_uheader), &bytesRead, NULL);
//			ReadFile(_hfile, _header, sizeof(_header), &bytesRead, NULL);
//
//			_width = _header[1] * 256 + _header[0];
//			_height = _header[3] * 256 + _header[2];
//			_colordepth = _header[4];
//
//			_bpp = _colordepth / 8;
//
//			_imagesize = _bpp * _width * _height;
//
//			_data = new unsigned char[_imagesize];
//
//			ReadFile(_hfile, _data, _imagesize, &bytesRead, NULL);
//
//			//	Swap BGR to RGB
//
//			for (ui i = 0; i < _imagesize; i += _bpp)
//			{
//				ui temp = _data[i];
//				_data[i] = _data[i + 2];
//				_data[i + 2] = static_cast<unsigned char>(temp);
//			}
//			CloseHandle(_hfile);
//			//Generate();
//			return true;
//		}
//
//		//.........................................//
//		void FileTGA::draw(float x, float y)
//		{
//			if (_hfile == INVALID_HANDLE_VALUE)
//			{
//				MessageBox(NULL, TGA_LOAD_FAIL.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
//				return;
//			}
//
//			//GL_UNPACK_ALIGNMENT default value is 4, textures should be in BGRA format which is best solution for GPU's
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//			glRasterPos2f(x, y);
//			if (_bpp == 3)
//			{
//				glDrawPixels(_width, _height, GL_RGB, GL_UNSIGNED_BYTE, _data);
//			}
//			else if (_bpp == 4)
//			{
//				glDrawPixels(_width, _height, GL_RGBA, GL_UNSIGNED_BYTE, _data);
//			}
//		}
//	}
//}