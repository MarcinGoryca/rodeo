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
#include "scene\Camera.h"

using namespace rodeo::math;
//using namespace core;
//using namespace scene;

namespace rodeo
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

			_camera_position = tempPosition;
			_camera_target = tempTarget;
			_up = tempUp;
		}

		//----------------------------------------------------------------------------------------------------------------------------

		//void Camera::setRotation(float x, float y, float z)
		//{
		//    rotate_x = x;
		//    rotate_y = y;
		//    rotate_z = z;
		//
		//    recalcAxes();
		//}

		//------------------------------------------------------------------------------------------------------------------

		//void Camera::getRotation(float* x, float* y, float* z)const
		//{
		//    if(*x)* x = rotate_x;
		//    if(*y)* y = rotate_y;
		//    if(*z)* z = rotate_z;
		//}

		//-------------------------------------------------------------------------------------------------------------------

		//void Camera::recalcAxes()
		//{
		//	Matrix4 matrix;
		//
		//	if(rotate_y > RODEO_TWOPI)
		//	{
		//		rotate_y -= RODEO_TWOPI;	
		//	}
		//	else if(rotate_y < - RODEO_TWOPI)
		//	{
		//		rotate_y += RODEO_TWOPI;
		//	}
		////1.4f == 80 degrees
		////Prevent from Gimbal Lock
		//	if(rotate_x > 1.4f)
		//	{
		//		rotate_x = 1.4f;
		//	}
		//	else if(rotate_x < -1.4f)
		//	{
		//		rotate_x = - 1.4f;
		//	}
		//
		//	_right = Vector3(1.0f, 0.0f, 0.0f);
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
		 //    position_._x = px;
		 //    position_._y = py;
		 //    position_._z = pz;
		 //
		 //    view_._x = vx;
		 //    view_._y = vy;
		 //    view_._z = vz;
		 //
		 //    up_._x = ux;
		 //    up_._y = uy;
		 //    up_._z = uz;
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
		 //    position_._x = 0.0f;
		 //    position_._y = 0.0f;
		 //    position_._z = 10.0f;
		 //
		 //    view_._x = 0.0f;
		 //    view_._y = 0.0f;
		 //    view_._z = 0.0f;
		 //    
		 //    up_._x = 0.0f;
		 //    up_._y = 1.0f;
		 //    up_._z = 0.0f;
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
		 //    tempView._x = view_._x - position_._x;
		 //    tempView._y = view_._y - position_._y;
		 //    tempView._z = view_._z - position_._z;
		 //
		 //    float cosine = static_cast<float>(::cos(angle));
		 //    float sine = static_cast<float>(::sin(angle));
		 //
		 //    newView._x = (cosine + (1 - cosine) * x * x) * tempView._x;
		 //    newView._x += ((1 - cosine) * x * y - z * sine)	* tempView._y;
		 //    newView._x += ((1 - cosine) * x * z + y * sine)	* tempView._z;
		 //
		 //    newView._y  = ((1 - cosine) * x * y + z * sine)	* tempView._x;
		 //    newView._y += (cosine + (1 - cosine) * y * y)		* tempView._y;
		 //    newView._y += ((1 - cosine) * y * z - x * sine)	* tempView._z;
		 //
		 //    newView._z  = ((1 - cosine) * x * z - y * sine)	* tempView._x;
		 //    newView._z += ((1 - cosine) * y * z + x * sine)	* tempView._y;
		 //    newView._z += (cosine + (1 - cosine) * z * z) * tempView._z;
		 //
		 //    view_ = position_ + newView;
		 //}

		 /**
		  * -- Move
		  */

		void Camera::move(float speed)
		{
			Vector3 tempView = _camera_target - _camera_position;

			tempView.normalize();

			/*_camera_position.getX() +=tempView._x * speed;
			_camera_position._y += tempView._y * speed;
			_camera_position._z += tempView._z * speed;

			_camera_target._x += tempView._x * speed;
			_camera_target._y += tempView._y * speed;
			_camera_target._z += tempView._z * speed;*/

			_camera_position.setX(_camera_position.getX() + (tempView.getX() * speed));
			_camera_position.setY(_camera_position.getY() + (tempView.getY() * speed));
			_camera_position.setZ(_camera_position.getZ() + (tempView.getZ() * speed));

			_camera_target.setX(_camera_target.getX() + (tempView.getX() * speed));
			_camera_target.setY(_camera_target.getY() + (tempView.getY() * speed));
			_camera_target.setZ(_camera_target.getZ() + (tempView.getZ() * speed));
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
		//    newPosition._x  = (cosine + (1 - cosine) * x * x) * tempPosition._x;
		//    newPosition._x += ((1 - cosine) * x * y - z * sine)	* tempPosition._y;
		//    newPosition._x += ((1 - cosine) * x * z + y * sine)	* tempPosition._z;
		//
		//    newPosition._y  = ((1 - cosine) * x * y + z * sine)	* tempPosition._x;
		//    newPosition._y += (cosine + (1 - cosine) * y * y) * tempPosition._y;
		//    newPosition._y += ((1 - cosine) * y * z - x * sine)	* tempPosition._z;
		//
		//    newPosition._z = ((1 - cosine) * x * z - y * sine)	* tempPosition._x;
		//    newPosition._z += ((1 - cosine) * y * z + x * sine)	* tempPosition._y;
		//    newPosition._z += (cosine + (1 - cosine) * z * z) * tempPosition._z;
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

					rotate(1.0f - lastRotationX, axis._x, axis._y, axis._z);
				}
			}
			else if(currentRotationX < -1.0f)
			{
				currentRotationX = -1.0f;

				if(lastRotationX != -1.0f)
				{
					Vector3 axis = axis.cross(view_ - position_, up_);
					axis.normalize();

					rotate(-1.0f - lastRotationX, axis._x, axis._y, axis._z);
				}
			}
			else
			{
				Vector3 axis = axis.cross(view_ - position_, up_);
				axis.normalize();
				rotate(anglez, axis._x, axis._y, axis._z);
			}
			rotate(angley, 0.0f, 1.0f, 0.0f);*/
			/*  return true;
		  }*/

		  //--------------------------------------------------------------------------------------------

		  //void Camera::strafe(float speed)
		  //{
		  //    //position_._x += strafe_._x * speed;
		  //    //position_._z += strafe_._z * speed;
		  //
		  //    //view_._x += strafe_._x * speed;
		  //    //view_._z += strafe_._z * speed;
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
		  //		position_._x += 10.0f;
		  //		position_._y += 10.0f;
		  //		position_._z += 10.0f;
		  //
		  //		view_._x += 10.0f;
		  //		view_._y += 10.0f;
		  //		view_._z += 10.0f;
		  //
		  //		gluLookAt(position_._x, position_._y, position_._z,
		  //				  view_._x, view_._y, view_._z,
		  //				  up_._x, up_._y, up_._z);
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

			gluLookAt(new_position._x, new_position._y, new_position._z, new_view._x, new_view._y, new_view._z,
				new_up._x, new_up._y, new_up._z);*/
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
			_projection = Matrix4::_S_IDENTITY;

			_field_of_view = fov;
			_near = n;
			_far = f;
			_aspect_ratio = aspect;
			_top = _near * ::tan(degreesToRadians(_field_of_view * 0.5f));;
			_bottom = -_top;
			_left = _bottom * _aspect_ratio;
			_right = -_left;

			_projection._m4[0] = (2.0f * _near) / (_right - _left);
			_projection._m4[5] = (2.0f * _near) / (_top - _bottom);
			_projection._m4[8] = (_right + _left) / (_right - _left);
			_projection._m4[9] = (_top + _bottom) / (_top - _bottom);
			_projection._m4[10] = -((_far + _near) / (_far - _near));
			_projection._m4[11] = -1.0f;
			_projection._m4[14] = -((2.0f * (_far * _near)) / (_far - _near));
			_projection._m4[15] = 0.0f;

			return _projection;
		}

		/**
		 * -- Orthographic Projection
		 */

		Matrix4 Camera::orthographic(float l, float t, float r, float b, float n, float f)
		{
			//enginemath::Matrix4 orthographic_projection;
			_projection.loadIdentity();

			_left = l;
			_top = t;
			_right = r;
			_bottom = b;
			_near = n;
			_far = f;


			_projection._m4[0] = 2.0f / (_right - _left);
			_projection._m4[5] = 2.0f / (_top - _bottom);
			_projection._m4[10] = -2.0f / (_far - _near);
			_projection._m4[12] = -((_right + _left) / (_right - _left));
			_projection._m4[13] = -((_top + _bottom) / (_top - _bottom));
			_projection._m4[14] = -((_far + _near) / (_far - _near));
			_projection._m4[15] = 1.0f;

			return _projection;
		}

		/**
		* -- Frustum
		*/
		Matrix4 Camera::frustum(float left, float right, float top, float bottom, float n, float f)
		{
			Matrix4 frustum;
			frustum.loadIdentity();

			_left = left;
			_right = right;
			_top = top;
			_bottom = bottom;
			_near = n;
			_far = f;

			frustum._m4[0] = (2.0f * _near) / (_right - _left);
			frustum._m4[5] = (2.0f * _near) / (_top - _bottom);
			frustum._m4[8] = (_right + _left) / (_right - _left);
			frustum._m4[9] = (_top + _bottom) / (_top - _bottom);
			frustum._m4[10] = -((_far + _near) / (_far - _near));
			frustum._m4[11] = -1.0f;
			frustum._m4[14] = -((2.0f * _far * _near) / (_far - _near));
			frustum._m4[15] = 0.0f;

			return frustum;
		}

		/**
		 * -- lookAt
		 */
		Matrix4 Camera::lookAt(Vector3 position, Vector3 target, Vector3 up)
		{
			_camera_position = position;
			_up = up;
			_camera_target = target;

			Vector3 a = normalize(_camera_target - _camera_position);

			Vector3 b;
			Vector3::cross(b, a, up);
			Vector3 c;
			Vector3::cross(c, b, a);
			Matrix4 m = Matrix4(Vector4(b.getX(), c.getX(), -a.getX(), 0.0f),
				Vector4(b.getY(), c.getY(), -a.getY(), 0.0f),
				Vector4(b.getZ(), c.getZ(), -a.getZ(), 0.0f),
				Vector4(0.0f, 0.0f, 0.0f, 1.0f));

			Transform t;
			_view = Matrix4::_S_IDENTITY;
			_view = m * t.translate(-_camera_position.getX(), -_camera_position.getY(), -_camera_position.getZ());
			return _view;
		}
	}
}