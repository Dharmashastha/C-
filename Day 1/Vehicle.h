#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include<string>
#include<ostream>

using namespace std;

class Vehicle
{
private:                    
    string vehicleType;     //Attributes vehicleType,brand,model,color,mileage,price
    string brand;
    string model;
    string color;
    float mileage;
    double price;

 public:
    virtual int getNoOfWheels() = 0;  //Abstract method 

    void setVehicleType(string vehicleType)  //getter setter method
    {
        this -> vehicleType = vehicleType;
    }

    string getVehicleType()
    {
        return vehicleType;
    }

    void setBrand(string brand)
    {
        this -> brand = brand;
    }

    string getBrand()
    {
        return brand;
    }

    void setModel(string model)
    {
        this -> model = model;
    }

    string getModel()
    {
        return model;
    }

    void setColor(string color)
    {
        this -> color = color;
    }

    string getColor()
    {
        return color;
    }
    
    void setMileage(float mileage)
    {
        this -> mileage = mileage;
    }

    float getMileage()
    {
        return mileage;
    }

    void setPrice(double price)
    {
        this -> price = price;
    }

    double getPrice()
    {
        return price;
    }
};
#endif