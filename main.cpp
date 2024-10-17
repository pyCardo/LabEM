#include "particle.hpp"
#include "resonanceType.hpp"

int main()
{
  ParticleType p("giorgio", 5, 1);
  ResonanceType r("riccardo", 7, 2, 4);

  std::cout << "Charge: " << p.GetCharge() << std::endl;
  p.Print();

  std::cout << "Charge: " << r.GetCharge() << std::endl;
  r.Print();

  std::array<ParticleType*, 2> container;
  container[0] = &p;
  container[1] = &r;

  for (ParticleType* i : container) {
    i->Print();
  }

  return 0;
}