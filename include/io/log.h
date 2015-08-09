/*
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
        :hfile_(NULL),
         filename_(""),
         mode_(""),
         fileopen_(false)
    {}

    ~Log()
    {
        fileopen_ = false;
        mode_ = "";
        filename_ = "";
        hfile_ = NULL;
    }

    //Copy constructor
    Log(const Log& log);

    bool open(std::wstring filename);
    void write(std::wstring string);

private:
    void close();
    void update(std::string filename, std::string buffer);
    void save(std::wstring filename);
    void load(std::string filename);

    HANDLE hfile_;
    const char* filename_;
    const char* mode_;
    bool fileopen_;
};
}    // end of io namespace
}    // end of mg namespace
#endif