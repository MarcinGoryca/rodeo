/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ FontManager.h ] [ mg\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_FONTMANAGER_H_
#define MG_CORE_FONTMANAGER_H_

#ifndef MG_RENDERER_FONT_H_
#include "renderer\font.h"
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "core\Singleton.h"
#endif

#ifndef MG_CORE_MASTERMANAGER_H_
#include "core\mastermanager.h"
#endif

namespace mg
{
	namespace core
	{
		class FontManager : public Singleton<FontManager>, public MasterManager
		{
		public:
			FontManager() {}

			~FontManager()
			{
				clear();
			}

			// Gets Font object pointer
			mg::renderer::Font* getFont() const { return font_; }


		private:
			void init();
			void clear();

			mg::renderer::Font* font_;
		};
	}   // end of core namespace
}   // end of mg namespace
#endif    // MG_CORE_FONTMANAGER_H_