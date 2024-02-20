#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Vehicle {
private:
    string model_;
    int year_;
    string registrationNumber_;
    string color_;

public:
    Vehicle(string model, int year, string registrationNumber, string color)
        : model_(model), year_(year), registrationNumber_(registrationNumber), color_(color) {}

    void displayVehicle() {
        cout << "Model: " << model_ << endl;
        cout << "Year: " << year_ << endl;
        cout << "Registration Number: " << registrationNumber_ << endl;
        cout << "Color: " << color_ << endl;
    }
};

class Owner {
private:
    string name_;
    string phone_;
    string address_;
    shared_ptr<Vehicle> vehicle_;

public:
    Owner(string name, string phone, string address, shared_ptr<Vehicle> vehicle)
        : name_(name), phone_(phone), address_(address), vehicle_(vehicle) {}

    shared_ptr<Vehicle> getVehicle() {
        return vehicle_;
    }

    void displayOwner() {
        cout << "Name: " << name_ << endl;
        cout << "Phone: " << phone_ << endl;
        cout << "Address: " << address_ << endl;
    }
};

int main() {
    shared_ptr<Vehicle> vehicle = make_shared<Vehicle>("Porsche", 2024, "1234", "Race Green");

    unique_ptr<Owner> owner = make_unique<Owner>("Kaya", "CSUF CS 102B", "CSUF CS 102B", vehicle);

    owner->displayOwner();

    owner->getVehicle()->displayVehicle();

    return 0;
}