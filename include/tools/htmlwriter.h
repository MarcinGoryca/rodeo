/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_TOOLS_HTMLWRITER_H_
#define MG_TOOLS_HTMLWRITER_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

namespace mg
{
namespace tools
{
class HtmlWriter
{
public:
    HtmlWriter()
        :hfile_(NULL)
    {}

    ~HtmlWriter(){}

    // filename - specify your destination HTML file e.g. index.html 
    // add your website content
    bool writeToHTML(std::wstring filename, std::string s);

protected:

    bool create(std::wstring filename);
    void writeHeader();
    void writeFooter();
    void addToPage(std::string s); 

    HANDLE hfile_;
};
}    // end of tools namespace
}    // end of mg namespace
#endif