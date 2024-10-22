#include "particle.hpp"

#include <math.h>

int Particle::fNParticleTypes = 0;
// std::array<ParticleType*, 7> Particle::fParticleTypes;

Particle::Particle(std::string name, Momentum p)
    : fP{p}
{
  int fIndex = FindParticle(name);
}

int Particle::FindParticle(std::string name)
{
  for (int i = 0; i < fParticleTypes.size(); i++) {
    if (fParticleTypes[i]->GetName() == name) {
      return i;
    }
  }
  std::cout << "Particle not found." << std::endl;
  return -1;
}

void Particle::AddParticleType(ResonanceType type)
{
  for (int i = 0; i < fParticleTypes.size(); i++) {
    if (fParticleTypes[i]->GetName() == type.GetName()) {
      std::cout << "Particle already exists." << std::endl;
      return;
    } else if ((fParticleTypes[i]->GetName()).empty()) {
      fParticleTypes[i] = &type;
      return;
    }
  }
  std::cout << "No space left for a new particle." << std::endl;
  return;
}

void Particle::PrintParticleTypes()
{
  for (auto type : Particle::fParticleTypes) {
    type->Print();
  }
}

void Particle::PrintParticleData() const
{
  std::cout << "Particle index: " << fIndex << '\n';
  std::cout << "Particle name: " << fParticleTypes[fIndex]->GetName() << '\n';
  std::cout << "Particle Px: " << fP.x << '\n';
  std::cout << "Particle Py: " << fP.y << '\n';
  std::cout << "Particle Pz: " << fP.z << '\n';
}

double Particle::GetEnergy() const
{
  return sqrt(GetMass() + fP.Norm2());
}

double Particle::InvariantMass(const Particle& particle) const
{
  const double sumEnergy{GetEnergy() + particle.GetEnergy()};
  const Momentum sumP{fP.x + particle.fP.x, fP.y + particle.fP.y, fP.z + particle.fP.z};

  return std::sqrt(sumEnergy * sumEnergy - sumP.Norm2());
}