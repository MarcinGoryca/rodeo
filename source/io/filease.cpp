/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "io\filease.h"

using namespace laura::core;

namespace laura
{
	namespace io
	{
		const char* const FileASE::_S_ASE_STRING = "*3DSMAX_ASCIIEXPORT 200";
		const char* const FileASE::_S_SCENE_STRING = "*SCENE";

		bool FileASE::import(const char* filename)
		{
			try
			{
				LPWSTR temp = 0;
				MultiByteToWideChar(0, 0, filename, 0, temp, 0);
				LPCWSTR t = temp;
				_file = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

				if (_file == INVALID_HANDLE_VALUE)
					throw - 1;
			}
			catch (...)
			{
				MessageBox(NULL, L"Couldn't Load ASE file!", LAURA_HEADER.c_str(), ERR_ICON_OK);
				return false;
			}

			DWORD bytesRead = 0;
			//char tempBuffer[9] = {0};
			ReadFile(_file, _buffer, 20, &bytesRead, NULL);

			if (_S_SCENE_STRING)
			{

			}
			CloseHandle(_file);
			return true;
		}
	}
}