#ifndef BROKER_H_INCLUDED
#define BROKER_H_INCLUDED

#include<string>
#include<iostream>
#include "Bank.h"
#include "Loan.h"
#include "HDFC.h"
#include "SBI.h"
#include "ICICI.h"
#include "IndianBank.h"

using namespace std;

class Broker
{
public:

    //Low InterestRate Bank Name Find Method

    string findBank(float interestRate,HDFC &hdfcCall,SBI &sbiCall,ICICI &icicCall,IndianBank &indianCall)
    {
        if(interestRate == hdfcCall.getInterestRate())
        {
            return hdfcCall.getBankName();
        }
        else if(interestRate == sbiCall.getInterestRate())
        {
            return sbiCall.getBankName();
        }
        else if(interestRate == icicCall.getInterestRate())
        {
            return icicCall.getBankName();
        }
        return indianCall.getBankName();
        
    }


    //Low InterestRate Find Method

    float compareBankInterestRate(HDFC *hdfcCall,SBI *sbiCall,ICICI *iciciCall,IndianBank *indianCall)
    {
        Loan *dummyCall = hdfcCall;
        if(sbiCall -> getInterestRate() < dummyCall -> getInterestRate())
        {
            dummyCall = sbiCall;
        }
        if(iciciCall -> getInterestRate() < dummyCall -> getInterestRate())
        {
            dummyCall = iciciCall;
        }
        if (indianCall -> getInterestRate() < dummyCall -> getInterestRate())
        {
            dummyCall = indianCall;
        }
        
        return dummyCall -> getInterestRate();    
    }

    //Compare Two banks loan rates Find Method

    float compareLoanRate(Loan *loanCall1,Loan *loanCall2)
    {
        if (loanCall1 -> getInterestRate() < loanCall2 -> getInterestRate())
        {
            return loanCall1 -> getInterestRate();
        }
        return loanCall2 -> getInterestRate();
    }

    //Compare Three banks loan rates Find Method && overloading Method

    float compareLoanRate(Loan *loanCall1,Loan *loanCall2,Loan *loanCall3)
    {
        Loan * dummyCall = loanCall1;
        if (loanCall2 -> getInterestRate() < dummyCall -> getInterestRate())
        {
            dummyCall = loanCall2;
        }
        if (loanCall3 -> getInterestRate() < dummyCall -> getInterestRate())
        {
            dummyCall = loanCall3;
        }
        return dummyCall -> getInterestRate();
    }

    //Compare “n” banks loan rates Find Method && overloading Method

    float compareLoanRate(Loan *loanArray[],int size)             //Size parameter Array Size
    {
        Loan * dummyCall = loanArray[0];
        for(int iter = 1; iter < size; iter++)
        {
            if (loanArray[iter] -> getInterestRate() < dummyCall -> getInterestRate())
            {
                dummyCall = loanArray[iter];
            }
        }
        return dummyCall -> getInterestRate();  
    }

    //Print the Details of single bank

    string printBankDetails(Bank &bankCall)
    {
        return bankCall.getInfo();
    }

    //Print the details of the multiple banks  && overloading Method

    void printBankDetails(Bank *bankArray[],int size)
    {
        for(int iter = 0; iter < size; iter++)
        {
            cout << bankArray[iter] -> getInfo() + "\n";
        }
    }
};
#endif