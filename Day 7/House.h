#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

#include <iostream>
#include <functional>
#include "DeviceController.h"
#include "SensorController.h"
#include "TemperatureSensor.h"
#include "MotionSensor.h"
#include "WaterLevelSensor.h"
#include "GasDetectionSensor.h"
#include "Fan.h"
#include "Light.h"
#include "Door.h"
#include "InputCenter.h"


using std::function;
using std::cout;
using std::string;

class House
{

public:

    function<void(SensorController &senCall)> inceraseValue = [=](SensorController &senCall){
        senCall.increaseValue();
    };

    function<void(SensorController &senCall)> decreaseValue = [=](SensorController &senCall){
        senCall.decreaseValue();
    };

    function<float(SensorController &senCall)> displaySensorValue = [=](SensorController &senCall){
        return senCall.getSensorValue();
    };

    function<void(DeviceController &deviceCall)> onConnect = [=] (DeviceController &deviceCall){
        deviceCall.onConnect();
    };
    
    function<void(DeviceController &deviceCall)> disConnect = [=] (DeviceController &deviceCall){
        deviceCall.onDisconnect();
    };

    function<void(TemperatureSensor &tempCall,float newValue)> changeTemp = [=] (TemperatureSensor &tempCall,float newValue){
        if(!tempCall.getValue())
        {
            throw "TemperatureSensor OFF";
        }
        tempCall.onTemperatureChange(newValue);
    };

    function<void(TemperatureSensor &tempCall,Fan &fanCall)> checkTemp = [=] (TemperatureSensor &tempCall,Fan &fanCall){
        if(!tempCall.getValue())
        {
            throw "TemperatureSensor OFF";
        }
        if(tempCall.getSensorValue() > 22.0)
        {
            fanCall.onFan();
        }
    };

    function<void(MotionSensor &motionCall,bool checking)> checkMotion = [=] (MotionSensor &motionCall,bool checking){
        if(!motionCall.getValue())
        {
            throw "MotionSensor OFF";
        }
        motionCall.checkMotionSensor(checking);
        int count = 0;
        while(motionCall.getMotionValue())
        {
            if(count < 5)
            {
                cout << "Ringtone Sound On\n";
                count++;
            }
            else
            {
                break;
            }    
        }
    };

    function<void(MotionSensor &motionCall)> motionOff = [=] (MotionSensor &motionCall){
        if(!motionCall.getValue())
        {
            throw "MotionSensor OFF";
        }
        motionCall.checkMotionSensor(false);
    };

    function<void(WaterLevelSensor &waterCall,float waterLevel)> checkWaterLevel = [=] (WaterLevelSensor &waterCall,float waterLevel){
        if(!waterCall.getValue())
        {
            throw "WaterLevelSensor OFF";
        }
        if(waterCall.getSensorValue() <= 10.0)
        {
            waterCall.onConnect();
            waterCall.setWaterLevel(waterLevel);
        }
    };

    function<string(GasDetectionSensor &gasCall)> checkGas = [=] (GasDetectionSensor &gasCall){
        if(!gasCall.getValue())
        {
            throw "GasDetectionSensor OFF";
        }
        string saved = "";
        if(gasCall.getSensorValue() > 0.0030)
        {
            saved = "Ringtone Sound On";
        }
        return saved;
    };

    function<void(Fan &fanCall)> setDefaultFan = [=] (Fan &fanCall){
        fanCall.setDefaultValue();
    };

    function<void(Fan &fanCall)> onFan = [=] (Fan &fanCall){
        fanCall.onFan();
    };

    function<void(Fan &fanCall)> offFan = [=] (Fan &fanCall){
        fanCall.offFan();
    };

    function<void(Light &lightCall)> onLight = [=] (Light &lightCall){
        lightCall.onLight();
    };

    function<void(Light &lightCall)> offLight = [=] (Light &lightCall){
        lightCall.offLight();
    };

    function<void(Door &doorCall)> openDoor = [=] (Door &doorCall){
        doorCall.openDoor();
    };

    function<void(Door &doorCall)> closeDoor = [=] (Door &doorCall){
        doorCall.closeDoor();
    };

};
#endif
