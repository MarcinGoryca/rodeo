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
				:_gravity(0.0f),
				_mass(0.0f),
				_velocity(0.0f),
				_length(0.0)
			{}

			~Particle() {}

		private:
			float _gravity;
			float _mass;
			float _velocity;
			float _length;

			//Center of mass (gravity)
			//Mass
			//Velocity
			//Length
		};
	}
}
#endif