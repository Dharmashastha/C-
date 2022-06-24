#ifndef CUSTOMERDETAILS_H_INCLUDED
#define CUSTOMERDETAILS_H_INCLUDED

#include<string>

using std::string;

class CustomerDetails               
{

private:                                //Attributes accountNumber,accountHolder,pinNumber,accountBalance

    int accountNumber;
    string accountHolder;
    int pinNumber;
    double accountBalance;

public:

    //Getter Setter Methods 

    void setAccountNumber(int accountNumber)
    {
        this -> accountNumber = accountNumber;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    void setAccountHolder(string accountHolder)
    {
        this -> accountHolder = accountHolder;
    }

    string getAccountHolder()
    {
        return accountHolder;
    }

    void setPinNumber(int pinNumber)
    {
        this -> pinNumber = pinNumber;
    }

    int getPinNumber()
    {
        return pinNumber;
    }

    void setAccountBalance(double accountBalance)
    {
        this -> accountBalance = accountBalance;
    }

    double getAccountBalance()
    {
        return accountBalance;
    }

    bool checkAccNumberPin(int &accountNumber,int &pinNumber)                       //Enter the Account Number and Pin Number Check Condition Method
    {
        return getAccountNumber() == accountNumber && getPinNumber() == pinNumber;
    }
};
#endif