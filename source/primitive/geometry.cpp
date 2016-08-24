/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "primitive\geometry.h"
#include "io\log.h"

using namespace mona::entity;
using namespace mona::math;
using namespace mona::core;

namespace mona
{
	namespace primitive
	{
		void Line::draw()
		{
		}

		/*
		void Cube::build()
		{
			Mesh mesh;
			mesh.reset();
			_model._mesh.push_back(mesh);
			_model._meshcount_++;
			_model._mesh[0].vertex_count_ = 8;
			_model._mesh[0].vertex_ = new MeshVertex[_model._mesh[0].vertex_count_];
			ZeroMemory(_model._mesh[0].vertex_, sizeof(_model._mesh[0].vertex_));
		}

		void Cube::build(const Vector3& v1, const Vector3& v2)
		{
			Mesh mesh;
			mesh.reset();
			_model._mesh.push_back(mesh);
			_model._meshcount_++;
			_model._mesh[0].vertex_count_ = 8;
			_model._mesh[0].vertex_ = new MeshVertex[_model._mesh[0].vertex_count_];
			ZeroMemory(_model._mesh[0].vertex_, sizeof(_model._mesh[0].vertex_));

			_model._mesh[0].vertex_[0].vertex_.x_ = v1.x_;
			_model._mesh[0].vertex_[0].vertex_.y_ = v1.y_;
			_model._mesh[0].vertex_[0].vertex_.z_ = v1.z_;

			_model._mesh[0].vertex_[1].vertex_.x_ = v2.x_;
			_model._mesh[0].vertex_[1].vertex_.y_ = v1.y_;
			_model._mesh[0].vertex_[1].vertex_.z_ = v1.z_;

			_model._mesh[0].vertex_[2].vertex_.x_ = v2.x_;
			_model._mesh[0].vertex_[2].vertex_.y_ = v2.y_;
			_model._mesh[0].vertex_[2].vertex_.z_ = v1.z_;

			_model._mesh[0].vertex_[3].vertex_.x_ = v1.x_;
			_model._mesh[0].vertex_[3].vertex_.y_ = v2.y_;
			_model._mesh[0].vertex_[3].vertex_.z_ = v1.z_;

			_model._mesh[0].vertex_[4].vertex_.x_ = v1.x_;
			_model._mesh[0].vertex_[4].vertex_.y_ = v2.y_;
			_model._mesh[0].vertex_[4].vertex_.z_ = v2.z_;

			_model._mesh[0].vertex_[5].vertex_.x_ = v1.x_;
			_model._mesh[0].vertex_[5].vertex_.y_ = v1.y_;
			_model._mesh[0].vertex_[5].vertex_.z_ = v2.z_;

			_model._mesh[0].vertex_[6].vertex_.x_ = v2.x_;
			_model._mesh[0].vertex_[6].vertex_.y_ = v1.y_;
			_model._mesh[0].vertex_[6].vertex_.z_ = v2.z_;

			_model._mesh[0].vertex_[7].vertex_.x_ = v2.x_;
			_model._mesh[0].vertex_[7].vertex_.y_ = v2.y_;
			_model._mesh[0].vertex_[7].vertex_.z_ = v2.z_;

			Vector3 ta[8];

			for(int i=0; i < 8; ++i)
			{
				ta[i] = _model._mesh[0].vertex_[i].vertex_;
			}

			_model._mesh[0].face_count_ = 36;
			_model._mesh[0]._triangle = new MeshTriangle[_model._mesh[0].face_count_];
			ZeroMemory(_model._mesh[0]._triangle, sizeof(_model._mesh[0]._triangle));

			_model._mesh[0]._triangle[0]._triangle[0] = 0;
			_model._mesh[0]._triangle[0]._triangle[1] = 1;
			_model._mesh[0]._triangle[0]._triangle[2] = 2;

			_model._mesh[0]._triangle[0]._triangle[3] = 2;
			_model._mesh[0]._triangle[0]._triangle[4] = 3;
			_model._mesh[0]._triangle[0]._triangle[5] = 0;

			_model._mesh[0]._triangle[0]._triangle[6] = 4;
			_model._mesh[0]._triangle[0]._triangle[7] = 5;
			_model._mesh[0]._triangle[0]._triangle[8] = 6;

			_model._mesh[0]._triangle[0]._triangle[9] = 6;
			_model._mesh[0]._triangle[0]._triangle[10] = 7;
			_model._mesh[0]._triangle[0]._triangle[11] = 4;

			_model._mesh[0]._triangle[0]._triangle[12] = 1;
			_model._mesh[0]._triangle[0]._triangle[13] = 6;
			_model._mesh[0]._triangle[0]._triangle[14] = 7;

			_model._mesh[0]._triangle[0]._triangle[15] = 7;
			_model._mesh[0]._triangle[0]._triangle[16] = 2;
			_model._mesh[0]._triangle[0]._triangle[17] = 1;

			_model._mesh[0]._triangle[0]._triangle[18] = 4;
			_model._mesh[0]._triangle[0]._triangle[19] = 5;
			_model._mesh[0]._triangle[0]._triangle[20] = 0;

			_model._mesh[0]._triangle[0]._triangle[21] = 0;
			_model._mesh[0]._triangle[0]._triangle[22] = 3;
			_model._mesh[0]._triangle[0]._triangle[23] = 4;

			_model._mesh[0]._triangle[0]._triangle[24] = 5;
			_model._mesh[0]._triangle[0]._triangle[25] = 0;
			_model._mesh[0]._triangle[0]._triangle[26] = 1;

			_model._mesh[0]._triangle[0]._triangle[27] = 1;
			_model._mesh[0]._triangle[0]._triangle[28] = 6;
			_model._mesh[0]._triangle[0]._triangle[29] = 5;

			_model._mesh[0]._triangle[0]._triangle[30] = 4;
			_model._mesh[0]._triangle[0]._triangle[31] = 3;
			_model._mesh[0]._triangle[0]._triangle[32] = 2;

			_model._mesh[0]._triangle[0]._triangle[33] = 2;
			_model._mesh[0]._triangle[0]._triangle[34] = 7;
			_model._mesh[0]._triangle[0]._triangle[35] = 4;

			setMeshCount(_model._meshcount_);
			setVertexCount(_model._mesh[0].vertex_count_);
			setIndexCount(_model._mesh[0].face_count_);

			create();
		}

		void Cube::draw()
		{
			face_type_ = GL_FRONT_AND_BACK;
			face_mode_ = GL_LINE;

			render();
		}
		*/
		void Point::draw()
		{
		}

