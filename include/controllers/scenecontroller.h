/*
 |  -----------------------------------
 |     LAURA GAME ENGINE
 |     [ SceneController.h ] [ laura\controllers ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef LAURA_CONTROLLERS_SCENECONTROLLER_H_
#define LAURA_CONTROLLERS_SCENECONTROLLER_H_

#ifndef LAURA_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef LAURA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef LAURA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

#ifndef LAURA_SCENE_SCENE_H_
#include "scene\scene.h"
#endif

/*
#ifndef LIST_H_
#include <list>
#endif    //LIST_H_
*/
namespace laura
{
    namespace controllers
    {
        class SceneController : public laura::core::Singleton<SceneController>, public MasterController
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