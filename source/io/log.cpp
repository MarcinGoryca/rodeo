/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "io\log.h"

using namespace laura::core;
using namespace std;

namespace laura
{
	namespace io
	{
		Log::Log(const Log& log)
		{
			_hfile = NULL;
			_fileopen = false;
		}

		//.................................//
		bool Log::open(wstring fileName)
		{
			_hfile = CreateFile(fileName.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			if (_hfile == INVALID_HANDLE_VALUE)
			{
				MessageBox(NULL, LOGFILE_ERROR.c_str(), LAURA_HEADER.c_str(), ERR_ICON_OK);
				return false;
			}

			wchar_t actualData[68];
			wchar_t actualTime[68];

			_wstrdate_s(actualData);
			_wstrtime_s(actualTime);

			wstring getDate = L"Log created: ";
			getDate += actualData;
			getDate += L", ";
			getDate += actualTime;
			save(LAURA_HEADER);
			save(getDate);

			return true;
		}

		//...........................................//
		void Log::close()
		{
			CloseHandle(_hfile);
		}

		//-------------------------
		//void Log::update(const char* filename, const char* buffer)
		//{
		//
		//}
		//----------------------------

		void Log::write(wstring str)
		{
			save(str);
		}

		//........................................//
		void Log::save(wstring str)
		{
			//DWORD bytes = 100;
			DWORD bytesWrite = 0;

			const char* newLine = "\r\n";

			WriteFile(_hfile, str.c_str(), wcslen(str.c_str()), &bytesWrite, NULL);
			WriteFile(_hfile, newLine, strlen(newLine), &bytesWrite, NULL);
		}
	}
}