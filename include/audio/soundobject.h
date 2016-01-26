/*
 |  --------------------------------------------------------
 |    MG GAME ENGINE
 |    [ Soundobject.h ] [ mg\audio ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  --------------------------------------------------------
 |
 |
 |    FMOD Non-Commercial License
 |
 |    If your title is not intended for commercial gain
 |    and does not include the FMOD library for resale, 
 |    license or other commercial distribution, then use of FMOD is free. 
 |    Yes that’s right, free from license fees!
 |
 |    Conditions/Limitations
 |
 |    When using this license, the FMOD library cannot be used for resale
 |    or other commercial distribution
 |    This license cannot be used for titles which do not make profit
 |    but are still commercially released
 |    This license cannot be used for commercial services,
 |    where the executable containing fmod is not sold, but the data is.
 |    When using FMOD, a credit line is required in either documentation, 
 |    or 'on screen' format (if possible). 
 |    It should contain at least the words 'FMOD Sound System'
 |    and 'Firelight Technologies'. 
 |    Logos are available for box or manual art, but are not mandatory.
 |    An example credit could be:
 |
 |    FMOD Sound System, copyright © Firelight Technologies Pty, Ltd., 1994-2012.
 |
 |    or
 |    Audio engine : FMOD Sound System by Firelight Technologies
 |
 |    Note this in advance, as it must be done
 |    before shipping your title with FMOD.
 |  --------------------------------------------------------
 */

#ifndef MG_AUDIO_SOUNDOBJECT_H_
#define MG_AUDIO_SOUNDOBJECT_H_

#ifndef MG_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#ifndef MG_FMOD_FMOD_HPP_
#include "fmod\fmod.hpp"
#endif

namespace mg
{
    namespace audio
    {
        class SoundObject : public mg::entity::Entity
        {
        public:
            /*
             |  ------------------------------------------------------
             |    Constructor
             |  ------------------------------------------------------
             */
            SoundObject()
                :file_("")
            {}

            /*
             |  ------------------------------------------------------
             |    Constructor
             |    Parameter - filename of the sound object
             |  ------------------------------------------------------
             */
            explicit SoundObject(const char* filename)
                :file_(filename)
            {}

            /*
             |  -----------------------------------------------------
             |    Destructor
             |  -----------------------------------------------------
             */
            ~SoundObject() {}

            /*
             |  -----------------------------------------------------
             |    Creates the sound object
             |  -----------------------------------------------------
             */
            bool createSound();

            /*
             |  ----------------------------------------------------
             |    Sets file of the sound
             |  ----------------------------------------------------
             */
            void setFile(const char* filename) { file_ = filename; }

            /*
             |  ---------------------------------------------------
             |    Gets sound file name 
             |  ---------------------------------------------------
             */
            const char* getFile() const { return file_; }

            /*
             |  ---------------------------------------------------
             |    Inits the sound object
             |  ---------------------------------------------------
             */
            bool initSound();
        protected:

            /*
             |  ---------------------------------------------------
             |    Releases the sound object
             |  ---------------------------------------------------
             */
            void release();
        private:
            /*
             |  ---------------------------------------------------
             |    Copy Constructor
             |  ---------------------------------------------------
             */
            SoundObject(const SoundObject& copy);

            /*
             |  ---------------------------------------------------
             |    Copy Operator
             |  ---------------------------------------------------
             */
            SoundObject& operator=(const SoundObject& copy);

            /*
             |  ---------------------------------------------------
             |    System - it's main FMOD object
             |  ---------------------------------------------------
             */
            FMOD::System* system_;
            FMOD_RESULT result_;
            mg::core::ui version_;
            int numdrivers_;
            FMOD_SPEAKERMODE speakermode_;
            //FMOD_CAPS caps_;
            char drivername_[256];
            /*
             |  ---------------------------------------------------
             |    Sound file
             |  ---------------------------------------------------
             */
            const char* file_;
        };
    }    // end of audio namespace
}    // end of mg namespace
#endif