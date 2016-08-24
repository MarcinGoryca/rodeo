/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CORE_RENDEREREXCEPTION_H_
#define MONA_CORE_RENDEREREXCEPTION_H_

#ifndef MONA_CORE_EXCEPTION_H_
#include "core/exception.h"
#endif

namespace mona
{
	namespace core
	{
		class RendererException : public Exception
		{
		public:
			RendererException() {}

			/*
			 |  -----------------------------------------------------------
			 |    Constructor
			 |    Parameter const char* You must specify what went wrong
			 |  -----------------------------------------------------------
			 */
			explicit RendererException(std::wstring reason_of_exception)
				:Exception(reason_of_exception)
			{}

			~RendererException() {}
		};
	}
}
#endif