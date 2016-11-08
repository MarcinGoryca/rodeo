/*
 |  ----------------------------------------------
 |     LAURA GAME ENGINE
 |     [ Effects.h ] [ laura\renderer ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef LAURA_RENDERER_EFFECTS_H_
#define LAURA_RENDERER_EFFECTS_H_

//#include "core\common.h"

#ifndef LAURA_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

namespace laura
{
    namespace renderer
    {
        class Effects : public laura::entity::Entity
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