/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_FILE3DS_H_
#define MG_IO_FILE3DS_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_IO_IMPORTER_H_
#include "io\importer.h"
#endif

#ifndef MG_IO_LOG_H_
#include "io\log.h"
#endif

#ifndef MG_MATH_MATRIX4_H_
#include "math\matrix4.h"
#endif

#ifndef MG_MATH_VECTOR2_H_
#include "math\vector2.h"
#endif

#ifndef MG_RENDERER_COLORS_H_
#include "renderer\colors.h"
#endif

namespace mg
{
namespace io
{
// ---- < Chunk > ---- //
struct Chunk
{
    core::us id_;
    core::ui length_; 
    core::ui bytesread_;
};

class File3DS : public Importer
{
public:
    File3DS()
        :file_(NULL),
         classname_("File3DS")
    {}
    virtual ~File3DS(){}

    virtual bool import(const char* filename);

    virtual const std::string& getClassName()const { return classname_; }

private:
    bool release();

    void readHeaderChunk(Chunk& chunk);
    void readVersionChunk(Chunk& chunk);
    void readChunk(Chunk& chunk);
    core::ui skipChunk(Chunk& chunk);
    void readNextChunk(Chunk& chunk);

    void readMeshChunk(entity::Mesh& m, Chunk& c);
    void readMaterialChunk(entity::MeshMaterial& mat, Chunk& c);

    int getString(char* str);

    void readVertexList(entity::Mesh& m, Chunk& c);
    void readFaceList(entity::Mesh& m, Chunk& c);
    void readUVMapping(entity::Mesh& m, Chunk& c);

    void readFaceMaterial(entity::Mesh& m, Chunk& chunk);
    void readColorChunk(entity::MeshMaterial& mat, Chunk& c);

    // Maximum number of chars in the buffer
    static const int BUFFER_MAX = 500000;
    HANDLE file_;
    DWORD bytesread_;
    char buffer_[BUFFER_MAX];
    std::string classname_;
};
}    // end of io namespace
}    // end of mg namespace
#endif