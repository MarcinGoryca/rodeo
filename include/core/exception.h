﻿/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    [ Exception.h ] [ mona\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CORE_EXCEPTION_H_
#define MONA_CORE_EXCEPTION_H_

#include <string>

namespace mona
{
	namespace core
	{
		class Exception
		{
		public:
			Exception()
			:_exception_string(L"")
			{}

			/*
			 |  ---------------------------------------------------
			 |    Constructor
			 |    parameter [ wstring ]: the string to output
			 |  ---------------------------------------------------
			 */
			explicit Exception(std::wstring str)
				:_exception_string(str)
			{}

			/*
			 |  ---------------------------------------------------
			 |    Destructor
             |  ---------------------------------------------------			 
			 */
			virtual ~Exception() {}

			/* 
			 |  ---------------------------------------------------
			 |    Gets exception string
			 |    Returns [ wstring ]
			 |  ---------------------------------------------------
			 */
			std::wstring getExceptionString() const { return _exception_string; }

		private:
			std::wstring _exception_string;
		};
	}
}
#endif