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
//#ifndef RODEO_EVENT_EVENT_H_
//#define RODEO_EVENT_EVENT_H_
//
//#ifndef RODEO_CORE_CONSTANTS_H_
//#include "core\constants.h"
//#endif
//
//namespace rodeo
//{
//    namespace event
//    {
//        class Event
//        {
//        public:
//            Event() {}
//
//            virtual ~Event() {}
//
//            virtual void onMove();
//
//            virtual void onChange();
//
//            virtual void onUpdate();
//
//            virtual void onDraw();
//
//            virtual void onHit();
//
//            virtual void addedToScene();
//
//            virtual void removedFromScene();
//
//			/*
//			 | ------------------------------------------------
//			 |    Gets Current Target
//		     | ------------------------------------------------
//			 */
//			unsigned int getCurrentTarget() const { return _current_target; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Gets target
//			 | ------------------------------------------------
//			 */
//			unsigned int getTarget() const { return _target; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Get Type
//			 | ------------------------------------------------
//			 */
//			std::string getType() const { return _type; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Get Activate
//			 | ------------------------------------------------
//			 */
//			std::string getActivate() const { return _activate; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Get Cancel
//			 | ------------------------------------------------
//			 */
//			std::string getCancel() const { return _cancel; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Set Current Target
//			 | ------------------------------------------------
//			 */
//			void setCurrentTarget(unsigned int current_target) { _current_target = current_target; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Set Target
//			 | ------------------------------------------------
//			 */
//			void setTarget(unsigned int target) { _target = target; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Set Type
//			 | ------------------------------------------------
//			 */
//			void setType(std::string type) { _type = type; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Set Activate
//			 | ------------------------------------------------
//			 */
//			void setActivate(std::string activate) { _activate = activate; }
//
//			/*
//			 | ------------------------------------------------
//			 |    Set Cancel
//			 | ------------------------------------------------
//			 */
//			void setCancel(std::string cancel) { _cancel = cancel; }
//
//        protected:
//            unsigned int _current_target;
//
//            unsigned int _target;
//
//            std::string _type;
//
//            std::string _activate;
//
//            std::string _cancel;
//        };
//    }
//}
//#endif