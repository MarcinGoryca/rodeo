/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "scene\Camera.h"

using namespace mg::math;
//using namespace core;
//using namespace scene;

namespace mg
{
namespace scene
{
/**
 * Set Camera
 */

void Camera::set(float cam_pos_x, float cam_pos_y, float cam_pos_z, float cam_tgt_x, float cam_tgt_y, float cam_tgt_z, float ux, float uy, float uz)
{
    Vector3 tempPosition = Vector3(cam_pos_x, cam_pos_y, cam_pos_z);
    Vector3 tempTarget = Vector3(cam_tgt_x, cam_tgt_y, cam_tgt_z);
    Vector3 tempUp = Vector3(ux, uy, uz);

    camera_position_ = tempPosition;
    camera_target_ = tempTarget;
    up_ = tempUp;
}

//----------------------------------------------------------------------------------------------------------------------------

//void Camera::setRotation(float x, float y, float z)
//{
//    rotatex_ = x;
//    rotatey_ = y;
//    rotatez_ = z;
//
//    recalcAxes();
//}

//------------------------------------------------------------------------------------------------------------------

//void Camera::getRotation(float* x, float* y, float* z)const
//{
//    if(*x)* x = rotatex_;
//    if(*y)* y = rotatey_;
//    if(*z)* z = rotatez_;
//}

//-------------------------------------------------------------------------------------------------------------------

//void Camera::recalcAxes()
//{
//	Matrix4 matrix;
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
//	right_ = Vector3(1.0f, 0.0f, 0.0f);
//	up_ = Vector3(0.0f, 1.0f, 0.0f);
//	direction_ = Vector3(0.0f, 0.0f, 1.0f);

    //Rotate around y-axis
    //mat.RotArbi(up, rotateY)
    //right = right * mat;
    //direction = direction * mat;

    //RotateAround x- axis
    //mat.RotArbi(right, rotateX)
    //up = up * mat;
    //direction = direction * mat;

