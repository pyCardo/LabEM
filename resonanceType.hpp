#ifndef RESONANCE_TYPE
#define RESONANCE_TYPE
#include "particleType.hpp"

class ResonanceType : ParticleType public
{
 public:
  double GetWidth() const
  {
    return fWidth;
  }
  void Print() const;
  ResonanceType(std::string*, double, int, double);

 private:
  const double fWidth;
};
#endif
