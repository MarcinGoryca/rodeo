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
//#include "Heightmap.h"
//
//using namespace enginerenderer;
//
////unsigned char Heightmap::MAP_SIZE = width * height;
//
//void Heightmap::Load(const char* filename, int size, ucp heightmap)
//{
//	FILE* file = NULL;
//	fopen_s(&file, filename, "rb"); 
//
//	if(file == NULL)
//	{
//		MessageBox(NULL, "Couldn't load file", HEADER, errIconOK);
//		return;
//	}
//	fread(heightmap, 1, size, file);
//
//	int result = ferror(file);
//
//	if(result)
//	{
//		MessageBox(NULL, "Couldn't Get The Data!", HEADER, errIconOK);
//		return;
//	}
//
//	fclose(file);
//}
////----------------------------------------------------------------------------------------------------------------
//void Heightmap::SetMap(int w, int h)
//{
//	width = w;
//	height = h;
//}
////----------------------------------------------------------------------------------------------------------------
//int Heightmap::Height(ucp heightmap, int x, int y)
//{
//	int x2 = x % mapsize1024;
//	int y2 = y % mapsize1024;
//
//	if(!heightmap) return 0;
//
//	return heightmap[x2 + (y2 * mapsize1024)];
//}
////----------------------------------------------------------------------------------------------------------------
//void Heightmap::SetColor(ucp heightmap, int x, int y)
//{
//	if(!heightmap)return;
//
//	float color = -0.15f + (Height(heightmap, x, y) / 256.0f);
//
//	glColor3f(0, color, 0);
//}
////----------------------------------------------------------------------------------------------------------------
//void Heightmap::Render(uc heightmap[])
//{
//	int x = 0;
//	int y = 0;
//
//	int x1, y1, z1;
//	float color = 0.0f;
//
//	if(!heightmap)return;
//
//	glBegin(GL_QUADS);
//		for(x = 0; x < mapsize1024; x += quadSize)
//		
//			for(y=0; y < mapsize1024; y += quadSize)
//			{
//				x1 = x;
//				y1 = Height(heightmap, x, y);
//				z1 = y;
//
//				SetColor(heightmap, x1, z1);
//
//				glVertex3i(x1, y1, z1);
//
//				x1 = x;
//				y1 = Height(heightmap, x, y+quadSize);
//				z1 = y + quadSize;
//
//				SetColor(heightmap, x1, z1);
//
//				glVertex3i(x1, y1, z1);
//
//				x1 = x + quadSize;
//				y1 = Height(heightmap, x + quadSize, y + quadSize);
//				z1 = y + quadSize;
//
//				SetColor(heightmap, x1, z1);
//
//				glVertex3i(x1, y1, z1);
//
//				x1 = x + quadSize;
//				y1 = Height(heightmap, x + quadSize, y);
//				z1 = y;
//
//				SetColor(heightmap, x1, z1);
//
//				glVertex3i(x1, y1, z1);
//
//
//			
//		}
//	glEnd();
//	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//}