    //Correct rounding errors
    //direction.Normalize();
    //right.Cross(up, direction);
    //right.Normalize();
    //up.Cross(direction, right);
    //up.Normalize();
//}

/**
 * -- Look
 */

//void Camera::look(float px, float py, float pz, float vx, float vy, float vz, float ux, float uy, float uz)
//{
//    position_.x_ = px;
//    position_.y_ = py;
//    position_.z_ = pz;
//
//    view_.x_ = vx;
//    view_.y_ = vy;
//    view_.z_ = vz;
//
//    up_.x_ = ux;
//    up_.y_ = uy;
//    up_.z_ = uz;
//
//    /*MouseLook(Window::GetInstance().GetWidth(), Window::GetInstance().GetHeight());*/
//}

//--------------------------------------------------------------------------------------------------------------------
//void Camera::Look()
//{
//	gluLookAt(position.x, position.y, position.z, view.x, view.y, view.z, up.x, up.y, up.z);
//}
//--------------------------------------------------------------------------------------------------------------------
//void Camera::update(float elapsedTime, bool mm)
//{
//	//float delta = elapsedTime;
//	//mm=false;
//	Vector3 cross_product;
//	Vector3 product = view_ - position_;
//
//	cross_product = cross_product.cross(product, up_);
//	cross_product.normalize();
//	strafe_ = cross_product;
//
//	mouseLook(Window::getInstance().getWidth(), Window::getInstance().getHeight());
//	
//	onMovement();
//}

//---------------------------------------------------------------------------------------------------------------------

//void Camera::init()
//{
//    position_.x_ = 0.0f;
//    position_.y_ = 0.0f;
//    position_.z_ = 10.0f;
//
//    view_.x_ = 0.0f;
//    view_.y_ = 0.0f;
//    view_.z_ = 0.0f;
//    
//    up_.x_ = 0.0f;
//    up_.y_ = 1.0f;
//    up_.z_ = 0.0f;
//}

//---------------------------------------------------------------------------------------------------------------------

//void Camera::onKeydown(engineio::KeyMap key)
//{
//    switch(key)
//    {
//    case VK_LEFT:
//        {
//            rotate(-0.02f, 0.0f, 1.0f, 0.0f);
//
//            //RotateAroundPoint(view, 0.01f, 1.0f, 0.0f, 0.0f);
//            //Move(0.2f);
//            strafe(0.01f);
//        }
//        break;
//
//    case VK_RIGHT:
//        {
//            rotate(0.01f, 0.0f, 1.0f, 0.0f);
//            strafe(-0.01f);
//        }
//        break;
//
//    case VK_UP:
//        {
//            move(0.1f);
//        }
//        break;
//
//    case VK_DOWN:
//        {
//            move(-0.1f);
//        }
//        break;
//    }
//}

//-----------------------------------------------------------------------------------------------

//void Camera::rotate(float angle, float x, float y, float z)
//{
//    Vector3 newView;
//    Vector3 tempView;
//
//    tempView.x_ = view_.x_ - position_.x_;
//    tempView.y_ = view_.y_ - position_.y_;
//    tempView.z_ = view_.z_ - position_.z_;
//
//    float cosine = static_cast<float>(::cos(angle));
//    float sine = static_cast<float>(::sin(angle));
//
//    newView.x_ = (cosine + (1 - cosine) * x * x) * tempView.x_;
//    newView.x_ += ((1 - cosine) * x * y - z * sine)	* tempView.y_;
//    newView.x_ += ((1 - cosine) * x * z + y * sine)	* tempView.z_;
//
//    newView.y_  = ((1 - cosine) * x * y + z * sine)	* tempView.x_;
//    newView.y_ += (cosine + (1 - cosine) * y * y)		* tempView.y_;
//    newView.y_ += ((1 - cosine) * y * z - x * sine)	* tempView.z_;
//
//    newView.z_  = ((1 - cosine) * x * z - y * sine)	* tempView.x_;
//    newView.z_ += ((1 - cosine) * y * z + x * sine)	* tempView.y_;
//    newView.z_ += (cosine + (1 - cosine) * z * z) * tempView.z_;
//
//    view_ = position_ + newView;
//}

/**
 * -- Move
 */

void Camera::move(float speed)
{
    Vector3 tempView = camera_target_ - camera_position_;

    tempView.normalize();
    
    camera_position_.x_ += tempView.x_ * speed;
    camera_position_.y_ += tempView.y_ * speed;
    camera_position_.z_ += tempView.z_ * speed;

    camera_target_.x_ += tempView.x_ * speed;
    camera_target_.y_ += tempView.y_ * speed;
    camera_target_.z_ += tempView.z_ * speed;
}

//------------------------------------------------------------------------------------------------

//void Camera::rotateAroundPoint(Vector3 center, float speed, float x, float y, float z)
//{
//    Vector3 newPosition;
//    Vector3 tempPosition = position_ - center;
//
//    float cosine = static_cast<float>(::cos(speed));
//    float sine = static_cast<float>(::sin(speed));
//
//    newPosition.x_  = (cosine + (1 - cosine) * x * x) * tempPosition.x_;
//    newPosition.x_ += ((1 - cosine) * x * y - z * sine)	* tempPosition.y_;
//    newPosition.x_ += ((1 - cosine) * x * z + y * sine)	* tempPosition.z_;
//
//    newPosition.y_  = ((1 - cosine) * x * y + z * sine)	* tempPosition.x_;
//    newPosition.y_ += (cosine + (1 - cosine) * y * y) * tempPosition.y_;
//    newPosition.y_ += ((1 - cosine) * y * z - x * sine)	* tempPosition.z_;
//
//    newPosition.z_ = ((1 - cosine) * x * z - y * sine)	* tempPosition.x_;
//    newPosition.z_ += ((1 - cosine) * y * z + x * sine)	* tempPosition.y_;
//    newPosition.z_ += (cosine + (1 - cosine) * z * z) * tempPosition.z_;
//
//    position_ = center + newPosition;
//}

//---------------------------------------------------------------------------------------------

//bool Camera::mouseLook(int w, int h)
//{
//    POINT mouse_position;
//    POINT current_position;
    //bool mousing = false;
    //int middlex = w /2;
    //int middley = h /2;

