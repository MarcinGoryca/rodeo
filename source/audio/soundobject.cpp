/*
 | --------------------------------------------------------------------------------------------------
 |     Rodeo Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2010 - ... Marcin Goryca
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
//#include "audio\soundobject.h"
//
//namespace rodeo
//{
//namespace audio
//{
//bool SoundObject::initSound()
//{
//    _result = FMOD::System_Create(&_system);
//    if(_result != FMOD_OK)
//    {
//        MessageBox(NULL, L"core::FMOD_SYSTEM_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;
//    }
//
//    _result = _system->getVersion(&_version);
//    if(_result != FMOD_OK)
//    {
//        MessageBox(NULL, L"core::FMOD_VERSION_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;
//    }
//
//    if(_version < FMOD_VERSION)
//    {
//        MessageBox(NULL, L"core::FMOD_VERSION_NOT_SUPPORTED", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;
//    }
//
//    _result = _system->getNumDrivers(&_numdrivers);
//    if(_result != FMOD_OK)
//    {
//        MessageBox(NULL, L"core::FMOD_DRIVERS_ENUMERATE_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;
//    }
//
//    if(_numdrivers == 0)
//    {
//        MessageBox(NULL, L"core::FMOD_SOUND_DRIVERS_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;	
//    }
//    else
//    {
//        _result = _system->getDriverCaps(0, &_caps, 0, 0, &_speakermode);
//        if(_result != FMOD_OK)
//        {
//            MessageBox(NULL, L"core::FMOD_SPEAKER_MODE_NOT_AVAILABLE", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//            return false;
//        }
//        _result = _system->setSpeakerMode(_speakermode);
//        if(_result != FMOD_OK)
//        {
//            MessageBox(NULL, L"core::FMOD_SET_SPEAKER_MODE_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//            return false;
//        }
//        if(_caps & FMOD_CAPS_HARDWARE_EMULATED)
//        {
//            _result = _system->setDSPBufferSize(1024, 10);
//            if(_result != FMOD_OK)
//            {
//                MessageBox(NULL, L"core::FMOD_DSP_BUFFER_SIZE_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//                return false;
//            }
//        }
//        _result = _system->getDriverInfo(0, _drivername, 256, 0);
//        if(_result != FMOD_OK)
//        {
//            MessageBox(NULL, L"core::FMOD_DRIVER_INFO_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//            return false;
//        }
//    }
//    _result = _system->init(100, FMOD_INIT_NORMAL, 0);
//    if(_result == FMOD_ERR_OUTPUT_CREATEBUFFER)
//    {
//        _result = _system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
//        if(_result != FMOD_OK)
//        {
//            MessageBox(NULL, L"core::FMOD_SPEAKER_MODE_STEREO_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//            return false;
//        }
//        _result = _system->init(100, FMOD_INIT_NORMAL, 0);
//        if(_result != FMOD_OK)
//        {
//            MessageBox(NULL, L"core::FMOD_SYSTEM_INITIALIZE_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
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
//    if(_file == NULL)
//    {
//        MessageBox(NULL, L"core::CREATE_SOUND_OBJECT_FIRST", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;
//    }
//
//    if(_system->createSound(_file, FMOD_DEFAULT, 0, &sound) != FMOD_OK)
//    {
//        MessageBox(NULL, L"core::CREATE_SOUND_OBJECT_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;
//    }
//
//    FMOD::Channel* channel;
//    if(_system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel) != FMOD_OK)
//    {
//        MessageBox(NULL, L"core::CANNOT_PLAY_SOUND", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
//        return false;
//    }
//    if(channel->setVolume(0.6f) != FMOD_OK)
//    {
//        MessageBox(NULL, L"core::SET_VOLUME_FAIL", L"core::PROJECT_HEADER", core::ERR_ICON_OK);
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
//    _file = NULL;
//    _system->release();
//}
//}
//}