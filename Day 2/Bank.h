#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <string>

using namespace std;

//Base Class

class Bank      
{
protected:           //Attributes BankName,EstablisedDate,BankType,BranchName  

    string bankName;
    string establisedDate;
    string bankType;
    string branchName;

public:

    Bank()
    {}

    Bank(string bankName,string establisedDate,string bankType,string branchName)
    {}
    //setter method

    void setBankName(string bankName)  
    {
        this -> bankName = bankName;
    }

    void setEstablisedDate(string establisedDate)
    {
        this -> establisedDate = establisedDate;
    }

    void setBankType(string bankType)
    {
        this -> bankType = bankType;
    }

    void setBranchName(string branchName)
    {
        this -> branchName = branchName;
    }

    //Overriding method from Derived Class

    virtual string getBankName(){return "";};
    virtual string getEstablisedDate(){return "";};
    virtual string getBankType(){return "";};
    virtual string getBranchName(){return "";};
    virtual string getInfo(){return "";};           //Print of Bank Details

};
#endif
