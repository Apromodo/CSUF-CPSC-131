#include <iostream>
#include "Vehicle.h"
#include "Owner.h"

int main() {
    std::shared_ptr<Vehicle> vehicle = std::make_shared<Vehicle>
                    ("Mazda RX7 Veilside", 1997, "NONE", "Orange & Black");

    std::unique_ptr<Owner> owner = std::make_unique<Owner>
                    ("Kaya", "CSUF CS 102B", vehicle);

    owner->displayOwner();

    owner->getVehicle()->displayVehicle();

    return 0;
}
