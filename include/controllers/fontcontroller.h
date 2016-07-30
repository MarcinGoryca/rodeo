/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ FontController.h ] [ mg\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

#ifndef MG_CORE_FONTCONTROLLER_H_
#define MG_CORE_FONTCONTROLLER_H_

#ifndef MG_RENDERER_FONT_H_
#include "renderer\font.h"
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "core\Singleton.h"
#endif

namespace mg
{
	namespace controllers
	{
		class FontController : public mg::core::Singleton<FontController>, public MasterController
		{
		public:
			FontController() {}

			~FontController()
			{
				clear();
			}

			// Gets Font object pointer
			mg::renderer::Font* getFont() const { return _font; }


		private:
			mg::renderer::Font* _font;

			void init();
			void clear();
			
		};
	}
}
#endif