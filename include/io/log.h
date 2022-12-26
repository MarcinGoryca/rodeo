/*
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
//#ifndef RODEO_IO_LOG_H_
//#define RODEO_IO_LOG_H_
//
//#ifndef RODEO_CORE_ERROR_H_
//#include "core\error.h"
//#endif
//
//namespace rodeo
//{
//	namespace io
//	{
//		class Log
//		{
//		public:
//			Log()
//				:_hfile(NULL),
//				_filename(""),
//				_mode(""),
//				_fileopen(false)
//			{}
//
//			~Log()
//			{
//				_fileopen = false;
//				_mode = "";
//				_filename = "";
//				_hfile = NULL;
//			}
//
//			bool open(std::wstring filename);
//			void write(std::wstring string);
//
//		private:
//			HANDLE _hfile;
//			const char* _filename;
//			const char* _mode;
//			bool _fileopen;
//
//			//Copy constructor
//			Log(const Log& log);
//
//			void close();
//			void update(std::string filename, std::string buffer);
//			void save(std::wstring filename);
//			void load(std::string filename);
//		};
//	}
//}
//#endif