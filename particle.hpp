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
 private:
  static int fNParticleTypes;                         // number of types
  static std::array<ParticleType*, 7> fParticleTypes; // array of types

  int fIndex;
  Momentum fP{};

  int FindParticle(std::string);

 public:
  Particle() = default;
  Particle(std::string, Momentum);

  // getters
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

  // setters
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

  double InvMass(const Particle& particle) const;

  void PrintParticleData() const;

  int Decay2Body(Particle& dau1, Particle& dau2) const;

  void Boost(Momentum b);

  // static functions
  static void AddParticleType(ParticleType);

  static void PrintParticleTypes();
};

#endif