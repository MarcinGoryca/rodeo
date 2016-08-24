///*
// * -------------------------------------
// *    Rodeo Game Engine
// *    Rodeo IO Module
// *    FileFBX.h - header file
// *    Copyright(C) Marcin Goryca
// * -------------------------------------
// */
//#ifndef RODEO_IO_FILEFBX_H_
//#define RODEO_IO_FILEFBX_H_
////#pragma comment(lib, "libs/fbxsdk-2013.2.lib")
//
//#ifndef RODEO_IO_IMPORTER_H_
//#include "io\importer.h"
//#endif
//
//#ifndef RODEO_CORE_ERROR_H_
//#include "core\error.h"
//#endif
//
//#include <fbxsdk.h>
//
//namespace engineio
//{
//class FileFBX : public Importer
//{
//public: 
//    FileFBX()
//    :classname_("FileFBX")
//    {}
//
//    virtual ~FileFBX(){}
//
//    virtual bool import(const char* filename);
//
//    virtual const std::string& getClassName()const { return classname_; }
//
//private:
//    void readFile(FbxScene* scene);
//    void readContent(FbxNode* node);
//    void readMesh(FbxNode* node);
//    void readMarker(FbxNode* node);
//    void readSkeleton(FbxNode* node);
//    void readNurbs(FbxNode* node);
//    void readPatch(FbxNode* node);
//    void readCamera(FbxNode* node);
//    void readLight(FbxNode* node);
//    void readLODGroup(FbxNode* node);
//    void readstring(const char* header, const char* value, const char* suffix);
//
//// ---- < MEMBERS > ---- //
//    FbxManager* fbx_monar_;
//    FbxNode* node_;
//    std::string classname_;
//};
//}    //end of engineio namespace
//#endif //RODEO_IO_FILEFBX_H_