/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_MASTERMANAGER_H
#define MG_CORE_MASTERMANAGER_H

#ifndef MG_CORE_COMMON_H_
#include "common.h"
#endif

namespace mg
{
namespace core
{
class MasterManager
{
public:
    MasterManager()
    :module_initialized_(false)
    {
        initstr_.clear();
    }

    virtual ~MasterManager()
    {
        initstr_.clear();
        module_initialized_ = false;
    }

    bool module_initialized_;

    virtual std::wstring getString() const { return initstr_; }

protected:
    std::wstring initstr_;
};
}    // end of core namespace
}    // end of mg namespace
#endif