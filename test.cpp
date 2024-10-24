#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "particle.hpp"

// TEST dei getters

TEST_CASE("Testing the getters of PType")
{
  ParticleType u("up", 5, 1);
  ParticleType d("down", 20, 4);
  // ParticleType b("bottom", -3, 3);
  // ParticleType t("top", 6, -1);

  CHECK(u.GetName() == "up");
  CHECK(u.GetMass() == 5);
  CHECK(u.GetCharge() == 1);

  CHECK(d.GetName() == "down");
  CHECK(d.GetMass() == 20);
  CHECK(d.GetCharge() == 4);

  /*CHECK(b.GetName() == "bottom");
  CHECK(b.GetMass() == -3);
  CHECK(b.GetCharge() == 3);

  CHECK(t.GetName() == "top");
  CHECK(t.GetMass() == 6);
  CHECK(t.GetCharge() == -1);*/
}

TEST_CASE("Testing the getters of RType")
{
  ResonanceType u("up", 5, 1, 2.);
  ResonanceType d("down", 20, 4, 7.);
  // ResonanceType b("bottom", -3, 3, -1.);
  // ResonanceType t("top", 6, -1, 4);

  CHECK(u.GetName() == "up");
  CHECK(u.GetMass() == 5);
  CHECK(u.GetCharge() == 1);
  CHECK(u.GetWidth() == 2.);

  CHECK(d.GetName() == "down");
  CHECK(d.GetMass() == 20);
  CHECK(d.GetCharge() == 4);
  CHECK(d.GetWidth() == 7.);

  /*CHECK(b.GetName() == "bottom");
  CHECK(b.GetMass() == -3);
  CHECK(b.GetCharge() == 3);

  CHECK(t.GetName() == "top");
  CHECK(t.GetMass() == 6);
  CHECK(t.GetCharge() == -1);*/
}

