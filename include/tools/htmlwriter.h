/*
-----------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
-----------------------------------
*/
#ifndef MONA_TOOLS_HTMLWRITER_H_
#define MONA_TOOLS_HTMLWRITER_H_

#ifndef MONA_CORE_ERROR_H_
#include "core\error.h"
#endif

namespace mona
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