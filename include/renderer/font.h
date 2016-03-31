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

#ifndef MG_RENDERER_GL_GLCOMMON_H_
#include "renderer\gl\glcommon.h"
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
            float _x;
            float _y;
            float _s;
            float _t;
        };

        class Font : public entity::Entity
        {
            public:
                Font()
                    :_text(""),
                    _fontfile(""),
                    _error(0),
                    _pen(),
                    _library(NULL),
                    _face(NULL),
                    _slot(NULL),
                    _glyph(),
                    _position_x(0.0f),
                    _position_y(0.0f),
                    _scale_x(0.0f),
                    _scale_y(0.0f)
                {}

                /*
                 |  -------------------------------------------------------------------------
                 |    Constructor
                 |    Parameter const char* fontfile - Filename of the font to use with path.
                 |        "\\assets\\fonts\\verdana.ttf"
                 |  -------------------------------------------------------------------------
                 */
                Font(const char* fontfile)
                    :_text(""),
                    _error(0),
                    _pen(),
                    _library(NULL),
                    _face(NULL),
                    _slot(NULL),
                    _glyph(),
                    _position_x(0.0f),
                    _position_y(0.0f),
                    _scale_x(0.0f),
                    _scale_y(0.0f)
                {
                    _fontfile = fontfile;
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

                void setText(const char* text) { _text = text; }
                const char* getText()const { return _text; }

                void setFontfile(const char* fontfile) { _fontfile = fontfile; }
                const char* getFontfile()const { return _fontfile; }

                // Gets the error code
                // Returns Code of the error 0 - success, 1 - fail
                FT_Error getError()const { return _error; }

                // Gets the 2D vector structure
                FT_Vector getPen()const { return _pen; }

                // Get the handle of the library
                // Returns The handle to a library
                FT_Library getLibrary()const { return _library; }

                // Get the handle to the face object
                // Returns The handle to the face object
                FT_Face getFace()const { return _face; }

                // Get the slot for glyphs
                // Returns The slot (container)
                FT_GlyphSlot getGlyphSlot()const { return _slot; }

                float getPositionX()const { return _position_x; }
                void setPositionX(float npx) { _position_x = npx; }

                float getPositionY()const { return _position_y; }
                void setPositionY(float npy) { _position_y = npy; }

                float getScaleX()const { return _scale_x; }
                void setScaleX(float nsx) { _scale_x = nsx; }

                float getScaleY()const { return _scale_y; }
                void setScaleY(float nsy) { _scale_y = nsy; }

                //TODO
                // Remove this members and use other struct/class for OpenGL-specific members
                GLuint _vbo;
                GLuint _tex;
                GLint _uniform_tex;
                GLint _uniform_color;
                GLint _attr;

        private:
            const char* _text;
            const char* _fontfile;

            // Error code type.
            // A value of 0 is always interpreted as a successful operation.
            FT_Error _error;

            // A simple structure used to store 2D Vector.
            FT_Vector _pen;

            // A handle to library instance
            FT_Library _library;

            // A handle to a given typographic face object
            FT_Face _face;

            // A handle to a given 'glyph slot'.<br/>
            // A slot is a container where it is possible<br/>
            // to load any of the glyphs contained in its parent face.
            FT_GlyphSlot _slot;
            Glyph _glyph;
            float _position_x;
            float _position_y;
            float _scale_x;
            float _scale_y;
        };
    }
}
#endif