#ifndef WATERLEVELSENSOR_H_INCLUDED
#define WATERLEVELSENSOR_H_INCLUDED

#include<string>
#include "DeviceController.h"
#include "SensorController.h"

class WaterLevelSensor : public DeviceController,public SensorController  // Derived class && Multiple Inheritance
{

public:

    void setWaterLevel(float waterLevel)
    {
        SensorController::setSensorValue(waterLevel);
    }

};
#endif