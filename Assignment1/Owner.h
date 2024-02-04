#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <string>
#include <memory>
#include "Vehicle.h"

class Owner {
private:
    std::string name_;
    std::string adress_;
    std::shared_ptr<Vehicle> vehicle_;

public:
    Owner(std::string name, std::string adress, std::shared_ptr<Vehicle> vehicle);

    std::shared_ptr<Vehicle> getVehicle();

    void displayOwner();
};

#endif // OWNER_H