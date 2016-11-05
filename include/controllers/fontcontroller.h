/*
 |  -----------------------------------
 |    LAURA SOFTWARE
 |    [ FontController.h ] [ laura\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

#ifndef LAURA_CORE_FONTCONTROLLER_H_
#define LAURA_CORE_FONTCONTROLLER_H_

#ifndef LAURA_RENDERER_FONT_H_
#include "renderer\font.h"
#endif

#ifndef LAURA_CORE_SINGLETON_H_
#include "core\Singleton.h"
#endif

namespace laura
{
	namespace controllers
	{
		class FontController : public laura::core::Singleton<FontController>, public MasterController
		{
		public:
			FontController() {}

			~FontController()
			{
				clear();
			}

			// Gets Font object pointer
			laura::renderer::Font* getFont() const { return _font; }


		private:
			laura::renderer::Font* _font;

			void init();
			void clear();
			
		};
	}
}
#endif