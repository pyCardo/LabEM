#include "resonanceType.hpp"

void ResonanceType::print() const
{
  ParticleType::print();
  std::cout << "Width of the particle: " << fWidth << std::endl;
}

ResonanceType::ResonanceType(std::string* Name, double Mass, int Charge,
                             double Width)
    : particleType(*Name, Mass, Charge)
    , fWidth{Width} {};