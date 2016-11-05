/*
 |  -----------------------------------
 |    LAURA SOFTWARE
 |    [ AudioController.h ] [ laura\controllers ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CONTROLLERS_AUDIOCONTROLLER_H_
#define LAURA_CONTROLLERS_AUDIOCONTROLLER_H_

#ifndef LAURA_MATH_VECTOR_H_
#include <vector>
#endif

#ifndef LAURA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef LAURA_AUDIO_SOUNDOBJECT_H_
#include "audio\soundobject.h"
#endif

namespace laura
{
	namespace controllers
	{
		class AudioController : public laura::core::Singleton<AudioController>
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
			 |    Returns SoundObject pointer to the sound object
			 |  -------------------------------------------------
			 */
			laura::audio::SoundObject* getSoundObject() const
			{ 
				return _sound_object;
			}

			/*
			 |  -------------------------------------------------
			 |    Sets SoundObject object
			 |  -------------------------------------------------
			 */
			void setSoundObject(laura::audio::SoundObject* so)
			{ 
				_sound_object = so;
			}

			/*
			 |  --------------------------------------------------
			 |    Gets Container of the sound
			 |    Returns Vector object, container of SoundObject objects
			 |  --------------------------------------------------
			 */
			std::vector<laura::audio::SoundObject*> getSoundContainer() const
			{ 
				return _sound_container;
			}

			/*
			 |  -------------------------------------------------
			 |    Puts SoundObject into the container
			 |  -------------------------------------------------
			 */
			void putSound(laura::audio::SoundObject* so);
		protected:

		private:
			laura::audio::SoundObject* _sound_object;
			std::vector<laura::audio::SoundObject*> _sound_container;

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
