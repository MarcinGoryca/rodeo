﻿/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_LOG_H_
#define MG_IO_LOG_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

namespace mg
{
namespace io
{
class Log
{
public:
    Log()
        :_hfile(NULL),
         _filename(""),
         _mode(""),
         _fileopen(false)
    {}

    ~Log()
    {
        _fileopen = false;
        _mode = "";
        _filename = "";
        _hfile = NULL;
    }

    //Copy constructor
    Log(const Log& log);

    bool open(std::wstring filename);
    void write(std::wstring string);

private:
	HANDLE _hfile;
	const char* _filename;
	const char* _mode;
	bool _fileopen;

    void close();
    void update(std::string filename, std::string buffer);
    void save(std::wstring filename);
    void load(std::string filename);
};
}
}
#endif