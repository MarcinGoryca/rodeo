/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "io\importer.h"
#include "io\file3Dfactory.h"

namespace mg
{
namespace io
{
Importer* File3DFactory::create(File3DType type)
{
    Importer* importer = NULL;

    switch(type)
    {
    case MG_FILE_3DS:
        {
            importer = new File3DS;
            break;
        }

    case MG_FILE_FBX:
        {
            //importer = new FileFBX;
            break;
        }

    default:
        importer = NULL;
    }

    return importer;
}
}    // end of io namespace
}    // end of mg namespace