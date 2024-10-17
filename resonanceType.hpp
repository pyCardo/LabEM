#ifndef RESONANCE_TYPE_HPP
#define RESONANCE_TYPE_HPP
#include "particleType.hpp"

class ResonanceType : public ParticleType
{
 public:
  double GetWidth() const
  {
    return fWidth;
  }
  void Print() const override;
  ResonanceType(std::string, double, int, double);

 private:
  const double fWidth;
};
#endif
