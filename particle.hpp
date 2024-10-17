#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "resonanceType.hpp"

struct Momentum
{
  double x{0};
  double y{0};
  double z{0};
};

class Particle
{
 public:
  Particle() = default;
  Particle(std::string, Momentum);
  int GetIndex()
  {
    return fIndex;
  };
  void AddParticleType(ResonanceType);

 private:
  static int fNParticleType;
  static std::array<ParticleType*, 7> fParticleType;

  int fIndex;
  Momentum fP{};

  int FindParticle(std::string);
};

#endif