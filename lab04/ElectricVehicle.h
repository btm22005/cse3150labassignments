#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include "Vehicle.h"

class ElectricVehicle : virtual public Vehicle {
protected:
    double electricMiles;
    double kwh;

public:
    ElectricVehicle() : electricMiles(0), kwh(0) {}

    void setElectricMiles(double m) { electricMiles = m; }
    void setKwh(double k) { kwh = k; }

    double calcMPGe() const {
        if (kwh == 0) return 0;
        return electricMiles / (kwh / 33.7);
    }
};

#endif