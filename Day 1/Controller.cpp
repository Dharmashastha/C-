#include<iostream>
#include<string>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "InputCenter.h"

using namespace std;


class Controller
{
InputCenter inputCall;
public:
void carDetails(Car &carCall)
{
    cout << "Enter the Car VehicleType :\n";
    carCall.setVehicleType(inputCall.stringInput());
    cout << "Enter the Car Brand :\n";
    carCall.setBrand(inputCall.stringInput());
    cout << "Enter the Car Model :\n";
    carCall.setModel(inputCall.stringInput());
    cout << "Enter the Car Color :\n";
    carCall.setColor(inputCall.stringInput());
    cout << "Enter the Car Mileage :\n";
    carCall.setMileage(inputCall.floatInput());
    cout << "Enter the Car Price :\n" ;
    carCall.setPrice(inputCall.doubleInput());
    cout << "Enter the Car NoOfPersons :\n";
    carCall.setNoOfPersons(inputCall.intInput());
    inputCall.stringInput();
    cout << "Enter the CarType :\n";
    carCall.setCarType(inputCall.stringInput());

}

void bikeDetails(Bike &bikeCall)
{
    cout << "Enter the Bike VehicleType :\n";
    bikeCall.setVehicleType(inputCall.stringInput());
    cout << "Enter the Bike Brand :\n";
    bikeCall.setBrand(inputCall.stringInput());
    cout << "Enter the Bike Model :\n";
    bikeCall.setModel(inputCall.stringInput());
    cout << "Enter the Bike Color :\n";
    bikeCall.setColor(inputCall.stringInput());
    cout << "Enter the Bike Mileage :\n";
    bikeCall.setMileage(inputCall.floatInput());
    cout << "Enter the Bike Price :\n";
    bikeCall.setPrice(inputCall.doubleInput());
    cout << "Enter the Bike Weight :\n";
    bikeCall.setWeight(inputCall.doubleInput());
    cout << "Enter the BikeType :\n";
    inputCall.stringInput();
    bikeCall.setBikeType(inputCall.stringInput());
}
};

int main()
{
    Controller conCall;
    Car carCall;
    conCall.carDetails(carCall);
    Car carCall1;
    conCall.carDetails(carCall1);
    Bike bikeCall;
    conCall.bikeDetails(bikeCall);

    cout << carCall;
    cout << "\n";
    cout << bikeCall;
    cout << "\n";


    cout << carCall.getNoOfWheels();
    cout << "\n";
    cout << bikeCall.getNoOfWheels();
    cout << "\n";

    if(carCall < carCall1)
    {
        cout << carCall1.getBrand() +" "+ carCall1.getModel() + " " +"price high";
    }
    else
    {
        cout << carCall.getBrand() +" "+ carCall.getModel() + " " +"price high";
    }
   return 0; 
}
