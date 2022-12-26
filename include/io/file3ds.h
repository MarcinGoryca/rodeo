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
//#ifndef RODEO_IO_FILE3DS_H_
//#define RODEO_IO_FILE3DS_H_
//
//#ifndef RODEO_CORE_ERROR_H_
//#include "core\error.h"
//#endif
//
//#ifndef RODEO_IO_IMPORTER_H_
//#include "io\importer.h"
//#endif
//
//#ifndef RODEO_IO_LOG_H_
//#include "io\log.h"
//#endif
//
//#ifndef RODEO_MATH_MATRIX4_H_
//#include "math\matrix4.h"
//#endif
//
//#ifndef RODEO_MATH_VECTOR2_H_
//#include "math\vector2.h"
//#endif
//
//#ifndef RODEO_RENDERER_COLORS_H_
//#include "renderer\colors.h"
//#endif
//
//namespace rodeo
//{
//namespace io
//{
//	//-----------------------------------
//	// CONSTANTS 3DS (For 3ds Files)
//	//-----------------------------------
//
//	// Every Header in 3DS is 6 bytes long 
//	// 2 bytes ID and 4 bytes length
//
//	// Header of 3DS file
//	// This chunk contains length of whole 3ds file 
//	const int MAIN3DS = 0x4D4D;
//
//	// Editor version 
//	const int VERSION = 0x0002;
//
//	// Editor Config 
//	// Here starts all geometry
//	const int EDITOR = 0x3D3D;
//
//	// Chunk of objects in 3DS file
//	// In this chunk there are objects: cameras, lights, meshes 
//	const int MESH = 0x4000;
//
//	// Materials
//	// Holds information about ambient, diffuse, specular color,\n
//	// texture information, shininess
//	// Chunk 0xAFFF itself contains no data 
//	const int MATERIAL = 0xAFFF;
//
//	// Editor config (unneeded) 
//	const int MESHVERSION = 0x3D3E;
//
//	//--------------
//	//    OBJECT's
//	//--------------
//
//	// Triangular Mesh
//	// There is real data of 3DS file.\n
//	// This chunk holds a mesh containing triangles 
//	const int TRIANGLE_POLYGON_MESH = 0x4100;
//
//	// Mesh Vertices
//	// Contains all information about vertices of a mesh 
//	const int VERTEX_LIST = 0x4110;
//
//	// MeshFaces
//	// Contains the vertex indexes, so the model is solid 
//	const int FACE_LIST = 0x4120;
//
//	// Face Material Info 
//	const int FACE_MATERIAL = 0x4130;
//
//	// Texture Coordinates
//	// Holds  u, v coordinates of textures for every vertex 
//	const int UVMAPPING = 0x4140;
//
//	// Local axis 
//	const int AXIS = 0x4160;
//
//	//----------------
//	//    MATERIAL
//	//----------------
//
//	// Material Name 
//	const int MATERIAL_NAME = 0xA000;
//
//	// Ambient Color
//	// Contains ambient color of the current material.\n
//	// Subchank 0x0011 contains information of color in RGB format. 
//	const int MATERIAL_AMBIENT = 0xA010;
//
//	// Diffuse
//	// same as Ambient Color 
//	const int MATERIAL_DIFFUSE = 0xA020;
//
//	// Specular Color
//	// same as Ambient Color and Diffuse 
//	const int MATERIAL_SPECULAR = 0xA030;
//
//	// Shininess 
//	const int MATERIAL_SHININESS = 0xA040;
//
//	// Transparency 
//	const int MATERIAL_TRANSPARENCY = 0xA050;
//
//	// Texture Map 
//	const int MATERIAL_TEXTURE_MAP = 0xA200;
//
//	// Texture Map Filename 
//	const int MATERIAL_TEXTURE_FILENAME = 0xA300;
//
//	//--------------------
//	//    ANIMATION
//	//--------------------
//
//	// Keyframe data 
//	const int KEYFRAME = 0xB000;
//
//	// Mesh anim data 
//	const int ANIMOBJECT = 0xB002;
//
//	// Number of keyframes 
//	const int FRAMES = 0xB008;
//
//	// Object parameters for animation 
//	const int PARAM = 0xB010;
//
//	// Object pivot point 
//	const int PIVOT = 0xB013;
//
//	// Object hierarchy position 
//	const int HIERARCHY = 0xB030;
//
//	// Track position 
//	const int POSITON = 0xB020;
//
//	// Track rotation 
//	const int ROTATION = 0xB021;
//
//	// Track scale 
//	const int SCALE = 0xB022;
//
//	//------------
//	//    TODO
//	//------------
//
//	const int KFVERSION = 0x0005;
//	const int COLORF = 0x0010;
//	const int COLOR24 = 0x0011;
//	const int LINCOLOR24 = 0x0012;
//	const int LINCOLORF = 0x0013;
//	const int INTPERCENTAGE = 0x0030;
//	const int FLOATPERC = 0x0031;
//	const int MASTERSCALE = 0x0100;
//	const int IMAGEFILE = 0x1100;
//	const int AMBIENTLIGHT = 0x2100;
//	const int VERTEXFLAGS = 0x4111;
//
//	const int MESHCOLORIND = 0x4165;
//	const int MESHTEXTUREINFO = 0x4170;
//	//const int HIERARCHY = 0x4F00;
//	const int MATERIALFALLOFF = 0xA052;
//	const int MATERIALEMMISIVE = 0xA080;
//	const int MATERIALSHADER = 0xA100;
//	const int OBJECTLIGHT = 0x4600;
//	const int OBJECTCAMERA = 0x4700;
//	const int ANIMHEADER = 0xB00A;
//
//
//// ---- < Chunk > ---- //
//struct Chunk
//{
//    unsigned short _id;
//    unsigned int _length; 
//    unsigned int _bytesread;
//};
//
//class File3DS : public Importer
//{
//public:
//    File3DS()
//        :_file(NULL),
//         _classname("File3DS")
//    {}
//    virtual ~File3DS(){}
//
//    virtual bool import(const char* filename);
//
//    virtual const std::string& getClassName()const { return _classname; }
//
//private:
//	// Maximum number of chars in the buffer
//	static const int _S_BUFFER_MAX = 500000;
//	HANDLE _file;
//	DWORD _bytesread;
//	char _buffer[_S_BUFFER_MAX];
//	std::string _classname;
//
//    bool release();
//
//    void readHeaderChunk(Chunk& chunk);
//    void readVersionChunk(Chunk& chunk);
//    void readChunk(Chunk& chunk);
//    unsigned int skipChunk(Chunk& chunk);
//    void readNextChunk(Chunk& chunk);
//
//    void readMeshChunk(entity::Mesh& m, Chunk& c);
//    void readMaterialChunk(entity::MeshMaterial& mat, Chunk& c);
//
//    int getString(char* str);
//
//    void readVertexList(entity::Mesh& m, Chunk& c);
//    void readFaceList(entity::Mesh& m, Chunk& c);
//    void readUVMapping(entity::Mesh& m, Chunk& c);
//
//    void readFaceMaterial(entity::Mesh& m, Chunk& chunk);
//    void readColorChunk(entity::MeshMaterial& mat, Chunk& c);
//};
//}
//}
//#endif