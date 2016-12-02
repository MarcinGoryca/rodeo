﻿/*
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
//
//#ifndef LAURA_CORE_OUTPUTCONTROLLER_H
//#define LAURA_CORE_OUTPUTCONTROLLER_H
//
//#ifndef LAURA_IO_LOG_H_
//#include "io/log.h"
//#endif
//
//#ifndef LAURA_CONTROLLERS_MASTERCONTROLLER_H_
//#include "controllers/mastercontroller.h"
//#endif
//
//namespace laura
//{
//	namespace controllers
//	{
//		class OutputController : public MasterController
//		{
//		public:
//
//			OutputController()
//				:MasterController()
//			{
//				init();
//			}
//
//			~OutputController()
//			{
//				clear();
//			}
//
//			/*
//			 * --------------------------------------------
//			 *    Gets Log
//			 *    Returns Log log
//			 * --------------------------------------------
//			 */
//
//			std::unique_ptr<io::Log*> getLog() const
//			{
//				return _log;
//			}
//
//		private:
//			void init();
//			void clear();
//
//			//io::Log* _log;
//			std::unique_ptr<io::Log*> _log;
//		};
//	}
//}
//#endif