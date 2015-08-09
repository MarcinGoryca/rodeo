/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "renderer\font.h"

using namespace mg::core;
using namespace std;

namespace mg
{
namespace renderer
{

void Font::init()
{
    error_ = FT_Init_FreeType(&library_);
    if(error_)
    {
        MessageBox(NULL, FREETYPE_LIBRARY_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        library_ = NULL;
    }
    error_ = FT_New_Face(library_, getFontfile(), 0, &face_); 
    if(error_ == FT_Err_Unknown_File_Format)
    {
        MessageBox(NULL, FREETYPE_UNKNOWN_FILE_FORMAT.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
    }
    else if(error_)
    {
        MessageBox(NULL, FREETYPE_BROKEN_FONT_FILE.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        face_ = NULL;
    }
    /*error_ = FT_Set_Char_Size(face_, 0, 16*64, 300, 300); 
    if(error_)
    {
        MessageBox(NULL, FreeType_Char_Size_Error, HEADER, errIconOK);
    }*/

    glGenBuffers(1, &vbo_);
    //glBindBuffer(GL_ARRAY_BUFFER, vbo_);
}

//----------------------------------------------------------

void Font::draw()
{
}

// ---- //
void Font::print(std::string text, float x, float y, float sx, float sy)
{
    const char* tp;

    slot_ = face_->glyph;

    GLuint tex;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(uniform_tex_, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
   
    glEnableVertexAttribArray(attr_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glVertexAttribPointer(attr_, 4, GL_FLOAT, GL_FALSE, 0, 0);


    for (tp = text.c_str(); *tp; tp++) {
        if (FT_Load_Char(face_, *tp, FT_LOAD_RENDER))
            continue;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, slot_->bitmap.width, slot_->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, slot_->bitmap.buffer);

        float x2 = x + slot_->bitmap_left * sx;
        float y2 = -y - slot_->bitmap_top * sy;
        float w = slot_->bitmap.width * sx;
        float h = slot_->bitmap.rows * sy;

        Glyph box[4] = {
            {x2, -y2, 0, 0},
            {x2 + w, -y2, 1, 0},
            {x2, -y2 - h, 0, 1},
            {x2 + w, -y2 - h, 1, 1}
        };
        glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        x += (slot_->advance.x >> 6) * sx;
        y += (slot_->advance.y >> 6) * sy;
    }
    glDisableVertexAttribArray(attr_);
    glDeleteTextures(1, &tex);
}

// ---- //
void Font::print(std::string text, float x, float y)
{
    const char* tp;
    setPositionX(x);
    setPositionY(y);
    //float sx = 2.0f / 1600;
    //float sy = 2.0f / 1050;
    slot_ = face_->glyph;

    position_x_ = position_x_ + 8 * scale_x_;
    position_y_ = 1 - position_y_ * scale_y_;
    //setPositionX(getPositionX() + 8 * getScaleX());
    //setPositionY(1 - getPositionY() * getScaleY());
    //y = 1 - y * sy;

    GLuint tex;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(uniform_tex_, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glEnableVertexAttribArray(attr_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glVertexAttribPointer(attr_, 4, GL_FLOAT, GL_FALSE, 0, 0);


    for (tp = text.c_str(); *tp; tp++) {
        if (FT_Load_Char(face_, *tp, FT_LOAD_RENDER))
            continue;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, slot_->bitmap.width, slot_->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, slot_->bitmap.buffer);

        float x2 = getPositionX() + slot_->bitmap_left * getScaleX();
        float y2 = -position_y_ - slot_->bitmap_top *getScaleY();
        float w = slot_->bitmap.width * getScaleX();
        float h = slot_->bitmap.rows * getScaleY();

        Glyph box[4] = {
            { x2, -y2, 0, 0 },
            { x2 + w, -y2, 1, 0 },
            { x2, -y2 - h, 0, 1 },
            { x2 + w, -y2 - h, 1, 1 }
        };
        glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        position_x_ += (slot_->advance.x >> 6) * getScaleX();
        position_y_ += (slot_->advance.y >> 6) * getScaleY();
    }
    glDisableVertexAttribArray(attr_);
    glDeleteTextures(1, &tex);
}

// ---- //
void Font::setFontSize(ui height)
{
    FT_Set_Pixel_Sizes(getFace(), 0, height);
}
}    // end of renderer namespace
}    // end of mg namespace