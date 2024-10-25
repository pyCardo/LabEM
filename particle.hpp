#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <algorithm>

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
  std::string type;
  Momentum p;
  Particle(std::string, Momentum);
  Particle()
      : type("")
      , p{0, 0, 0} {};

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
  static void AddParticleType(ParticleType*);
  static void ClearParticleTypes();

  static void PrintParticleTypes();

 private:
  static int fNParticleTypes;                         // number of types
  static std::array<ParticleType*, 7> fParticleTypes; // array of types

  int fIndex;
  Momentum fP{};

  static int FindParticle(std::string);
};

#endif