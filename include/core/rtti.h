/*
 |  -----------------------------------
 |     mona GAME ENGINE
 |     [ Rtti.h ] [ mona\core ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CORE_RTTI_H_
#define MONA_CORE_RTTI_H_

#ifndef MONA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace mona
{
    namespace core
    {
        class Rtti
        {
        public:
            Rtti(const std::string& name)
                :_classname(name)
            {}

            virtual const std::string& getClassName()const { return _classname; }

            ~Rtti() {}

        private:
            std::string _classname;

			/*
			 | ---------------------------------------------------
			 |    Default constructor
			 | ---------------------------------------------------
			 */
			Rtti()
				:_classname("")
			{}
        };
    }
}
#endif