/*
//Non possiamo ancora svolgere questi test per COLPA di NicoCardo;

TEST_CASE("Test GetEnergy, InvMass, SetType e SetP") {
    // Crea alcune particelle di esempio
    ResonanceType pionPlus("Pione+", 0.13957, 1, 0.0);
    ResonanceType kaonPlus("Kaone+", 0.49367, 1, 0.0);

    // Aggiungi i tipi di particelle
    Particle::AddParticleType(pionPlus);
    Particle::AddParticleType(kaonPlus);

    // Test 1: Verifica GetEnergy per un Pione+ con impulso nullo
    Particle p1("Pione+", {0, 0, 0});
    CHECK(p1.GetEnergy() == doctest::Approx(0.13957));  // Energia = massa,
impulso nullo

    // Test 2: Verifica GetEnergy per un Kaone+ con impulso non nullo
    Particle p2("Kaone+", {1.0, 0.0, 0.0});
    CHECK(p2.GetEnergy() == doctest::Approx(sqrt(0.49367 * 0.49367 + 1.0)));  //
Energia relativistica

    // Test 3: Verifica InvMass tra due particelle diverse (Pione+ e Kaone+)
    double invMass = p1.InvMass(p2);
    CHECK(invMass == doctest::Approx(sqrt(pow(p1.GetEnergy() + p2.GetEnergy(),
2) - 1.0)));  // Invariante con Px sommati

    // Test 4: Verifica SetType cambiando il tipo di particella da Pione+ a
Kaone+ p1.SetType("Kaone+"); CHECK(p1.GetMass() == doctest::Approx(0.49367)); //
Ora la massa è quella del Kaone+

    // Test 5: Verifica SetP cambiando l'impulso della particella
    Momentum newP = {0.5, 0.5, 0.0};
    p1.SetP(newP);
    CHECK(p1.GetMomentum().x == doctest::Approx(0.5));
    CHECK(p1.GetMomentum().y == doctest::Approx(0.5));
    CHECK(p1.GetMomentum().z == doctest::Approx(0.0));
}

TEST_CASE("Test Getter: GetIndex, GetMomentum, GetMass, GetEnergy") {
    // Crea alcune particelle di esempio
    ResonanceType pionPlus("Pione+", 0.13957, 1, 0.0);
    ResonanceType kaonPlus("Kaone+", 0.49367, 1, 0.0);

    // Aggiungi i tipi di particelle
    Particle::AddParticleType(pionPlus);
    Particle::AddParticleType(kaonPlus);

    // Test 1: Verifica GetIndex dopo aver settato una particella a "Pione+"
    Particle p1("Pione+", {0, 0, 0});
    CHECK(p1.GetIndex() == 0);  // Assumiamo che il primo tipo aggiunto sia
indicizzato come 0

    // Test 2: Verifica GetMomentum per una particella con impulso non nullo
    Momentum p = {1.0, 2.0, 3.0};
    Particle p2("Kaone+", p);
    Momentum p2_momentum = p2.GetMomentum();
    CHECK(p2_momentum.x == doctest::Approx(1.0));
    CHECK(p2_momentum.y == doctest::Approx(2.0));
    CHECK(p2_momentum.z == doctest::Approx(3.0));

    // Test 3: Verifica GetMass per una particella di tipo "Kaone+"
    CHECK(p2.GetMass() == doctest::Approx(0.49367));

    // Test 4: Verifica GetMass per una particella di tipo "Pione+"
    CHECK(p1.GetMass() == doctest::Approx(0.13957));

    // Test 5: Verifica GetEnergy per una particella con impulso non nullo
    CHECK(p2.GetEnergy() == doctest::Approx(sqrt(0.49367 * 0.49367 +
p.Norm2())));  // Energia relativistica
}

//TEST delle funzioni:

TEST_CASE("Test AddParticleType e FindParticle") {
    // Crea alcune particelle di esempio
    ResonanceType pionPlus("Pione+", 0.13957, 1, 0.0);
    ResonanceType pionMinus("Pione-", 0.13957, -1, 0.0);
    ResonanceType kaonPlus("Kaone+", 0.49367, 1, 0.0);
    ResonanceType protonPlus("Protone+", 0.93827, 1, 0.0);
    ResonanceType photon("Fotone", 0.0, 0, 0.0);

    // Test 1: Aggiungi particelle e verifica la loro presenza con FindParticle
    Particle::AddParticleType(pionPlus);
    CHECK()
    CHECK(Particle::FindParticle("Pione+") == 0);  // Indice 0

    // Test 2: Aggiungi un'altra particella e verifica
    Particle::AddParticleType(pionMinus);
    CHECK(Particle::FindParticle("Pione-") == 1);  // Indice 1

    // Test 3: Aggiungi altre particelle
    Particle::AddParticleType(kaonPlus);
    CHECK(Particle::FindParticle("Kaone+") == 2);  // Indice 2

    // Test 4: Verifica una particella che non è stata aggiunta
    CHECK(Particle::FindParticle("Protone-") == -1);  // Non presente, dovrebbe
ritornare -1

    // Test 5: Aggiungi e verifica l'ultima particella
    Particle::AddParticleType(protonPlus);
    CHECK(Particle::FindParticle("Protone+") == 3);  // Indice 3

    // Test 6: Verifica la presenza di una particella fotone
    Particle::AddParticleType(photon);
    CHECK(Particle::FindParticle("Fotone") == 4);  // Indice 4
}

TEST_CASE("Test AddParticleType") {

    // Test 1: Aggiungi una particella e verifica che sia stata aggiunta
correttamente ResonanceType pionPlus("Pione+", 0.13957, 1, 0.0);
    Particle::AddParticleType(pionPlus);
    CHECK(Particle::fParticleTypes[0]->GetName() == "Pione+");
    CHECK(Particle::fParticleTypes[0]->GetMass() == doctest::Approx(0.13957));

    // Test 2: Aggiungi un'altra particella e verifica che venga aggiunta in un
nuovo slot ResonanceType kaonPlus("Kaone+", 0.49367, 1, 0.0);
    Particle::AddParticleType(kaonPlus);
    CHECK(Particle::fParticleTypes[1]->GetName() == "Kaone+");
    CHECK(Particle::fParticleTypes[1]->GetMass() == doctest::Approx(0.49367));

    // Test 3: Tenta di aggiungere di nuovo lo stesso tipo di particella
    Particle::AddParticleType(kaonPlus);
    // Deve stampare "Particle already exists" e non fare nulla, quindi l'indice
2 deve essere vuoto (nullptr) CHECK(Particle::fParticleTypes[2] == nullptr);

    // Test 4: Verifica che il numero di tipi di particelle sia stato
incrementato correttamente CHECK(Particle::fNParticleTypes == 2);

    // Test 5: Aggiungi una terza particella e verifica
    ResonanceType proton("Protone+", 0.93827, 1, 0.0);
    Particle::AddParticleType(proton);
    CHECK(Particle::fParticleTypes[2]->GetName() == "Protone+");
    CHECK(Particle::fParticleTypes[2]->GetMass() == doctest::Approx(0.93827));
    CHECK(Particle::fNParticleTypes == 3);
}
*/
