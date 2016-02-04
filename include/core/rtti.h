/*
 |  -----------------------------------
 |     MG GAME ENGINE
 |     [ Rtti.h ] [ mg\core ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_RTTI_H_
#define MG_CORE_RTTI_H_

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace mg
{
    namespace core
    {
        class RTTI
        {
        public:
            RTTI(const std::string& name)
                :classname_(name)
            {}

            virtual const std::string& getClassName()const { return classname_; }

            ~RTTI() {}

        private:
            std::string classname_;
        };
    }    // end of core namespace
}    // end of mg namespace
#endif