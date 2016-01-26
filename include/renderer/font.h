/*
 |  ----------------------------------------------
 |      MG GAME ENGINE
 |      [ Font.h ] [ mg\renderer ]
 |      Copyright(c) Marcin Goryca
 |      marcin.goryca@gmail.com
 |      http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef MG_RENDERER_FONT_H_
#define MG_RENDERER_FONT_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_RENDERER_COLORS_H_
#include "renderer\colors.h"
#endif

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#include "freetype\include\ft2build.h"
#include FT_FREETYPE_H

namespace mg
{
    namespace renderer
    {
        struct Glyph
        {
            float x_;
            float y_;
            float s_;
            float t_;
        };

        class Font : public entity::Entity
        {
            public:
                Font()
                    :text_(""),
                    fontfile_(""),
                    error_(0),
                    pen_(),
                    library_(NULL),
                    face_(NULL),
                    slot_(NULL),
                    glyph_(),
                    position_x_(0.0f),
                    position_y_(0.0f),
                    scale_x_(0.0f),
                    scale_y_(0.0f)
                {}

                /*
                 |  -------------------------------------------------------------------------
                 |    Constructor
                 |    Parameter const char* fontfile - Filename of the font to use with path.
                 |        "\\assets\\fonts\\verdana.ttf"
                 |  -------------------------------------------------------------------------
                 */
                Font(const char* fontfile)
                    :text_(""),
                    error_(0),
                    pen_(),
                    library_(NULL),
                    face_(NULL),
                    slot_(NULL),
                    glyph_(),
                    position_x_(0.0f),
                    position_y_(0.0f),
                    scale_x_(0.0f),
                    scale_y_(0.0f)
                {
                    fontfile_ = fontfile;
                }

                virtual ~Font() {}

                /*
                 |  -------------------------------------------------
                 |    Inits the object of the Font class
                 |  -------------------------------------------------
                 */
                void init();

                /*
                 |  -------------------------------------------------
                 |    Overloaded method from Entity base class
                 |  -------------------------------------------------
                 */
                virtual void draw();

                /*
                 |  ----------------------------------------------------------------
                 |    Prints out the text to the screen
                 |    Parameter string text - text to print
                 |    Parameter float x - starting point of the text in the X-axis
                 |    Parameter float y - starting point of the text in the Y-axis
                 |    Parameter float sx - scale of the font in the X-axis
                 |    Parameter float sy - scale of the font in the Y-axis
                 |  ----------------------------------------------------------------
                 */
                void print(std::string text, float x, float y, float sx, float sy);

                // Prints out the text to the screen
                void print(std::string text, float x, float y);

                // Sets new Size for the font
                void setFontSize(core::ui height);

                void setText(const char* text) { text_ = text; }
                const char* getText()const { return text_; }

                void setFontfile(const char* fontfile) { fontfile_ = fontfile; }
                const char* getFontfile()const { return fontfile_; }

                // Gets the error code
                // Returns Code of the error 0 - success, 1 - fail
                FT_Error getError()const { return error_; }

                // Gets the 2D vector structure
                FT_Vector getPen()const { return pen_; }

                // Get the handle of the library
                // Returns The handle to a library
                FT_Library getLibrary()const { return library_; }

                // Get the handle to the face object
                // Returns The handle to the face object
                FT_Face getFace()const { return face_; }

                // Get the slot for glyphs
                // Returns The slot (container)
                FT_GlyphSlot getGlyphSlot()const { return slot_; }

                float getPositionX()const { return position_x_; }
                void setPositionX(float npx) { position_x_ = npx; }

                float getPositionY()const { return position_y_; }
                void setPositionY(float npy) { position_y_ = npy; }

                float getScaleX()const { return scale_x_; }
                void setScaleX(float nsx) { scale_x_ = nsx; }

                float getScaleY()const { return scale_y_; }
                void setScaleY(float nsy) { scale_y_ = nsy; }

                //TODO
                // Remove this members and use other struct/class for OpenGL-specific members
                GLuint vbo_;
                GLuint tex_;
                GLint uniform_tex_;
                GLint uniform_color_;
                GLint attr_;

        private:
            const char* text_;
            const char* fontfile_;

            // Error code type.
            // A value of 0 is always interpreted as a successful operation.
            FT_Error error_;

            // A simple structure used to store 2D Vector.
            FT_Vector pen_;

            // A handle to library instance
            FT_Library library_;

            // A handle to a given typographic face object
            FT_Face face_;

            // A handle to a given 'glyph slot'.<br/>
            // A slot is a container where it is possible<br/>
            // to load any of the glyphs contained in its parent face.
            FT_GlyphSlot slot_;
            Glyph glyph_;
            float position_x_;
            float position_y_;
            float scale_x_;
            float scale_y_;
        };
    }    // end of renderer namespace
}    // end of mg namespace
#endif