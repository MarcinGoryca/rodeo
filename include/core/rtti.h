/*
 |  -----------------------------------
 |     LAURA GAME ENGINE
 |     [ Rtti.h ] [ laura\core ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CORE_RTTI_H_
#define LAURA_CORE_RTTI_H_

#ifndef LAURA_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

namespace laura
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