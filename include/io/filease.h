/*
-----------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_IO_FILEASE_H_
#define MONA_IO_FILEASE_H_

#ifndef MONA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef MONA_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MONA_ENTITY_MESH_H_
#include "entity\mesh.h"
#endif

#ifndef MONA_IO_LOG_H_
#include "io\log.h"
#endif

#ifndef MONA_IO_IMPORTER_H_
#include "io\importer.h"
#endif

namespace mona 
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
    static const int _S_MAX_BUFFER = 5000;
    char _buffer[_S_MAX_BUFFER];

private:
    static const char* const _S_ASE_STRING;
    static const char* const _S_SCENE_STRING;
    
    HANDLE _file;
};
}
}
#endif