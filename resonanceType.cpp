#include "resonanceType.hpp"

void ResonanceType::Print() const
{
  ParticleType::Print();
  std::cout << "Width of the particle: " << fWidth << std::endl;
}

ResonanceType::ResonanceType(std::string* Name, double Mass, int Charge,
                             double Width)
    : ParticleType(*Name, Mass, Charge)
    , fWidth{Width} {};