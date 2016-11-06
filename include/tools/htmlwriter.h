/*
-----------------------------------
	Laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
-----------------------------------
*/
#ifndef LAURA_TOOLS_HTMLWRITER_H_
#define LAURA_TOOLS_HTMLWRITER_H_

#ifndef LAURA_CORE_ERROR_H_
#include "core\error.h"
#endif

namespace laura
{
	namespace tools
	{
		class HtmlWriter
		{
		public:
			HtmlWriter()
				:_hfile(NULL)
			{}

			~HtmlWriter() {}

			// filename - specify your destination HTML file e.g. index.html 
			// add your website content
			bool writeToHTML(std::wstring filename, std::string s);

		protected:

			bool create(std::wstring filename);
			void writeHeader();
			void writeFooter();
			void addToPage(std::string s);

			HANDLE _hfile;
		};
	}
}
#endif