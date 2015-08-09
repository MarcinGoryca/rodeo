/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#include "core\audiomanager.h"

namespace mg
{
namespace core
{
void AudioManager::putSound(audio::SoundObject* so)
{
    sound_container_.push_back(so);
}

// - private - //
void AudioManager::clean()
{
    if(sound_object_ != NULL)
    {
        delete sound_object_;
        sound_object_ = NULL;
    }
}
}    // end of core namespace
}    // end of mg namespace