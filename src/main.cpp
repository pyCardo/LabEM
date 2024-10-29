#include <TFile.h>
#include <TH1.h>
#include <TMath.h>
#include <TRandom.h>

#include "particle.hpp"

// #include <vector>

void SetUp() {
  gRandom->SetSeed();

  Particle::AddParticleType(new ParticleType("pi+", .13957, 1));
  Particle::AddParticleType(new ParticleType("pi-", .13957, -1));
  Particle::AddParticleType(new ParticleType("K+", .49367, 1));
  Particle::AddParticleType(new ParticleType("K-", .49367, -1));
  Particle::AddParticleType(new ParticleType("p+", .93827, 1));
  Particle::AddParticleType(new ParticleType("p-", .93827, -1));
  Particle::AddParticleType(
      new ResonanceType("K*", .89166, 0, .05));  // index for K* is 6
  // this way, ownership is implicitly transferred to the Particle class when
  // AddParticleType is called
}

int main() {
  SetUp();

  // Histograms
  auto* hParticleTypes{new TH1I{"hParticleTypes", "Particle types", 7, 0, 7}};
  hParticleTypes->GetXaxis()->SetBinLabel(1, "pi+");
  hParticleTypes->GetXaxis()->SetBinLabel(2, "pi-");
  hParticleTypes->GetXaxis()->SetBinLabel(3, "K+");
  hParticleTypes->GetXaxis()->SetBinLabel(4, "K-");
  hParticleTypes->GetXaxis()->SetBinLabel(5, "p+");
  hParticleTypes->GetXaxis()->SetBinLabel(6, "p-");
  hParticleTypes->GetXaxis()->SetBinLabel(7, "K*");
  hParticleTypes->GetYaxis()->SetTitle("Entries");

  auto* hPhi{new TH1D{"hPhi", "Azimuthal angle Distribution", 500, 0.,
                      TMath::TwoPi()}};
  hPhi->GetXaxis()->SetTitle("#phi (rad)");
  hPhi->GetYaxis()->SetTitle("Entries");

  auto* hTheta{
      new TH1D{"hTheta", "Polar angle Distribution", 500, 0., TMath::Pi()}};
  hTheta->GetXaxis()->SetTitle("#theta (rad)");
  hTheta->GetYaxis()->SetTitle("Entries");

  auto* hImpulse{new TH1D{"hImpulse", "Impulse", 500, 0., 5.}};
  hImpulse->GetXaxis()->SetTitle("Impulse (GeV/c)");
  hImpulse->GetYaxis()->SetTitle("Entries");

  auto* hTransverseImpulse{
      new TH1D{"hTransverseImpulse", "Transverse impulse", 100, 0., 4.}};
  hTransverseImpulse->GetXaxis()->SetTitle("Transverse impulse (GeV/c)");
  hTransverseImpulse->GetYaxis()->SetTitle("Entries");

  auto* hEnergy{new TH1D{"hEnergy", "Energy", 500, 0., 5.}};
  hEnergy->GetXaxis()->SetTitle("Energy (GeV)");
  hEnergy->GetYaxis()->SetTitle("Entries");

  auto* hInvMass{
      new TH1D{"hInvMass", "Invariant mass (all particles)", 500, 0., 6.}};
  hInvMass->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
  hInvMass->GetYaxis()->SetTitle("Entries");

  auto* hInvMassSameSign{new TH1D{
      "hInvMassSameSign", "Invariant mass (same sign particles)", 500, 0., 5.}};
  hInvMassSameSign->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
  hInvMassSameSign->GetYaxis()->SetTitle("Entries");

  auto* hInvMassDiscSign{new TH1D{"hInvMassDiscSign",
                                  "Invariant mass (discordant sign particles)",
                                  500, 0., 5.}};
  hInvMassDiscSign->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
  hInvMassDiscSign->GetYaxis()->SetTitle("Entries");

  auto* hInvMassPiKSame{new TH1D{
      "hInvMassPiKSame", "Invariant mass (pi-K same sign)", 500, 0., 5.}};
  hInvMassPiKSame->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
  hInvMassPiKSame->GetYaxis()->SetTitle("Entries");

  auto* hInvMassPiKDisc{new TH1D{
      "hInvMassPiKDisc", "Invariant mass (pi-K discordant sign)", 500, 0., 5.}};
  hInvMassPiKDisc->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
  hInvMassPiKDisc->GetYaxis()->SetTitle("Entries");

  // Benchmark
  auto* hInvMassDecayProd{new TH1D{
      "hInvMassDecayProd", "Invariant mass (decay products)", 500, 0.4, 1.4}};
  hInvMassDecayProd->GetXaxis()->SetTitle("Invariant mass (GeV/c^2)");
  hInvMassDecayProd->GetYaxis()->SetTitle("Entries");

  // create structure to store sum of squares of weights
  // error per bin will be computed as sqrt(sum of squares of weight) for each bin
  hInvMassSameSign->Sumw2();
  hInvMassDiscSign->Sumw2();
  hInvMassPiKSame->Sumw2();
  hInvMassPiKDisc->Sumw2();

  constexpr std::size_t numEvents{100000};
  constexpr std::size_t numParticles{100};

  std::array<Particle, 120> EventParticles;
  // taking into account that each particle might decay

  for (std::size_t event{0}; event < numEvents; ++event) {

    EventParticles.fill(Particle());  // default
    int number_of_K = 0;

    for (std::size_t i{0}; i < numParticles; ++i) {

      const double phi{gRandom->Uniform(0., TMath::TwoPi())};
      const double theta{gRandom->Uniform(0., TMath::Pi())};
      const double pAbs{gRandom->Exp(1.)};

      // Filling Histos
      hPhi->Fill(phi);
      hTheta->Fill(theta);
      hImpulse->Fill(pAbs);

      const Momentum P{pAbs * TMath::Sin(theta) * TMath::Cos(phi),
                       pAbs * TMath::Sin(theta) * TMath::Sin(phi),
                       pAbs * TMath::Cos(theta)};

      hTransverseImpulse->Fill(std::sqrt(std::pow(P.x, 2) + std::pow(P.y, 2)));

      std::string partName;
      const double x{gRandom->Uniform()};
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
      // should this be done using indices?
      // comparing strings often leads to unexpected behaviours...

      Particle particle;
      particle.SetType(partName);
      particle.SetP(P);

      hParticleTypes->Fill(static_cast<int>(particle.GetIndex()));
      hEnergy->Fill(particle.Energy());

      EventParticles[i] = particle;

      // Handle K* decays
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

        EventParticles[static_cast<std::size_t>(numParticles +
                                                2 * number_of_K)] = (dau1);
        EventParticles[static_cast<std::size_t>(numParticles + 2 * number_of_K +
                                                1)] = (dau2);
        ++number_of_K;
        // each daughter is moved at the end of EventParticles
      }
    }

    // here a double for is necessary
    // since the second loop needs indices to start from the (i+1)-th element
    // of the array, it makes more sense to use indices for the first loop as well
    for (std::size_t i{0}; i < EventParticles.size(); i++) {

      if (EventParticles[i].GetIndex() == 6) {
        continue;
      }

      for (std::size_t j{i + 1}; j < EventParticles.size(); j++) {
        if (EventParticles[j].GetIndex() == 6) {
          continue;
        }

        Particle p1{EventParticles[i]};
        Particle p2{EventParticles[j]};

        // Calculate the invariant mass of every couple of particles of the event
        // Note that particles of type K* are not considered, as they are decayed
        const double invMass{p1.InvMass(p2)};

        hInvMass->Fill(invMass);

        if (p1.GetCharge() * p2.GetCharge() > 0) {
          hInvMassSameSign->Fill(invMass);
        } else if (p1.GetCharge() * p2.GetCharge() < 0) {
          hInvMassDiscSign->Fill(invMass);
        }

        // check if the particles are pi-K, with opposite signs
        if ((p1.GetName() == "pi+" && p2.GetName() == "K-") ||
            (p1.GetName() == "K-" && p2.GetName() == "pi+") ||
            (p1.GetName() == "pi-" && p2.GetName() == "K+") ||
            (p1.GetName() == "K+" && p2.GetName() == "pi-")) {
          hInvMassPiKDisc->Fill(invMass);
        }

        // check if the particles are pi-K, with the same sign
        if ((p1.GetName() == "pi+" && p2.GetName() == "K+") ||
            (p1.GetName() == "K+" && p2.GetName() == "pi+") ||
            (p1.GetName() == "pi-" && p2.GetName() == "K-") ||
            (p1.GetName() == "K-" && p2.GetName() == "pi-")) {
          hInvMassPiKSame->Fill(invMass);
        }
      }
    }

    // Calculate the invariant mass of the 2 decay products of the K* particles
    for (std::size_t i{numParticles}; i < EventParticles.size(); i += 2) {
      const double invMass{EventParticles[i].InvMass(EventParticles[i + 1])};
      hInvMassDecayProd->Fill(invMass);
    }
  }

  // Open a file to save the histograms
  auto* outFile{TFile::Open("histos.root", "RECREATE")};

  hParticleTypes->Write();
  hPhi->Write();
  hTheta->Write();
  hImpulse->Write();
  hTransverseImpulse->Write();
  hEnergy->Write();
  hInvMass->Write();
  hInvMassSameSign->Write();
  hInvMassDiscSign->Write();
  hInvMassPiKSame->Write();
  hInvMassPiKDisc->Write();
  hInvMassDecayProd->Write();

  outFile->Close();

  // Clean Exit
  Particle::ClearParticleTypes();

  return 0;
}