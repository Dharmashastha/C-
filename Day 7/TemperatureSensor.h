#ifndef TEMPERATURESENSOR_H_INCLUDED
#define TEMPERATURESENSOR_H_INCLUDED

#include<string>
#include "DeviceController.h"
#include "SensorController.h"

class TemperatureSensor : public DeviceController,public SensorController  // Derived class && Multiple Inheritance
{

public:

    void onTemperatureChange(float newTemperature)
    {
        SensorController::setSensorValue(newTemperature);
    }

};
#endif