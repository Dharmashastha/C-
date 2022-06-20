#ifndef SENSORCONTROLLER_H_INCLUDED
#define SENSORCONTROLLER_H_INCLUDED

#include<string>

class SensorController      //Base Class
{

private:
    float sensorValue;

public:
    void increaseValue()
    {
        if(sensorValue >= 5)
        {
            throw sensorValue;    
        }
        sensorValue += 1;
    }

    void decreaseValue()
    {
        if(sensorValue <= 0)
        {
            throw sensorValue;
        }
        sensorValue -= 1;
    }

    float getSensorValue()
    {
        return sensorValue;
    }
    
protected:

    void setSensorValue(float sensorValue)
    {
        this -> sensorValue = sensorValue;
    }    
};
#endif