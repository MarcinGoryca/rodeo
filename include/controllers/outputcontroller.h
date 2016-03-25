/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ OutputController.h ] [ mg\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_OUTPUTCONTROLLER_H
#define MG_CORE_OUTPUTCONTROLLER_H

#ifndef MG_IO_LOG_H_
#include "io/log.h"
#endif

#ifndef MG_CORE_MASTERCONTROLLER_H_
#include "core/mastercontroller.h"
#endif

namespace mg
{
	namespace core
	{
		class OutputController : public MasterController
		{
		public:

			OutputController()
				:MasterController()
			{
				init();
			}

			~OutputController()
			{
				clear();
			}

			mg::io::Log* getLog() const
			{
				return log_;
			}

		private:
			void init();
			void clear();

			io::Log* log_;
		};
	}    // end of core namespace
}    // end of mg namespace
#endif    // MG_CORE_OUTPUTCONTROLLER_H_