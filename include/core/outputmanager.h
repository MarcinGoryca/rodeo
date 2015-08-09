/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_OUTPUTMANAGER_H
#define MG_CORE_OUTPUTMANAGER_H

#ifndef MG_IO_LOG_H_
#include "io/log.h"
#endif

#ifndef MG_CORE_MASTERMANAGER_H_
#include "core/mastermanager.h"
#endif

namespace mg 
{
namespace core
{
class OutputManager : public MasterManager
{
public:

    OutputManager()
        :MasterManager()
    {
        init();
    }

    ~OutputManager()
    {
        clear();
    }

    mg::io::Log* getLog() const
    {
        return log_;
    }

private:
    void init();
    void clear();

    io::Log* log_;
};
}    // end of core namespace
}    // end of mg namespace
#endif