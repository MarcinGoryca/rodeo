/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_FILE3DFACTORY_H_
#define MG_IO_FILE3DFACTORY_H_

#ifndef MG_IO_FILE3DS_H_
#include "io\file3ds.h"
#endif

#ifndef MG_IO_FILEFBX_H_
#include "io\filefbx.h"
#endif

namespace mg
{
namespace io
{
class Importer;

class File3DFactory
{
public:
    File3DFactory(){}

    virtual ~File3DFactory(){}

    enum File3DType
    {
        MG_FILE_3DS,
        MG_FILE_FBX
    };

    static Importer* create(File3DType type);
};
}    // end of io namespace
}    // end of mg namespace
#endif