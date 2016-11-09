///*
//----------------------------------------------
//	Laura Game Engine
//	Copyright(c) Marcin Goryca
//	marcin.goryca@gmail.com
//	http://marcingoryca.pl
//----------------------------------------------
//*/
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