﻿/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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
#ifndef RODEO_CORE_EXCEPTION_H_
#define RODEO_CORE_EXCEPTION_H_

#include <string>

namespace rodeo
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