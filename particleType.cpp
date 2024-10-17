#include "particleType.hpp"

ParticleType::ParticleType(std::string name, double mass, int charge) : fName{name}, fMass{mass}, fCharge{charge}
{
}

void ParticleType::Print() const
{
    std::cout << "Particle: " << fName << std::endl;
    std::cout << "Mass: " << fMass << "GeV/c^2" << std::endl;
    std::cout << "Charge: " << fCharge << "e" << std::endl;
}