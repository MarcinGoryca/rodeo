/*
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

#ifndef MG_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
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
    Buffers(){}
    
    ~Buffers(){}

    /*
	 |  ----------------------------------------------------------------------------------
	 |    Inits the buffers
     |    Parameter ArrayType - RODEO_ARRAY, RODEO_ELEMENT
     |    Parameter unsigned int count - how many objects to generate
     |    Parameter unsigned int buffer - buffer object
     |    Parameter const float* data - actual geometry of the object
	 |  ----------------------------------------------------------------------------------
	 */
    void init(ArrayType at, core::ui count, core::ui buffer, const float* data, ArrayDraw ad);

    /*
	 |  ----------------------------------------------------------------------------------
	 |    Inits the buffers
     |    Parameter ArrayType RODEO_ARRAY, RODEO_ELEMENT
     |    Parameter ArrayDraw RODEO_STATIC, RODEO_STREAM, RODEO_DYNAMIC
	 |  ----------------------------------------------------------------------------------
	 */
    void initBuffers(ArrayType array_type, ArrayDraw array_draw, const float* data);

    /*
	 |  ----------------------------------------------------------------------------------
	 |    Draws the data
     |    Parameter ArrayType RODEO_ARRAY, RODEO_ELEMENT
     |    Parameter int attribute in shader
     |    Parameter const float* data to draw
	 |  ----------------------------------------------------------------------------------
	 */
    void draw(ArrayType array_type, int attrib, const float* data);

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
    void draw(ArrayType array_type, DrawingMode drawing_mode, int& attrib, const float* data);

    /*
	 |  ---------------------------------------------------------------------------------------------------
	 |    Creates buffer object
     |    Parameter unsigned int buffer - object of Vertex Buffer, Color Buffer, Normal Buffer, Element Buffer
     |    Parameter enumeration BufferType - RODEO_VBO, RODEO_CBO, RODEO_NBO, RODEO_TBO, RODEO_EBO
	 |  ---------------------------------------------------------------------------------------------------
	 */
    void createBuffer(core::ui buffer, BufferType bt);

    /*
	 |  -----------------------------------------------------------------
	 |    Sets Data of Geometry
     |    Parameter const float* data of Geometry
	 |  -----------------------------------------------------------------
	 */
    void setData(const float* data) { data_ = data; }

    /*
	 |  -----------------------------------------------------------------
	 |    Gets Data of Geometry
	 |  -----------------------------------------------------------------
	 */
    const float* getData() const { return data_; }

    /*
	 |  -----------------------------------------------------------------
	 |    Gets Vertex Buffer Object
     |    Returns unsigned int value of created buffer object
	 |  -----------------------------------------------------------------
	 */
    core::ui getVertexObject() const { return vbo; }

    /*
	 |  -----------------------------------------------------------------
	 |    Gets Color Buffer Object
     |    Returns unsigned int value of created buffer object
	 |  -----------------------------------------------------------------
	 */
    core::ui getColorObject() const { return cbo; }

    /*
	 |  -----------------------------------------------------------------
	 |    Gets Normal Buffer Object
     |    Returns unsigned int value of created buffer object
	 |  -----------------------------------------------------------------
	 */
    core::ui getNormalObject() const { return nbo; }

    /*
	 |  -------------------------------------------------------------------
	 |    Gets Texture Buffer Object
     |    Returns unsigned int value of created buffer object
	 |  -------------------------------------------------------------------
	 */
    core::ui getTextureObject() const { return tbo; }

    /*
	 |  ------------------------------------------------------------------
	 |    Gets Element Buffer Object
     |    Returns unsigned int value of created buffer object
	 |  ------------------------------------------------------------------
	 */
    core::ui getElementObject() const { return ebo; }

    /*
	 |  -------------------------------------------------------------------
	 |    Fills buffers with model data 
     |    Parameter stride - for multiple meshes in model file
     |    Call this method in Model3D create() method, 
     |    simply pass by reference model_, and usually i as a stride
	 |  -------------------------------------------------------------------
	 */
    void fill(const entity::Model& model, core::ui stride);
    void fillWithTexture(const entity::Model& model, core::ui stride);
    void update();
    void reset();

    void draw(core::ui& vb);
    void draw(core::ui& vb, DrawingMode dm);

    void draw(const entity::Model& model, core::ui stride);

    void scale(const entity::Model& model, float scale_factor, core::ui stride);

    void fill(float* va, core::ui& vb);

    void destroy(const entity::Model& model, core::ui stride);

private:
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

    core::ui vbo;
    core::ui cbo;
    core::ui nbo;
    core::ui tbo;
    core::ui ebo;
    const float* data_;
};
}    // end of renderer namespace
}    // end of mg namespace
#endif