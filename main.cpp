#include "particle.hpp"

int main()
{
  Particle::AddParticleType(ParticleType("pi+", 0.13957, 1));
	Particle::AddParticleType(ParticleType("pi-", 0.13957, -1));
	Particle::AddParticleType(ParticleType("K+", 0.49367, 1));
	Particle::AddParticleType(ParticleType("K-", 0.49367, -1));
	Particle::AddParticleType(ParticleType("p+", 0.93827, 1));
	Particle::AddParticleType(ParticleType("p-", 0.93827, -1));
	Particle::AddParticleType(ResonanceType("K*", 0.89166, 0, 0.05));

  Particle::PrintParticleTypes();
  return 9;
}