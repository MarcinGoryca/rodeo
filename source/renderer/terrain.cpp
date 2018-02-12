/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
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
