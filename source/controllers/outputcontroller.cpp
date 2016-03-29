/*
----------------------------------------------
	MG Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers/outputcontroller.h"

namespace mg
{
	namespace controllers
	{

		void OutputController::init()
		{
			_log = NULL;

			_initstr = L"OutputManager initialized.";

			_module_initialized = true;

			_log = new io::Log();
		}

		//..............................//
		void OutputController::clear()
		{
			if (_log != NULL)
			{
				delete _log;
				_log = NULL;
			}

			_module_initialized = false;

			_initstr = L"OutputManager shutdown...";
		}
	}
}