		/* --- */
		void Point::setPosition(float px, float py, float pz)
		{
		}

		/* --- */
		void Grid::draw()
		{
			_face_type = GL_FRONT_AND_BACK;
			_face_mode = GL_LINE;
			render();
		}

		/* --- */
		void Grid::translate(float x, float y, float z)
		{

		}

		/* --- */
		void Grid::generate(unsigned short n, unsigned short m)
		{
			//w = (n-1) * dx
			//d = (m-1) * dz
			Mesh mesh;
			mesh.reset();

			_model._mesh.push_back(mesh);
			_model._mesh_count++;
			_model._mesh[0]._vertex_count = n * m;
			_model._mesh[0]._vertex = new MeshVertex[_model._mesh[0]._vertex_count];
			ZeroMemory(_model._mesh[0]._vertex, sizeof(_model._mesh[0]._vertex));


			_quad_x = 8.0f;
			_quad_z = 8.0f;

			for (int i = 0; i < m; ++i)
			{

				float z = 0.5f - i * _quad_z;

				for (int j = 0; j < n; ++j)
				{

					float x = -0.5f - j * _quad_x;
					float y = 0.0f;

					_model._mesh[0]._vertex[i * n + j]._vertex.setX(x);
					_model._mesh[0]._vertex[i * n + j]._vertex.setY(y);
					_model._mesh[0]._vertex[i * n + j]._vertex.setZ(z);
				}
			}

			//Generate indices for every vertex
			int k = 0;
			_model._mesh[0]._face_count = (m - 1) * (n - 1) * 2;
			_model._mesh[0]._triangle = new MeshTriangle[_model._mesh[0]._face_count];

			for (unsigned short i = 0; i < m - 1; ++i)
			{
				for (unsigned short j = 0; j < n - 1; ++j)
				{
					_model._mesh[0]._triangle[0]._triangle[k] = i * n + j;
					_model._mesh[0]._triangle[0]._triangle[k + 1] = i * n + j + 1;
					_model._mesh[0]._triangle[0]._triangle[k + 2] = (i + 1) * n + j;
					_model._mesh[0]._triangle[0]._triangle[k + 3] = (i + 1) * n + j;
					_model._mesh[0]._triangle[0]._triangle[k + 4] = i * n + j + 1;
					_model._mesh[0]._triangle[0]._triangle[k + 5] = (i + 1) * n + j + 1;
					k += 6;
				}
			}

			setMeshCount(_model._mesh_count);
			setVertexCount(_model._mesh[0]._vertex_count);
			setIndexCount(_model._mesh[0]._face_count);
			//Creating Axis Aligned Bounding Box
				//box_.reset();

			for (ui i = 0; i < _model._mesh[0]._face_count; ++i)
			{
				_box.add(_model._mesh[0]._vertex[0]._vertex);
			}

			create();
		}

