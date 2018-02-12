/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Engine
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */
#include "audio\soundobject.h"

namespace rodeo
{
namespace audio
{
//bool SoundObject::initSound()
//{
//    result_ = System_Create(&system_);
//    if(result_ != FMOD_OK)
//    {
//        MessageBox(NULL, enginecore::FMODSystemFail, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//
//    result_ = system_->getVersion(&version_);
//    if(result_ != FMOD_OK)
//    {
//        MessageBox(NULL, enginecore::FMODVersionFail, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//
//    if(version_ < FMOD_VERSION)
//    {
//        MessageBox(NULL, enginecore::FMODVersionNotSupported, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//
//    result_ = system_->getNumDrivers(&numdrivers_);
//    if(result_ != FMOD_OK)
//    {
//        MessageBox(NULL, enginecore::FMODDriversEnumerateFail, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//
//    if(numdrivers_ == 0)
//    {
//        MessageBox(NULL, enginecore::FMODSoundDriversFail, enginecore::HEADER, enginecore::errIconOK);
//        return false;	
//    }
//    else
//    {
//        result_ = system_->getDriverCaps(0, &caps_, 0, 0, &speakermode_);
//        if(result_ != FMOD_OK)
//        {
//            MessageBox(NULL, enginecore::FMODSpeakerModeNotAvailable, enginecore::HEADER, enginecore::errIconOK);
//            return false;
//        }
//        result_ = system_->setSpeakerMode(speakermode_);
//        if(result_ != FMOD_OK)
//        {
//            MessageBox(NULL, enginecore::FMODSetSpeakerModeFail, enginecore::HEADER, enginecore::errIconOK);
//            return false;
//        }
//        if(caps_ & FMOD_CAPS_HARDWARE_EMULATED)
//        {
//            result_ = system_->setDSPBufferSize(1024, 10);
//            if(result_ != FMOD_OK)
//            {
//                MessageBox(NULL, enginecore::FMODDSPBufferSizeFail, enginecore::HEADER, enginecore::errIconOK);
//                return false;
//            }
//        }
//        result_ = system_->getDriverInfo(0, drivername_, 256, 0);
//        if(result_ != FMOD_OK)
//        {
//            MessageBox(NULL, enginecore::FMODDriverInfoFail, enginecore::HEADER, enginecore::errIconOK);
//            return false;
//        }
//    }
//    result_ = system_->init(100, FMOD_INIT_NORMAL, 0);
//    if(result_ == FMOD_ERR_OUTPUT_CREATEBUFFER)
//    {
//        result_ = system_->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
//        if(result_ != FMOD_OK)
//        {
//            MessageBox(NULL, enginecore::FMODSpeakerModeStereoFail, enginecore::HEADER, enginecore::errIconOK);
//            return false;
//        }
//        result_ = system_->init(100, FMOD_INIT_NORMAL, 0);
//        if(result_ != FMOD_OK)
//        {
//            MessageBox(NULL, enginecore::FMODSystemInitializeFail, enginecore::HEADER, enginecore::errIconOK);
//            return false;
//        }
//    }
//    return true;
//}
//
///**
// *
// */
//
//bool SoundObject::createSound()
//{
//    FMOD::Sound* sound = NULL;
//    if(file_ == NULL)
//    {
//        MessageBox(NULL, enginecore::CreateSoundObjectFirst, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//
//    if(system_->createSound(file_, FMOD_DEFAULT, 0, &sound) != FMOD_OK)
//    {
//        MessageBox(NULL, enginecore::CreateSoundObjectFail, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//
//    FMOD::Channel* channel;
//    if(system_->playSound(FMOD_CHANNEL_FREE, sound, false, &channel) != FMOD_OK)
//    {
//        MessageBox(NULL, enginecore::CannotPlaySound, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//    if(channel->setVolume(0.6f) != FMOD_OK)
//    {
//        MessageBox(NULL, enginecore::SetVolumeFail, enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//    return true;
//}
//
///**
// *
// */
//
//void SoundObject::release()
//{
//    file_ = NULL;
//    system_->release();
//}
}
}