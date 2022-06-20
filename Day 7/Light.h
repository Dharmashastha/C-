#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

#include<string>
#include "DeviceController.h"

class Light : public DeviceController  // Derived class
{

public:
    void onLight()
    {
        DeviceController::onConnect();
    }
    
    void offLight()
    {
        DeviceController::onDisconnect();
    }

    std::string getDeviceValue()
    {
        if(DeviceController::getValue())
        {
            return "Light ON";
        }
        return "Light OFF";
    }

};
#endif