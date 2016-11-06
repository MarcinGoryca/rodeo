/*
-----------------------------------
    Laura Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef LAURA_IO_FILE3DFACTORY_H_
#define LAURA_IO_FILE3DFACTORY_H_

#ifndef LAURA_IO_FILE3DS_H_
#include "io\file3ds.h"
#endif

#ifndef LAURA_IO_FILEFBX_H_
#include "io\filefbx.h"
#endif

namespace laura
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
        LAURA_FILE_3DS,
        LAURA_FILE_FBX,
		LAURA_FILE_OBJ
    };

    static Importer* create(File3DType type);
};
}
}
#endif