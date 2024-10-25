#include <TMath.h>
#include <TRandom.h>

#include "particle.hpp"
#include <vector>
void SetUp()
{
  gRandom->SetSeed();
  Particle::AddParticleType(new ParticleType("pi+", 0.13957, 1));
  Particle::AddParticleType(new ParticleType("pi-", 0.13957, -1));
  Particle::AddParticleType(new ParticleType("K+", 0.49367, 1));
  Particle::AddParticleType(new ParticleType("K-", 0.49367, -1));
  Particle::AddParticleType(new ParticleType("p+", 0.93827, 1));
  Particle::AddParticleType(new ParticleType("p-", 0.93827, -1));
  Particle::AddParticleType(new ResonanceType("K*", 0.89166, 0, 0.05));
}

int main()
{
  SetUp();

  // Particle::PrintParticleTypes();
  std::vector<Particle> EventParticles;
  const int numEvents{100000};
  /* const int numParticles{120};

   std::array<Particle, numParticles> eventParticles;

   for (int event{0}; event < numEvents; event++) {
     eventParticles = {}; // clears array

     std::generate(eventParticles.begin(), eventParticles.end(), [&]() {
       const double pAbs{gRandom->Exp(1.)};
       const double phi{gRandom->Uniform(0., TMath::TwoPi())};
       const double theta{gRandom->Uniform(0., TMath::Pi())};

       const Momentum P{pAbs * TMath::Sin(theta) * TMath::Cos(phi),
                        pAbs * TMath::Sin(theta) * TMath::Sin(phi),
                        pAbs * TMath::Cos(theta)};

       const double x{gRandom->Uniform()};

       std::string partName;
       if (x < 0.4) {
         partName = "pi+";
       } else if (x < 0.8) {
         partName = "pi-";
       } else if (x < 0.85) {
         partName = "K+";
       } else if (x < 0.9) {
         partName = "K-";
       } else if (x < 0.945) {
         partName = "p+";
       } else if (x < 0.99) {
         partName = "p-";
       } else {
         partName = "K*";
       }

       Particle particle;
       particle.SetType(partName);
       particle.SetP(P);

       return particle;
     });
   }
 */
  const int numParticles{100};
  for (int event{0}; event < numEvents; ++event) {
    for (int Particles{0}; Particles < numParticles; ++Particles) {
      const double pAbs{gRandom->Exp(1.)};
      const double phi{gRandom->Uniform(0., TMath::TwoPi())};
      const double theta{gRandom->Uniform(0., TMath::Pi())};

      const Momentum P{pAbs * TMath::Sin(theta) * TMath::Cos(phi),
                       pAbs * TMath::Sin(theta) * TMath::Sin(phi),
                       pAbs * TMath::Cos(theta)};

      const double x{gRandom->Uniform()};
      std::string partName;
      if (x < 0.4) {
        partName = "pi+";
      } else if (x < 0.8) {
        partName = "pi-";
      } else if (x < 0.85) {
        partName = "K+";
      } else if (x < 0.9) {
        partName = "K-";
      } else if (x < 0.945) {
        partName = "p+";
      } else if (x < 0.99) {
        partName = "p-";
      } else {
        partName = "K*";
      }
      Particle particle;
      particle.SetType(partName);
      particle.SetP(P);
      if (partName == "K*") {
        Particle dau1;
        Particle dau2;
        const double new_x{gRandom->Uniform()};
        if (x < 0.5) {
          dau1.SetType("pi+");
          dau2.SetType("K-");
        } else {
          dau1.SetType("pi-");
          dau2.SetType("K+");
        }
        particle.Decay2Body(dau1, dau2);
        EventParticles.push_back(dau1);
        EventParticles.push_back(dau2);
      } else
        EventParticles.push_back(particle);
    }
  }
  // Clean Exit
  Particle::ClearParticleTypes();
  return 0;
}