#include "particle.hpp"

#include <math.h>
#include <random>

int Particle::fNParticleTypes = 0;
std::array<ParticleType*, 7> Particle::fParticleTypes;

Particle::Particle(std::string name, Momentum p)
    : fP{p}
{
  int fIndex = FindParticle(name);
}

int Particle::FindParticle(std::string name)
{
  for (int i = 0; i < fParticleTypes.size(); i++) {
    if (fParticleTypes[i]->GetName() == name) {
      return i;
    }
  }
  std::cout << "Particle not found." << std::endl;
  return -1;
}

void Particle::AddParticleType(ResonanceType type)
{
  for (int i = 0; i < fParticleTypes.size(); i++) {
    if (fParticleTypes[i]->GetName() == type.GetName()) {
      std::cout << "Particle already exists." << std::endl;
      return;
    } else if ((fParticleTypes[i]->GetName()).empty()) {
      fParticleTypes[i] = &type;
      return;
    }
  }
  std::cout << "No space left for a new particle." << std::endl;
  return;
}

void Particle::PrintParticleTypes()
{
  for (auto type : Particle::fParticleTypes) {
    type->Print();
  }
}

void Particle::PrintParticleData() const
{
  std::cout << "Particle index: " << fIndex << '\n';
  std::cout << "Particle name: " << fParticleTypes[fIndex]->GetName() << '\n';
  std::cout << "Particle Px: " << fP.x << '\n';
  std::cout << "Particle Py: " << fP.y << '\n';
  std::cout << "Particle Pz: " << fP.z << '\n';
}

double Particle::GetEnergy() const
{
  return std::sqrt(std::pow(GetMass(), 2) + fP.Norm2());
}

double Particle::InvMass(const Particle& particle) const
{
  const double sumEnergy{GetEnergy() + particle.GetEnergy()};
  const Momentum sumP{fP.x + particle.fP.x, fP.y + particle.fP.y,
                      fP.z + particle.fP.z};

  return std::sqrt(std::pow(sumEnergy, 2) - sumP.Norm2());
}

int Particle::Decay2Body(Particle& dau1, Particle& dau2) const
{
  if (GetMass() == 0.) {
    printf("Decayment cannot be preformed if mass is zero\n");
    return 1;
  }

  double massMot  = GetMass();
  double massDau1 = dau1.GetMass();
  double massDau2 = dau2.GetMass();

  std::default_random_engine randEngine{std::random_device{}()};
  std::normal_distribution<double> normDistr{0., 1.};

  const double y1{normDistr(randEngine)};
  massMot += fParticleTypes[fIndex]->GetWidth() * y1;

  if (massMot < massDau1 + massDau2) {
    std::cout
        << "Decay cannot occur in this channel, because mass is too low.\n";
    return 2;
  }

  const double pOut =
      sqrt(
          (massMot * massMot - (massDau1 + massDau2) * (massDau1 + massDau2))
          * (massMot * massMot - (massDau1 - massDau2) * (massDau1 - massDau2)))
      / massMot * 0.5;

  std::uniform_real_distribution<double> phiDistr{0., M_PI * 2.};
  std::uniform_real_distribution<double> thetaDistr{-M_PI_2, M_PI_2};

  const double phi{phiDistr(randEngine)};
  const double theta{thetaDistr(randEngine)};

  const Momentum p1 =
      Momentum{pOut * std::sin(theta) * std::cos(phi),
               pOut * std::sin(theta) * std::sin(phi), pOut * std::cos(theta)};
  const Momentum p2 = Momentum{-p1.x, -p1.y, -p1.z};
  dau1.SetP(p1);
  dau2.SetP(p2);

  const double energy{GetEnergy()};
  const Momentum B{fP.x / energy, fP.y / energy, fP.z / energy};

  dau1.Boost(B);
  dau2.Boost(B);
}

void Particle::Boost(Momentum b)
{
  double energy = GetEnergy();

  // Boost this Lorentz vector
  double b2     = b.x * b.x + b.y * b.y + b.z * b.z;
  double gamma  = 1.0 / sqrt(1.0 - b2);
  double bp     = b.x * fP.x + b.y * fP.y + b.z * fP.z;
  double gamma2 = b2 > 0 ? (gamma - 1.0) / b2 : 0.0;

  fP.x += gamma2 * bp * b.x + gamma * b.x * energy;
  fP.y += gamma2 * bp * b.y + gamma * b.y * energy;
  fP.z += gamma2 * bp * b.z + gamma * b.z * energy;
}