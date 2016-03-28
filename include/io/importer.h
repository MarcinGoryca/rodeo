/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_IO_IMPORTER_H_
#define MG_IO_IMPORTER_H_

#ifndef MG_ENTITY_MODEL_H_
#include "entity\model.h"
#endif

#ifndef MG_CORE_RTTI_H_
#include "core\rtti.h"
#endif

namespace mg
{
namespace io
{
class Importer
{
public:
    Importer(){}
    virtual~Importer(){}

    virtual bool import(const char* filename)=0;

    virtual const std::string& getClassName()const = 0;

    // Gets Model object
    entity::Model* getModel() const
    {
        return _model;
    }

protected:
    entity::Model* _model;
};
}
}
#endif