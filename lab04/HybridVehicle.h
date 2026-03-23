#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include "GasolineVehicle.h"
#include "ElectricVehicle.h"

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
public:
    double calcTotalMPGe() const {
        double totalMiles = gasMiles + electricMiles;
        double totalGallonsEquivalent = gallons + (kwh / 33.7);

        if (totalGallonsEquivalent == 0) return 0;
        return totalMiles / totalGallonsEquivalent;
    }

    double costPerMile(double costPerGallon, double costPerKwh = 0.24) const {
        double totalMiles = gasMiles + electricMiles;
        if (totalMiles == 0) return 0;

        double totalCost = gallons * costPerGallon + kwh * costPerKwh;
        return totalCost / totalMiles;
    }
};

#endif