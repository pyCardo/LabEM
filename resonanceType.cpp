#include "resonanceType.hpp"

void ResonanceType::Print() const
{
  ParticleType::Print();
  std::cout << "Width: " << fWidth << std::endl;
}

ResonanceType::ResonanceType(std::string name, double mass, int charge,
                             double width)
    : ParticleType(name, mass, charge)
    , fWidth{width} {};