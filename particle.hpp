#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "particleType.hpp"

struct Momentum
{
    double x;
    double y;
    double z;
};

class Particle
{
public:
    Particle(int index, Momentum p);

private:
    static const int fMaxNumParticles{10};
    static int fNParticleType;
    static ParticleType *fParticleType[fMaxNumParticles];

    int fIndex;
    Momentum fP{0, 0, 0};
};

#endif