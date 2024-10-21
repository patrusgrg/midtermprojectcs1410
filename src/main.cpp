#include <iostream>
#include <vector>
#include "Car.h"

using namespace std;

//Function to disolay all cars
void displayCars(const vector<Car>& cars) {
cout << " Available Cars:" << endl;
for (size_t i = 0; i < cars.size(); ++i) {
    cout << i + 1 << ". Model: " << cars[i].getModel()
             << ", Type: " << getCartype(cars[i].getType())
             << ", Price per day: $" << cars[i].getRentalPricePerDay()
             << ", Available: " << (cars[i].isAvailable() ? "Yes" : "No") << endl;
    }
}

//function to rent a car
void rentCar(vector<Car>& cars) {
    int choice;
    int days;
    displayCars(cars);
    cout << "Enter the number of the car you want to rent: ";
    cin >> choice;
    if (choice < 1 || choice > cars.size() || !cars[choice - 1].isAvailable()) {
        cout << "Invalid choice or car not available!" << endl;
    } else {
         cout << "Enter the number of days you want to rent the car: ";
        cin >> days;
        double totalCost = days * cars[choice - 1].getRentalPricePerDay();
        cars[choice - 1].setAvailable(false);
        cout << "You have rented the " << cars[choice - 1].getModel() << " for " << days
             << " days. Total cost: $" << totalCost << endl;
    }
}

//function for returnign a car
void returnCar(vector<Car>& cars) {
    int choice;
    cout << "Enter the number of the car you want to return: ";
    cin >> choice;
    if (choice < 1 || choice > cars.size() || cars[choice - 1].isAvailable()) {
        cout << "Invalid choice or car is not rented!" << endl;
    } else {
        cars[choice - 1].setAvailable(true);
        cout << "You have returned the " << cars[choice - 1].getModel() << "." << endl;
    }
}

int main() {
    // Create some cars
    vector<Car> cars = {
        Car("Toyota Camry", 50, SEDAN),
        Car("Honda CR-V", 60, SUV),
        Car("Ford F-150", 75, TRUCK)
    };

    int choice;
    do {
        cout << "\nCar Rental System\n";
        cout << "1. Display all cars\n";
        cout << "2. Rent a car\n";
        cout << "3. Return a car\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayCars(cars);
                break;
            case 2:
                rentCar(cars);
                break;
            case 3:
                returnCar(cars);
                break;
            case 4:
                cout << "Thank you for using the Car Rental System!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
