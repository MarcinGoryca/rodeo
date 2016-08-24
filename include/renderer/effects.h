/*
 |  ----------------------------------------------
 |     mona GAME ENGINE
 |     [ Effects.h ] [ mona\renderer ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef MONA_RENDERER_EFFECTS_H_
#define MONA_RENDERER_EFFECTS_H_

//#include "core\common.h"

#ifndef MONA_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace mona
{
    namespace renderer
    {
        class Effects : public mona::entity::Entity
        {
            public:
                Effects(std::string filename);
            protected:
            private:
                Effects(){}
        };
    }
}
#endif