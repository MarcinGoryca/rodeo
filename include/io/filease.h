/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_FILEASE_H_
#define MG_IO_FILEASE_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_ENTITY_MESH_H_
#include "entity\mesh.h"
#endif

#ifndef MG_IO_LOG_H_
#include "io\log.h"
#endif

#ifndef MG_IO_IMPORTER_H_
#include "io\importer.h"
#endif

namespace mg 
{
namespace io
{
class FileASE : public Importer
{
public:
    FileASE(){}
    ~FileASE(){}
    bool import(const char* filename);
    void release();
    static const int MAX_BUFFER = 5000;
    char buffer_[MAX_BUFFER];

private:
    static const char* const ASE_STRING;
    static const char* const SCENE_STRING;
    
    HANDLE file_;
};
}    // end of io namespace
}    // end of mg namespace
#endif