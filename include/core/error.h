/*
 |  -----------------------------------
 |    laura GAME ENGINE
 |    [ Error.h ] [ laura\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CORE_ERROR_H_
#define LAURA_CORE_ERROR_H_

#ifndef LAURA_CORE_CONSTANTS_H_
#include "constants.h"
#endif

namespace laura
{
	namespace core
	{
		//	WINDOWS ERRORS  
		/*
		 :  ------------------------------------------------------------
		 :    If RegisterClassEx fails this message will show up
		 :  ------------------------------------------------------------
		 */
		const std::wstring REGISTER_FAIL_MESSAGE = L"Cannot Register Window Class";

		/*
		 :  --------------------------------------------------------------
		 :    If CreateWindowEx fails this message will show up
		 :  --------------------------------------------------------------
		 */
		const std::wstring CREATE_FAIL_MESSAGE = L"Cannot Create Window Class";

		//	TGA FILES ERRORS
		/*
		 :  ------------------------------------------------
		 :    If there are problems to find this file
		 :  ------------------------------------------------
		 */
		const std::wstring TGA_LOAD_FAIL = L"Couldn't Load TGA File";

		/*
		 :  -------------------------------------------------
		 :    If file has invalid size
		 :  -------------------------------------------------
		 */
		const std::wstring TGA_INVALID_SIZE = L"Invalid File Size";

		//	3DS FILES ERRORS
		/*
		 :  ------------------------------------------
		 :    If system cannot find this file
		 :  ------------------------------------------
		 */
		const std::wstring FILE3DS_FAIL = L"Couldn't Load 3ds File";

		/*
		 :  ------------------------------------------
		 :    This is not proper .3DS file
		 :  ------------------------------------------
		 */
		const std::wstring FILE3DS_ERROR = L"This is Not .3DS File OR is Not Supported";

		//	HTML FILES ERRORS
		/*
		 :  -----------------------------------------------
		 :    If system cannot load HTML file
		 :  -----------------------------------------------
		 */
		const std::wstring HTMLFILE_LOAD_FAIL = L"Couldn't Load HTML file";
	
		//	ALL FILES ERRORS
		/*
		 :  --------------------------------------------
		 :    If file cannot be opened
		 :  --------------------------------------------
		 */
		const std::wstring FILE_FAIL = L"Couldn't open file";

		/*
		 |  --------------------------------------------
		 |    If file cannot be loaded
		 |  --------------------------------------------
		 */
		const std::wstring LOAD_FAIL = L"File Open Failed!";

		/*
		 |  --------------------------------------------
		 |    File cannot be read
		 |  --------------------------------------------
		 */
		const std::wstring READ_FAIL = L"Couldn't read file";

		/*
		 |  --------------------------------------------
		 |    Invalid handle
		 |  --------------------------------------------
		 */
		const std::wstring INVALIDHANDLE_VALUE = L"Invalid Handle Value";

		/*
		 |  --------------------------------------------
		 |    Win32 error - changed for convinience?
		 |  --------------------------------------------
		 */
		const unsigned int ERR_ICON_OK = MB_ICONERROR | MB_OK;

		/*
		 |  --------------------------------
		 |    ***  FONT ERRORS  ***
		 |  --------------------------------
		 */

		/*
		 |  ----------------------------------
		 |    System cannot create font 
		 |  ----------------------------------
		 */
		const std::wstring FONT_CREATE_FAIL = L"Couldn't create font!";

		/*
		 |  --------------------------------------
		 |    Font Unknown Error
		 |  --------------------------------------
		 */
		const std::wstring FONT_FAIL = L"Font Error";
		const std::wstring FREETYPE_LIBRARY_LOAD_FAIL = L"Couldn't Load FreeType Library.\nQuiting...";
		const std::wstring FREETYPE_UNKNOWN_FILE_FORMAT = L"Specified Font File Format is NOT SUPPORTED.\nQuiting...";
		const std::wstring FREETYPE_BROKEN_FONT_FILE = L"Font File Could NOT be Opened or File is Broken.\nQuiting...";
		const std::wstring FREETYPE_CHAR_SIZE_ERROR = L"Couldn't set char size.\nQuiting...";

		/*
		 |  ----------------------------------
		 |   ***  TEXT ERRORS  ***
		 |  ---------------------------------
		 */

		/*
		 |  --------------------------------------
		 |    There is no text to print
		 |  --------------------------------------
		 */
		const std::wstring NOTEXTTOPRINT = L"There's NO Text to Print!";

		/*
		 |  --------------------------------------
		 |    Text error
		 |  --------------------------------------
		 */
		const std::wstring NOTEXT = L"Text Error";

		/*
		 |  ------------------------------
		 |    ***  LOG ERRORS  ***
		 |  ------------------------------
		 */

		/*
		 |  ---------------------------------------
		 |    System cannot open the log file
		 |  ---------------------------------------
		 */
		const std::wstring LOGFILE_ERROR = L"Couldn't open Log file";

		/*
		 |  ------------------------------
		 |    ***  DDS FILES  ***
		 |  ------------------------------
		 */

		/*
		 |  -------------------------------------
		 |    Cannot load DDS file
		 |  -------------------------------------
		 */
		const std::wstring DDS_LOAD_FAIL = L"Couldn't Load DDS File";

		/*
		 |  ------------------------------
		 |    ***  PNG FILES  ***
		 |  -------------------------------
		 */

		/*
		 |  ---------------------------------
		 |    Cannot load PNG file
		 |  ---------------------------------
		 */
		const std::wstring PNG_LOAD_FAIL = L"Couldn't Load PNG File";

		/*
		 |  ------------------------------
		 |    ***  OBJ FILES  ***
		 |  ------------------------------
		 */

		/*
		 |  ------------------------------------
		 |    Cannot open OBJ file
		 |  ------------------------------------
		 */
		const std::wstring OBJFILE_LOAD_FAIL = L"Couldn't Load OBJ File";

		/*
		 |  -------------------------------
		 |   ***  XMLParser ERROR  ***
		 |  -------------------------------
		 */

		/*
		 |  ----------------------------------
		 |    Cannot open XML File
		 |  ----------------------------------
		 */
		const std::wstring XMLPARSER_FAIL = L"Couldn't Load XML File!";

		/*
		 |  -------------------------------------------------
		 |    This is for Title Bar in the Message Box
		 |	  laura GAME ENGINE header
		 |  -------------------------------------------------
		 */
		const std::wstring LAURA_HEADER = L"LAURA";

		//	FMOD ERRORS
		const char* const FMOD_SYSTEM_FAIL = "Couldn't Create FMOD System Object!";

		const char* const FMOD_VERSION_FAIL = "Couldn't Get FMOD Version!";

		const char* const FMOD_VERSION_NOT_SUPPORTED = "FMOD Version NOT Supported!";

		const char* const FMOD_DRIVER_ENUMERATE_FAIL = "Couldn't Enumerate FMOD Drivers!";

		const char* const FMOD_SOUNDDRIVERS_NOTAVAILABLE = "No Sound Drivers Available!";

		const char* const FMOD_SPEAKERMODE_NOTAVAILABLE = "Speaker Mode Not Available!";

		const char* const FMOD_SET_SPEAKERMODE_FAIL = "Couldn't Set Speaker Mode!";

		const char* const FMOD_DSP_BUFFERSIZE_FAIL = "Couldn't Set DSP Buffer Size";

		const char* const FMOD_DRIVERINFO_FAIL = "Couldn't Get Driver Info";

		const char* const FMOD_SPEAKERMODE_STEREO_FAIL = "Couldn't Set Speaker Mode To Stereo";

		const char* const FMOD_SYSTEMINIT_FAIL = "Couldn't Initialize FMOD System Object";

		const char* const CREATE_SOUNDOBJECT_FIRST = "You MUST Call GetFileSound(const char* filename) First!";

		const char* const CREATE_SOUNDOBJECT_FAIL = "Couldn't create Sound Object!";

		const char* const CANNOT_PLAY_SOUND = "Cannot Play sound!";

		const char* const SET_VOLUME_FAIL = "Set Volume Failed!";

		/*
		 |  -------------------------------------
		 |    ***  OPENGL ERRORS  ***
		 |  -------------------------------------
		 */

		/*
		 |  -------------------------------------------
		 |    User GPU not supports OpenGL 2.0 version
		 |  -------------------------------------------
		 */
		const std::wstring OPENGL_VERSION_NOT_SUPPORTED = L"Sorry, your GPU doesn't support OpenGL 2.0!\nTerminating...";

		/*
		 |  -------------------------------------
		 |     ***  MEMORY ERRORS  ***
		 |  -------------------------------------
		 */

		/*
		 |  ----------------------------------------
		 |    Allocate memory fails
		 |  ----------------------------------------
		 */
		const char* const ALLOCATE_MEMORY_FAIL = "Couldn't Allocate Enough Memory!";
	}
}
#endif