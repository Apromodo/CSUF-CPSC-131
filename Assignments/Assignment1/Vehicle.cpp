#include "Vehicle.h"

Vehicle::Vehicle(std::string model, int year, std::string registrationNumber, std::string color)
    : model_(model), year_(year), registrationNumber_(registrationNumber), color_(color) {}

void Vehicle::displayVehicle() {
    std::cout << "Model: " << model_ << std::endl;
    std::cout << "Year: " << year_ << std::endl;
    std::cout << "Registration Number: " << registrationNumber_ << std::endl;
    std::cout << "Color: " << color_ << std::endl;
}
