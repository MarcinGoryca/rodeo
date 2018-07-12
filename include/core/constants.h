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
#ifndef RODEO_CORE_CONSTANTS_H_
#define RODEO_CORE_CONSTANTS_H_

#ifndef RODEO_COMMON_H_
#include "common.h"
#endif

#ifndef RODEO_RENDERER_COLORS_H_
#include "renderer\colors.h"
#endif

namespace rodeo
{
	namespace core
	{
		/*
		 | -------------------------------------------
		 |    TYPEDEFS
		 | -------------------------------------------
		 */
		typedef const std::wstring cws;
		typedef unsigned int ui;
		typedef const unsigned int cui;

		/*
		 |  -----------------
		 |    MATH
		 |  -----------------
		 */
		const float RODEO_ONE = 1.0f;
		const float RODEO_ZERO = 0.0f;
		const float RODEO_HALF = 0.5f;
		const float RODEO_NEGATIVE_ONE = -1.0f;
		const float RODEO_PI = 3.14159265f;
		const float RODEO_TWOPI = 6.2831852f;
		const float RODEO_HALFPI = 1.5707963f;
		const float RODEO_ONEBYPI = 1.0f / RODEO_PI;
		const float RODEO_ONEBY2PI = 1.0f / RODEO_TWOPI;
		const unsigned int RODEO_FULL_CIRCLE = 360;

		// DEGREE - Degrees From Radians [180 / PI] 
		const float RODEO_DEGREE = 57.2957f;
		const float RODEO_RADIAN = 0.01745f;

		//namespaces

		//Default Engine Configuration Values

		// Relative\Absolute Path to engine configuration file
		const std::wstring CONFIGURATION_INI = L"configuration\\EngineStart.ini";
		const std::wstring CONFIGURATION_XML = L"configuration\\engine_start.xml";

		// Default window properties string
		const std::wstring CONF_DEF_WINDOW_STRING = L"Window";
		const std::wstring CONF_DEF_WINDOW_WIDTH_KEY = L"windowWidth";
		const std::wstring CONF_DEF_WINDOW_HEIGHT_KEY = L"windowHeight";
		const std::wstring CONF_DEF_SCREEN_DEPTH_KEY = L"screenDepth";
		const std::wstring CONF_DEF_SCREEN_FREQUENCY_KEY = L"screenFrequency";
		const std::wstring CONF_DEF_FULLSCREEN_KEY = L"fullScreen";
		const int CONF_DEF_WINDOW_WIDTH = 600;
		const int CONF_DEF_WINDOW_HEIGHT = 400;
		const int CONF_DEF_WINDOW_DEPTH = 24;
		const int CONF_DEF_WINDOW_FREQUENCY = 60;
		const int CONF_DEF_FULLSCREEN = 0;

		// ALL IN-ENGINE ASSETS

		// Engine Window Icons - DO NOT MODIFY!
		const std::wstring ICON_ASSETS_PATH = L"assets\\icons\\rrbi-32.ico";
		const std::wstring ICON_SMALL_ASSETS_PATH = L"assets\\icons\\rrbi-16.ico";

		// RAW FILES - TERRAIN DATA
		//const char* const kMap1_raw = "assets\\heightmaps\\map1.raw";

		// AUDIO FILES
		//const char* const kMm9_mp3 = "assets\\audio\\mm9.mp3";

		// FONT MEDIA PATH
		//const char* const fonts_path = "assets\\fonts";

		// Maximum amount of objects on the scene
		const unsigned int MAX_OBJECTS_ = 100;
	}
}
#endif