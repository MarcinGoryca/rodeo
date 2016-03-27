/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ AudioController.h ] [ mg\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CONTROLLERS_AUDIOCONTROLLER_H_
#define MG_CONTROLLERS_AUDIOCONTROLLER_H_

#ifndef MG_MATH_VECTOR_H_
#include <vector>
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MG_AUDIO_SOUNDOBJECT_H_
#include "audio\soundobject.h"
#endif

namespace mg
{
	namespace controllers
	{
		class AudioController : public mg::core::Singleton<AudioController>
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
			mg::audio::SoundObject* getSoundObject() const
			{ 
				return _sound_object;
			}

			/*
			 |  -------------------------------------------------
			 |    Sets SoundObject object
			 |  -------------------------------------------------
			 */
			void setSoundObject(mg::audio::SoundObject* so)
			{ 
				_sound_object = so;
			}

			/*
			 |  --------------------------------------------------
			 |    Gets Container of the sound
			 |    Returns Vector object, container of SoundObject objects
			 |  --------------------------------------------------
			 */
			std::vector<mg::audio::SoundObject*> getSoundContainer() const
			{ 
				return _sound_container;
			}

			/*
			 |  -------------------------------------------------
			 |    Puts SoundObject into the container
			 |  -------------------------------------------------
			 */
			void putSound(mg::audio::SoundObject* so);
		protected:

		private:
			mg::audio::SoundObject* _sound_object;
			std::vector<mg::audio::SoundObject*> _sound_container;

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
