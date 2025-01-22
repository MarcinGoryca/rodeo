/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
#ifndef RODEO_IO_FILEASE_H_
#define RODEO_IO_FILEASE_H_

#ifndef RODEO_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef RODEO_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef RODEO_ENTITY_MESH_H_
#include "entity\mesh.h"
#endif

#ifndef RODEO_IO_LOG_H_
#include "io\log.h"
#endif

#ifndef RODEO_IO_IMPORTER_H_
#include "io\importer.h"
#endif

namespace rodeo 
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