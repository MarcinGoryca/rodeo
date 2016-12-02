/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
#ifndef LAURA_CORE_MASTERCONTROLLER_H
#define LAURA_CORE_MASTERCONTROLLER_H

#ifndef LAURA_CORE_COMMON_H_
#include "core\common.h"
#endif

namespace laura
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