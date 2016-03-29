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

//#include "core\common.h"

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace mg
{
    namespace renderer
    {
        class Effects : public mg::entity::Entity
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