/*
----------------------------------------------
	laura Game Engine
	Copyright(c) Marcin Goryca
	marcin.goryca@gmail.com
	http://marcingoryca.pl
----------------------------------------------
*/
#ifndef LAURA_PHYSICS_PARTICLE_H_
#define LAURA_PHYSICS_PARTICLE_H_

namespace laura
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