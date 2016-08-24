/*
 |  -----------------------------------------------
 |    mona GAME ENGINE
 |    [ OutputController.h ] [ mona\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------------------
 */

#ifndef MONA_CORE_OUTPUTCONTROLLER_H
#define MONA_CORE_OUTPUTCONTROLLER_H

#ifndef MONA_IO_LOG_H_
#include "io/log.h"
#endif

#ifndef MONA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers/mastercontroller.h"
#endif

namespace mona
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