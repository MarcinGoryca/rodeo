/*
 |  -----------------------------------
 |    MG GAME ENGINE
 |    [ AudioController.h ] [ mg\core ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MG_CORE_AUDIOCONTROLLER_H_
#define MG_CORE_AUDIOCONTROLLER_H_

#ifndef MG_MATH_VECTOR_H_
#include <vector>
#endif

#ifndef MG_CORE_SINGLETON_H_
#include "singleton.h"
#endif

#ifndef MG_AUDIO_SOUNDOBJECT_H_
#include "audio\soundobject.h"
#endif

namespace mg
{
	namespace core
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
				:sound_object_(NULL),
				sound_container_(0)
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
			mg::audio::SoundObject* getSoundObject() const { return sound_object_; }

			/*
			 |  -------------------------------------------------
			 |    Sets SoundObject object
			 |  -------------------------------------------------
			 */
			void setSoundObject(mg::audio::SoundObject* so) { sound_object_ = so; }

			/*
			 |  --------------------------------------------------
			 |    Gets Container of the sound
			 |    Returns Vector object, container of SoundObject objects
			 |  --------------------------------------------------
			 */
			std::vector<mg::audio::SoundObject*> getSoundContainer() const { return sound_container_; }

			/*
			 |  -------------------------------------------------
			 |    Puts SoundObject into the container
			 |  -------------------------------------------------
			 */
			void putSound(mg::audio::SoundObject* so);
		protected:

		private:
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

			mg::audio::SoundObject* sound_object_;
			std::vector<mg::audio::SoundObject*> sound_container_;
		};
	}    //end of core namespace
}    // end of mg namespace
#endif    //MG_CORE_AUDIOCONTROLLER_H_
