#include "Car.h"

Car::Car(string model, double rentalPricePerDay, CarType type)
    : model(model), rentalPricePerDay(rentalPricePerDay), available(true), type(type) {}


//gettter functions
string Car::getModel() const {
    return model;

}

double Car::getRentalPricePerDay() const{
    return rentalPricePerDay;
}

bool Car::isAvailable() const{
    return available;
}

CarType Car::getType() const{
    return type;
}

//Functions to convert enum to string
string getCartype(CarType type) {
    switch (type) {
        case SEDAN: return "Sedan0";
        case SUV: return "SUV";
        case TRUCK: return "Truck";
        default: return "Unknown";

    }
}
