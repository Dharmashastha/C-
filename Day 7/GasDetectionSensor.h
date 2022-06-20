#ifndef GASDETECTIONSENSOR_H_INCLUDED
#define GASDETECTIONSENSOR_H_INCLUDED

#include<string>
#include "DeviceController.h"
#include "SensorController.h"

class GasDetectionSensor : public DeviceController,public SensorController  // Derived class && Multiple Inheritance
{

public:

    void setGasDetectionSensor()
    {
        SensorController::setSensorValue(0.0f);
    }
    

};
#endif