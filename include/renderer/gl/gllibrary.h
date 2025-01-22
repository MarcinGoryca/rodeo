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
#pragma once

#include "glcommon.h"

namespace rodeo {
	namespace renderer {
		bool lineAntialias();
		bool pointAntialias();
		void polygonMode(GLenum face, GLenum mode);
		bool polyFrontFill();
		bool polyFrontLine();
		bool polyFrontPoint();
		bool polyFrontBackFill();
		bool polyFrontBackLine();
		bool polyFrontBackPoint();
		bool cullFrontOn();
		bool cullBackOn();
		bool cullFrontBackOn();
		bool cullFrontOff();
		bool cullBackOff();
		bool cullFrontBackOff();
		bool polygonWinding(GLenum mode);
		bool polygonWithEdges(GLboolean edge);
		bool polygonAntialias();
		bool shadeMode(GLenum mode);
		bool lightingOn();
		bool lightingOff();
		bool depthTestOn();
		bool depthTestOff();
		bool scissorsOn();
		bool scissorsOff();
		bool stencilOn();
		bool stencilOff();
		void push();
		void pop();
		bool pointSize(float ps);
		bool lineWidth(float lw);
		bool lightModel(GLenum mode, float r, float g, float b);
		bool colorMaterial();
		bool colorMaterialMode(GLenum face, GLenum mode);
		bool blendingOn();
		bool blendingOff();
		bool texturingOn();
		bool texturingOff();
	}

}
