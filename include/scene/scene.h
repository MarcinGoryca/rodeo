/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_SCENE_SCENE_H_
#define MG_SCENE_SCENE_H_

#ifndef MG_RENDERER_GL_GLLIBRARY_H_
#include "renderer\gl\gllibrary.h"
#endif

#ifndef MG_ENTITY_ENTITY_H_
#include "entity\entity.h"
#endif

#ifndef MG_CORE_CONSTANTS_H_
#include "core\constants.h"
#endif

#ifndef LIST_H_
#include <list>
#endif

namespace mg
{
namespace renderer
{
class RenderState;
}
namespace scene
{
class Scene
{
public:
    Scene()
    :node_count_(0)
    {}
    
    ~Scene(){}

    void addChild(entity::Entity* entity);
    void removeChild(entity::Entity* entity);
    void removeChild();

    // Allows clear entire scene
    void clear();

    void render();
    void update(float dt);

    void onEvent();

    renderer::RenderState* getState()const { return render_state_; }

    core::ui getNodeCount()const { return node_count_; }

protected:
    renderer::RenderState* render_state_;
    std::list<entity::Entity*> node_;
private:
    core::ui node_count_;
    static core::ui children_;
};
}    // end of scene namespace
}    // end of mg namespace
#endif