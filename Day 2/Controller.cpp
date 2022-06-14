#include<string>
#include<iostream>

#include "Bank.h"
#include "Loan.h"
#include "HDFC.h"
#include "SBI.h"
#include "ICICI.h"
#include "IndianBank.h"
#include "InputCenter.h"
#include "Broker.h"


using namespace std;

class Controller
{
    InputCenter inputCall;

private:
    string bankType(int number)
    {
        string dummyString = "";
        switch (number)
        {
        case 1:
        {
            dummyString = "Public";
            break;
        }    
        case 2:
        {
            dummyString = "Private";
            break;
        }    
        
        default:
            throw("Please Enter Valid Number");
            break;
        }
        return dummyString;
    } 

    string loanType(int number)
    {
        string dummyString = "";
        switch (number)
        {
        case 1:
        {
            dummyString = "GoldLoan";
            break;
        }    
        case 2:
        {
            dummyString = "LandLoan";
            break;
        }    
        
        case 3:
        {
            dummyString = "PersonalLoan";
            break;
        }

        default:
            throw("Please Enter Valid Number");
            break;
        }
        return dummyString;
    }


    string documentType(int number)
    {
        string dummyString = "";
        switch (number)
        {
        case 1:
        {           
            dummyString = "Enter the GoldLoan Document Number :\n";
            break;
        }    
        case 2:
        {
            dummyString = "Enter the LandLoan Document Number :\n";
            break;
        }    
        
        case 3:
        {
            dummyString = "Enter the PersonalLoan Document Number :\n";
            break;
        }
        }
        return dummyString;
    }

    

    void BankDetails(Bank &bankCall)
    {
        cout << "Enter the BankName :\n";
        bankCall.setBankName(inputCall.stringInput());
        cout << "Enter the EstablisedDate :\n";
        bankCall.setEstablisedDate(inputCall.stringInput());
        cout << "Enter the BankType :\n";
        cout << "1.Public\n";
        cout << "2.Private\n";
        bankCall.setBankType(bankType(inputCall.intInput()));
        inputCall.stringInput();
        cout << "Enter the BranchName :\n";
        bankCall.setBranchName(inputCall.stringInput());
    }

    void LoanDetails(Loan &loanCall)
    {
        cout << "Enter the LoanType :\n";
        cout << "1.GoldLoan\n";
        cout << "2.LandLoan\n";
        cout << "3.PersonalLoan\n";
        int number = inputCall.intInput();
        loanCall.setLoanType(loanType(number));
        cout << "Enter the InterestRate :\n";
        loanCall.setInterestRate(inputCall.floatInput());
        inputCall.stringInput();
        cout << documentType(number);
        loanCall.setDocument(inputCall.stringInput());
    }

public:

    void hdfcDetails(HDFC &hdfcCall)
    {
        BankDetails(hdfcCall);
        LoanDetails(hdfcCall);
    }

    void sbiDetails(SBI &sbiCall)
    {
        BankDetails(sbiCall);
        LoanDetails(sbiCall);
    }

    void icicDetails(ICICI &icicCall)
    {
        BankDetails(icicCall);
        LoanDetails(icicCall);
    }

    void indianBankDetails(IndianBank &indianCall)
    {
        BankDetails(indianCall);
        LoanDetails(indianCall);
    }

};

int main()
{

    Controller conCall;

    HDFC hdfcCall;
    SBI sbiCall;
    ICICI iciciCall;
    IndianBank indianCall;

    conCall.hdfcDetails(hdfcCall);
    conCall.sbiDetails(sbiCall);
    conCall.icicDetails(iciciCall);
    conCall.indianBankDetails(indianCall);


    Broker brokerCall;

    HDFC * hdfcValues = &hdfcCall; 
    SBI *  sbiValues = &sbiCall;
    ICICI * iciciValues = &iciciCall;
    IndianBank * indianValues = &indianCall;

    float intersetRate = brokerCall.compareBankInterestRate(hdfcValues,sbiValues,iciciValues,indianValues);
    string bankName = brokerCall.findBank(intersetRate,hdfcCall,sbiCall,iciciCall,indianCall);
    cout << "Low Bank InterestRate is a : " + to_string(intersetRate) + "  Bank Name : " + bankName + "\n";
    
    intersetRate = brokerCall.compareLoanRate(hdfcValues,sbiValues);
    bankName = brokerCall.findBank(intersetRate,hdfcCall,sbiCall,iciciCall,indianCall);
    cout << "Two Bank Compare Low Bank InterestRate is a : " + to_string(intersetRate) + "  Bank Name : " + bankName + "\n";

    intersetRate = brokerCall.compareLoanRate(sbiValues,iciciValues,indianValues);
    bankName = brokerCall.findBank(intersetRate,hdfcCall,sbiCall,iciciCall,indianCall);
    cout << "Three Bank Compare Low Bank InterestRate is a : " + to_string(intersetRate) + "  Bank Name : " + bankName + "\n";


    Loan * loanArray[] = {&hdfcCall,&sbiCall,&iciciCall,&indianCall};
    
   // int arraySize = sizeof(loanArray) / sizeof(Loan);             //Find Array Size

    intersetRate = brokerCall.compareLoanRate(loanArray,4);         // using Array Size defalut Value static
    bankName = brokerCall.findBank(intersetRate,hdfcCall,sbiCall,iciciCall,indianCall);
    cout << "N Bank Compare Low Bank InterestRate is a : " + to_string(intersetRate) + "   Bank Name : " + bankName + "\n";

    cout <<  brokerCall.printBankDetails(hdfcCall) +"\n";
    cout <<  brokerCall.printBankDetails(sbiCall) + "\n";
    cout <<  brokerCall.printBankDetails(iciciCall) + "\n";
    cout <<  brokerCall.printBankDetails(indianCall) + "\n";

    Bank * loanArr[] = {&hdfcCall,&sbiCall,&iciciCall,&indianCall};

    //int size = sizeof(loanArr) / sizeof(Bank);

    brokerCall.printBankDetails(loanArr,4);
    return 0;
}