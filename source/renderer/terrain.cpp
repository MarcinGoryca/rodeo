/*
----------------------------------------------
    JENNIE Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
//#include "scene\terrain.h"
//
//using namespace jenniescene;
//using namespace jenniecore;
//
//
//bool Terrain::load(const char* filename, int sz)
//{
//	FILE* file = NULL;
//	
//	fopen_s(&file, filename, "rb");
//
//	if(hmap_.data_)
//	{
//		unload();
//	}
//
////Allocate memory
//	hmap_.data_ = new uc[sz * sz];
//
//	if(hmap_.data_ == NULL)
//	{
//		MessageBox(NULL, AllocateMemoryFail, HEADER, errIconOK);
//		return false;
//	}
//
//	fread(hmap_.data_, 1, sz*sz, file);
//	fclose(file);
//
//	hmap_.size_ = sz;
//
//	size_ = hmap_.size_;
//
//	return true;
//}
//
//
//bool Terrain::unload()
//{
//	if(hmap_.data_)
//	{
//		delete [] hmap_.data_;
//		hmap_.size_ = 0;
//	}
//	return true;
//}
