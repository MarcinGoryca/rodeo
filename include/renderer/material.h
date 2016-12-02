/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
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
//#ifndef LAURA_RENDERER_MATERIAL_H_
//#define LAURA_RENDERER_MATERIAL_H_
//
//namespace laura
//{
//	namespace renderer
//	{
//		class Material
//		{
//		public:
//			Material();
//			~Material() {}
//
//			inline void setSpecular(float r, float g, float b, float a)
//			{
//				_specular[0] = r;
//				_specular[1] = g;
//				_specular[2] = b;
//				_specular[3] = a;
//			}
//
//			inline void setAmbient(float r, float g, float b, float a)
//			{
//				_ambient[0] = r;
//				_ambient[1] = g;
//				_ambient[2] = b;
//				_ambient[3] = a;
//			}
//
//			inline void setDiffuse(float r, float g, float b, float a)
//			{
//				_diffuse[0] = r;
//				_diffuse[1] = g;
//				_diffuse[2] = b;
//				_diffuse[3] = a;
//			}
//
//			inline void setShininess(float ns)
//			{
//				_shininess[0] = ns;
//			}
//
//			const float* getSpecular()const { return &_specular[0]; }
//			const float* getAmbient()const { return &_ambient[0]; }
//			const float* getDiffuse()const { return &_diffuse[0]; }
//			const float* getShininess()const { return &_shininess[0]; }
//
//		private:
//			float _specular[4];
//			float _ambient[4];
//			float _diffuse[4];
//			float _shininess[1];
//		};
//	}
//}
//#endif