#ifndef MOTIONSENSOR_H_INCLUDED
#define MOTIONSENSOR_H_INCLUDED

#include<string>
#include "DeviceController.h"
#include "SensorController.h"

class MotionSensor : public DeviceController,public SensorController  // Derived class && Multiple Inheritance
{
private:
    bool motionValue = false;

public:
    
    void checkMotionSensor(bool motionValue)
    {
        this -> motionValue = motionValue;
    }

    bool getMotionValue()
    {
        return motionValue;
    }

    std::string getMotion()
    {
        if(motionValue)
        {
            return "Person Entered.";
        }
        return "No Person Crossed.";
    }

};
#endif