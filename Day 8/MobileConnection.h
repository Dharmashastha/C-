#ifndef MOBILECONNECTION_H_INCLUDED
#define MOBILECONNECTION_H_INCLUDED

#include<string>

using std::string;

class MobileConnection
{

private:
    string mobileNumber;
    double billAmount;

public:
    void setMobileNumber(string mobileNumber)
    {
        this -> mobileNumber = mobileNumber;
    }

    string getMobileNumber()
    {
        return mobileNumber;
    }

    string getConnectionNumber()            //Update BillAmount Stored Vector Check Method
    {
        return mobileNumber;    
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
        return mobileNumber == connectionNumber;
    }
};
#endif