/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MONA_RENDERER_MAP_H_
#define MONA_RENDERER_MAP_H_

namespace mona
{
	namespace renderer
	{
		class Map
		{
		public:
			Map() {}
			virtual ~Map() {}

			virtual void create();
		};
	}
}
#endif