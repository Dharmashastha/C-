#ifndef LOADCASHTOATM_H_INCLUDED
#define LOADCASHTOATM_H_INCLUDED

//Enum Method const Value Denomination 2000,500,100

enum Denomination                                     
{
    TWOTHOUSAND = 2000,FIVEHUNDRED = 500,HUNDRED = 100
};

class LoadCashToATM                         
{
private:                                //Attributes denominationType,cashCount,totalValue

    Denomination denominationType;
    int cashCount;
    int totalValue;

public:

    //Getter Setter Methods

    void setDenominationType(Denomination denominationType)
    {
        this -> denominationType = denominationType;
    }

    Denomination getDenominationType()
    {
        return denominationType;
    }

    void setCashCount(int cashCount)
    {
        this -> cashCount = cashCount;
    }

    int getCashCount()
    {
        return cashCount;
    }

    void setTotalValue(int totalValue)
    {
        this -> totalValue = totalValue;
    }

    int getTotalValue()
    {
        return totalValue;
    }

};
#endif