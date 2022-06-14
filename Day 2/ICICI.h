#ifndef ICICI_H_INCLUDED
#define ICICI_H_INCLUDED

#include<string>
#include "Bank.h"
#include "Loan.h"

using namespace std;

// Derived class

class ICICI : public Bank,public Loan           //Multiple Inheritance
{
    //Bank & Loan class Overriding Method
public:


    ICICI()
    {}

    // ICICI():Bank(bankName,establisedDate,bankType,branchName),
    // Loan(loanType,interestRate,document)
    // {}

   string getBankName()
    {
       return Bank::bankName;               // Multiple Inheritance using Scope Resolution  Bank Base Class
    }

    string getEstablisedDate()
    {
        return Bank::establisedDate;
    }

    string getBankType()
    {
        return Bank::bankType;
    }

    string getBranchName()
    {
        return Bank::branchName;
    }

    string getLoanType()
    {
        return Loan::loanType;              // Multiple Inheritance using Scope Resolution  Loan Base Class
    }

    float getInterestRate()
    {
        return Loan::interestRate; 
    }

    string getDoument()
    {
        return Loan::document;
    }

    //Print ICIC Bank Details

    string getInfo()
    {
         return "BankName : " + getBankName() + "\nEstablisedDate : " + getEstablisedDate() + "\nBankType : " + getBankType() + "\nBranchName : " 
         + getBranchName() + "\nLoanType : " + getLoanType() + "\nInterestRate : " + to_string(getInterestRate()) + "\nDoument : " + getDoument();
    }

};
#endif