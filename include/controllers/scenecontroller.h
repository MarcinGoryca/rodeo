/*
 |  -----------------------------------
 |     mona GAME ENGINE
 |     [ SceneController.h ] [ mona\controllers ]
 |     Copyright(c) Marcin Goryca
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |  -----------------------------------
 */

#ifndef MONA_CONTROLLERS_SCENECONTROLLER_H_
#define MONA_CONTROLLERS_SCENECONTROLLER_H_

#ifndef MONA_CORE_ERROR_H_
#include "core\error.h"
#endif

#ifndef MONA_CORE_SINGLETON_H_
#include "core\singleton.h"
#endif

#ifndef MONA_CONTROLLERS_MASTERCONTROLLER_H_
#include "controllers\mastercontroller.h"
#endif

#ifndef MONA_SCENE_SCENE_H_
#include "scene\scene.h"
#endif

/*
#ifndef LIST_H_
#include <list>
#endif    //LIST_H_
*/
namespace mona
{
    namespace controllers
    {
        class SceneController : public mona::core::Singleton<SceneController>, public MasterController
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