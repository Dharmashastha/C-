#ifndef LANDLINECONNECTION_H_INCLUDED
#define LANDLINECONNECTION_H_INCLUDED

#include<string>

using std::string;

class LandlineConnection
{

private:
    string landlineNumber;
    string stdCode;
    double billAmount;

public:

    void setLandlineNumber(string landlineNumber)
    {
        this -> landlineNumber = landlineNumber;
    }

    string getLandlineNumber()
    {
        return landlineNumber;
    }

    string getConnectionNumber()                //Update BillAmount Stored Vector Check Method  
    {
        return landlineNumber;    
    }

    void setSTDCode(string stdCode)
    {
        this -> stdCode = stdCode;
    }

    string getSTDCode()
    {
        return stdCode;
    }

    void setBillAmount(double billAmount)
    {
        this -> billAmount = billAmount;
    }

    double getBillAmount()
    {
        return billAmount;
    }

    bool matches(string connectionNumber)
    {
        return stdCode + landlineNumber == connectionNumber;
    }
};
#endif