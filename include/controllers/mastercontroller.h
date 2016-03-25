/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ MasterController.h ] [ mg\ core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_MASTERCONTROLLER_H
#define MG_CORE_MASTERCONTROLLER_H

#ifndef MG_CORE_COMMON_H_
#include "common.h"
#endif

namespace mg
{
	namespace core
	{
		class MasterController
		{
		public:
			MasterController()
				:module_initialized_(false)
			{
				initstr_.clear();
			}

			virtual ~MasterController()
			{
				initstr_.clear();
				module_initialized_ = false;
			}

			bool module_initialized_;

			virtual std::wstring getString() const { return initstr_; }

		protected:
			std::wstring initstr_;
		};
	}    // end of core namespace
}    // end of mg namespace
#endif    // MG_CORE_MASTERCONTROLLER_H_