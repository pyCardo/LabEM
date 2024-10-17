#include "particle.hpp"

int Particle::fNParticleType = 0;

Particle::Particle(int index, Momentum p) : fIndex{index}, fP{p}
{
}