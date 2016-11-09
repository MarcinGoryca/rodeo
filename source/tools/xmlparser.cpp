///*
// * ---------------------------------------------
// *		LAURA Game Engine
// *		Copyright(c) Marcin Goryca
// *		marcin.goryca@gmail.com
// *		http://marcingoryca.pl
// * ----------------------------------------------
// */
//#ifndef LAURA_TOOLS_XMLPARSER_H_
//#include "tools\xmlparser.h"
//#endif
//
//using namespace laura::core;
//using namespace laura::math;
//using namespace std;
//
//namespace laura
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
//				MessageBox(NULL, L"Couldn't load XML File!", LAURA_HEADER.c_str(), ERR_ICON_OK);
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
//				MessageBox(NULL, L"Failed to load XML file. No root element", LAURA_HEADER.c_str(), ERR_ICON_OK);
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