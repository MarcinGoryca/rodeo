/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_TOOLS_XMLPARSER_H_
#include "tools\xmlparser.h"
#endif

using namespace mg::core;
using namespace mg::math;
using namespace std;

namespace mg
{
namespace tools
{
bool XmlParser::read(const std::wstring filepath)
{
// Step 1. Try to load XML file
    try
    {
       //if(!xml_document_.LoadFile(filepath))
        //{
        //    throw -1;
        //}
    }
    catch(...)
    {
        MessageBox(NULL, L"Couldn't load XML File!", MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }

// Step 2. Assign root element of document to element object 
    xml_element_ = xml_document_.FirstChildElement();
    std::string el = xml_element_->Value();
    std::string el_attr = xml_element_->Attribute("name");
    if(xml_element_ == NULL)
    {
        xml_document_.Clear();
        MessageBox(NULL, L"Failed to load XML file. No root element", MG_HEADER.c_str(), ERR_ICON_OK);
        return false;
    }

// Step 3. Loop through whole document and retrieve information

    for(TiXmlElement* elem = xml_element_->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
    {
        std::string element = elem->Value();
        for(TiXmlElement* child_elem = elem->FirstChildElement(); child_elem != NULL; child_elem = child_elem->NextSiblingElement())
        {
            std::string element = child_elem->Value();
            if(child_elem->GetText() != NULL)
            {
                const char* value = child_elem->GetText();
                if(isdigit(value[0]))
                {
                    int value_int = 0;
                    value_int = toInt(value);
                    map_int_[element] = value_int;
                }
                else
                {
                    std::string value_string;
                    value_string = child_elem->GetText();
                    map_string_[element] = value_string;
                }
            }
            else
            {
                std::string value = "";
                int value_int = 0;
                map_int_[element] = value_int;
            }
        }
    }
    return true;
}
}    // end of tools namespace
}    // end of mg namespace