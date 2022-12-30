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
//#include "renderer\font.h"
//
//using namespace rodeo::core;
//using namespace std;
//
//namespace rodeo
//{
//	namespace renderer
//	{
//
//		void Font::init()
//		{
//			_error = FT_Init_FreeType(&_library);
//			if (_error)
//			{
//				MessageBox(NULL, FREETYPE_LIBRARY_LOAD_FAIL.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
//				_library = NULL;
//			}
//			_error = FT_New_Face(_library, getFontfile(), 0, &_face);
//			if (_error == FT_Err_Unknown_File_Format)
//			{
//				MessageBox(NULL, FREETYPE_UNKNOWN_FILE_FORMAT.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
//			}
//			else if (_error)
//			{
//				MessageBox(NULL, FREETYPE_BROKEN_FONT_FILE.c_str(), RODEO_HEADER.c_str(), ERR_ICON_OK);
//				_face = NULL;
//			}
//			/*_error = FT_Set_Char_Size(_face, 0, 16*64, 300, 300);
//			if(_error)
//			{
//				MessageBox(NULL, FreeType_Char_Size_Error, HEADER, errIconOK);
//			}*/
//
//			glGenBuffers(1, &_vbo);
//			//glBindBuffer(GL_ARRAY_BUFFER, _vbo);
//		}
//
//		//----------------------------------------------------------
//
//		void Font::draw()
//		{
//		}
//
//		// ---- //
//		void Font::print(std::string text, float x, float y, float sx, float sy)
//		{
//			const char* tp;
//
//			_slot = _face->glyph;
//
//			GLuint tex;
//			glActiveTexture(GL_TEXTURE0);
//			glGenTextures(1, &tex);
//			glBindTexture(GL_TEXTURE_2D, tex);
//			glUniform1i(_uniform_tex, 0);
//
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//			glEnableVertexAttribArray(_attr);
//			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
//			glVertexAttribPointer(_attr, 4, GL_FLOAT, GL_FALSE, 0, 0);
//
//
//			for (tp = text.c_str(); *tp; tp++) {
//				if (FT_Load_Char(_face, *tp, FT_LOAD_RENDER))
//					continue;
//				glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, _slot->bitmap.width, _slot->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, _slot->bitmap.buffer);
//
//				float x2 = x + _slot->bitmap_left * sx;
//				float y2 = -y - _slot->bitmap_top * sy;
//				float w = _slot->bitmap.width * sx;
//				float h = _slot->bitmap.rows * sy;
//
//				Glyph box[4] = {
//					{x2, -y2, 0, 0},
//					{x2 + w, -y2, 1, 0},
//					{x2, -y2 - h, 0, 1},
//					{x2 + w, -y2 - h, 1, 1}
//				};
//				glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_DYNAMIC_DRAW);
//				glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//
//				x += (_slot->advance.x >> 6) * sx;
//				y += (_slot->advance.y >> 6) * sy;
//			}
//			glDisableVertexAttribArray(_attr);
//			glDeleteTextures(1, &tex);
//		}
//
//		// ---- //
//		void Font::print(std::string text, float x, float y)
//		{
//			const char* tp;
//			setPositionX(x);
//			setPositionY(y);
//			//float sx = 2.0f / 1600;
//			//float sy = 2.0f / 1050;
//			_slot = _face->glyph;
//
//			_position_x = _position_x + 8 * _scale_x;
//			_position_y = 1 - _position_y * _scale_y;
//			//setPositionX(getPositionX() + 8 * getScaleX());
//			//setPositionY(1 - getPositionY() * getScaleY());
//			//y = 1 - y * sy;
//
//			GLuint tex;
//			glActiveTexture(GL_TEXTURE0);
//			glGenTextures(1, &tex);
//			glBindTexture(GL_TEXTURE_2D, tex);
//			glUniform1i(_uniform_tex, 0);
//
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//			glEnableVertexAttribArray(_attr);
//			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
//			glVertexAttribPointer(_attr, 4, GL_FLOAT, GL_FALSE, 0, 0);
//
//
//			for (tp = text.c_str(); *tp; tp++) {
//				if (FT_Load_Char(_face, *tp, FT_LOAD_RENDER))
//					continue;
//				glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, _slot->bitmap.width, _slot->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, _slot->bitmap.buffer);
//
//				float x2 = getPositionX() + _slot->bitmap_left * getScaleX();
//				float y2 = -_position_y - _slot->bitmap_top *getScaleY();
//				float w = _slot->bitmap.width * getScaleX();
//				float h = _slot->bitmap.rows * getScaleY();
//
//				Glyph box[4] = {
//					{ x2, -y2, 0, 0 },
//					{ x2 + w, -y2, 1, 0 },
//					{ x2, -y2 - h, 0, 1 },
//					{ x2 + w, -y2 - h, 1, 1 }
//				};
//				glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_DYNAMIC_DRAW);
//				glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//
//				_position_x += (_slot->advance.x >> 6) * getScaleX();
//				_position_y += (_slot->advance.y >> 6) * getScaleY();
//			}
//			glDisableVertexAttribArray(_attr);
//			glDeleteTextures(1, &tex);
//		}
//
//		// ---- //
//		void Font::setFontSize(ui height)
//		{
//			FT_Set_Pixel_Sizes(getFace(), 0, height);
//		}
//	}
//}