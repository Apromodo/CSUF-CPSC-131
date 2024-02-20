#include "Owner.h"

Owner::Owner(std::string name, std::string phone, std::shared_ptr<Vehicle> vehicle)
    : name_(name), adress_(phone), vehicle_(vehicle) {}

std::shared_ptr<Vehicle> Owner::getVehicle() {
    return vehicle_;
}

void Owner::displayOwner() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Address: " << adress_ << std::endl;
}