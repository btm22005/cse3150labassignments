#include <iostream>
#include "HybridVehicle.h"

using namespace std;

int main() {
    HybridVehicle h;

    h.setGasMiles(200);
    h.setGallons(5);

    h.setElectricMiles(300);
    h.setKwh(70);

    cout << "Gas MPG: " << h.calcMPG() << endl;
    cout << "Electric MPGe: " << h.calcMPGe() << endl;
    cout << "Total MPGe: " << h.calcTotalMPGe() << endl;
    cout << "Cost per mile: " << h.costPerMile(3.10) << endl;

    return 0;
}