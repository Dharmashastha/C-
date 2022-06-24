
#include<string>
#include<iostream>
#include<map>
#include<stdexcept>
#include "LoadCashToATM.h"
#include "CustomerDetails.h"
#include "ATMProcess.h"
#include "InputCenter.h"

using std::string;
using std::cout;
using std::map;
using std::rand;
using std::to_string;

class Controller
{

private:

    InputCenter inputCall;

    int accountNumber = 1000;

    Denomination selectDenomination(int number)
    {
        Denomination denominationType;

        switch(number)
        {
            case 1:
            {
                denominationType = TWOTHOUSAND;
                break;
            }

            case 2:
            {
                denominationType = FIVEHUNDRED;
                break;
            }

            case 3:
            {
                denominationType = HUNDRED;
                break;
            }

            default:
            {
                throw("Please Enter Valid Number\n");
                break;
            }    
        }
        return denominationType;
    }

    int accNumberGenerate()
    {
        return ++accountNumber;
    }

    int pinGenerate()
    {
        return rand() % 9000 + 1000;
    }


    void checkATMBalanceMethod(ATMProcess &processCall)
    {
        map<Denomination,LoadCashToATM> storeATM = processCall.getStoreATM();

        map<Denomination,LoadCashToATM>::iterator iter;

        double totalAmount = 0;

        cout << " Denomination                  CashCount                TotalValue\n";

        cout << " ------------                  ---------                ----------\n";

        for(iter = storeATM.begin(); iter != storeATM.end(); iter++)
        {
            LoadCashToATM atmCall = iter -> second;

            double saved = atmCall.getTotalValue();

            totalAmount += saved;    

            cout << atmCall.getDenominationType() << "                       " << atmCall.getCashCount() << "                " << saved << "\n";
        }

        cout << "Total Amount available in the ATM = " << totalAmount << "\n";
    }

    void transferMoneyMethod(int &accountNumber,ATMProcess &processCall)
    {
        cout << "Enter the Transfer Account Number\n";


        int transferAccountNumber = inputCall.intInput();

        cout << "Enter the Transfer Amount\n";

        double amount = inputCall.doubleInput();

        checkTransferAmount(amount);

        processCall.transferMoney(accountNumber,transferAccountNumber,amount);        
    }

    void withdrawMethod(int &accountNumber,ATMProcess &processCall,bool &withdrawCheck,bool &firstCheck)
    {
        if(withdrawCheck)
        {
            cout << "Enter Your Pin Number\n";

            int pinNumber = inputCall.intInput();

            firstCheck = processCall.checkerCustomer(accountNumber,pinNumber);
        }    

        if(firstCheck)
        {
            cout << "Enter Your Withdraw Amount\n";

            double withdrawAmount = inputCall.doubleInput();

            checkWithdrawAmount(withdrawAmount);

            withdrawRoundOfCheck(withdrawAmount);

            processCall.withdrawMoney(accountNumber,withdrawAmount);

            firstCheck = false;

            withdrawCheck = true;
        }
        else
        {
            cout << "Your Pin Number Invalid\n";
        }
    }

    void checkTransferAmount(double &transferAmount)
    {
        if(1000 > transferAmount || transferAmount > 10000)
        {
            throw "Max Transfer Limit Per Transaction Amount 1000 to 10000\n";
        }
    }

    void checkWithdrawAmount(double &withdrawAmount)
    {
        if(100 > withdrawAmount || withdrawAmount > 10000)
        {
            throw "Max Withdrawal Limit for a Single Transaction is 10,000 and Minimum is 100\n";
        }
    }

    void withdrawRoundOfCheck(double withdrawAmonut)
    {
        string saved = to_string((int)withdrawAmonut);

        int size = saved.size();

        if(saved[size - 1] != '0' && saved[size - 2] != '0')
        {
            throw "Please Enter the Round Of WithdrawAmonut(last two digit zero Value)\n";
        }    
    }

public:

    void loadCashToATMDetails(LoadCashToATM &loadCall)
    {
        cout << "Enter the DenominationType\n";
        
        cout << "1.TWOTHOUSAND\n2.FIVEHUNDRED\n3.HUNDRED\n";

        Denomination denominationType = selectDenomination(inputCall.intInput());

        loadCall.setDenominationType(denominationType);

        cout << "Enter the CashCount\n";

        int cashCount = inputCall.intInput();

        loadCall.setCashCount(cashCount);

        loadCall.setTotalValue(denominationType * cashCount);
    }

