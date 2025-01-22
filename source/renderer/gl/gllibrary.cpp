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
#include "renderer\gl\gllibrary.h"

namespace rodeo
{
namespace renderer
{
bool lineAntialias()
{
    glEnable(GL_LINE_SMOOTH);
    return true;
}

/* ... */
bool pointAntialias()
{
    glEnable(GL_POINT_SMOOTH);
    return true;
}

/* ... */
void polygonMode(GLenum face, GLenum mode)
{
    glPolygonMode(face, mode);
}

/* ... */
bool polyFrontFill()
{
    glPolygonMode(GL_FRONT, GL_FILL);
    return true;
}

/* ... */
bool polyFrontLine()
{
    glPolygonMode(GL_FRONT, GL_LINE);
    return true;
}

/* ... */
bool polyFrontPoint()
{
    glPolygonMode(GL_FRONT, GL_POINT);
    return true;
}

/* ... */
bool polyFrontBackFill()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    return true;
}

/* ... */
bool polyFrontBackLine()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    return true;
}

/* ... */
bool polyFrontBackPoint()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    return true;
}

/* ... */
bool cullFrontOn()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    return true;
}

/* ... */
bool cullBackOn()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    return true;
}

/* ... */
bool cullFrontBackOn()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT_AND_BACK);
    return true;
}

/* ... */
bool cullFrontOff()
{
    glDisable(GL_CULL_FACE);
    return true;
}

/* ... */
bool cullBackOff()
{
    glDisable(GL_CULL_FACE);
    return true;
}

/* ... */
bool cullFrontBackOff()
{
    glDisable(GL_CULL_FACE);
    return true;
}

/* ... */
bool polygonWinding(GLenum mode)
{
    glFrontFace(mode);
    return true;
}

/* ... */
bool polygonWithEdges(GLboolean edge)
{
    glEdgeFlag(edge);
    return true;
}

/* ... */
bool polygonAntialias()
{
    glEnable(GL_POLYGON_SMOOTH);
    return true;
}

/* ... */
bool shadeMode(GLenum mode)
{
    glShadeModel(mode);
    return true;
}

/* ... */
bool lightingOn()
{
    glEnable(GL_LIGHTING);
    return true;
}

/* ... */
bool lightingOff()
{
    glDisable(GL_LIGHTING);
    return true;
}

/* ... */
bool depthTestOn()
{
    glEnable(GL_DEPTH_TEST);
    return true;
}

/* ... */
bool depthTestOff()
{
    glDisable(GL_DEPTH_TEST);
    return true;
}

/* ... */
bool scissorsOn()
{
    glEnable(GL_SCISSOR_TEST);
    return true;
}

/* ... */
bool scissorsOff()
{
    glDisable(GL_SCISSOR_TEST);
    return true;
}

/* ... */
bool stencilOn()
{
    glEnable(GL_STENCIL_TEST);
    return true;
}

/* ... */
bool stencilOff()
{
    glDisable(GL_STENCIL_TEST);
    return true;
}

/* ... */
void push()
{
    glPushMatrix();
}

/* ... */
void pop()
{
    glPopMatrix();
}

/* ... */
bool pointSize(float ps)
{
    glPointSize(ps);
    return true;
}

/* ... */
bool lineWidth(float lw)
{
    glLineWidth(lw);
    return true;
}

/* ... */
bool lightModel(GLenum mode, float r, float g, float b)
{
    float ambientLight[] = {r, g, b};
    glLightModelfv(mode, ambientLight);
    return true;
}

/* ... */
bool colorMaterial()
{
    glEnable(GL_COLOR_MATERIAL);
    return true;
}

/* ... */
bool colorMaterialMode(GLenum face, GLenum mode)
{
    glColorMaterial(face, mode);
    return true;
}

/* ... */
bool blendingOn()
{
    glEnable(GL_BLEND);
    return true;
}

/* ... */
bool blendingOff()
{
    glDisable(GL_BLEND);
    return true;
}

/* ... */
bool texturingOn()
{
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    return true;
}

/* ... */
bool texturingOff()
{
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);
    return true;
}
}
}