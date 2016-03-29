#include "audio\soundobject.h"

namespace mg
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