    void CustomerDetails(CustomerDetails &customerCall)
    {

        customerCall.setAccountNumber(accNumberGenerate());

        cout << "Enter the Account Holder\n";

        inputCall.stringInput();

        string accountHolder = inputCall.stringInput();

        customerCall.setAccountHolder(accountHolder);

        customerCall.setPinNumber(pinGenerate());

        cout << "Enter the Account Amount\n";

        double balance = inputCall.doubleInput();

        customerCall.setAccountBalance(balance);
    }

    void customerOptions(int &accountNumber,ATMProcess &processCall)
    {
        bool flag = false;

        bool withdrawCheck = false;

        bool firstCheck = true;

        while(!flag)
        {
            cout << "1.Check Balance\n2.Withdraw Money\n3.Transfer Money\n4.Check ATM Balance\n5.Exit\n";

            cout << "Enter Your Choice\n";

            int choice = inputCall.intInput();

            inputCall.stringInput();

            switch(choice)
            {
                case 1:
                {
                    cout << "Your Account Balance : " << processCall.checkBalance(accountNumber) << "\n";
                    break;
                }

                case 2:
                {
                    withdrawMethod(accountNumber,processCall,withdrawCheck,firstCheck);

                    cout << "Withdraw Amount Successful!\n";

                    cout << "Your Amount Balance : " << processCall.checkBalance(accountNumber) << "\n"; 
                    break;
                }

                case 3:
                {
                    transferMoneyMethod(accountNumber,processCall);
                    break;
                }

                case 4:
                {
                    checkATMBalanceMethod(processCall);
                    break; 
                }

                case 5:
                {
                    flag = true;
                    break;
                }

                default:
                {
                    cout << "Enter the Valid Choice\n";
                    break;
                }
            }
        }
    }

    void processATM(ATMProcess &processCall)
    {
        cout << "Enter The Your Account Number\n";

        int accNumber = inputCall.intInput();

        cout << "Enter The Your Pin Number\n";

        int pinNumber = inputCall.intInput();

        if(processCall.checkerCustomer(accNumber,pinNumber))
        {
            cout << "Welcome ATM Process\n";

            customerOptions(accNumber,processCall);
        }
        else
        {
            cout << "Check Your AccountNumber & Pin Number\n";
        }
    }

};

int main()
{
    Controller conCall;                         //Controller Object Created Name conCall

    InputCenter inputCall;                      //InputCenter Object Created Name inputCall

    ATMProcess processCall;

    bool flag = false;

    while(!flag)
    {
        cout << "1.Load Cash to ATM\n2.Add New Customer\n3.ATM Operations\n4.Exit\n";

        cout << "Enter Your Choice\n";

        int choice = inputCall.intInput();

        switch(choice)
        {
            case 1:
            {
                try
                {
                    LoadCashToATM atmCall;
                
                    conCall.loadCashToATMDetails(atmCall);
                
                    processCall.storeATMValues(atmCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                catch(std::exception &e)
                {
                    std::cerr << "Error Occurred " << e.what() << "\n";
                }
                break;
            }

            case 2:
            {
                try
                {
                    CustomerDetails customerCall;

                    conCall.CustomerDetails(customerCall);
                
                    string name = customerCall.getAccountHolder();

                    cout << name + "  Account Number is " << customerCall.getAccountNumber() << "\n";

                    cout << name + "  Pin Number is " << customerCall.getPinNumber() << "\n";
                
                    processCall.storeCustomerDetails(customerCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                catch(std::exception &e)
                {
                    std::cerr << "Error Occurred " << e.what() << "\n";
                }
                break;
            }

            case 3:
            {
                try
                {
                    conCall.processATM(processCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                catch(std::exception &e)
                {
                    std::cerr << "Error Occurred " << e.what() << "\n";
                }    
                break;
            }

            case 4:
            {
                flag = true;
                break;
            }

            default:
            {
                cout << "Enter the Valid Choice\n";
                break;
            }

        }
    }


}