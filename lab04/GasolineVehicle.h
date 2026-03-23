#ifndef GASOLINEVEHICLE_H
#define GASOLINEVEHICLE_H

#include "Vehicle.h"

class GasolineVehicle : virtual public Vehicle {
protected:
    double gasMiles;
    double gallons;

public:
    GasolineVehicle() : gasMiles(0), gallons(0) {}

    void setGasMiles(double m) { gasMiles = m; }
    void setGallons(double g) { gallons = g; }

    double calcMPG() const {
        if (gallons == 0) return 0;
        return gasMiles / gallons;
    }
};

#endif