﻿/*
 |  ----------------------------------------------
 |    MG GAME ENGINE
 |    [ Buffers.h ] [ mg\renderer ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef MG_RENDERER_BUFFERS_H_
#define MG_RENDERER_BUFFERS_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "renderer\gl\glcommon.h"
#endif

#ifndef MG_ENTITY_MODEL_H_
#include "entity\model.h"
#endif

namespace mg
{
	namespace renderer
	{
		class Buffers
		{
		public:
			Buffers() {}

			~Buffers() {}

			/*
			 |  ----------------------------------------------------------------------------------
			 |    Inits the buffers
			 |    Parameter ArrayType - RODEO_ARRAY, RODEO_ELEMENT
			 |    Parameter unsigned int count - how many objects to generate
			 |    Parameter unsigned int buffer - buffer object
			 |    Parameter const float* data - actual geometry of the object
			 |  ----------------------------------------------------------------------------------
			 */
			void init(gl::ArrayType at, core::ui count, core::ui buffer, const float* data, gl::ArrayDraw ad);

			/*
			 |  ----------------------------------------------------------------------------------
			 |    Inits the buffers
			 |    Parameter ArrayType RODEO_ARRAY, RODEO_ELEMENT
			 |    Parameter ArrayDraw RODEO_STATIC, RODEO_STREAM, RODEO_DYNAMIC
			 |  ----------------------------------------------------------------------------------
			 */
			void initBuffers(gl::ArrayType array_type, gl::ArrayDraw array_draw, const float* data);

			/*
			 |  ----------------------------------------------------------------------------------
			 |    Draws the data
			 |    Parameter ArrayType RODEO_ARRAY, RODEO_ELEMENT
			 |    Parameter int attribute in shader
			 |    Parameter const float* data to draw
			 |  ----------------------------------------------------------------------------------
			 */
			void draw(gl::ArrayType array_type, int attrib, const float* data);

			/*
			 |  -----------------------------------------------------------------------------------
			 |    Draws the data
			 |    Parameter ArrayType RODEO_ARRAY, RODEO_ELEMENT
			 |    Parameter DrawingMode RODEO_TRIANGLES, RODEO_TRIANGLE_STRIP, RODEO_TRIANGLE_FAN, RODEO_POINTS,
			 |                    RODEO_LINES, RODEO_LINE_STRIP, RODEO_LINE_LOOP, RODEO_QUADS
			 |    Parameter int reference to attribute from the shader
			 |    Parameter const float* data to draw
			 |  ------------------------------------------------------------------------------------
			 */
			void draw(gl::ArrayType array_type, gl::DrawingMode drawing_mode, int& attrib, const float* data);

			/*
			 |  ---------------------------------------------------------------------------------------------------
			 |    Creates buffer object
			 |    Parameter unsigned int buffer - object of Vertex Buffer, Color Buffer, Normal Buffer, Element Buffer
			 |    Parameter enumeration BufferType - RODEO_VBO, RODEO_CBO, RODEO_NBO, RODEO_TBO, RODEO_EBO
			 |  ---------------------------------------------------------------------------------------------------
			 */
			void createBuffer(core::ui buffer, gl::BufferType bt);


			void fill(const entity::Model& model, core::ui stride);
			void fillWithTexture(const entity::Model& model, core::ui stride);
			void update();
			void reset();

			void draw(core::ui& vb);
			void draw(core::ui& vb, gl::DrawingMode dm);

			void draw(const entity::Model& model, core::ui stride);

			void scale(const entity::Model& model, float scale_factor, core::ui stride);

			void fill(float* va, core::ui& vb);

			void destroy(const entity::Model& model, core::ui stride);
			/*
			|  -----------------------------------------------------------------
			|    Sets Data of Geometry
			|    Parameter const float* data of Geometry
			|  -----------------------------------------------------------------
			*/
			void setData(const float* data) { _data = data; }

			/*
			|  -----------------------------------------------------------------
			|    Gets Data of Geometry
			|  -----------------------------------------------------------------
			*/
			const float* getData() const { return _data; }

			/*
			|  -----------------------------------------------------------------
			|    Gets Vertex Buffer Object
			|    Returns unsigned int value of created buffer object
			|  -----------------------------------------------------------------
			*/
			unsigned int getVertexObject() const { return _vbo; }

			/*
			|  -----------------------------------------------------------------
			|    Gets Color Buffer Object
			|    Returns unsigned int value of created buffer object
			|  -----------------------------------------------------------------
			*/
			unsigned int getColorObject() const { return _cbo; }

			/*
			|  -----------------------------------------------------------------
			|    Gets Normal Buffer Object
			|    Returns unsigned int value of created buffer object
			|  -----------------------------------------------------------------
			*/
			unsigned int getNormalObject() const { return _nbo; }

			/*
			|  -------------------------------------------------------------------
			|    Gets Texture Buffer Object
			|    Returns unsigned int value of created buffer object
			|  -------------------------------------------------------------------
			*/
			unsigned int getTextureObject() const { return _tbo; }

			/*
			|  ------------------------------------------------------------------
			|    Gets Element Buffer Object
			|    Returns unsigned int value of created buffer object
			|  ------------------------------------------------------------------
			*/
			unsigned int getElementObject() const { return _ebo; }

			/*
			|  -------------------------------------------------------------------
			|    Fills buffers with model data
			|    Parameter stride - for multiple meshes in model file
			|    Call this method in Model3D create() method,
			|    simply pass by reference model_, and usually i as a stride
			|  -------------------------------------------------------------------
			*/

		private:
			unsigned int _vbo;
			unsigned int _cbo;
			unsigned int _nbo;
			unsigned int _tbo;
			unsigned int _ebo;
			const float* _data;

			/*
			 |  -------------------------------------------------------
			 |    Copy constructor
			 |  -------------------------------------------------------
			 */
			Buffers(const Buffers& copy);

			/*
			 |  -------------------------------------------------------
			 |    Copy operator
			 |  -------------------------------------------------------
			 */
			Buffers operator=(const Buffers& copy);
		};
	}
}
#endif