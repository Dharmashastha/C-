#ifndef ATMPROCESS_H_INCLUDED
#define ATMPROCESS_H_INCLUDED

#include<string>
#include<map>
#include<vector>
#include "LoadCashToATM.h"
#include "CustomerDetails.h"

using std::string;
using std::map;
using std::pair;
using std::vector;

class ATMProcess
{

private:

    map<Denomination,LoadCashToATM> storeATM;                           //Stored Data of LoadCashToATM class data Key DenominationType,value class object

    map<int,CustomerDetails> storeCustomer;                             //Stored Data of CustomerDetails class data Key AccountNumber,value class object

    CustomerDetails getCustomer(int &accountNumber)                     //Method use return type CustomerDetails Object
    {
        auto iter = storeCustomer.find(accountNumber);

        if(storeCustomer.count(accountNumber) == 0)                     //Check Account number stored in Map 
        {
            throw "Your Account Number Invalid";
        }
        
    return iter -> second;
    }

    LoadCashToATM getDenomination(const Denomination &denominationType)     //Method use return type LoadCashToATM Object
    {
        auto iter = storeATM.find(denominationType);
    return iter -> second;
    }

    void overrideATMValues(LoadCashToATM &loadCall)
    {
        auto iter = storeATM.find(loadCall.getDenominationType());

        if(iter != storeATM.end())
        {
            iter -> second = loadCall;
        }
    }

    void overrideCustomerDetails(CustomerDetails &customerCall)
    {
        auto iter = storeCustomer.find(customerCall.getAccountNumber());

        if(iter != storeCustomer.end())
        {
            iter -> second = customerCall;
        }
    }

    void controlDenomination(LoadCashToATM &loadCall,double &checkAmount,double &savedAmount,int numberOfCashCount)
    {
        checkAmount += numberOfCashCount * loadCall.getDenominationType();

        savedAmount -= numberOfCashCount * loadCall.getDenominationType();    
    }

    void denominationTwoThousand(LoadCashToATM &twoThousandCall,double &checkAmount,double &savedAmount,vector<int> &count)
    {
        if(savedAmount > 4000)
        {
            controlDenomination(twoThousandCall,checkAmount,savedAmount,2);
            count.push_back(2);
        }
        else
        {
            controlDenomination(twoThousandCall,checkAmount,savedAmount,1);
            count.push_back(1);
        }  
    }

    void denominationFiveHundred(LoadCashToATM &fiveHundredCall,double &checkAmount,double &savedAmount,vector<int> &count)
    {
        if(savedAmount > 2500)
        {
            controlDenomination(fiveHundredCall,checkAmount,savedAmount,2);
            count.push_back(2);
        }
        else
        {
            controlDenomination(fiveHundredCall,checkAmount,savedAmount,1);
            count.push_back(1);
        }
    }

    void denominationHundred(LoadCashToATM &hundredCall,double &checkAmount,double &savedAmount,vector<int> &count)
    {
        controlDenomination(hundredCall,checkAmount,savedAmount,15);
        count.push_back(15);
    }

    void denominationTwoThousand(LoadCashToATM &twoThousandCall,double &checkAmount,double &savedAmount,vector<int> &count,int value)
    {
        if(savedAmount > 9000)
        {
            controlDenomination(twoThousandCall,checkAmount,savedAmount,4);
            count.push_back(4);
        }
        else
        {
            controlDenomination(twoThousandCall,checkAmount,savedAmount,2);
            count.push_back(2);
        }
    }

    void denominationFiveHundred(LoadCashToATM &fiveHundredCall,double &checkAmount,double &savedAmount,vector<int> &count,int value)
    {
        if(savedAmount > 6000)
        {
            controlDenomination(fiveHundredCall,checkAmount,savedAmount,6);
            count.push_back(6);    
        }
        else
        {
            controlDenomination(fiveHundredCall,checkAmount,savedAmount,4);
            count.push_back(4);
        }
    }

    void denominationHundred(LoadCashToATM &hundredCall,double &checkAmount,double &savedAmount,vector<int> &count,int value)
    {
        controlDenomination(hundredCall,checkAmount,savedAmount,10);
        count.push_back(10);
    }

    void setTotalValue(LoadCashToATM &loadCall,vector<int> &count,int &iter)
    {
        int numberOfCashCount = count[iter++];

        if(loadCall.getCashCount() >= numberOfCashCount)
        {
            loadCall.setCashCount(loadCall.getCashCount() - numberOfCashCount);

            loadCall.setTotalValue(loadCall.getDenominationType() * loadCall.getCashCount());
        }
        else
        {
            throw "Insufficient Balance ATM\n";
        }
    }

    void setCheckDenomination(LoadCashToATM &twoThousandCall,LoadCashToATM &fiveHundredCall,LoadCashToATM &hundredCall,vector<int> &count)
    {
        int size = count.size();
        int iter = 0;
        if(size == 3)
        {
            setTotalValue(twoThousandCall,count,iter);
        }

        if(size >= 2)
        {
            setTotalValue(fiveHundredCall,count,iter);
        }

        if(size >= 1)
        {
            setTotalValue(hundredCall,count,iter);
        }
    }

