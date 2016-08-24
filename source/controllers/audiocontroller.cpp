/*
----------------------------------------------
	mona Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#include "controllers\audiocontroller.h"

namespace mona
{
	namespace controllers
	{
		void AudioController::putSound(audio::SoundObject* so)
		{
			_sound_container.push_back(so);
		}

		// - private - //
		void AudioController::clean()
		{
			if (_sound_object != nullptr)
			{
				delete _sound_object;
				_sound_object = nullptr;
			}
		}
	}
}