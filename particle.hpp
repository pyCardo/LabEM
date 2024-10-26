#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <math.h>
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
 private:
  // type-related members
  static int fNParticleTypes; // number of types, counter
  static std::array<ParticleType*, 7> fParticleTypes; // array of types
  int fIndex;

  // kinematic-related members
  Momentum fP{};

  static int FindParticle(std::string);

 public:
  std::string type;
  Momentum p;

  // constructors
  Particle(std::string, Momentum);

  Particle()
      : type("") // default constructor uses an empty string
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

  double GetEnergy() const
  {
    return std::sqrt(std::pow(GetMass(), 2) + fP.Norm2());
  };

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

  int Decay2Body(Particle& dau1, Particle& dau2) const;

  void Boost(Momentum b);

  // fParticleTypes handlers
  static void AddParticleType(ParticleType*);
  static void ClearParticleTypes();

  // output
  static void PrintParticleTypes();
  void PrintParticleData() const;
};

#endif