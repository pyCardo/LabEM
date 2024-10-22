#include "particle.hpp"

#include <algorithm>

int Particle::fNParticleType = 0;
// std::array<ParticleType*, 7> Particle::fParticleType;

Particle::Particle(std::string name, Momentum p)
    : fP{p}
{
  int fIndex = FindParticle(name);
}

int Particle::FindParticle(std::string name)
{
  for (int i = 0; i < fParticleType.size(); i++) {
    if (fParticleType[i]->GetName() == name) {
      return i;
    }
  }
  std::cout << "Particle not found." << std::endl;
  return -1;
}

void Particle::AddParticleType(ResonanceType type)
{
  for (int i = 0; i < fParticleType.size(); i++) {
    if (fParticleType[i]->GetName() == type.GetName()) {
      std::cout << "Particle already exists." << std::endl;
      return;
    } else if ((fParticleType[i]->GetName()).empty()) {
      fParticleType[i] = &type;
      return;
    }
  }
  std::cout << "No space left for a new particle." << std::endl;
  return;
}