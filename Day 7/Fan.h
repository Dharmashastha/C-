#ifndef FAN_H_INCLUDED
#define FAN_H_INCLUDED

#include<string>
#include "DeviceController.h"
#include "SensorController.h"

class Fan : public DeviceController,public SensorController  // Derived class && Multiple Inheritance
{

public:
    void onFan()
    {
        DeviceController::onConnect();
    }
    
    void offFan()
    {
        DeviceController::onDisconnect();
    }

    void setDefaultValue()
    {
        SensorController::setSensorValue(0.0f);
    }

    std::string getDeviceValue()
    {
        if(DeviceController::getValue())
        {
            return "Fan ON";
        }
        return "Fan OFF";
    }

};
#endif