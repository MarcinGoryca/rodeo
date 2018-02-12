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
//#include "io\log.h"
//
//using namespace rodeo::core;
//using namespace std;
//
//namespace rodeo
//{
//	namespace io
//	{
//		Log::Log(const Log& log)
//		{
//			_hfile = NULL;
//			_fileopen = false;
//		}
//
//		//.................................//
//		bool Log::open(wstring fileName)
//		{
//			_hfile = CreateFile(fileName.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//
//			if (_hfile == INVALID_HANDLE_VALUE)
//			{
//				MessageBox(NULL, LOGFILE_ERROR.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
//				return false;
//			}
//
//			wchar_t actualData[68];
//			wchar_t actualTime[68];
//
//			_wstrdate_s(actualData);
//			_wstrtime_s(actualTime);
//
//			wstring getDate = L"Log created: ";
//			getDate += actualData;
//			getDate += L", ";
//			getDate += actualTime;
//			save(RODEO_HEADER);
//			save(getDate);
//
//			return true;
//		}
//
//		//...........................................//
//		void Log::close()
//		{
//			CloseHandle(_hfile);
//		}
//
//		//-------------------------
//		//void Log::update(const char* filename, const char* buffer)
//		//{
//		//
//		//}
//		//----------------------------
//
//		void Log::write(wstring str)
//		{
//			save(str);
//		}
//
//		//........................................//
//		void Log::save(wstring str)
//		{
//			//DWORD bytes = 100;
//			DWORD bytesWrite = 0;
//
//			const char* newLine = "\r\n";
//
//			WriteFile(_hfile, str.c_str(), wcslen(str.c_str()), &bytesWrite, NULL);
//			WriteFile(_hfile, newLine, strlen(newLine), &bytesWrite, NULL);
//		}
//	}
//}