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
|
|    FMOD Non-Commercial License
|
|    If your title is not intended for commercial gain
|    and does not include the FMOD library for resale,
|    license or other commercial distribution, then use of FMOD is free.
|    Yes that’s right, free from license fees!
|
|     Conditions/Limitations
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

#ifndef RODEO_AUDIO_SOUNDOBJECT_H_
#define RODEO_AUDIO_SOUNDOBJECT_H_

#ifndef RODEO_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef RODEO_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#ifndef RODEO_FMOD_FMOD_HPP_
#include "fmod\fmod.hpp"
#endif

namespace rodeo
{
	namespace audio
	{
		class SoundObject : public rodeo::entity::Entity
		{
		public:
			SoundObject()
				:_file("")
			{}

			explicit SoundObject(const char* filename)
				:_file(filename)
			{}

			~SoundObject() {}

			bool createSound();

			// Sets file of the sound
			void setFile(const char* filename) { _file = filename; }

			//Gets sound file name 
			const char* getFile() const { return _file; }
			bool initSound();
		protected:
			void release();
		private:
			// System - it's main FMOD object
			FMOD::System* _system;
			FMOD_RESULT _result;
			FMOD_SPEAKERMODE _speakermode;
			unsigned int _version;
			int _numdrivers;

			FMOD_CAPS _caps;
			char _drivername[256];
			// Sound file
			const char* _file;

			// Copy Constructor
			SoundObject(const SoundObject& copy);

			// Copy Operator
			SoundObject& operator=(const SoundObject& copy);
		};
	}
}
#endif
