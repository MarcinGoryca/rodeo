/*
 |  ----------------------------------------------
 |     MG GAME ENGINE
 |     [ Effects.h ] [ mg\renderer ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef MG_RENDERER_EFFECTS_H_
#define MG_RENDERER_EFFECTS_H_

namespace mg
{
    namespace renderer
    {
        class Effects : public Entity
        {
            public:
                Effects(std::string filename);
            protected:
            private:
                Effects(){}
        };
    }    // end of renderer namespace
}    // end of mg namespace
#endif