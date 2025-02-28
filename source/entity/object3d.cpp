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
#include "entity\object3D.h"

namespace rodeo {

	namespace entity {
		Object3D::Object3D()
			:file_(NULL)
		{
			setObjectType("Model3D");
			_renderable = true;
			//_has_color = true;
		}

		Object3D::Object3D(const char* filename)
			:file_(filename)
		{
			setObjectType("Model3D");
			_renderable = true;
			//_model3d.load(filename);
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::draw()
		{
			//texturerodeor_.bind(texturerodeor_.texture_id_[0]);
			//model3d_.render();
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::load(const char* filename)
		{
			//_model3d.load(filename);
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::load()
		{
			if (getFile() == NULL)
			{
				MessageBox(NULL, L"core::LOAD_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
				return;
			}
			else
			{
				//_model3d.load(getFile());
			}
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::update(float x, float y, float z)
		{
			glTranslatef(x, y, z);

			_model3d.render();
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::update()
		{
			_model3d.render();
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::scale(float scale_factor)
		{
			_model3d.scale(scale_factor);
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::setPosition(float px, float py, float pz)
		{
			/*world_.m4_[12] = px;
			world_.m4_[13] = py;
			world_.m4_[14] = pz;

			last_position_.x_ = world_.m4_[12];
			last_position_.y_ = world_.m4_[13];
			last_position_.z_ = world_.m4_[14];

			glTranslatef(world_.m4_[12], world_.m4_[13], world_.m4_[14]);*/
		}
		//-----------------------------------------------------------------------------------------------------------------------
		void Object3D::setColor(renderer::Colors& rgb)
		{
			/*material_.setAmbient(rgb.r_, rgb.g_, rgb.b_, 1.0f);
			material_.setSpecular(rgb.r_, rgb.g_, rgb.b_, 1.0f);
			material_.setDiffuse(rgb.r_, rgb.g_, rgb.b_, 1.0f);

			material_.setShininess(50.0f);

			glMaterialfv(GL_FRONT, GL_SPECULAR, material_.getSpecular());
			glMaterialfv(GL_FRONT, GL_AMBIENT, material_.getAmbient());
			glMaterialfv(GL_FRONT, GL_DIFFUSE, material_.getDiffuse());
			glMaterialfv(GL_FRONT, GL_SHININESS, material_.getShininess());*/
		}
		//---------------------------------------------------------------------
		void Object3D::setTexture(const char* texture_filename)
		{
			texture_filename_ = texture_filename;
			texture_id_ = 1;
		}

		void Object3D::render() {
			std::cout << "RENDERING" << std::endl;
		}
	}
}