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
#include "..\include\io\file3ds.h"

using namespace std;
using namespace rodeo::core;
using namespace rodeo::math;
using namespace rodeo::renderer;

//================================================================
//	3DS LOADER	BASED ON GAME TUTORIALS BY BEN HUMPHREY
//================================================================

namespace rodeo
{
	namespace io
	{
		bool File3DS::import(const char* filename)
		{
			//TODO:	Implement Rodeo3DSException!
			try
			{
				LPWSTR temp = 0;
				MultiByteToWideChar(0, 0, filename, 0, temp, 0);
				LPCWSTR t = temp;
				_file = CreateFile(t, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

				if (_file == INVALID_HANDLE_VALUE)
					throw - 1;
			}
			catch (...)
			{
				//MessageBox(NULL, FILE3DS_FAIL.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
				return false;
			}

			Chunk currentChunk = { 0 };

			readHeaderChunk(currentChunk);

			//TODO:
			//Compute Normals in this place
			CloseHandle(_file);
			return true;
		}

		//................................//
		void File3DS::readHeaderChunk(Chunk& chunk)
		{
			// 1. Get Header Chunk (6 bytes)
			//	  It's 0x4D4D	
			DWORD bytesRead = 0;
			ReadFile(_file, &chunk._id, 2, &bytesRead, NULL);

			chunk._bytesread += bytesRead;

			if (chunk._id != MAIN3DS)
			{
				//MessageBox(NULL, FILE3DS_ERROR.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
				return;
			}
			else
			{
				ReadFile(_file, &chunk._length, 4, &bytesRead, NULL);
				chunk._bytesread += bytesRead;
			}
			// 2. Get Version Chunk (10 bytes)
			//	  It's 0x0002
			readVersionChunk(chunk);
			// 3. Get Next Chunks containing real data
			readNextChunk(chunk);
		}

		//...................................//
		void File3DS::readVersionChunk(Chunk& chunk)
		{
			//Read Chunks while we get to the end
			//Version Chunk Id == 2
			//Version Chunk Length == 10 bytes
			Chunk currentChunk = { 0 };
			//Chunk tempChunk = {0};

			while (chunk._bytesread < chunk._length)
			{
				readChunk(currentChunk);

				if (currentChunk._id == VERSION)
				{
					skipChunk(currentChunk);
				}
				break;
			}
			chunk._bytesread += currentChunk._bytesread;
		}

		//........................................//
		void File3DS::readChunk(Chunk& chunk)
		{
			DWORD bytesRead = 0;

			ReadFile(_file, &chunk._id, 2, &bytesRead, NULL);

			chunk._bytesread = bytesRead;

			ReadFile(_file, &chunk._length, 4, &bytesRead, NULL);

			chunk._bytesread += bytesRead;
		}

		//.......................................//
		unsigned int File3DS::skipChunk(Chunk& chunk)
		{
			DWORD bytesRead = 0;
			ReadFile(_file, _buffer, chunk._length - chunk._bytesread, &bytesRead, NULL);
			chunk._bytesread += bytesRead;
			return chunk._bytesread;
		}

		//.........................................//
		void File3DS::readNextChunk(Chunk& chunk)
		{
			Chunk currentChunk = { 0 };
			Chunk tempChunk = { 0 };
			entity::MeshMaterial newMaterial = { 0 };
			entity::Mesh mesh;
			//memset(&modelB, 0, sizeof(Model));
			ZeroMemory(&mesh, sizeof(mesh));

			//Model* tempModel = new Model;

			while (chunk._bytesread < chunk._length)
			{
				readChunk(currentChunk);

				switch (currentChunk._id)
				{
					// 4. This Chunk (id == 0x3D3D) Contains Next Chunks with important data
				case EDITOR:
				{
					DWORD bytesRead = 0;
					readChunk(tempChunk);

					ReadFile(_file, _buffer, tempChunk._length - tempChunk._bytesread, &bytesRead, NULL);

					tempChunk._bytesread += bytesRead;
					currentChunk._bytesread += tempChunk._bytesread;

					readNextChunk(currentChunk);
				}
				break;
				// 5. This Chunk (id == 0x4000) Contains Mesh Data, Vertices, Faces
				case MESH:
				{
					// We found objects in this chunk, let's counting them
					// Then we add those objects (if > 0) to master object
					// We must read mesh name, e.g. "Box01", which is set in 3ds Max
									//modelB.meshCount++;
					_model->_mesh_count++;
					_model->_mesh.push_back(mesh);

					//memset(&model.mesh, 0, sizeof(Mesh));

					currentChunk._bytesread += getString(_model->_mesh[_model->_mesh_count - 1]._meshname);

					readMeshChunk(_model->_mesh[_model->_mesh_count - 1], currentChunk);
				}
				break;

				//5. This Chunk (id == 0xAFFF) Contains Material Data	
				case MATERIAL:
				{
					// We found material objects, count them
					// Add any found material object to our model

					_model->_material_count++;
					_model->_material.push_back(newMaterial);

					readMaterialChunk(_model->_material[_model->_material_count - 1], currentChunk);

				}
				break;

				default:
				{
					skipChunk(currentChunk);
				}
				break;
				}

				chunk._bytesread += currentChunk._bytesread;
			}
		}

		//..........................................//
		void File3DS::readMeshChunk(entity::Mesh& model, Chunk& chunk)
		{
			Chunk currentChunk = { 0 };

			while (chunk._bytesread < chunk._length)
			{
				readChunk(currentChunk);

				switch (currentChunk._id)
				{
					// 6. This chunk (id == 0x4100) holds triangle data
				case TRIANGLE_POLYGON_MESH:
				{
					readMeshChunk(model, currentChunk);
				}
				break;
				// 7. This chunk (id == 0x4110) has vertex data, very important
				case VERTEX_LIST:
				{
					readVertexList(model, currentChunk);
				}
				break;
				//8. This chunk (id == 0x4120) contains face data, indices
				case FACE_LIST:
				{
					readFaceList(model, currentChunk);
				}
				break;
				//9. This chunk (id == 0x4130) contains information about materials
				case FACE_MATERIAL:
				{
					readFaceMaterial(model, currentChunk);
				}
				break;
				// 10. This chunk (id == 0x4140) has uv coordinates		
				case UVMAPPING:
				{
					readUVMapping(model, currentChunk);
				}
				break;

				default:
				{
					skipChunk(currentChunk);
				}
				}
				chunk._bytesread += currentChunk._bytesread;
			}
		}

		//...........................................//
		int File3DS::getString(char* str)
		{
			int offset = 0;
			DWORD bytesRead = 0;

			ReadFile(_file, str, 1, &bytesRead, NULL);
			//We read string for object name or material name
			while (*(str + offset++) != 0)
			{
				ReadFile(_file, str + offset, 1, &bytesRead, NULL);
			}
			return strlen(str) + 1;
		}

		//..........................................//
		void File3DS::readVertexList(entity::Mesh& m, Chunk& chunk)
		{
			DWORD bytesRead = 0;

			ReadFile(_file, &(m._vertex_count), 2, &bytesRead, NULL);

			chunk._bytesread += bytesRead;

			//Allocate memory for vertex data
			m._vertex = new entity::MeshVertex[m._vertex_count];

			//Zero the memory
			ZeroMemory(m._vertex, sizeof(m._vertex) * m._vertex_count);
			//Actual read the vertex data, after that we have vertex list in memory
			ReadFile(_file, m._vertex, chunk._length - chunk._bytesread, &bytesRead, NULL);

			chunk._bytesread += bytesRead;
			//Now important thing to do, 3ds Max has Z vector pointing UP, so we must flip it with Y vector
			//In FBX export dialog box there is option to flip it automatically
			for (unsigned int i = 0; i < m._vertex_count; ++i)
			{
				float temp = m._vertex[i]._vertex.getY();
				m._vertex[i]._vertex.setY(m._vertex[i]._vertex.getZ());
				m._vertex[i]._vertex.setZ(-temp);
			}
		}

		//........................................//
		void File3DS::readFaceList(entity::Mesh& m, Chunk& chunk)
		{
			unsigned short index = 0;
			DWORD bytesRead = 0;
			// Here we read face data 
			// First we count them by reading header 
			ReadFile(_file, &(m._face_count), 2, &bytesRead, NULL);

			chunk._bytesread += bytesRead;

			// Allocate new face data
			m._triangle = new entity::MeshTriangle[m._face_count];
			m._normal = new entity::MeshNormal;

			ZeroMemory(m._triangle, sizeof(m._triangle) * m._face_count);

			// Reading all faces 
			// 3ds max has 4 values for indices, 4th value is visibility flag, we skip it
			for (unsigned int i = 0; i < m._face_count; ++i)
			{
				for (unsigned int j = 0; j < 4; ++j)
				{
					ReadFile(_file, &index, 2, &bytesRead, NULL);
					chunk._bytesread += bytesRead;

					if (j < 3)
					{
						m._triangle[i]._triangle[j] = index;
					}
				}
			}
			//Computing Triangle Normals
		}

		//............................................//
		void File3DS::readFaceMaterial(entity::Mesh& m, Chunk& chunk)
		{
			char materialName[255] = { 0 };

			chunk._bytesread += getString(materialName);

			for (unsigned int i = 0; i < _model->_material_count; ++i)
			{
				// Here we check if the read material name equals texture name
				if (strcmp(materialName, _model->_material[i]._name) == 0)
				{
					// Now we check if this is a texture map, if string is greater than 0 it's texture from file
					if (strlen(_model->_material[i]._file) > 0)
					{
						m._material_id = i;
						m._has_texture = true;
					}
					break;
				}
				else
				{
					if (m._has_texture != true)
					{
						m._material_id = -1;
					}
				}
			}

			DWORD bytesRead = 0;
			ReadFile(_file, _buffer, chunk._length - chunk._bytesread, &bytesRead, NULL);

			chunk._bytesread += bytesRead;
		}

		//.....................................//
		void File3DS::readMaterialChunk(entity::MeshMaterial& mat, Chunk& chunk)
		{
			Chunk currentChunk = { 0 };

			while (chunk._bytesread < chunk._length)
			{
				readChunk(currentChunk);

				switch (currentChunk._id)
				{
				case MATERIAL_NAME:
				{
					DWORD bytesRead = 0;
					ReadFile(_file, mat._name, currentChunk._length - currentChunk._bytesread, &bytesRead, NULL);
					currentChunk._bytesread += bytesRead;
				}
				break;

				case MATERIAL_DIFFUSE:
				{
					readColorChunk(mat, currentChunk);
				}
				break;

				case MATERIAL_TEXTURE_MAP:
				{
					readMaterialChunk(mat, currentChunk);
				}
				break;

				case MATERIAL_TEXTURE_FILENAME:
				{
					DWORD bytesRead = 0;
					ReadFile(_file, mat._file, currentChunk._length - currentChunk._bytesread, &bytesRead, NULL);
					currentChunk._bytesread += bytesRead;
				}
				break;

				default:
				{
					skipChunk(currentChunk);
				}
				break;
				}

				chunk._bytesread += currentChunk._bytesread;
			}
		}

		//.........................................//
		void File3DS::readColorChunk(entity::MeshMaterial& material, Chunk& chunk)
		{
			Chunk tempChunk = { 0 };
			readChunk(tempChunk);

			DWORD bytesRead = 0;
			ReadFile(_file, material._color, tempChunk._length - tempChunk._bytesread, &bytesRead, NULL);

			tempChunk._bytesread += bytesRead;

			chunk._bytesread += tempChunk._bytesread;
		}

		//..........................................//
		void File3DS::readUVMapping(entity::Mesh& m, Chunk& chunk)
		{
			DWORD bytesRead = 0;

			ReadFile(_file, &(m._uv_count), 2, &bytesRead, NULL);

			chunk._bytesread += bytesRead;

			m._coordinate = new entity::MeshUV[m._uv_count];

			ZeroMemory(m._coordinate, sizeof(m._coordinate) * m._uv_count);

			ReadFile(_file, m._coordinate, chunk._length - chunk._bytesread, &bytesRead, NULL);

			chunk._bytesread += bytesRead;
		}

		//.........................................//
		bool File3DS::release()
		{
			return true;
		}
	}
}