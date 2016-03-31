/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ MasterController.h ] [ mg\ controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_MASTERCONTROLLER_H
#define MG_CORE_MASTERCONTROLLER_H

#ifndef MG_CORE_COMMON_H_
#include "core\common.h"
#endif

namespace mg
{
	namespace controllers
	{
		class MasterController
		{
		public:
			MasterController()
				:_module_initialized(false)
			{
				_initstr.clear();
			}

			virtual ~MasterController()
			{
				_initstr.clear();
				_module_initialized = false;
			}

			bool _module_initialized;

			virtual std::wstring getString() const { return _initstr; }

		protected:
			std::wstring _initstr;
		};
	}
}
#endif