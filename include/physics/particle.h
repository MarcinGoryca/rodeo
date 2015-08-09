/*
----------------------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
----------------------------------------------
*/
#ifndef MG_PHYSICS_PARTICLE_H_
#define MG_PHYSICS_PARTICLE_H_

namespace mg
{
namespace physics
{
class Particle
{
public:
    Particle()
    :gravity_(0.0f),
     mass_(0.0f),
     velocity_(0.0f),
     length_(0.0)
    {}

    ~Particle(){}

private:
    float gravity_;
    float mass_;
    float velocity_;
    float length_;

    //Center of mass (gravity)
    //Mass
    //Velocity
    //Length
};
}    // end of physics namespace
}    // end of mg namespace
#endif