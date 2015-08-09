/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "..\include\io\file3ds.h"

using namespace std;
using namespace mg::core;
using namespace mg::math;
using namespace mg::renderer;

//================================================================
//	3DS LOADER	BASED ON GAME TUTORIALS BY BEN HUMPHREY
//================================================================

namespace mg
{
namespace io
{
bool File3DS::import(const char* filename)
{
//TODO:	Implement Rodeo3DSException!
    try
    {
        LPWSTR temp = 0;
        MultiByteToWideChar(0, 0, filename, 0, temp, 0);
        LPCWSTR t = temp;
        file_ = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if(file_ == INVALID_HANDLE_VALUE)
            throw -1;
    }
    catch(...)
    {
        MessageBox(NULL, FILE3DS_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }

    Chunk currentChunk = {0};

    readHeaderChunk(currentChunk);

//TODO:
//Compute Normals in this place
    CloseHandle(file_);
    return true;
}

//................................//
void File3DS::readHeaderChunk(Chunk& chunk)
{
// 1. Get Header Chunk (6 bytes)
//	  It's 0x4D4D	
    DWORD bytesRead = 0;
    ReadFile(file_, &chunk.id_, 2, &bytesRead, NULL);

    chunk.bytesread_ += bytesRead;

    if(chunk.id_ != MAIN3DS)
    {
        MessageBox(NULL, FILE3DS_ERROR.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return;
    }
    else
    {
        ReadFile(file_, &chunk.length_, 4, &bytesRead, NULL);
        chunk.bytesread_ += bytesRead;
    }
// 2. Get Version Chunk (10 bytes)
//	  It's 0x0002
    readVersionChunk(chunk);
// 3. Get Next Chunks containing real data
    readNextChunk(chunk);
}

//...................................//
void File3DS::readVersionChunk(Chunk& chunk)
{
//Read Chunks while we get to the end
//Version Chunk Id == 2
//Version Chunk Length == 10 bytes
    Chunk currentChunk = {0};
    //Chunk tempChunk = {0};

    while(chunk.bytesread_ < chunk.length_)
    {
        readChunk(currentChunk);

        if(currentChunk.id_ == VERSION)
        {
            skipChunk(currentChunk);
        }
        break;
    }
    chunk.bytesread_ += currentChunk.bytesread_;
}

//........................................//
void File3DS::readChunk(Chunk& chunk)
{
    DWORD bytesRead = 0;

    ReadFile(file_, &chunk.id_, 2, &bytesRead, NULL);

    chunk.bytesread_ = bytesRead;

    ReadFile(file_, &chunk.length_, 4, &bytesRead, NULL);

    chunk.bytesread_ += bytesRead;
}

//.......................................//
ui File3DS::skipChunk(Chunk& chunk)
{
    DWORD bytesRead = 0;
    ReadFile(file_, buffer_, chunk.length_ - chunk.bytesread_, &bytesRead, NULL);
    chunk.bytesread_ += bytesRead;
    return chunk.bytesread_;
}

//.........................................//
void File3DS::readNextChunk(Chunk& chunk)
{
    Chunk currentChunk = {0};
    Chunk tempChunk = {0};
    entity::MeshMaterial newMaterial = {0};
    entity::Mesh mesh;
    //memset(&modelB, 0, sizeof(Model));
    ZeroMemory(&mesh, sizeof(mesh));

    //Model* tempModel = new Model;

    while(chunk.bytesread_ < chunk.length_)
    {
        readChunk(currentChunk);

        switch(currentChunk.id_)
        {
// 4. This Chunk (id == 0x3D3D) Contains Next Chunks with important data
        case EDITOR:
            {
                DWORD bytesRead = 0;
                readChunk(tempChunk);

                ReadFile(file_, buffer_, tempChunk.length_ - tempChunk.bytesread_, &bytesRead, NULL);

                tempChunk.bytesread_ += bytesRead;
                currentChunk.bytesread_ += tempChunk.bytesread_;

                readNextChunk(currentChunk);
            }
            break;
// 5. This Chunk (id == 0x4000) Contains Mesh Data, Vertices, Faces
        case MESH:
            {
// We found objects in this chunk, let's counting them
// Then we add those objects (if > 0) to master object
// We must read mesh name, e.g. "Box01", which is set in 3ds Max
                //modelB.meshCount++;
                model_->mesh_count_++;
                model_->mesh_.push_back(mesh);

                //memset(&model.mesh, 0, sizeof(Mesh));

                currentChunk.bytesread_ += getString(model_->mesh_[model_->mesh_count_ - 1].meshname_);

                readMeshChunk(model_->mesh_[model_->mesh_count_ - 1], currentChunk);
            }
            break;

//5. This Chunk (id == 0xAFFF) Contains Material Data	
        case MATERIAL:
            {
// We found material objects, count them
// Add any found material object to our model
                
                model_->material_count_++;
                model_->material_.push_back(newMaterial);

                readMaterialChunk(model_->material_[model_->material_count_-1], currentChunk);
                
            }
            break;

        default:
            {
                skipChunk(currentChunk);
            }
            break;
        }

        chunk.bytesread_ += currentChunk.bytesread_;
    }
}

//..........................................//
void File3DS::readMeshChunk(entity::Mesh& model, Chunk& chunk)
{
    Chunk currentChunk = {0};

    while(chunk.bytesread_ < chunk.length_)
    {
        readChunk(currentChunk);

        switch(currentChunk.id_)
        {	
// 6. This chunk (id == 0x4100) holds triangle data
        case TRIANGLE_POLYGON_MESH:
            {
                readMeshChunk(model, currentChunk);
            }
            break;
// 7. This chunk (id == 0x4110) has vertex data, very important
        case VERTEX_LIST:
            {
                readVertexList(model, currentChunk);
            }
            break;
//8. This chunk (id == 0x4120) contains face data, indices
        case FACE_LIST:
            {
                readFaceList(model, currentChunk);
            }
            break;
//9. This chunk (id == 0x4130) contains information about materials
        case FACE_MATERIAL:
            {
                readFaceMaterial(model, currentChunk);
            }
            break;
// 10. This chunk (id == 0x4140) has uv coordinates		
        case UVMAPPING:
            {
                readUVMapping(model, currentChunk);
            }
            break;

        default:
            {
                skipChunk(currentChunk);
            }
        }
        chunk.bytesread_ += currentChunk.bytesread_;
    }
}

//...........................................//
int File3DS::getString(char* str)
{
    int offset = 0;
    DWORD bytesRead = 0;

    ReadFile(file_, str, 1, &bytesRead, NULL);
//We read string for object name or material name
    while(*(str + offset++) != 0)
    {
        ReadFile(file_, str + offset, 1, &bytesRead, NULL);
    }
    return strlen(str) + 1;
}

//..........................................//
void File3DS::readVertexList(entity::Mesh& m, Chunk& chunk)
{
    DWORD bytesRead = 0;

    ReadFile(file_, &(m.vertex_count_), 2, &bytesRead, NULL);

    chunk.bytesread_ += bytesRead;

//Allocate memory for vertex data
    m.vertex_ = new entity::MeshVertex[m.vertex_count_];

//Zero the memory
    ZeroMemory(m.vertex_, sizeof(m.vertex_) * m.vertex_count_);
//Actual read the vertex data, after that we have vertex list in memory
    ReadFile(file_, m.vertex_, chunk.length_ - chunk.bytesread_, &bytesRead, NULL);

    chunk.bytesread_ += bytesRead;
//Now important thing to do, 3ds Max has Z vector pointing UP, so we must flip it with Y vector
//In FBX export dialog box there is option to flip it automatically
    for(ui i=0; i < m.vertex_count_; ++i)
    {
        float temp = m.vertex_[i].vertex_.y_;
        m.vertex_[i].vertex_.y_ = m.vertex_[i].vertex_.z_;
        m.vertex_[i].vertex_.z_ = -temp;
    }
}

//........................................//
void File3DS::readFaceList(entity::Mesh& m, Chunk& chunk)
{
    us index = 0;
    DWORD bytesRead = 0;
// Here we read face data 
// First we count them by reading header 
    ReadFile(file_, &(m.face_count_), 2, &bytesRead, NULL);

    chunk.bytesread_ += bytesRead;

// Allocate new face data
    m.triangle_ = new entity::MeshTriangle[m.face_count_];
    m.normal_ = new entity::MeshNormal;
    
    ZeroMemory(m.triangle_, sizeof(m.triangle_) * m.face_count_);

// Reading all faces 
// 3ds max has 4 values for indices, 4th value is visibility flag, we skip it
    for(ui i=0; i < m.face_count_; ++i)
    {
        for(ui j=0; j < 4; ++j)
        {
            ReadFile(file_, &index, 2, &bytesRead, NULL);
            chunk.bytesread_ += bytesRead;

            if(j < 3)
            {
                m.triangle_[i].triangle_[j] = index;
            }
        }
    }
//Computing Triangle Normals
}

//............................................//
void File3DS::readFaceMaterial(entity::Mesh& m, Chunk& chunk)
{
    char materialName[255] = {0};

    chunk.bytesread_ += getString(materialName);

    for(ui i=0; i < model_->material_count_; ++i)
    {
// Here we check if the read material name equals texture name
        if(strcmp(materialName, model_->material_[i].name_) == 0)
        {
// Now we check if this is a texture map, if string is greater than 0 it's texture from file
            if(strlen(model_->material_[i].file_) > 0)
            {
                m.material_id_ = i;
                m.has_texture_ = true;
            }
            break;
        }
        else
        {
            if(m.has_texture_ != true)
            {
                m.material_id_ = -1;
            }
        }
    }

    DWORD bytesRead = 0;
    ReadFile(file_, buffer_, chunk.length_ - chunk.bytesread_, &bytesRead, NULL);

    chunk.bytesread_ += bytesRead;
}

//.....................................//
void File3DS::readMaterialChunk(entity::MeshMaterial& mat, Chunk& chunk)
{
    Chunk currentChunk = {0};

    while(chunk.bytesread_ < chunk.length_)
    {
        readChunk(currentChunk);

        switch(currentChunk.id_)
        {
        case MATERIAL_NAME:
            {
                DWORD bytesRead = 0;
                ReadFile(file_, mat.name_, currentChunk.length_ - currentChunk.bytesread_, &bytesRead, NULL);
                currentChunk.bytesread_ += bytesRead;
            }
            break;

        case MATERIAL_DIFFUSE:
            {
                readColorChunk(mat, currentChunk);
            }
            break;

        case MATERIAL_TEXTURE_MAP:
            {
                readMaterialChunk(mat, currentChunk);
            }
            break;

        case MATERIAL_TEXTURE_FILENAME:
            {
                DWORD bytesRead = 0;
                ReadFile(file_, mat.file_, currentChunk.length_ - currentChunk.bytesread_, &bytesRead, NULL);
                currentChunk.bytesread_ += bytesRead;
            }
            break;

        default:
            {
                skipChunk(currentChunk);
            }
            break;
        }

        chunk.bytesread_ += currentChunk.bytesread_;
    }
}

//.........................................//
void File3DS::readColorChunk(entity::MeshMaterial& material, Chunk& chunk)
{
    Chunk tempChunk = {0};
    readChunk(tempChunk);

    DWORD bytesRead = 0;
    ReadFile(file_, material.color_, tempChunk.length_ - tempChunk.bytesread_, &bytesRead, NULL);

    tempChunk.bytesread_ += bytesRead;

    chunk.bytesread_ += tempChunk.bytesread_;
}

//..........................................//
void File3DS::readUVMapping(entity::Mesh& m, Chunk& chunk)
{
    DWORD bytesRead = 0;
    
    ReadFile(file_, &(m.uv_count_), 2, &bytesRead, NULL);
    
    chunk.bytesread_ += bytesRead;

    m.coordinate_ = new entity::MeshUV[m.uv_count_];

    ZeroMemory(m.coordinate_, sizeof(m.coordinate_) * m.uv_count_);

    ReadFile(file_, m.coordinate_, chunk.length_ - chunk.bytesread_, &bytesRead, NULL);

    chunk.bytesread_ += bytesRead;
}

//.........................................//
bool File3DS::release()
{
    return true;
}
}    // end of io namespace
}    // end of mg namespace