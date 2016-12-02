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
//#ifndef RODEO_RENDERER_OBJECT_3D_H_
//#define RODEO_RENDERER_OBJECT_3D_H_
////
//#include "renderer\model3d.h"
//#include "core\entity.h"
//
//namespace enginerenderer
//{
//class Object3D : public enginecore::Entity
//{
//public:
//	Object3D();
//	Object3D(const char* filename);
//	~Object3D(){}
//
//	void update();
//	void update(float x, float y, float z);
//	virtual void draw();
//	virtual void scale(float scale_factor);
//	void load(const char* filename);
//	void load();
//	const char* getFile()const { return file_; }
//	Model3D& getModel() { return model3d_; }
//
//	virtual void setPosition(float px, float py, float pz);
//	virtual void setColor(Colors& rgb);
//
//	void setTexture(const char* texture_filename);
//	//enginecore::TextureManager texturelaurar_;
//protected:	
//	Model3D model3d_;
//	const char* file_;
//
//	const char* texture_filename_;
//
//	ui texture_id_;
//};
//}
//
//#endif	//RODEO_RENDERER_OBJECT_3D_H_