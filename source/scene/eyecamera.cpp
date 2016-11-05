///**
//==================================
//	{EyeCamera.cpp}
//	Rodeo Game Engine source file
//	Copyright(c) 2010-2011 Marcin Goryca
//	http://rodeo.lauradev.pl
//==================================
//*/
//#include "scene\eyecamera.h"
//
//using namespace enginecore;
//using namespace engineio;
//using namespace enginemath;
//
//namespace enginerenderer
//{
//void EyeCamera::setRotation(float x, float y, float z)
//{
//	rotatex_ = x;
//	rotatey_ = y;
//	rotatez_ = z;
//
//	recalcAxes();
//}
////------------------------------------------------------------------------------------------------------------------
//void EyeCamera::getRotation(float* x, float* y, float* z)const
//{
//	if(*x)* x = rotatex_;
//	if(*y)* y = rotatey_;
//	if(*z)* z = rotatez_;
//}
////-------------------------------------------------------------------------------------------------------------------
//void EyeCamera::recalcAxes()
//{
//	Matrix4 mat;
//
//	if(rotatey_ > RODEO_TWOPI)
//	{
//		rotatey_ -= RODEO_TWOPI;	
//	}
//	else if(rotatey_ < - RODEO_TWOPI)
//	{
//		rotatey_ += RODEO_TWOPI;
//	}
////1.4f == 80 degrees
////Prevent from Gimbal Lock
//	if(rotatex_ > 1.4f)
//	{
//		rotatex_ = 1.4f;
//	}
//	else if(rotatex_ < -1.4f)
//	{
//		rotatex_ = - 1.4f;
//	}
//
//	//right_ = Vector3(1.0f, 0.0f, 0.0f);
//	//up_ = Vector3(0.0f, 1.0f, 0.0f);
//	//direction_ = Vector3(0.0f, 0.0f, 1.0f);
//
//	//Rotate around y-axis
//	//mat.RotArbi(up, rotateY)
//	//right = right * mat;
//	//direction = direction * mat;
//
//	//RotateAround x- axis
//	//mat.RotArbi(right, rotateX)
//	//up = up * mat;
//	//direction = direction * mat;
//
//	//Correct rounding errors
//	//direction.Normalize();
//	//right.Cross(up, direction);
//	//right.Normalize();
//	//up.Cross(direction, right);
//	//up.Normalize();
//}
////-------------------------------------------------------------------------------------------------------------------
//void EyeCamera::look(float px, float py, float pz, float vx, float vy, float vz, float ux, float uy, float uz)
//{
//	
//}
////--------------------------------------------------------------------------------------------------------------------
////void EyeCamera::update(float elapsedTime)
////{
////}
////---------------------------------------------------------------------------------------------------------------------
//void EyeCamera::init()
//{
//	position_.x_ = 0.0f;
//	position_.y_ = 0.0f;
//	position_.z_ = 10.0f;
//
//	view_.x_ = 0.0f;
//	view_.y_ = 0.0f;
//	view_.z_ = 0.0f;
//	
//	up_.x_ = 0.0f;
//	up_.y_ = 1.0f;
//	up_.z_ = 0.0f;
//}
////---------------------------------------------------------------------------------------------------------------------
//void EyeCamera::onKeydown(KeyMap key)
//{
//	switch(key)
//	{
//	case VK_LEFT:
//		{
//			//Rotate(-0.02f, 0.0f, 1.0f, 0.0f);
//
//			//RotateAroundPoint(view, 0.01f, 1.0f, 0.0f, 0.0f);
//			//Move(0.2f);
//			strafe(0.01f);
//		}
//		break;
//
//	case VK_RIGHT:
//		{
//			//Rotate(0.01f, 0.0f, 1.0f, 0.0f);
//			strafe(-0.01f);
//		}
//		break;
//
//	case VK_UP:
//		{
//			move(0.1f);
//		}
//		break;
//
//	case VK_DOWN:
//		{
//			move(-0.1f);
//		}
//		break;
//
//		}
//}
////-----------------------------------------------------------------------------------------------
//void EyeCamera::rotate(float angle, float x, float y, float z)
//{
//	Vector3 newView;
//	Vector3 tempView;
//
//	tempView.x_ = view_.x_ - position_.x_;
//	tempView.y_ = view_.y_ - position_.y_;
//	tempView.z_ = view_.z_ - position_.z_;
//
//	float cosine = static_cast<float>(::cos(angle));
//	float sine = static_cast<float>(::sin(angle));
//
//	newView.x_ = (cosine + (1 - cosine) * x * x) * tempView.x_;
//	newView.x_ += ((1 - cosine) * x * y - z * sine)	* tempView.y_;
//	newView.x_ += ((1 - cosine) * x * z + y * sine)	* tempView.z_;
//
//	newView.y_  = ((1 - cosine) * x * y + z * sine)	* tempView.x_;
//	newView.y_ += (cosine + (1 - cosine) * y * y)		* tempView.y_;
//	newView.y_ += ((1 - cosine) * y * z - x * sine)	* tempView.z_;
//
//	newView.z_  = ((1 - cosine) * x * z - y * sine)	* tempView.x_;
//	newView.z_ += ((1 - cosine) * y * z + x * sine)	* tempView.y_;
//	newView.z_ += (cosine + (1 - cosine) * z * z) * tempView.z_;
//
//	view_ = position_ + newView;
//}
////----------------------------------------------------------------------------------------------
//void EyeCamera::move(float speed)
//{
//	Vector3 tempView;
//
//	tempView.x_ = view_.x_ - position_.x_;
//	tempView.y_ = view_.y_ - position_.y_;
//	tempView.z_ = view_.z_ - position_.z_;
//
//	position_.x_ += tempView.x_ * speed;
//	position_.z_ += tempView.z_ * speed;
//
//	view_.x_ += tempView.x_ * speed;
//	view_.z_ += tempView.z_ * speed;
//}
////------------------------------------------------------------------------------------------------
//void EyeCamera::rotateAroundPoint(Vector3 center, float speed, float x, float y, float z)
//{
//	Vector3 newPosition;
//	Vector3 tempPosition = position_ - center;
//
//	float cosine = static_cast<float>(::cos(speed));
//	float sine = static_cast<float>(::sin(speed));
//
//	newPosition.x_  = (cosine + (1 - cosine) * x * x) * tempPosition.x_;
//	newPosition.x_ += ((1 - cosine) * x * y - z * sine)	* tempPosition.y_;
//	newPosition.x_ += ((1 - cosine) * x * z + y * sine)	* tempPosition.z_;
//
//	newPosition.y_  = ((1 - cosine) * x * y + z * sine)	* tempPosition.x_;
//	newPosition.y_ += (cosine + (1 - cosine) * y * y) * tempPosition.y_;
//	newPosition.y_ += ((1 - cosine) * y * z - x * sine)	* tempPosition.z_;
//
//	newPosition.z_  = ((1 - cosine) * x * z - y * sine)	* tempPosition.x_;
//	newPosition.z_ += ((1 - cosine) * y * z + x * sine)	* tempPosition.y_;
//	newPosition.z_ += (cosine + (1 - cosine) * z * z) * tempPosition.z_;
//
//	position_ = center + newPosition;
//}
////---------------------------------------------------------------------------------------------
//bool EyeCamera::mouseLook(int w, int h)
//{
//	POINT mousePosition;
//
//	int middlex = w /2;
//	int middley = h /2;
//
//	float angley = 0.0f;
//	float anglez = 0.0f;
//
//	static float currentRotationX = 0.0f;
//
//	GetCursorPos(&mousePosition);
//
//	ShowCursor(false);
//
//	if((mousePosition.x == middlex) && (mousePosition.y == middley)) return true;
//
//	SetCursorPos(middlex, middley);
//
//	angley = static_cast<float>((middlex - mousePosition.x) / 1000.0f);
//	anglez = static_cast<float>((middley - mousePosition.y) / 1000.0f);
//
//	static float s_last_rotationx = 0.0f;
//
//	s_last_rotationx = currentRotationX;
//
//	currentRotationX += anglez;
//
//	if(currentRotationX > 1.0f)
//	{
//		currentRotationX = 1.0f;
//
//		if(s_last_rotationx != 1.0f)
//		{
//			Vector3 axis;
//			Vector3 product = view_ - position_;
//			axis = axis.cross(product, up_);
//			axis.normalize();
//
//			rotate(1.0f - s_last_rotationx, axis.x_, axis.y_, axis.z_);
//		}
//	}
//	else if(currentRotationX < -1.0f)
//	{
//		currentRotationX = -1.0f;
//
//		if(s_last_rotationx != -1.0f)
//		{
//			Vector3 axis;
//			Vector3 product = view_ - position_;
//			axis = axis.cross(product, up_);
//			axis.normalize();
//
//			rotate(-1.0f - s_last_rotationx, axis.x_, axis.y_, axis.z_);
//		}
//	}
//	else
//	{
//		Vector3 axis;
//		Vector3 product = view_ - position_;
//		axis = axis.cross(product, up_);
//		axis.normalize();
//		rotate(anglez, axis.x_, axis.y_, axis.z_);
//	}
//
//	rotate(angley, 0.0f, 1.0f, 0.0f);
//	return true;
//}
//
////--------------------------------------------------------------------------------------------
//void EyeCamera::strafe(float speed)
//{
//	/*position_.x_ += strafe_.x_ * speed;
//	position_.z_ += strafe_.z_ * speed;
//
//	view_.x_ += strafe_.x_ * speed;
//	view_.z_ += strafe_.z_ * speed;*/
//}
//
////--------------------------------------------------------------------------------------------------
//void EyeCamera::look()
//{
//	gluLookAt(position_.x_, position_.y_, position_.z_,
//		      view_.x_, view_.y_, view_.z_,
//			  up_.x_, up_.y_, up_.z_);
//}
//}