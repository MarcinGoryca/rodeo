/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
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
//#ifndef LAURA_RENDERER_HEIGHTMAP_H_
//#define LAURA_RENDERER_HEIGHTMAP_H_
//
//#include "core\constants.h"
//#include "core\error.h"
//#include "..\common\glheader.h"
//
//namespace laura
//{
//namespace renderer
//{
//struct Heightmap
//{
//    unsigned char* _data;
//    unsigned int _size;
//};
//
////class Heightmap
////{
////public:
////	Heightmap()
////		:height(0), width(0), heightRatio(0.0f)
////	{
////		//mapSize = width * height;
////	}
////	~Heightmap(){}
////	const char* filename;
////
////	ucp hmapData;
////
////	void Load(const char* filename, int size, ucp heightmap);
////
////	int GetWidth()const { return width; }
////	int GetHeight()const { return height; } 
////	int GetQuadSize()const { return quadSize; }
////	float GetHeightRatio()const{ return heightRatio; }
////	
////	void SetMap(int w, int h);
////
////	int width;
////	int height;
////
////	int Height(ucp heightmap, int x, int y);
////	void SetColor(ucp heightmap, int x, int y);
////
////	void Render(uc heightmap[]);
////
////	//static const unsigned char MAP_SIZE;
////
////private:
////	FILE* file;
////	
////	static const int quadSize = 16;
////	static const int mapsize1024 = 1024;
////	float heightRatio;
////};
//}    // end of renderer namespace
//}    // end of laura namespace
//#endif