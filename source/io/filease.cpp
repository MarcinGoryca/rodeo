/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
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
//#include "io\filease.h"
//
//using namespace laura::core;
//
//namespace laura
//{
//	namespace io
//	{
//		const char* const FileASE::_S_ASE_STRING = "*3DSMAX_ASCIIEXPORT 200";
//		const char* const FileASE::_S_SCENE_STRING = "*SCENE";
//
//		bool FileASE::import(const char* filename)
//		{
//			try
//			{
//				LPWSTR temp = 0;
//				MultiByteToWideChar(0, 0, filename, 0, temp, 0);
//				LPCWSTR t = temp;
//				_file = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//
//				if (_file == INVALID_HANDLE_VALUE)
//					throw - 1;
//			}
//			catch (...)
//			{
//				MessageBox(NULL, L"Couldn't Load ASE file!", LAURA_HEADER.c_str(), ERR_ICON_OK);
//				return false;
//			}
//
//			DWORD bytesRead = 0;
//			//char tempBuffer[9] = {0};
//			ReadFile(_file, _buffer, 20, &bytesRead, NULL);
//
//			if (_S_SCENE_STRING)
//			{
//
//			}
//			CloseHandle(_file);
//			return true;
//		}
//	}
//}