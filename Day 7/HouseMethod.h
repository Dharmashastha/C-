#ifndef HOUSEMETHOD_H_INCLUDED
#define HOUSEMETHOD_H_INCLUDED

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
#include "House.h"

using std::cout;
using std::string;

class HouseMethod
{

    InputCenter inputCall;

    House houseCall;

public:

    void temperatureSensorMethod(TemperatureSensor &tempCall,Fan &fanCall)
    {

        bool flag = false;

        while(!flag)
        {
            cout << "1.TemperatureSensor Connect Device\n2.TemperatureSensor Disconnect Device\n3.TemperatureSensor ChangeTemperatureValue\n";

            cout << "4.Check TemperatureSensor\n5.TempertureSensor Value\n6.Exit\n";
            
            cout << "Enter Your Choice\n";
            
            int choice = inputCall.intInput();

            switch(choice)
            {
                case 1:
                {
                    houseCall.onConnect(tempCall);
                    break;
                }

                case 2:
                {
                    houseCall.disConnect(tempCall);
                    break;
                }

                case 3:
                {
                    cout << "Enter the New Temperture Value\n";

                    float tempValue = inputCall.floatInput();

                    houseCall.changeTemp(tempCall,tempValue);
                    break;
                }

                case 4:
                {
                    houseCall.checkTemp(tempCall,fanCall);
                    break;
                }

                case 5:
                {
                    cout << houseCall.displaySensorValue(tempCall) << "\n";
                    break;
                }

                case 6:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Input Value\n";
                    break;
                }
            }
        }    
    }


    void motionSensorMethod(MotionSensor &motionCall)
    {
        bool flag = false;

        while(!flag)
        {
            cout << "1.MotionSensor Connect Device\n2.MotionSensor Disconnect Device\n3.MotionSensor Checking\n";

            cout << "4.MotionSensor Off(Sound).\n5.Exit\n";
            
            cout << "Enter Your Choice\n";
            
            int choice = inputCall.intInput();

            switch(choice)
            {
                case 1:
                {
                    houseCall.onConnect(motionCall);
                    break;
                }

                case 2:
                {
                    houseCall.disConnect(motionCall);
                    break;
                }

                case 3:
                {
                    houseCall.checkMotion(motionCall,true);
                    break;
                }

                case 4:
                {
                    houseCall.motionOff(motionCall);
                    break;
                }

                case 5:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Input Value\n";
                    break;
                }
            }
        }
    }


    void waterLevelSensorMethod(WaterLevelSensor &waterCall)
    {
        bool flag = false;

        while(!flag)
        {
            cout << "1.WaterLevelSensor Connect Device\n2.WaterLevelSensor Disconnect Device\n3.WaterLevelSensor SetWaterLevelValue\n";

            cout << "4.Check WaterLevelSensor\n5.WaterLevelSensor Display Value\n6.Exit\n";
            
            cout << "Enter Your Choice\n";
            
            int choice = inputCall.intInput();

            switch(choice)
            {
                case 1:
                {
                    houseCall.onConnect(waterCall);
                    break;
                }

                case 2:
                {
                    houseCall.disConnect(waterCall);
                    break;
                }

                case 3:
                {
                    cout << "Enter Your setWaterLevel Value\n";

                    float setWater = inputCall.floatInput();

                    waterCall.setWaterLevel(setWater);
                    break;
                }

                case 4:
                {
                    cout << "Enter Your setWaterLevel Value\n";

                    float setWater = inputCall.floatInput();
                    
                    houseCall.checkWaterLevel(waterCall,setWater);
                    break;
                }

                case 5:
                {
                    cout << houseCall.displaySensorValue(waterCall) << "\n";
                    break;
                }

                case 6:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Input Value\n";
                    break;
                }
            }
        }
    }

    void gasDetectionSensorMethod(GasDetectionSensor &gasCall)
    {
        bool flag = false;

        while(!flag)
        {
            cout << "1.GasDetectionSensor Connect Device\n2.GasDetectionSensor Disconnect Device\n3.GasDetectionSensor DefaultSetValue\n";

            cout << "4.Check GasDetectionSensor\n5.GasDetectionSensor Display Value\n6.Exit\n";
            
            cout << "Enter Your Choice\n";
            
            int choice = inputCall.intInput();

            switch(choice)
            {
                case 1:
                {
                    houseCall.onConnect(gasCall);
                    break;
                }

                case 2:
                {
                    houseCall.disConnect(gasCall);
                    break;
                }

                case 3:
                {
                    gasCall.setGasDetectionSensor();
                    break;
                }

                case 4:
                {
                    cout << houseCall.checkGas(gasCall) << "\n";
                    break;
                }

                case 5:
                {
                    cout << houseCall.displaySensorValue(gasCall) << "\n";
                    break;
                }

                case 6:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Input Value\n";
                    break;
                }
            }
        }
    }

    void fanMethod(Fan &fanCall)
    {
        bool flag = false;

        while(!flag)
        {
            cout << "1.Fan Connect Device\n2.Fan Disconnect Device\n3.Fan Increase Value\n";

            cout << "4.Fan Decrease Value\n5.Fan Set Default Value\n6.Fan Display Value\n7.Exit\n";
            
            cout << "Enter Your Choice\n";
            
            int choice = inputCall.intInput();

            switch(choice)
            {
                case 1:
                {
                    houseCall.onConnect(fanCall);
                    break;
                }

                case 2:
                {
                    houseCall.disConnect(fanCall);
                    break;
                }

                case 3:
                {
                    houseCall.inceraseValue(fanCall);
                    break;
                }

                case 4:
                {
                    houseCall.decreaseValue(fanCall);
                    break;
                }

                case 5:
                {
                    houseCall.setDefaultFan(fanCall);
                    break;
                }

                case 6:
                {
                    cout << houseCall.displaySensorValue(fanCall) << "\n";
                    break;
                }

                case 7:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Input Value\n";
                    break;
                }
            }
        }
    }

    void lightMethod(Light &lightCall)
    {
        bool flag = false;

        while(!flag)
        {
            cout << "1.Light Connect Device\n2.Light Disconnect Device\n3.Light On\n";

            cout << "4.Light Off\n5.Exit\n";
            
            cout << "Enter Your Choice\n";
            
            int choice = inputCall.intInput();

            switch(choice)
            {
                case 1:
                {
                    houseCall.onConnect(lightCall);
                    break;
                }

                case 2:
                {
                    houseCall.disConnect(lightCall);
                    break;
                }

                case 3:
                {
                    houseCall.onLight(lightCall);
                    break;
                }

                case 4:
                {
                    houseCall.offLight(lightCall);
                    break;
                }

                case 5:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Input Value\n";
                    break;
                }
            }
        }
    }

    void doorMethod(Door &doorCall)
    {
        bool flag = false;

        while(!flag)
        {
            cout << "1.Door Connect Device\n2.Door Disconnect Device\n3.Door Open\n";

            cout << "4.Door Close\n5.Exit\n";
            
            cout << "Enter Your Choice\n";
            
            int choice = inputCall.intInput();

            switch(choice)
            {
                case 1:
                {
                    houseCall.onConnect(doorCall);
                    break;
                }

                case 2:
                {
                    houseCall.disConnect(doorCall);
                    break;
                }

                case 3:
                {
                    houseCall.openDoor(doorCall);
                    break;
                }

                case 4:
                {
                    houseCall.closeDoor(doorCall);
                    break;
                }

                case 5:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Input Value\n";
                    break;
                }
            }
        }
    }

};
#endif