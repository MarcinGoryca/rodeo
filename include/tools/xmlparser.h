/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_TOOLS_XMLPARSER_H_
#define MG_TOOLS_XMLPARSER_H_

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_MATH_MATHTOOLS_H_
#include "math\mathtools.h"
#endif

#ifndef MG_TINYXML_TINYXML_H_
#include "tinyxml\tinyxml.h"
#endif

#include <map>

#define TIXML_USE_STL

namespace mg
{
namespace tools
{
typedef std::map<std::string, std::string> XmlStringMap;
typedef std::map<std::string, int>XmlIntMap;
typedef std::map<std::string, float>XmlFloatMap;

class XmlParser: public core::Singleton<XmlParser>
{
public:
    XmlParser()
         :root_(0)
    {}

    ~XmlParser(){}

    bool read(const std::wstring filepath);

    XmlIntMap getIntMap() const
    {
        return map_int_;
    }

    XmlFloatMap getFloatMap() const
    {
        return map_float_;
    }

    XmlStringMap getStringMap() const
    {
        return map_string_;
    }

    TiXmlDocument getXmlDocument() const
    {
        return xml_document_;
    }

    TiXmlElement* getXmlElement() const
    {
        return xml_element_;
    }

    TiXmlNode* getXmlNode() const
    {
        return xml_node_;
    }

    TiXmlHandle getRoot() const
    {
        return root_;
    }

private:
    TiXmlHandle root_;
    TiXmlDocument xml_document_;
    TiXmlElement* xml_element_;
    TiXmlNode* xml_node_;
    XmlIntMap map_int_;
    XmlFloatMap map_float_;
    XmlStringMap map_string_;
};
}    // end of tools namespace
}    // end of mg namespace
#endif