    void checkDenomination(double &withdrawAmount)
    {
        LoadCashToATM twoThousandCall = getDenomination(TWOTHOUSAND);

        LoadCashToATM fiveHundredCall = getDenomination(FIVEHUNDRED);

        LoadCashToATM hundredCall = getDenomination(HUNDRED);

        double checkAmount = 0;

        double savedAmount = withdrawAmount;

        int count = 0;

        bool checking = false;

        vector<int> checkCashCount;

        if(withdrawAmount > 3000)
        {
            denominationTwoThousand(twoThousandCall,checkAmount,savedAmount,checkCashCount);        
        }

        if(savedAmount > 1000)
        {
            denominationFiveHundred(fiveHundredCall,checkAmount,savedAmount,checkCashCount);
        }

        if(savedAmount > 1500)
        {
            denominationHundred(hundredCall,checkAmount,savedAmount,checkCashCount);
             checking = true;   
        }

        while(checkAmount != withdrawAmount)
        {
            controlDenomination(hundredCall,checkAmount,savedAmount,1);
            count++;
        }

        if(checking)
        {
            count += checkCashCount[checkCashCount.size() - 1];

            checkCashCount[checkCashCount.size() - 1] = count;
        }
        else
        {
            checkCashCount.push_back(count);
        }

        

        setCheckDenomination(twoThousandCall,fiveHundredCall,hundredCall,checkCashCount);

        overrideATMValues(twoThousandCall);

        overrideATMValues(fiveHundredCall);

        overrideATMValues(hundredCall);

    }


    void checkDenomination(double &withdrawAmount,int value)
    {
        LoadCashToATM twoThousandCall = getDenomination(TWOTHOUSAND);

        LoadCashToATM fiveHundredCall = getDenomination(FIVEHUNDRED);

        LoadCashToATM hundredCall = getDenomination(HUNDRED);

        double checkAmount = 0;

        double savedAmount = withdrawAmount;

        int count = 0;

        bool checking = false;

        vector<int> checkCashCount;

        if(withdrawAmount > 8000)
        {
            denominationTwoThousand(twoThousandCall,checkAmount,savedAmount,checkCashCount,0);    
        }

        if(savedAmount > 4000)
        {
            denominationFiveHundred(fiveHundredCall,checkAmount,savedAmount,checkCashCount,0);
        }

        if(savedAmount > 1000)
        {
            denominationHundred(hundredCall,checkAmount,savedAmount,checkCashCount,0);
            checking = true;  
        }

        while(checkAmount != savedAmount)
        {
            controlDenomination(hundredCall,checkAmount,savedAmount,1);
            count++;
        }

        if(checking)
        {
            count += checkCashCount[checkCashCount.size() - 1];
        }

        checkCashCount[checkCashCount.size() - 1] = count;

        setCheckDenomination(twoThousandCall,fiveHundredCall,hundredCall,checkCashCount);

        overrideATMValues(twoThousandCall);

        overrideATMValues(fiveHundredCall);

        overrideATMValues(hundredCall);
    }


    double getATMTotalAmount()
    {
        map<Denomination,LoadCashToATM>::iterator iter;
        
        double totalAmount = 0;

        for(iter = storeATM.begin(); iter != storeATM.end(); iter++)
        {
            LoadCashToATM atmCall = iter -> second;

            totalAmount += atmCall.getTotalValue();
        }
        return totalAmount;
    }


    void checkMoney(const double &checkCustomerBalance,double &withdrawAmount)
    {
        if(checkCustomerBalance < withdrawAmount)
        {
            throw "Insufficient Balance\n";
        }
    }

    void checkATMMoney(double &withdrawAmount)
    {
        if(getATMTotalAmount() < withdrawAmount)
        {
            throw "Insufficient Balance ATM\n";
        }
    }

public:

    void storeATMValues(LoadCashToATM &atmCall)
    {
        storeATM.insert(pair<Denomination,LoadCashToATM>(atmCall.getDenominationType(),atmCall));
    }

    void storeCustomerDetails(CustomerDetails &customerCall)
    {
        storeCustomer.insert(pair<int,CustomerDetails>(customerCall.getAccountNumber(),customerCall));
    }

    bool checkerCustomer(int &accountNumber,int &pinNumber)
    {
        CustomerDetails customerCall = getCustomer(accountNumber);
        
        return customerCall.checkAccNumberPin(accountNumber,pinNumber);
    }

    double checkBalance(int &accountNumber)
    {
        CustomerDetails customerCall = getCustomer(accountNumber);
        
        return customerCall.getAccountBalance();
    }

    void withdrawMoney(int &accountNumber,double &withdrawAmount)
    {
        CustomerDetails customerCall = getCustomer(accountNumber);
        
        checkMoney(customerCall.getAccountBalance(),withdrawAmount);

        checkATMMoney(withdrawAmount);

        if(withdrawAmount > 5000)
        {
            checkDenomination(withdrawAmount,0);
        }
        else
        {
            checkDenomination(withdrawAmount);
        }

        customerCall.setAccountBalance(customerCall.getAccountBalance() - withdrawAmount);

        overrideCustomerDetails(customerCall);
    }

    
    void transferMoney(int &myAccountNumber,int &transferAcoountNumber,double &money)
    {
        CustomerDetails myCustomerCall = getCustomer(myAccountNumber);
        
        checkMoney(myCustomerCall.getAccountBalance(),money);
        
        CustomerDetails transferCustomerCall = getCustomer(transferAcoountNumber);
        
        myCustomerCall.setAccountBalance(myCustomerCall.getAccountBalance() - money);
        
        transferCustomerCall.setAccountBalance(transferCustomerCall.getAccountBalance() + money);   

        overrideCustomerDetails(myCustomerCall);
        
        overrideCustomerDetails(transferCustomerCall);
                
    }

    map<Denomination,LoadCashToATM> getStoreATM()
    {
        return storeATM;
    }
};
#endif