/*
 |  -----------------------------------
 |    MONA
 |    [ Constants.h ] [ mona\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CORE_CONSTANTS_H_
#define MONA_CORE_CONSTANTS_H_

#ifndef MONA_COMMON_H_
#include "common.h"
#endif

#ifndef MONA_RENDERER_COLORS_H_
#include "renderer\colors.h"
#endif

namespace mona
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
		const float MONA_ONE = 1.0f;
		const float MONA_ZERO = 0.0f;
		const float MONA_HALF = 0.5f;
		const float MONA_NEGATIVE_ONE = -1.0f;
		const float MONA_PI = 3.14159265f;
		const float MONA_TWOPI = 6.2831852f;
		const float MONA_HALFPI = 1.5707963f;
		const float MONA_ONEBYPI = 1.0f / MONA_PI;
		const float MONA_ONEBY2PI = 1.0f / MONA_TWOPI;
		const unsigned int MONA_FULL_CIRCLE = 360;

		// DEGREE - Degrees From Radians [180 / PI] 
		const float MONA_DEGREE = 57.2957f;
		const float MONA_RADIAN = 0.01745f;



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