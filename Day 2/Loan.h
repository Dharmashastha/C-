#ifndef LOAN_H_INCLUDED
#define LOAN_H_INCLUDED

#include<string>

using namespace std;

//Base Class

class Loan
{
protected:           //Attributes LoanType,InterestRate,Document

    string loanType;
    float interestRate;
    string document;

public:

    Loan()
    {}

    Loan(string loanType,float interestRate,string document)
    {}

    //setter method

    void setLoanType(string loanType)
    {
        this -> loanType = loanType;
    }

    void setInterestRate(float interestRate)
    {
        this -> interestRate = interestRate;
    }

    void setDocument(string document)
    {
        this ->  document = document;
    }

    //Overriding method from Derived Class

    virtual string getLoanType(){return "";};
    virtual float getInterestRate(){return 0;};
    virtual string getDoument(){return "";};
};
#endif