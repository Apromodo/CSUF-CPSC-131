#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
private:
    std::string model_;
    int year_;
    std::string registrationNumber_;
    std::string color_;

public:
    Vehicle(std::string model, int year, 
            std::string registrationNumber, 
            std::string color);
    
    void displayVehicle();
};

#endif // VEHICLE_H
