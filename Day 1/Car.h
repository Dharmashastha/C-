#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include<string>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle  //Car class is a derive class from Vehicle
{
private:
    int noOfPersons;   //Attributes vehicleType,brand,model,color,mileage,price,noOfPersons,carType
    string carType;

public:

    void setNoOfPersons(int noOfPersons)  //getter setter method
    {
        this -> noOfPersons = noOfPersons;
    }

    int getNoOfPersons()
    {
        return noOfPersons;
    }

    void setCarType(string carType)  
    {
        this -> carType = carType;
    }

    string getCarType()
    {
        return carType;
    }

    int getNoOfWheels()  //override abstract method from base class
    {
        return 4;
    }

    //operator overloading(<<) display car attributes 

    friend ostream &operator<<(ostream &output,Car &carCall)
    {
        output << "VehicleType : " << carCall.getVehicleType() << "\nBrand : " << carCall.getBrand() << "\n Model : " 
        << carCall.getModel() << "\nColor : " << carCall.getColor() << "\nMileage : " << carCall.getMileage() << "\nPrice : " << carCall.getPrice();
        return output;
    }

    //operator overloading two vehicles compared based on price of the vehicle 

    bool operator<(Car &carCall)
    {
        return this -> getPrice() < carCall.getPrice();
    }
};
#endif