///**
//============================================================================================================================================
//	{Object3D.h}
//	Rodeo Renderer header file
//	Copyright(c)2010-2011 Marcin Goryca
//	http://rodeo.lauradev.pl
//	Rodeo Game Engine Module
//============================================================================================================================================
//*/
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