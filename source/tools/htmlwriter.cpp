/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "tools\htmlwriter.h"

using namespace std;
using namespace mg::core;

namespace mg
{
namespace tools
{
bool HtmlWriter::writeToHTML(wstring filename, string s)
{
    create(filename);
    addToPage(s);
    CloseHandle(hfile_);
    return true;
}

bool HtmlWriter::create(wstring filename)
{
    hfile_ = CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if(hfile_ == INVALID_HANDLE_VALUE)
    {
        MessageBox(NULL, HTMLFILE_LOAD_FAIL.c_str(), MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }
    return true;
}

void HtmlWriter::writeHeader()
{
    const char* const doctype = "<!DOCTYPE html>\n<html lang=\"en\">\n";
    const char* const header = "<head>\n\t<title>Rodeo Game Engine::Tools</title>\n</head>\n<body>\n";
    DWORD bytesWrite;
    WriteFile(hfile_, doctype, strlen(doctype), &bytesWrite, NULL);
    WriteFile(hfile_, header, strlen(header), &bytesWrite, NULL);
}

void HtmlWriter::addToPage(string s)
{
    writeHeader();
    DWORD bytesWrite;
    WriteFile(hfile_, s.c_str(), s.length(), &bytesWrite, NULL);
    writeFooter();
}

void HtmlWriter::writeFooter()
{
    DWORD bytesWrite;
    const char* const end = "\n</body>\n</html>";
    WriteFile(hfile_, end, strlen(end), &bytesWrite, NULL);
}
}    // end of tools namespace
}    // end of mg namespace