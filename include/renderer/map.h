/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_RENDERER_MAP_H_
#define MG_RENDERER_MAP_H_

namespace mg
{
namespace renderer
{
class Map
{
public:
    Map(){}
    virtual ~Map(){}

    virtual void create();
};
}    // end of renderer namespace
}    // end of mg namespace
#endif