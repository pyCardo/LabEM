#ifndef RESONANCE_TYPE_HPP
#define RESONANCE_TYPE_HPP

#include "particleType.hpp"

class ResonanceType : public ParticleType
{
 private:
  const double fWidth;

 public:
  ResonanceType(std::string, double, int, double);

  double GetWidth() const
  {
    return fWidth;
  }

  void Print() const;
};
#endif
