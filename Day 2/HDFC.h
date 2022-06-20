#ifndef HDFC_H_INCLUDED
#define HDFC_H_INCLUDED

#include<string>
#include "Bank.h"
#include "Loan.h"

using namespace std;

// Derived class

class HDFC : public Bank,public Loan     //Multiple Inheritance
{
    //Bank & Loan class Overriding Method

public:

    HDFC()
    {}

    // HDFC():Bank(bankName,establisedDate,bankType,branchName),
    // Loan(loanType,interestRate,document)
    // {}

    string getBankName()
    {
       return Bank::bankName;   // Multiple Inheritance using Scope Resolution Bank Base Class
    }

    string getEstablisedDate()
    {
        return Bank::establisedDate;
    }

    BankType getBankType()
    {
        return Bank::bankType;
    }

    string getBranchName()
    {
        return Bank::branchName;
    }

    LoanType getLoanType()
    {
        return Loan::loanType;      // Multiple Inheritance using Scope Resolution Loan Base Class
    }

    float getInterestRate()
    {
        return Loan::interestRate; 
    }

    string getDoument()
    {
        return Loan::document;
    }

    //Print HDFC Bank Details

    string getInfo()
    {
         return "BankName : " + getBankName() + "\nEstablisedDate : " + getEstablisedDate() + "\nBankType : " + to_string(getBankType()) + "\nBranchName : " 
         + getBranchName() + "\nLoanType : " + to_string(getLoanType()) + "\nInterestRate : " + to_string(getInterestRate()) + "\nDoument : " + getDoument();
    }
};
#endif