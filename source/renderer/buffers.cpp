﻿/*
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
#include "renderer\buffers.h"

using namespace rodeo::core;
using namespace rodeo::entity;

namespace rodeo
{
	namespace renderer
	{
		void Buffers::init(gl::ArrayType at, unsigned int count, unsigned int buffer, const float* data, gl::ArrayDraw ad)
		{
			glGenBuffers(count, &buffer);
			glBindBuffer(at, buffer);
			glBufferData(at, sizeof(data), data, ad);
		}

		//..................//
		void Buffers::initBuffers(gl::ArrayType array_type, gl::ArrayDraw array_draw, const float* data)
		{
			glGenBuffers(1, &_vbo);
			glBindBuffer(array_type, _vbo);

			//data_ = data;

			glBufferData(array_type, sizeof(data), data, array_draw);
		}

		//........................//
		void Buffers::draw(gl::ArrayType array_type, int attrib, const float* data)
		{
			glEnableVertexAttribArray(attrib);
			//glBindBuffer(array_type, vbo);
			glVertexAttribPointer(attrib, 3, GL_FLOAT, GL_FALSE, 0, data);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glDisableVertexAttribArray(attrib);
		}

		//......................//
		void Buffers::draw(gl::ArrayType array_type, gl::DrawingMode drawing_mode, int& attrib, const float* data)
		{
			glEnableVertexAttribArray(attrib);
			glVertexAttribPointer(attrib, 4, GL_FLOAT, GL_FALSE, 0, data);
			glDrawArrays(drawing_mode, 0, 4);
			glDisableVertexAttribArray(attrib);
		}

		//......................//
		void Buffers::createBuffer(unsigned int buffer, gl::BufferType bt)
		{
			//switch(bt)
			//{
			//case RODEO_VBO:
			//    {
			//        vbo.push_back(buffer);
			//    }
			//    break;

			//case RODEO_CBO:
			//    {
			//        cbo.push_back(buffer);
			//    }
			//    break;

			//case RODEO_NBO:
			//    {
			//        nbo.push_back(buffer);
			//    }
			//    break;

			//case RODEO_TBO:
			//    {
			//        tbo.push_back(buffer);
			//    }
			//    break;

			//case RODEO_EBO:
			//    {
			//        ebo.push_back(buffer);
			//    }
			//    break;
			//}
		}

		//................//
		void Buffers::draw(unsigned int& vb)
		{
			glBindBuffer(GL_ARRAY_BUFFER, vb);
			glVertexPointer(3, GL_FLOAT, 0, 0);

			glEnableClientState(GL_VERTEX_ARRAY);
			glDrawArrays(GL_POINTS, 0, 1);
			glDisableClientState(GL_VERTEX_ARRAY);
		}

		//..................//
		void Buffers::fill(float* va, unsigned int& vb)
		{
			glGenBuffers(1, &vb);
			glBindBuffer(GL_ARRAY_BUFFER, vb);
			glBufferData(GL_ARRAY_BUFFER, sizeof(va) * 6, &va[0], GL_STREAM_DRAW);
		}

		//..................//
		void Buffers::draw(unsigned int& vb, gl::DrawingMode dm)
		{
			glBindBuffer(GL_ARRAY_BUFFER, vb);
			glVertexPointer(3, GL_FLOAT, 0, 0);

			glEnableClientState(GL_VERTEX_ARRAY);
			glDrawArrays(dm, 0, 2);
			glDisableClientState(GL_VERTEX_ARRAY);
		}

		//....................//
		void Buffers::reset()
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		//...................//
		void Buffers::fill(const Model& m, unsigned int stride)
		{
			/*
			glGenBuffers(1, &vertex_buffer_[stride]);
			glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_[stride]);

			glBufferData(GL_ARRAY_BUFFER, m.mesh_[stride].vertex_count_ * sizeof(float) * 3, m.mesh_[stride].vertex_, GL_STATIC_DRAW);

			glGenBuffers(1, &normal_buffer_[stride]);
			glBindBuffer(GL_ARRAY_BUFFER, normal_buffer_[stride]);

			if(m.mesh_[stride].normal_count_ > 0 )
			{
				glBufferData(GL_ARRAY_BUFFER, m.mesh_[stride].normal_count_ * sizeof(float) * 3, &m.mesh_[stride].normals_[0], GL_STATIC_DRAW);
			}

			if(m.mesh_[stride].has_texture_)
			{
				glGenBuffers(1, &texture_buffer_[stride]);
				glBindBuffer(GL_ARRAY_BUFFER, texture_buffer_[stride]);

				glBufferData(GL_ARRAY_BUFFER, m.mesh_[stride].uv_count_ * sizeof(float) * 2, m.mesh_[stride].coordinate_, GL_STATIC_DRAW);
			}

			glGenBuffers(1, &index_buffer_[stride]);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_[stride]);

			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m.mesh_[stride].face_count_ * sizeof(enginecore::us) * 3, m.mesh_[stride].triangle_, GL_STATIC_DRAW);

			reset();
			*/
		}

		//...........................//
		void Buffers::draw(const Model& m, unsigned int stride)
		{
			/*
			glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_[stride]);
			glVertexPointer(3, GL_FLOAT, 0, 0);

			glBindBuffer(GL_ARRAY_BUFFER, normal_buffer_[stride]);
			glNormalPointer(GL_FLOAT, 0, 0);

			if(m.mesh_[stride].has_texture_)
			{
				glEnableClientState(GL_TEXTURE_COORD_ARRAY);
				glBindBuffer(GL_ARRAY_BUFFER, texture_buffer_[stride]);
				glTexCoordPointer(2, GL_FLOAT, 0, 0);

				glEnable(GL_TEXTURE_2D);
			}
			else
			{
				glDisable(GL_TEXTURE_2D);
			}

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_[stride]);

			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);

			glDrawElements(GL_TRIANGLES, m.mesh_[stride].face_count_ * 3, GL_UNSIGNED_SHORT, 0);
			//glDrawRangeElements(GL_TRIANGLES, 0, 100, m.mesh_[stride].face_count_, GL_UNSIGNED_SHORT, 0);


			if(m.mesh_[stride].has_texture_)
			{
				glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			}

			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);


			reset();
			*/
		}

		//..................................//
		void Buffers::scale(const Model& m, float scale_factor, unsigned int stride)
		{
			/*
			glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_[stride]);

			engineentity::MeshVertex* ptr = static_cast<engineentity::MeshVertex*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));

			if(ptr != NULL)
			{
				for(enginecore::ui i=0; i < m.mesh_[stride].vertex_count_; ++i)
				{
					glScalef(scale_factor, scale_factor, scale_factor);
					ptr[i].vertex_;
				}
				glUnmapBuffer(GL_ARRAY_BUFFER);
			}
			*/
		}

		//..................................//
		void Buffers::fillWithTexture(const Model& model, unsigned int stride)
		{
			/*
			glGenBuffers(1, &vertex_buffer_[stride]);
			glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_[stride]);
			glBufferData(GL_ARRAY_BUFFER, model.mesh_[stride].vertex_count_ * 3 * sizeof(float), model.mesh_[stride].vertex_, GL_STREAM_DRAW);

			glGenBuffers(1, &normal_buffer_[stride]);
			glBindBuffer(GL_ARRAY_BUFFER, normal_buffer_[stride]);
			glBufferData(GL_ARRAY_BUFFER, model.mesh_[stride].normal_count_ * 3 * sizeof(float), model.mesh_[stride].normal_, GL_STREAM_DRAW);

			glGenBuffers(1, &texture_buffer_[stride]);
			glBindBuffer(GL_ARRAY_BUFFER, texture_buffer_[stride]);
			glBufferData(GL_ARRAY_BUFFER, model.mesh_[stride].uv_count_ * 2 * sizeof(float), &model.mesh_[stride].coordinates_, GL_STREAM_DRAW);

			glGenBuffers(1, &index_buffer_[stride]);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_[stride]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.mesh_[stride].face_count_ * 3 * sizeof(enginecore::ui), model.mesh_[stride].triangle_, GL_STREAM_DRAW);

			reset();
			*/
		}

		//..................................//
		void Buffers::destroy(const Model& model, unsigned int stride)
		{
			/*
			if(texture_buffer_[stride] > 0)
			{
				glDeleteBuffers(1, &texture_buffer_[stride]);
			}

			glDeleteBuffers(1, &normal_buffer_[stride]);
			glDeleteBuffers(1, &vertex_buffer_[stride]);
			glDeleteBuffers(1, &index_buffer_[stride]);
			*/
		}
	}
}