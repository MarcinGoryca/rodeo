/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    [ FontController.h ] [ mona\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

#ifndef MONA_CORE_FONTCONTROLLER_H_
#define MONA_CORE_FONTCONTROLLER_H_

#ifndef MONA_RENDERER_FONT_H_
#include "renderer\font.h"
#endif

#ifndef MONA_CORE_SINGLETON_H_
#include "core\Singleton.h"
#endif

namespace mona
{
	namespace controllers
	{
		class FontController : public mona::core::Singleton<FontController>, public MasterController
		{
		public:
			FontController() {}

			~FontController()
			{
				clear();
			}

			// Gets Font object pointer
			mona::renderer::Font* getFont() const { return _font; }


		private:
			mona::renderer::Font* _font;

			void init();
			void clear();
			
		};
	}
}
#endif