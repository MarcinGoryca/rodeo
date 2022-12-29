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
//#ifndef RODEO_SCENE_CAMERA_H_
//#define RODEO_SCENE_CAMERA_H_
//
//#ifndef RODEO_IO_KEYBOARD_H_
//#include "io\keyboard.h"
//#endif
//
//#ifndef RODEO_ENTITY_ENTITY_H_
//#include "entity\entity.h"
//#endif
//
//namespace rodeo
//{
//	namespace scene
//	{
//		class Camera : public entity::Entity
//		{
//		public:
//			Camera()
//				:Entity("Camera", "camera"),
//				_camera_position(0.0f, 0.0f, 0.0f),
//				_camera_target(0.0f, 0.0f, 0.0f),
//				_up(0.0f, 0.0f, 0.0f),
//				_near(0.0f),
//				_far(0.0f),
//				_bottom(0.0f),
//				_top(0.0f),
//				_left(0.0f),
//				_right(0.0f),
//				_aspect_ratio(0.0f),
//				_field_of_view(0.0f)
//			{}
//
//			virtual ~Camera() {}
//
//			// Sets Camera position
//			// Parameter px - position in x
//			// Parameter py - position in y
//			// Parameter pz - position in z
//			// Parameter vx - view in x
//			// Parameter vy - view in y
//			// Parameter vz - view in z
//			virtual void set(float px, float py, float pz, float vx, float vy, float vz, float ux, float uy, float uz);
//
//			virtual void update();
//			virtual void render();
//
//			// Gets position of the Camera
//			// Returns Vectr3 camera position
//			math::Vector3 getCameraPosition()const { return _camera_position; }
//
//			// Gets target of the Camera
//			// Returns Vector3 camera target
//			math::Vector3 getCameraTarget()const { return _camera_target; }
//
//			// Gets pointing of the Camera
//			// This is usually 0, 1, 0, the Y value defines where camera points\n
//			// -1 value of Y points upside down
//			// Returns Vector3 camera pointing
//			math::Vector3 getUp()const { return _up; }
//
//			// Sets X position of the Camera
//			// Parameter float value of new x position
//			void setPositionX(float new_x) { _camera_position.setX(new_x); }
//
//			// Sets Y position of the Camera
//			// Parameter float value of new y position
//			void setPositionY(float new_y) { _camera_position.setY(new_y); }
//
//			// Sets Z position of the Camera
//			// Parameter float value of new z position
//			void setPositionZ(float new_z) { _camera_position.setZ(new_z); }
//
//			// Sets position of the Camera
//			// Parameter Vector3 value of new camera position
//			void setPosition(const math::Vector3& position) { _camera_position = position; }
//
//			// Sets view in x of the Camera
//			// Parameter float new x value of the view
//			void setViewX(float new_x) { _camera_target.setX(new_x); }
//
//			// Sets view in y of the Camera
//			// Parameter float new y value of the view
//			void setViewY(float new_y) { _camera_target.setY(new_y); }
//
//			// Sets view in z of the Camera
//			// Parameter float new z value of the view
//			void setViewZ(float new_z) { _camera_target.setZ(new_z); }
//
//			// Sets view of the Camera
//			// Parameter Vector3 value of new view
//			void setView(const math::Vector3& view) { _view = view; }
//
//			// Sets pointing in x of the Camera
//			// Parameter float new x value of pointing
//			void setUpX(float new_x) { _up.setX(new_x); }
//
//			// Sets pointing in y of the Camera
//			// Parameter flaot new y value of pointing
//			void setUpY(float new_y) { _up.setY(new_y); }
//
//			// Sets pointing in z of the Camera
//			// Parameter float new z value of pointing
//			void setUpZ(float new_z) { _up.setZ(new_z); }
//
//			// Sets pointing of the Camera
//			// Parameter Vector3 value of pointing
//			void setUp(const math::Vector3& up) { _up = up; }
//
//			// Moves camera
//			// Parameter float value of moving speed
//			virtual void move(float speed);
//
//			// Gets x position of the Camera
//			// Returns float value of x position
//			float getPositionX()const { return _camera_position.getX(); }
//
//			// Gets y position of the Camera
//			// Returns float value of y position
//			float getPositionY()const { return _camera_position.getY(); }
//
//			// Gets z position of the Camera
//			// Returns float value of z position
//			float getPositionZ()const { return _camera_position.getZ(); }
//
//			// Gets x view value of the Camera
//			// Returns float view value in x
//			float getViewX()const { return _camera_target.getX(); }
//
//			// Gets y view value of the Camera
//			// Parameter float view value in y
//			float getViewY()const { return _camera_target.getY(); }
//
//			// Gets z view value of the Camera
//			// Returns float view value in z
//			float getViewZ()const { return _camera_target.getZ(); }
//
//			// Gets x value of pointing
//			// Returns float value of x pointing
//			float getUpX()const { return _up.getX(); }
//
//			// Gets y value of pointing
//			// Returns float value of y pointing
//			float getUpY()const { return _up.getY(); }
//
//			// Gets z value of pointing
//			// Returns float value of z pointing
//			float getUpZ()const { return _up.getZ(); }
//
//			// Gets Near plane of the Camera
//			// Returns float value of near plane
//			float getNear() const { return _near; }
//
//			// Gets Far plane of the Camera
//			// Returns float value of far plane
//			float getFar() const { return _far; }
//
//			// Gets Top plane of the Camera
//			// Returns float value of top plane
//			float getTop() const { return _top; }
//
//			// Gets Bottom plane of the Camera
//			// Returns float value of bottom plane
//			float getBottom() const { return _bottom; }
//
//			// Gets Left plane of the Camera
//			// Returns float value of left plane
//			float getLeft() const { return _left; }
//
//			// Gets Right plane of the Camera
//			// Returns float value of right plane
//			float getRight() const { return _right; }
//
//			// Perspective Projection
//			// Parameter float fov - field of view (in degrees)
//			// Parameter float near - near plane in negative z axis
//			// Parameter float far - far plane in positive z axis
//			// Parameter float aspect - aspect ratio of the screen (width / height) 
//			math::Matrix4 perspective(float fov, float near, float far, float aspect);
//
//			// Orthographic Projection
//			// Parameter float l - left
//			// Parameter float t - top
//			// Parameter float r - right
//			// Parameter float b - bottom
//			// Parameter float n - near
//			// Parameter float f - far
//			math::Matrix4 orthographic(float l, float t, float r, float b, float n, float f);
//
//			// Parameter left - x negative axis
//			// Parameter right - x positive axis
//			// Parameter top - y positive axis
//			// Parameter bottom - y negative axis
//			// Parameter n - z negative axis (near plane)
//			// Parameter f - z positive axis (far plane) 
//			math::Matrix4 frustum(float left, float right, float top, float bottom, float n, float f);
//
//			// Parameter position - position of the camera (in some sources this is called eye)
//			// Parameter view     - where the camera is pointing (in some sources this is called center)
//			// Parameter up       - up vector
//			math::Matrix4 lookAt(math::Vector3 position, math::Vector3 view, math::Vector3 up);
//
//			// Gets ProjectionMatrix - Perspective or Orthographic
//			// Returns Matrix4 object
//			math::Matrix4 getProjection() const
//			{
//				return _projection;
//			}
//
//			// Gets View Matrix - set by lookAt Matrix4
//			// Returns Matrix4 object
//			math::Matrix4 getView() const
//			{
//				return _view;
//			}
//
//		protected:
//			math::Matrix4 _projection;
//			math::Matrix4 _view;
//			math::Vector3 _camera_position;
//			math::Vector3 _camera_target;
//			math::Vector3 _up;
//
//			float _near;
//			float _far;
//			float _bottom;
//			float _top;
//			float _left;
//			float _right;
//			float _aspect_ratio;
//			float _field_of_view;
//		};
//	}
//}
//#endif