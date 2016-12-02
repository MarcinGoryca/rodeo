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
//#include "tools\htmlwriter.h"
//
//using namespace std;
//using namespace laura::core;
//
//namespace laura
//{
//	namespace tools
//	{
//		bool HtmlWriter::writeToHTML(wstring filename, string s)
//		{
//			create(filename);
//			addToPage(s);
//			CloseHandle(_hfile);
//			return true;
//		}
//
//		bool HtmlWriter::create(wstring filename)
//		{
//			_hfile = CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//
//			if (_hfile == INVALID_HANDLE_VALUE)
//			{
//				MessageBox(NULL, HTMLFILE_LOAD_FAIL.c_str(), LAURA_HEADER.c_str(), ERR_ICON_OK);
//				return false;
//			}
//			return true;
//		}
//
//		void HtmlWriter::writeHeader()
//		{
//			const char* const doctype = "<!DOCTYPE html>\n<html lang=\"en\">\n";
//			const char* const header = "<head>\n\t<title>Rodeo Game Engine::Tools</title>\n</head>\n<body>\n";
//			DWORD bytesWrite;
//			WriteFile(_hfile, doctype, strlen(doctype), &bytesWrite, NULL);
//			WriteFile(_hfile, header, strlen(header), &bytesWrite, NULL);
//		}
//
//		void HtmlWriter::addToPage(string s)
//		{
//			writeHeader();
//			DWORD bytesWrite;
//			WriteFile(_hfile, s.c_str(), s.length(), &bytesWrite, NULL);
//			writeFooter();
//		}
//
//		void HtmlWriter::writeFooter()
//		{
//			DWORD bytesWrite;
//			const char* const end = "\n</body>\n</html>";
//			WriteFile(_hfile, end, strlen(end), &bytesWrite, NULL);
//		}
//	}
//}