		/* --- */
		void Grid::generate(unsigned short n, unsigned short m, float qw, float qh)
		{
			//w = (n-1) * dx
			//d = (m-1) * dz
			Mesh mesh;
			mesh.reset();
			mesh._mesh_name = "mona Standard Grid";
			//memcpy(mesh._mesh_name, mesh._mesh_name, sizeof(mesh._mesh_name));

			_model._mesh.push_back(mesh);
			_model._mesh_count++;
			_model._mesh[0]._vertex_count = n * m;
			_model._mesh[0]._vertex = new MeshVertex[_model._mesh[0]._vertex_count];
			ZeroMemory(_model._mesh[0]._vertex, sizeof(_model._mesh[0]._vertex));

			_quad_x = qw;
			_quad_z = qh;

			for (unsigned short i = 0; i < m; ++i)
			{

				float z = 0.5f - i * _quad_z;

				for (unsigned short j = 0; j < n; ++j)
				{

					float x = -0.5f - j * _quad_x;
					float y = 0.0f;

					_model._mesh[0]._vertex[i * n + j]._vertex.setX(x);
					_model._mesh[0]._vertex[i * n + j]._vertex.setY(y);
					_model._mesh[0]._vertex[i * n + j]._vertex.setZ(z);
				}
			}

			//Generate indices for every vertex
			unsigned short k = 0;
			_model._mesh[0]._face_count = (m - 1) * (n - 1) * 2;
			_model._mesh[0]._triangle = new MeshTriangle[_model._mesh[0]._face_count];

			for (unsigned short i = 0; i < m - 1; ++i)
			{
				for (unsigned short j = 0; j < n - 1; ++j)
				{
					_model._mesh[0]._triangle[0]._triangle[k] = i * n + j;
					_model._mesh[0]._triangle[0]._triangle[k + 1] = i * n + j + 1;
					_model._mesh[0]._triangle[0]._triangle[k + 2] = (i + 1) * n + j;
					_model._mesh[0]._triangle[0]._triangle[k + 3] = (i + 1) * n + j;
					_model._mesh[0]._triangle[0]._triangle[k + 4] = i * n + j + 1;
					_model._mesh[0]._triangle[0]._triangle[k + 5] = (i + 1) * n + j + 1;
					k += 6;
				}
			}

			setMeshCount(_model._mesh_count);
			setVertexCount(_model._mesh[0]._vertex_count);
			setIndexCount(_model._mesh[0]._face_count);

			//_model._mesh[0].has_texture_ = true;

		//Creating Axis Aligned Bounding Box
			_winding = GL_CW;
			create();
		}
	}
}