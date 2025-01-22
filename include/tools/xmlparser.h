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
#ifndef RODEO_TOOLS_XMLPARSER_H_
#define RODEO_TOOLS_XMLPARSER_H_

#ifndef RODEO_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef RODEO_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef RODEO_MATH_MATHTOOLS_H_
#include "math\mathtools.h"
#endif

#ifndef RODEO_TINYXML_TINYXML_H_
#include "tinyxml\tinyxml.h"
#endif

#include <map>

#define TIXML_USE_STL

namespace rodeo
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