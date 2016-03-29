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

		class XmlParser : public core::Singleton<XmlParser>
		{
		public:
			XmlParser()
				:_root(0)
			{}

			~XmlParser() {}

			bool read(const std::wstring filepath);

			XmlIntMap getIntMap() const
			{
				return _map_int;
			}

			XmlFloatMap getFloatMap() const
			{
				return _map_float;
			}

			XmlStringMap getStringMap() const
			{
				return _map_string;
			}

			TiXmlDocument getXmlDocument() const
			{
				return _xml_document;
			}

			TiXmlElement* getXmlElement() const
			{
				return _xml_element;
			}

			TiXmlNode* getXmlNode() const
			{
				return _xml_node;
			}

			TiXmlHandle getRoot() const
			{
				return _root;
			}

		private:
			TiXmlHandle _root;
			TiXmlDocument _xml_document;
			TiXmlElement* _xml_element;
			TiXmlNode* _xml_node;
			XmlIntMap _map_int;
			XmlFloatMap _map_float;
			XmlStringMap _map_string;
		};
	}
}
#endif