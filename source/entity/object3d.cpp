//#include "renderer\object3D.h"
//
//using namespace engineio;
//using namespace enginerenderer;
//using namespace enginemath;
//using namespace enginecore;
//
//Object3D::Object3D()
//:file_(NULL)
//{
//	setType("Model3D");
//	renderable_ = true;
//	has_color_ = true;
//}
//
//Object3D::Object3D(const char* filename)
//:file_(filename)
//{
//	setType("Model3D");
//	renderable_ = true;
//	model3d_.load(filename);
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::draw()
//{
//	//textureMgr_.bind(textureMgr_.texture_id_[0]);
//	model3d_.render();
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::load(const char* filename)
//{
//	model3d_.load(filename);
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::load()
//{
//	if(getFile() == NULL)
//	{
//		MessageBox(NULL, loadFail, HEADER, errIconOK);
//		return;
//	}
//	else
//	{
//		model3d_.load(getFile());
//	}
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::update(float x, float y, float z)
//{
//	glTranslatef(x, y, z);
//
//	model3d_.render();
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::update()
//{
//	model3d_.render();
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::scale(float scale_factor)
//{
//	model3d_.scale(scale_factor);
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::setPosition(float px, float py, float pz)
//{
//	/*world_.m4_[12] = px;
//	world_.m4_[13] = py;
//	world_.m4_[14] = pz;
//	
//	last_position_.x_ = world_.m4_[12];
//	last_position_.y_ = world_.m4_[13];
//	last_position_.z_ = world_.m4_[14];
//
//	glTranslatef(world_.m4_[12], world_.m4_[13], world_.m4_[14]);*/
//}
////-----------------------------------------------------------------------------------------------------------------------
//void Object3D::setColor(Colors& rgb)
//{
//	/*material_.setAmbient(rgb.r_, rgb.g_, rgb.b_, 1.0f);
//	material_.setSpecular(rgb.r_, rgb.g_, rgb.b_, 1.0f);
//	material_.setDiffuse(rgb.r_, rgb.g_, rgb.b_, 1.0f);
//
//	material_.setShininess(50.0f);
//
//	glMaterialfv(GL_FRONT, GL_SPECULAR, material_.getSpecular());
//	glMaterialfv(GL_FRONT, GL_AMBIENT, material_.getAmbient());
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_.getDiffuse());
//	glMaterialfv(GL_FRONT, GL_SHININESS, material_.getShininess());*/
//}
////---------------------------------------------------------------------
//void Object3D::setTexture(const char* texture_filename)
//{
//	texture_filename_ = texture_filename;
//	texture_id_ = 1;
//}