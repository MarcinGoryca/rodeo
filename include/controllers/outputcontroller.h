/*
 |  -----------------------------------------------
 |    MG GAME ENGINE
 |    [ OutputController.h ] [ mg\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------------------
 */

#ifndef MG_CORE_OUTPUTCONTROLLER_H
#define MG_CORE_OUTPUTCONTROLLER_H

#ifndef MG_IO_LOG_H_
#include "io/log.h"
#endif

#ifndef MG_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers/mastercontroller.h"
#endif

namespace mg
{
	namespace controllers
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

			/*
			 * --------------------------------------------
			 *    Gets Log
			 *    Returns Log log
			 * --------------------------------------------
			 */

			std::unique_ptr<io::Log*> getLog() const
			{
				return _log;
			}

		private:
			void init();
			void clear();

			//io::Log* _log;
			std::unique_ptr<io::Log*> _log;
		};
	}
}
#endif