#include <TMath.h>
#include <TRandom.h>

#include "particle.hpp"
// #include <vector>
void SetUp() {
  gRandom->SetSeed();
  Particle::AddParticleType(new ParticleType("pi+", 0.13957, 1));
  Particle::AddParticleType(new ParticleType("pi-", 0.13957, -1));
  Particle::AddParticleType(new ParticleType("K+", 0.49367, 1));
  Particle::AddParticleType(new ParticleType("K-", 0.49367, -1));
  Particle::AddParticleType(new ParticleType("p+", 0.93827, 1));
  Particle::AddParticleType(new ParticleType("p-", 0.93827, -1));
  Particle::AddParticleType(new ResonanceType("K*", 0.89166, 0, 0.05));
  // this way, ownership is implicitly transferred to the Particle class when
  // AddParticleType is called
}

int main() {
  SetUp();
  const int numParticles{100};
  // Particle::PrintParticleTypes();
  std::array<Particle, 3 * numParticles> EventParticles;
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
   }*/

  for (int event{0}; event < numEvents; ++event) {
    EventParticles.fill(Particle());
    int number_of_K = 0;
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

      EventParticles[Particles] = (particle);
      if (partName == "K*") {
        Particle dau1;
        Particle dau2;
        const double new_x{gRandom->Uniform()};
        if (new_x < 0.5) {
          dau1.SetType("pi+");
          dau2.SetType("K-");
        } else {
          dau1.SetType("pi-");
          dau2.SetType("K+");
        }
        particle.Decay2Body(dau1, dau2);
        EventParticles[numParticles + 2 * number_of_K] = (dau1);
        EventParticles[numParticles + 2 * number_of_K + 1] = (dau2);
        ++number_of_K;
      }
    }
  }
  // Clean Exit
  Particle::ClearParticleTypes();
  return 0;
}