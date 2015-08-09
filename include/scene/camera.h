/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_SCENE_CAMERA_H_
#define MG_SCENE_CAMERA_H_

#ifndef MG_IO_KEYBOARD_H_
#include "io\keyboard.h"
#endif

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace mg
{
namespace scene
{
class Camera : public entity::Entity
{
public:
    Camera()
        :Entity("Camera", "camera"),
         camera_position_(0.0f, 0.0f, 0.0f),
         camera_target_(0.0f, 0.0f, 0.0f),
         up_(0.0f, 0.0f, 0.0f),
         near_(0.0f),
         far_(0.0f),
         bottom_(0.0f),
         top_(0.0f),
         left_(0.0f),
         right_(0.0f),
         aspect_ratio_(0.0f),
         field_of_view_(0.0f)
    {}
    
    virtual ~Camera(){}

    // Sets Camera position
    // Parameter px - position in x
    // Parameter py - position in y
    // Parameter pz - position in z
    // Parameter vx - view in x
    // Parameter vy - view in y
    // Parameter vz - view in z
    virtual void set(float px, float py, float pz, float vx, float vy, float vz, float ux,float uy, float uz);

    virtual void update();
    virtual void render();

    // Gets position of the Camera
    // Returns Vectr3 camera position
    math::Vector3 getCameraPosition()const { return camera_position_; }

    // Gets target of the Camera
    // Returns Vector3 camera target
    math::Vector3 getCameraTarget()const { return camera_target_; }

    // Gets pointing of the Camera
    // This is usually 0, 1, 0, the Y value defines where camera points\n
    // -1 value of Y points upside down
    // Returns Vector3 camera pointing
    math::Vector3 getUp()const { return up_; }

    // Sets X position of the Camera
    // Parameter float value of new x position
    void setPositionX(float new_x){ camera_position_.x_ = new_x; }
 
    // Sets Y position of the Camera
    // Parameter float value of new y position
    void setPositionY(float new_y){ camera_position_.y_ = new_y; }
 
    // Sets Z position of the Camera
    // Parameter float value of new z position
    void setPositionZ(float new_z){ camera_position_.z_ = new_z; }

    // Sets position of the Camera
    // Parameter Vector3 value of new camera position
    void setPosition(const math::Vector3& position) { camera_position_ = position; }

    // Sets view in x of the Camera
    // Parameter float new x value of the view
    void setViewX(float new_x){ camera_target_.x_ = new_x; }

    // Sets view in y of the Camera
    // Parameter float new y value of the view
    void setViewY(float new_y){ camera_target_.y_ = new_y; }

    // Sets view in z of the Camera
    // Parameter float new z value of the view
    void setViewZ(float new_z){ camera_target_.z_ = new_z; }

    // Sets view of the Camera
    // Parameter Vector3 value of new view
    void setView(const math::Vector3& view) { view_ = view; }

    // Sets pointing in x of the Camera
    // Parameter float new x value of pointing
    void setUpX(float new_x){ up_.x_ = new_x; }

    // Sets pointing in y of the Camera
    // Parameter flaot new y value of pointing
    void setUpY(float new_y){ up_.y_ = new_y; }

    // Sets pointing in z of the Camera
    // Parameter float new z value of pointing
    void setUpZ(float new_z){ up_.z_ = new_z; }

    // Sets pointing of the Camera
    // Parameter Vector3 value of pointing
    void setUp(const math::Vector3& up) { up_ = up; }

    // Moves camera
    // Parameter float value of moving speed
    virtual void move(float speed);

    // Gets x position of the Camera
    // Returns float value of x position
    float getPositionX()const { return camera_position_.x_; }

    // Gets y position of the Camera
    // Returns float value of y position
   float getPositionY()const { return camera_position_.y_; }

    // Gets z position of the Camera
    // Returns float value of z position
    float getPositionZ()const { return camera_position_.z_; }

    // Gets x view value of the Camera
    // Returns float view value in x
    float getViewX()const { return camera_target_.x_; }

    // Gets y view value of the Camera
    // Parameter float view value in y
    float getViewY()const { return camera_target_.y_; }

    // Gets z view value of the Camera
    // Returns float view value in z
    float getViewZ()const { return camera_target_.z_; }

    // Gets x value of pointing
    // Returns float value of x pointing
    float getUpX()const { return up_.x_; }

    // Gets y value of pointing
    // Returns float value of y pointing
    float getUpY()const { return up_.y_; }

    // Gets z value of pointing
    // Returns float value of z pointing
    float getUpZ()const { return up_.z_; }

    // Gets Near plane of the Camera
    // Returns float value of near plane
    float getNear() const { return near_; }

    // Gets Far plane of the Camera
    // Returns float value of far plane
    float getFar() const { return far_; }

    // Gets Top plane of the Camera
    // Returns float value of top plane
    float getTop() const { return top_; }

    // Gets Bottom plane of the Camera
    // Returns float value of bottom plane
    float getBottom() const { return bottom_; }

    // Gets Left plane of the Camera
    // Returns float value of left plane
    float getLeft() const { return left_; }

    // Gets Right plane of the Camera
    // Returns float value of right plane
    float getRight() const { return right_; }

    // Perspective Projection
    // Parameter float fov - field of view (in degrees)
    // Parameter float near - near plane in negative z axis
    // Parameter float far - far plane in positive z axis
    // Parameter float aspect - aspect ratio of the screen (width / height) 
    math::Matrix4 perspective(float fov, float near, float far, float aspect);

    // Orthographic Projection
    // Parameter float l - left
    // Parameter float t - top
    // Parameter float r - right
    // Parameter float b - bottom
    // Parameter float n - near
    // Parameter float f - far
    math::Matrix4 orthographic(float l, float t, float r, float b, float n, float f);

    // Parameter left - x negative axis
    // Parameter right - x positive axis
    // Parameter top - y positive axis
    // Parameter bottom - y negative axis
    // Parameter n - z negative axis (near plane)
    // Parameter f - z positive axis (far plane) 
    math::Matrix4 frustum(float left, float right, float top, float bottom, float n, float f);

    // Parameter position - position of the camera (in some sources this is called eye)
    // Parameter view     - where the camera is pointing (in some sources this is called center)
    // Parameter up       - up vector
    math::Matrix4 lookAt(math::Vector3 position, math::Vector3 view, math::Vector3 up);

    // Gets ProjectionMatrix - Perspective or Orthographic
    // Returns Matrix4 object
    math::Matrix4 getProjection() const
    {
        return projection_;
    }

    // Gets View Matrix - set by lookAt Matrix4
    // Returns Matrix4 object
    math::Matrix4 getView() const
    {
        return view_;
    }

protected:
    math::Matrix4 projection_;
    math::Matrix4 view_;
    math::Vector3 camera_position_;
    math::Vector3 camera_target_;
    math::Vector3 up_;

    float near_;
    float far_;
    float bottom_;
    float top_;
    float left_;
    float right_;
    float aspect_ratio_;
    float field_of_view_;
};
}    // end of scene namespace
}    // end of mg namespace
#endif