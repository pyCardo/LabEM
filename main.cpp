#include "particle.hpp"

void SetUp()
{
  // gRANDOM->SetSeed();
  Particle::AddParticleType(new ParticleType("p+", 0.93827, 1));
  Particle::AddParticleType(new ParticleType("p-", 0.93827, -1));
  Particle::AddParticleType(new ParticleType("K+", 0.49367, 1));
  Particle::AddParticleType(new ParticleType("K-", 0.49367, -1));
  Particle::AddParticleType(new ParticleType("pi+", 0.13957, 1));
  Particle::AddParticleType(new ParticleType("pi-", 0.13957, -1));
  Particle::AddParticleType(new ResonanceType("K*", 0.89166, 0, 0.05));
}

int main()
{
  SetUp();

  Particle::PrintParticleTypes();
  Particle::ClearParticleTypes();
  return 0;
}