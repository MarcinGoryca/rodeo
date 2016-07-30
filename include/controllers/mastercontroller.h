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
				//_module_initialized = false;
				setModuleInitialized(false);
			}

			/*
			 * ---------------------------------------------------------------
			 *	Gets initialization string
			 *  Returns std::wstring
			 * ---------------------------------------------------------------
			 */
			virtual std::wstring getString() const { return _initstr; }

			/*
			 * ---------------------------------------------------------------
			 *	Sets initialization string
			 *  Parameter std::wstring new initialization string
			 * ---------------------------------------------------------------
			 */
			virtual void setString(std::wstring str) { _initstr = str; }

			/*
			 * ---------------------------------------------------------------
			 *	Gets if module is initialized
			 *  Returns bool
			 * ---------------------------------------------------------------
			 */
			virtual bool getModuleInitialized() const { return _module_initialized; }

			/*
			 *----------------------------------------------------------------
			 *  Sets module initalized
			 *  Parameter bool module initialized
			 * ---------------------------------------------------------------
			 */
			virtual void setModuleInitialized(bool mi) { _module_initialized = mi; }
			

		protected:
			std::wstring _initstr;
			bool _module_initialized;
		};
	}
}
#endif