#ifndef RESONANCE_TYPE_HPP
#define RESONANCE_TYPE_HPP

#include "particleType.hpp"

class ResonanceType : public ParticleType
{
 public:
  ResonanceType(std::string, double, int, double);
  
  double GetWidth() const
  {
    return fWidth;
  }

  void Print() const override;

 private:
  const double fWidth;
};
#endif
