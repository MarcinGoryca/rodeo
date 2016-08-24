/*
-----------------------------------
    mona Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_IO_FILE3DFACTORY_H_
#define MONA_IO_FILE3DFACTORY_H_

#ifndef MONA_IO_FILE3DS_H_
#include "io\file3ds.h"
#endif

#ifndef MONA_IO_FILEFBX_H_
#include "io\filefbx.h"
#endif

namespace mona
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
        MONA_FILE_3DS,
        MONA_FILE_FBX,
		MONA_FILE_OBJ
    };

    static Importer* create(File3DType type);
};
}
}
#endif