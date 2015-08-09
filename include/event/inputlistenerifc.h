/*
-----------------------------------
    JENNIE Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef JENNIE_EVENT_INPUTLISTENERIFC_H_
#define JENNIE_EVENT_INPUTLISTENERIFC_H_

#include <list>

#ifndef JENNIE_IO_IINPUT_H_
#include "io\iinput.h"
#endif

namespace mg
{
	namespace event
	{
		class IInputListener
		{
		public:
			IInputListener(){}

			virtual ~IInputListener(){}

			int getInputType()const;

			void addInputListener(io::IInput* in);

			virtual void keyUp(io::IInput key) = 0;

			virtual void keyDown(io::IInput key) = 0;

			virtual void mouseDblClick(io::IInput ms) = 0;

			virtual void mouseMove(io::IInput ms) = 0;

			virtual void mouseExit(io::IInput ms) = 0;

			virtual void mouseScroll(io::IInput ms) = 0;

			virtual void mouseClick(io::IInput ms) = 0;

			virtual void mouseDrag(io::IInput ms) = 0;

		protected:
			std::list <io::IInput*> input_list_;
		};
	}
} 
#endif