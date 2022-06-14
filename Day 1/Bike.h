#ifndef BIKE_H_INCLUDED
#define BIKE_H_INCLUDED

#include<string>
#include "Vehicle.h"

using namespace std;

class Bike : public Vehicle     //Bike class is a derive class from Vehicle
{
private:    
    double weight;              //Attributes VehicleType,Brand,Model,Color,Mileage,Price,Weight,BikeType
    string bikeType;
public:

    void setWeight(double weight)  //getter setter method
    {
        this -> weight = weight;
    }

    double getWeight()
    {
        return weight;
    }

    void setBikeType(string bikeType)  
    {
        this -> bikeType = bikeType;
    }

    string getBikeType()
    {
        return bikeType;
    }

    int getNoOfWheels()  //override abstract method from base class
    {
        return 2;
    }

    friend ostream &operator<<(ostream &output,Bike &bikeCall)
    {
        output << "VehicleType : " << bikeCall.getVehicleType() << "\nBrand : " << bikeCall.getBrand() << "\nModel : " 
        << bikeCall.getModel() << "\nColor : " << bikeCall.getColor() << "\nMileage : " << bikeCall.getMileage() << "\nPrice : " << bikeCall.getPrice();
        return output;
    }

    //operator overloading two vehicles compared based on price of the vehicle 

    bool operator<(Bike &bikeCall)
    {
        return this -> getPrice() < bikeCall.getPrice();
    }
};
#endif