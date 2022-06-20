#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

#include<string>
#include "DeviceController.h"

class Door : public DeviceController  // Derived class
{

public:

    void openDoor()
    {
        DeviceController::onConnect();
    }
    
    void closeDoor()
    {
        DeviceController::onDisconnect();
    }

    std::string getDeviceValue()
    {
        if(DeviceController::getValue())
        {
            return "Door Open";
        }
        return "Door Closed";
    }

};
#endif