#define CAR_H 


#include <string>
using namespace std;

// Enum for car types
enum CarType{
    SEDAN,
    SUV, 
    TRUCK
};

// Function to convert enum to string 
string getCartype(CarType tyoe);

//Car class definition
class Car{
public:
     //Constructor 
     Car(string model, double rentalPricePerDay, CarType);

     //getter functions
     string getModel() const;
     double getRentalPricePerDay() const;
     bool isAvailable() const;
     CarType getType() const;

     //Sttter functions 
     void setAvailable(bool availability);

private:
    string model;
    double rentalPricePerDay;
    bool available;
    CarType type;

};
string getCartype(CarType type);

