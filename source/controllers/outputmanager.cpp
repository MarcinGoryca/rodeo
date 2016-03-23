/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core/outputmanager.h"

namespace mg
{
namespace core
{

void OutputManager::init()
{
    log_ = NULL;

    initstr_ = L"OutputManager initialized.";

    module_initialized_ = true;

    log_ = new io::Log();
}

//..............................//
void OutputManager::clear()
{
    if(log_ != NULL)
    {
        delete log_;
        log_ = NULL;
    }

    module_initialized_ = false;

    initstr_ = L"OutputManager shutdown...";
}
}    // end of core namespace
}    // end of mg namespace