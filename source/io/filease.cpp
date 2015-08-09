/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "io\filease.h"

using namespace mg::core;

namespace mg
{
namespace io
{
const char* const FileASE::ASE_STRING = "*3DSMAX_ASCIIEXPORT 200";
const char* const FileASE::SCENE_STRING = "*SCENE";

bool FileASE::import(const char* filename)
{
    try
    {
        LPWSTR temp = 0;
        MultiByteToWideChar(0, 0, filename, 0, temp, 0);
        LPCWSTR t = temp;
        file_ = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if(file_ == INVALID_HANDLE_VALUE)
            throw -1;
    }
    catch(...)
    {
        MessageBox(NULL, L"Couldn't Load ASE file!", MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }

    DWORD bytesRead = 0;
    //char tempBuffer[9] = {0};
    ReadFile(file_, buffer_, 20, &bytesRead, NULL);

    if(SCENE_STRING)
    {

    }
    CloseHandle(file_);
    return true;
}
}    // end of io namespace
}    // end of mg namespace