/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
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
//#ifndef RODEO_TOOLS_XMLPARSER_H_
//#include "tools\xmlparser.h"
//#endif
//
//using namespace rodeo::core;
//using namespace rodeo::math;
//using namespace std;
//
//namespace rodeo
//{
//	namespace tools
//	{
//		bool XmlParser::read(const std::wstring filepath)
//		{
//			// Step 1. Try to load XML file
//			try
//			{
//				//if(!xml_document_.LoadFile(filepath))
//				 //{
//				 //    throw -1;
//				 //}
//			}
//			catch (...)
//			{
//				MessageBox(NULL, L"Couldn't load XML File!", RODEO_HEADER.c_str(), ERR_ICON_OK);
//				return false;
//			}
//
//			// Step 2. Assign root element of document to element object 
//			_xml_element = _xml_document.FirstChildElement();
//			std::string el = _xml_element->Value();
//			std::string el_attr = _xml_element->Attribute("name");
//			if (_xml_element == NULL)
//			{
//				_xml_document.Clear();
//				MessageBox(NULL, L"Failed to load XML file. No root element", RODEO_HEADER.c_str(), ERR_ICON_OK);
//				return false;
//			}
//
//			// Step 3. Loop through whole document and retrieve information
//
//			for (TiXmlElement* elem = _xml_element->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
//			{
//				std::string element = elem->Value();
//				for (TiXmlElement* child_elem = elem->FirstChildElement(); child_elem != NULL; child_elem = child_elem->NextSiblingElement())
//				{
//					std::string element = child_elem->Value();
//					if (child_elem->GetText() != NULL)
//					{
//						const char* value = child_elem->GetText();
//						if (isdigit(value[0]))
//						{
//							int value_int = 0;
//							value_int = toInt(value);
//							_map_int[element] = value_int;
//						}
//						else
//						{
//							std::string value_string;
//							value_string = child_elem->GetText();
//							_map_string[element] = value_string;
//						}
//					}
//					else
//					{
//						std::string value = "";
//						int value_int = 0;
//						_map_int[element] = value_int;
//					}
//				}
//			}
//			return true;
//		}
//	}
//}