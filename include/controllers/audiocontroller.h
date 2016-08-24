/*
 |  -----------------------------------
 |    mona GAME ENGINE
 |    [ AudioController.h ] [ mona\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CONTROLLERS_AUDIOCONTROLLER_H_
#define MONA_CONTROLLERS_AUDIOCONTROLLER_H_

#ifndef MONA_MATH_VECTOR_H_
#include <vector>
#endif

#ifndef MONA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MONA_AUDIO_SOUNDOBJECT_H_
#include "audio\soundobject.h"
#endif

namespace mona
{
	namespace controllers
	{
		class AudioController : public mona::core::Singleton<AudioController>
		{
		public:
			/*
			 |  -------------------------------------------------
			 |    Constructor
			 |  -------------------------------------------------
			 */
			AudioController()
				:_sound_object(NULL),
				_sound_container(0)
			{}

			//explicit AudioController(const char* filename){}

			/*
			 |  -------------------------------------------------
			 |    Destructor
			 |  -------------------------------------------------
			 */
			~AudioController()
			{
				clean();
			}

			/*
			 |  -------------------------------------------------
			 |    Gets sound object
			 |    Returns SounObject pointer to the sound object
			 |  -------------------------------------------------
			 */
			mona::audio::SoundObject* getSoundObject() const
			{ 
				return _sound_object;
			}

			/*
			 |  -------------------------------------------------
			 |    Sets SoundObject object
			 |  -------------------------------------------------
			 */
			void setSoundObject(mona::audio::SoundObject* so)
			{ 
				_sound_object = so;
			}

			/*
			 |  --------------------------------------------------
			 |    Gets Container of the sound
			 |    Returns Vector object, container of SoundObject objects
			 |  --------------------------------------------------
			 */
			std::vector<mona::audio::SoundObject*> getSoundContainer() const
			{ 
				return _sound_container;
			}

			/*
			 |  -------------------------------------------------
			 |    Puts SoundObject into the container
			 |  -------------------------------------------------
			 */
			void putSound(mona::audio::SoundObject* so);
		protected:

		private:
			mona::audio::SoundObject* _sound_object;
			std::vector<mona::audio::SoundObject*> _sound_container;

			/*
			|  ---------------------------------------------------
			|    Copy Constructor
			|  ---------------------------------------------------
			*/
			AudioController(const AudioController& copy);

			/*
			|  ---------------------------------------------------
			|    Copy operator
			|  ---------------------------------------------------
			*/
			AudioController& operator=(const AudioController& copy);

			/*
			|  ---------------------------------------------------
			|    Cleans the memory
			|  ---------------------------------------------------
			*/
			void clean();
		};
	}
}
#endif
