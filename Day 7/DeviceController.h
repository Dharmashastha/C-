#ifndef DEVICECONTROLLER_H_INCLUDED
#define DEVICECONTROLLER_H_INCLUDED

#include<string>

class DeviceController          //Base Class
{

private:
    bool connection = false;

public:
    void onConnect()
    {
        connection = true;
    }

    void onDisconnect()
    {
        connection = false;
    }

    bool getValue()
    {
        return connection;
    }

    std::string getDeviceValue()
    {
        if(connection)
        {
            return "ON";
        }
        return "OFF";
    }

};
#endif