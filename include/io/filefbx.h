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
//
//#include <fbx\fbxsdk.h>
//
//namespace rodeo {
//    namespace io {
//        class FileFBX : public Importer
//        {
//        public:
//            FileFBX()
//                :classname_("FileFBX")
//            {
//            }
//
//            virtual ~FileFBX() {}
//
//            virtual bool import(const char* filename);
//
//            virtual const std::string& getClassName()const { return classname_; }
//
//        private:
//            void readFile(FbxScene* scene);
//            void readContent(FbxNode* node);
//            void readMesh(FbxNode* node);
//            void readMarker(FbxNode* node);
//            void readSkeleton(FbxNode* node);
//            void readNurbs(FbxNode* node);
//            void readPatch(FbxNode* node);
//            void readCamera(FbxNode* node);
//            void readLight(FbxNode* node);
//            void readLODGroup(FbxNode* node);
//            void readstring(const char* header, const char* value, const char* suffix);
//
//            // ---- < MEMBERS > ---- //
//            FbxManager* fbx_rodeor_;
//            FbxNode* node_;
//            std::string classname_;
//        };
//    }    //end of engineio namespace
//}
//#endif //RODEO_IO_FILEFBX_H_