    //float angley = 0.0f;
    //float anglez = 0.0f;
    //
    //static float currentRotationX = 0.0f;

    //GetCursorPos(&mouse_position);
    //ScreenToClient(Window::getInstance().getHWND(), &mouse_position);
    //current_position.x = mouse_position.x;
    //current_position.y = mouse_position.y;

    //if((mousePosition.x == middlex) && (mousePosition.y == middley)) return true;

    //SetCursorPos(middlex, middley);

    /*angley = static_cast<float>((middlex - mousePosition.x) / 1000.0f);
    anglez = static_cast<float>((middley - mousePosition.y) / 1000.0f);

    static float lastRotationX = 0.0f;

    lastRotationX = currentRotationX;

    currentRotationX += anglez;

    if(currentRotationX > 1.0f)
    {
        currentRotationX = 1.0f;

        if(lastRotationX != 1.0f)
        {
            Vector3 axis = axis.cross(view_ - position_, up_);
            axis.normalize();

            rotate(1.0f - lastRotationX, axis.x_, axis.y_, axis.z_);
        }
    }
    else if(currentRotationX < -1.0f)
    {
        currentRotationX = -1.0f;

        if(lastRotationX != -1.0f)
        {
            Vector3 axis = axis.cross(view_ - position_, up_);
            axis.normalize();

            rotate(-1.0f - lastRotationX, axis.x_, axis.y_, axis.z_);
        }
    }
    else
    {
        Vector3 axis = axis.cross(view_ - position_, up_);
        axis.normalize();
        rotate(anglez, axis.x_, axis.y_, axis.z_);
    }
    rotate(angley, 0.0f, 1.0f, 0.0f);*/
  /*  return true;
}*/

//--------------------------------------------------------------------------------------------

//void Camera::strafe(float speed)
//{
//    //position_.x_ += strafe_.x_ * speed;
//    //position_.z_ += strafe_.z_ * speed;
//
//    //view_.x_ += strafe_.x_ * speed;
//    //view_.z_ += strafe_.z_ * speed;
//}

//--------------------------------------------------------------------------------------------------
//void Camera::look()
//{
//
//}

//-------------------------------------------------------------------------------------------------------

//void Camera::onMovement()
//{
//	float frame = TimeManager::getInstance().time_.getDelta();
//	
//	float divider = 5;
//
////	float speed = s_staticspeed_ * frame / divider;
//
//	if(GetKeyState(VK_UP) & 0x80 || GetKeyState('W') & 0x80)
//	{
//		move(-speed);
//	}
//	if(GetKeyState(VK_DOWN) & 0x80 || GetKeyState('S') & 0x80)
//	{
//		move(speed);
//	}
//	if(GetKeyState(VK_LEFT) & 0x80 || GetKeyState('A') & 0x80)
//	{
//		strafe(speed);
//	}
//	if(GetKeyState(VK_RIGHT) & 0x80 || GetKeyState('D') & 0x80)
//	{
//		strafe(-speed);
//	}
//}
//--------------------------------------------------------------------------------------------------------
//void Camera::CalcFPS()
//{
//
//}
//-----------------------------------------------------------------------------------------------------------
//void Camera::look(bool ml)
//{
//	Vector3 tp = position_;
//	Vector3 tv = view_;
//	Vector3 tu = up_;
//	if(ml)
//	{
//		position_.x_ += 10.0f;
//		position_.y_ += 10.0f;
//		position_.z_ += 10.0f;
//
//		view_.x_ += 10.0f;
//		view_.y_ += 10.0f;
//		view_.z_ += 10.0f;
//
//		gluLookAt(position_.x_, position_.y_, position_.z_,
//				  view_.x_, view_.y_, view_.z_,
//				  up_.x_, up_.y_, up_.z_);
//	}
//}

/**
 * -- Update
 */

void Camera::update()
{
    /*Vector3 new_position = position_;
    Vector3 new_view = view_;
    Vector3 new_up = up_;

    gluLookAt(new_position.x_, new_position.y_, new_position.z_, new_view.x_, new_view.y_, new_view.z_,
        new_up.x_, new_up.y_, new_up.z_);*/
}

/**
 * -- Render
 */

void Camera::render()
{
//    gluLookAt(getPositionX(), getPositionY(), getPositionZ(), getViewX(), getViewY(), getViewZ(), getUpX(), getUpY(), getUpZ());
}

/**
 * -- Perspective Projection
 */

Matrix4 Camera::perspective(float fov, float n, float f, float aspect)
{
    projection_ = Matrix4::S_IDENTITY_;

    field_of_view_ = fov;
    near_ = n;
    far_ = f;
    aspect_ratio_ = aspect;
    top_ = near_ * ::tan(degreesToRadians(field_of_view_ * 0.5f));;
    bottom_ = -top_;
    left_ = bottom_ * aspect_ratio_;
    right_ = -left_;

    projection_.m4_[0] = (2.0f * near_) / (right_ - left_);
    projection_.m4_[5] = (2.0f * near_) / (top_ - bottom_);
    projection_.m4_[8] = (right_ + left_) / (right_ - left_);
    projection_.m4_[9] = (top_ + bottom_) / (top_ - bottom_);
    projection_.m4_[10] = -((far_ + near_) / (far_ - near_));
    projection_.m4_[11] = -1.0f;
    projection_.m4_[14] = -((2.0f * (far_ * near_)) / (far_ - near_));
    projection_.m4_[15] = 0.0f;
    
    return projection_;
}

/**
 * -- Orthographic Projection
 */

Matrix4 Camera::orthographic(float l, float t, float r, float b, float n, float f)
{
    //enginemath::Matrix4 orthographic_projection;
    projection_.loadIdentity();

    left_ = l;
    top_ = t;
    right_ = r;
    bottom_ = b;
    near_ = n;
    far_ = f;


    projection_.m4_[0] = 2.0f / (right_ - left_);
    projection_.m4_[5] = 2.0f / (top_ - bottom_);
    projection_.m4_[10] = -2.0f / (far_ - near_);
    projection_.m4_[12] = -((right_ + left_) / (right_ - left_));
    projection_.m4_[13] = -((top_ + bottom_) / (top_ - bottom_));
    projection_.m4_[14] = -((far_ + near_) / (far_ - near_));
    projection_.m4_[15] = 1.0f;

    return projection_;
}

/**
* -- Frustum
*/
Matrix4 Camera::frustum(float left, float right, float top, float bottom, float n, float f)
{
    Matrix4 frustum;
    frustum.loadIdentity();

    left_ = left;
    right_ = right;
    top_ = top;
    bottom_ = bottom;
    near_ = n;
    far_ = f;

    frustum.m4_[0] = (2.0f * near_) / (right_ - left_);
    frustum.m4_[5] = (2.0f * near_) / (top_ - bottom_);
    frustum.m4_[8] = (right_ + left_) / (right_ - left_);
    frustum.m4_[9] = (top_ + bottom_) / (top_ - bottom_);
    frustum.m4_[10] = -((far_ + near_) / (far_ - near_));
    frustum.m4_[11] = -1.0f;
    frustum.m4_[14] = -((2.0f * far_ * near_) / (far_ - near_));
    frustum.m4_[15] = 0.0f;

    return frustum;
}

/** 
 * -- lookAt
 */
Matrix4 Camera::lookAt(Vector3 position, Vector3 target, Vector3 up)
{
    camera_position_ = position;
    up_ = up;
    camera_target_ = target;

    Vector3 a = normalize(camera_target_ - camera_position_);

    Vector3 b;
    Vector3::cross(b, a, up);
    Vector3 c;
    Vector3::cross(c, b, a);
    Matrix4 m = Matrix4(Vector4(b.x_, c.x_, -a.x_, 0.0f),
                                              Vector4(b.y_, c.y_, -a.y_, 0.0f),
                                              Vector4(b.z_, c.z_, -a.z_, 0.0f),
                                              Vector4(0.0f, 0.0f, 0.0f, 1.0f));

    Transform t;
    view_ = Matrix4::S_IDENTITY_;
    view_ = m * t.translate(-camera_position_.x_, -camera_position_.y_, -camera_position_.z_);
    return view_;
}
}    // end of scene namespace
}    // end of mg namespace