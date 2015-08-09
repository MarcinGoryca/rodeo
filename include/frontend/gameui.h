/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_FRONTEND_GAMEUI_H
#define MG_FRONTEND_GAMEUI_H

#ifndef MG_FRONTEND_GUIIFC_H_
#include "frontend\guiifc.h"
#endif

namespace mg
{
namespace frontend
{
class GameUI : public GUIIfc
{
public:
    GameUI(){}
    virtual~GameUI(){}
};
}    // end of frontend namespace
}    // end of mg namespace
#endif