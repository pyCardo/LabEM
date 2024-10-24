#ifndef PARTICLE_TYPE_HPP
#define PARTICLE_TYPE_HPP

#include <array>
#include <iostream>
#include <string>

class ParticleType
{
 private:
  // attributes
  const std::string fName;
  const double fMass;
  const int fCharge;

 public:
  // constructor
  ParticleType(std::string name, double mass, int charge);
  // virtual ~ParticleType() = default;

  // getters
  const std::string GetName() const
  {
    return fName;
  }

  double GetMass() const
  {
    return fMass;
  }

  int GetCharge() const
  {
    return fCharge;
  }

  virtual double GetWidth() const
  {
    return 0;
  }

  // output
  virtual void Print() const;
};

#endif