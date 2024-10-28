#include "particle.hpp"

#include <random>

std::size_t Particle::fNParticleTypes = 0;
std::array<ParticleType*, 7> Particle::fParticleTypes;

Particle::Particle(std::string name, Momentum p) : fP{p} {
  fIndex = FindParticle(name);
}

std::size_t Particle::FindParticle(std::string name) {
  for (std::size_t i = 0; i < fParticleTypes.size(); i++) {
    if (fParticleTypes[i] && fParticleTypes[i]->GetName() == name) {
      return static_cast<int>(i);
    }  // is fParticleTypes[i] a meaningful request? isn't it always true?
    /* fParticleTypes[i] evaluates to true if fParticleTypes[i] is not nullptr;
     * thanks to short-circuit evaluation in &&, it's safe to dereference
     * fParticleTypes[i] without risking a null pointer dereference */
  }
  std::cout << "Particle not found." << std::endl;
  return -1;  // standing for "not found"
}

void Particle::AddParticleType(ParticleType* type) {
  if (fNParticleTypes == fParticleTypes.size()) {
    std::cout << "No space left for a new particle." << std::endl;
    return;
  }

  // Check if particle type already exists
  if (Particle::FindParticle(type->GetName()) != static_cast<std::size_t>(-1)) {
    std::cout << "Particle already exists." << std::endl;
    return;
  }

  // for (int i = 0; i < fNParticleTypes; i++) {
  //   if (fParticleTypes[i] && fParticleTypes[i]->GetName() == type->GetName())
  //   {
  //     std::cout << "Particle already exists." << std::endl;
  //     return;
  //   }
  // }

  // Allocate a new dynamic copy of 'type' and add it to fParticleTypes
  fParticleTypes[fNParticleTypes] = type;
  // Ownership of type is transferred from caller to Particle; deallocation will
  // be done by a static member function of Particle
  ++fNParticleTypes;
}

void Particle::ClearParticleTypes() {
  for (std::size_t i = 0; i < fNParticleTypes; ++i) {
    delete fParticleTypes[i];
    fParticleTypes[i] = nullptr;
  }
  fNParticleTypes = 0;
}

void Particle::PrintParticleTypes() {
  for (ParticleType* type : Particle::fParticleTypes) {
    if (type != nullptr) {
      type->Print();
      std::cout << std::endl;
    }
  }
}

void Particle::PrintParticleData() const {
  std::cout << "Particle index: " << fIndex << std::endl;
  std::cout << "Particle name: " << fParticleTypes[fIndex]->GetName()
            << std::endl;
  std::cout << "Particle Px: " << fP.x << std::endl;
  std::cout << "Particle Py: " << fP.y << std::endl;
  std::cout << "Particle Pz: " << fP.z << std::endl;
}

double Particle::InvMass(const Particle& particle) const {
  const double sumEnergy{Energy() + particle.Energy()};
  const Momentum sumP{fP.x + particle.fP.x, fP.y + particle.fP.y,
                      fP.z + particle.fP.z};

  return std::sqrt(std::pow(sumEnergy, 2) - sumP.Norm2());
}

int Particle::Decay2Body(Particle& dau1, Particle& dau2) const {
  if (GetMass() == 0.) {
    std::cout << "Decayment cannot be preformed if mass is zero" << std::endl;
    return 1;
  }

  double massMot = GetMass();  // stands for mother
  double massDau1 = dau1.GetMass();
  double massDau2 = dau2.GetMass();

  std::default_random_engine eng{std::random_device{}()};
  std::normal_distribution<double> normDistr{0., 1.};
  const double y1{normDistr(eng)};  // introducing a small random mass variation

  massMot += fParticleTypes[fIndex]->GetWidth() * y1;
  // scaling variation by width
  // this way, the mother particle is given a slightly variable mass

  if (massMot < massDau1 + massDau2) {
    std::cout << "Decay cannot occur in this channel, because mass is too low"
              << std::endl;
    return 2;
  }

  const double pOut =
      std::sqrt((std::pow(massMot, 2) - std::pow(massDau1 + massDau2, 2)) *
                (std::pow(massMot, 2) - std::pow(massDau1 - massDau2, 2))) /
      massMot * .5;
  // momentum is the same in module for the two daughters

  std::uniform_real_distribution<double> phiDistr{0., M_PI * 2.};
  std::uniform_real_distribution<double> thetaDistr{-M_PI_2, M_PI_2};

  const double phi{phiDistr(eng)};
  const double theta{thetaDistr(eng)};

  // Spherical coordinates: theta is the polar angle, phi is the azimuthal angle
  const Momentum p1 =
      Momentum{pOut * std::sin(theta) * std::cos(phi),
               pOut * std::sin(theta) * std::sin(phi), pOut * std::cos(theta)};
  const Momentum p2 = Momentum{-p1.x, -p1.y, -p1.z};
  // must be the opposite of p1 for the principle of conservation of momentum
  // in the mother's reference frame

  dau1.SetP(p1);
  dau2.SetP(p2);

  const double energy{Energy()};
  const Momentum B{fP.x / energy, fP.y / energy, fP.z / energy};
  // taking into account the mother's movement
  // warning: B is actually a velocity vector

  dau1.Boost(B);
  dau2.Boost(B);
  return 0;
}

void Particle::Boost(Momentum b) {
  double energy = Energy();

  double b2 = b.Norm2();
  double gamma = 1. / sqrt(1. - b2);
  double bp = b.x * fP.x + b.y * fP.y + b.z * fP.z;
  double gamma2 = b2 > 0 ? (gamma - 1.) / b2 : 0.;

  fP.x += gamma2 * bp * b.x + gamma * b.x * energy;
  fP.y += gamma2 * bp * b.y + gamma * b.y * energy;
  fP.z += gamma2 * bp * b.z + gamma * b.z * energy;
}