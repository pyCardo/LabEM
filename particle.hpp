#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "resonanceType.hpp"

struct Momentum
{
  double x{0};
  double y{0};
  double z{0};

  double Norm2() const
  {
    return x * x + y * y + z * z;
  }
};

class Particle
{
 public:
  Particle() = default;
  Particle(std::string, Momentum);

  int GetIndex() const
  {
    return fIndex;
  }

  Momentum GetMomentum() const
  {
    return fP;
  }

  double GetMass() const
  {
    return fParticleTypes[fIndex]->GetMass();
  }

  double GetEnergy() const;

  double InvariantMass(const Particle& particle) const;

  void SetType(int index)
  {
    fIndex = index;
  }

  void SetType(std::string typeName)
  {
    fIndex = FindParticle(typeName);
  }

  void SetP(Momentum p)
  {
    fP = p;
  }

  void PrintParticleData() const;

  static void AddParticleType(ResonanceType);

  static void PrintParticleTypes();

 private:
  static int fNParticleTypes;
  static std::array<ParticleType*, 7> fParticleTypes;

  int fIndex;
  Momentum fP{};

  int FindParticle(std::string);
};

#endif