
#include <iostream>
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
#include "HouseMethod.h"

using std::cout;
using std::string;

int main()
{
    HouseMethod houseMethodCall;    //HouseMethod Object Created Name houseMethodCall

    InputCenter inputCall;          //InputCenter Object Created Name inputCall 

    TemperatureSensor tempCall;     //TemperatureSensor Object Created Name tempCall

    MotionSensor motionCall;        //MotionSensor Object Created Name motionCall

    WaterLevelSensor waterCall;     //WaterLevelSensor Object Created Name waterCall

    GasDetectionSensor gasCall;     //GasDetectionSensor Object Created Name gasCall

    Fan fanCall;                    //Fan Object Created Name fanCall

    Light lightCall;                //Light Object Created Name lightCall

    Door doorCall;                  //Door Object Created Name doorCall

    bool flag = false;

    while(!flag)
    {

        cout << "1.TemperatureSensor Remote\n2.MotionSensor Remote\n3.WaterLevelSensor Remote\n4.GasDetectionSensor Remote\n";

        cout << "5.Fan Remote\n6.Light Remote\n7.Door Remote\n8.Print Display Value All Sensors/Devices\n9.Exit\n";

        cout << "Enter Your Choice\n";

        int choice = inputCall.intInput();

        switch(choice)
        {
            case 1:
            {
                try
                {
                    houseMethodCall.temperatureSensorMethod(tempCall,fanCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                break;
            }

            case 2:
            {
                try
                {
                    houseMethodCall.motionSensorMethod(motionCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                break;
            }

            case 3:
            {
                try
                {
                    houseMethodCall.waterLevelSensorMethod(waterCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }    
                break;
            }

            case 4:
            {
                try 
                {
                    houseMethodCall.gasDetectionSensorMethod(gasCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                break;
            }

            case 5:
            {
                try
                {
                    houseMethodCall.fanMethod(fanCall);
                }
                catch(float value)
                {
                    if(value == 0)
                    {
                        cout << "Fan Already Decrease Value\n";
                    }

                    if(value == 5)
                    {
                        cout << "Fan Already Increase Value\n";
                    }
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                break;
            }

            case 6:
            {
                houseMethodCall.lightMethod(lightCall);
                break;
            }

            case 7:
            {
                houseMethodCall.doorMethod(doorCall);
                break;
            }

            case 8:
            {
                cout << "SENSORS/DEVICES          STATUS              VALUE\n";
                cout << "---------------          ------              ------\n";
                cout << "  Temperature             " << tempCall.getDeviceValue() <<  "              " << tempCall.getSensorValue() << "\n";
                cout << "  Motion            "       << motionCall.getMotion()<<      "         -    " << "\n";
                cout << "  WaterLevel              " << waterCall.getDeviceValue() << "              " << waterCall.getSensorValue() << "\n";
                cout << "  GasDetection            " << gasCall.getDeviceValue() <<   "                  " << gasCall.getSensorValue() << "\n";
                cout << "  Fan                     " << fanCall.getDeviceValue() <<   "              " << fanCall.getSensorValue() << "\n";
                cout << "  Light                   " << lightCall.getDeviceValue() << "            -  " << "\n";
                cout << "  Door                    " << doorCall.getDeviceValue() <<  "          -    " << "\n";
                break;
            }

            case 9:
            {
                flag = true;
                break;
            }

            default:
            {
                cout << "Enter The Valid Choice\n";
                break;
            }
        }
    }
}