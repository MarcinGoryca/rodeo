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

#ifndef RODEO_CONTROLLERS_SCENECONTROLLER_H_
#define RODEO_CONTROLLERS_SCENECONTROLLER_H_

#ifndef RODEO_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef RODEO_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef RODEO_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

#ifndef RODEO_SCENE_SCENE_H_
#include "scene\scene.h"
#endif

/*
#ifndef LIST_H_
#include <list>
#endif    //LIST_H_
*/
namespace rodeo
{
    namespace controllers
    {
        class SceneController : public rodeo::core::Singleton<SceneController>, public MasterController
        {
        public:
            SceneController()
            {
                init();
            }

            virtual ~SceneController()
            {
                clear();
            }

            virtual void render();

            virtual void update(float dt);

            //virtual void onIdle();

            //void addChild(entity::Entity* entity);

            //void removeChild(entity::Entity* entity);

            //void removeChildren();

            scene::Scene* getScene()const { return _scene; }

        protected:
            void init();
            void clear();

        private:
            scene::Scene* _scene;
        };
    }
}
#endif