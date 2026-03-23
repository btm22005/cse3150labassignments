#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "HybridVehicle.h"

TEST_CASE("Gasoline MPG") {
    HybridVehicle h;
    h.setGasMiles(200);
    h.setGallons(5);

    CHECK(h.calcMPG() == doctest::Approx(40.0));
}

TEST_CASE("Electric MPGe") {
    HybridVehicle h;
    h.setElectricMiles(300);
    h.setKwh(70);

    CHECK(h.calcMPGe() == doctest::Approx(300.0 / (70.0 / 33.7)));
}

TEST_CASE("Hybrid total MPGe") {
    HybridVehicle h;
    h.setGasMiles(200);
    h.setGallons(5);

    h.setElectricMiles(300);
    h.setKwh(70);

    CHECK(h.calcTotalMPGe() == doctest::Approx(500.0 / (5.0 + 70.0 / 33.7)));
}

TEST_CASE("Cost per mile") {
    HybridVehicle h;
    h.setGasMiles(200);
    h.setGallons(5);

    h.setElectricMiles(300);
    h.setKwh(70);

    double expected = (5.0 * 3.10 + 70.0 * 0.24) / 500.0;
    CHECK(h.costPerMile(3.10) == doctest::Approx(expected));
}
