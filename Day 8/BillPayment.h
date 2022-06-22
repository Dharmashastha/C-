#ifndef BILLPAYMENT_H_INCLUDED
#define BILLPAYMENT_H_INCLUDED

#include<string>
#include<vector>

using std::string;
using std::vector;

template <class T>
class BillPayment
{

    vector<T> store;

    

    T checkConnectionNumber(string number,bool &checking)
    {
        T saved;
        int size = store.size();
        int iter = 0;
        for( ; iter < size; iter++)
        {
            if(store[iter].matches(number))
            {
                saved = store[iter];
                checking = true;
                break;
            }
        }

        // if(iter == size)
        // {
        //     throw "ConnectionNumber Not Found";
        // }
        
        return saved;    
    }

public:

    void storedConnection(T &tValue)
    {
        store.push_back(tValue);
    }


    void checkConnection(T &tValue)
    {
        int size = store.size();
        for(int iter = 0; iter < size; iter++)
        {
            if(store[iter].getConnectionNumber() == tValue.getConnectionNumber())
            {
                store[iter] = tValue;
            }
        }
    }

    // bool payBill(long mobileNumber,double newValue)
    // {
    //     T connection = checkConnectionNumber(mobileNumber);
    //     if(connection != NULL)
    //     {
    //         connection.setBillAmount(newValue);
    //         return true;
    //     }
    //     return false;
    // }

    // bool payBill(long Landlinenumber,long stdCode,double newValue)
    // {
    //     T connection = checkConnectionNumber(number);
    //     if(connection != NULL)
    //     {
    //         connection.setBillAmount(newValue);
    //         return true;
    //     }
    //     return false;
    // }


    bool updatePayBill(string mobileNumber,double value)
    {
        bool checking = false;
        T connection = checkConnectionNumber(mobileNumber,checking);
        if(checking)
        {
            connection.setBillAmount(connection.getBillAmount() + value);
            checkConnection(connection);
        }
        return checking;
    }

    double getPayBill(string mobileNumber)
    {
        bool checking = false;
        T connection = checkConnectionNumber(mobileNumber,checking);
        if(checking)
        {
            return connection.getBillAmount();
        }
        else
        {
            throw "Error";
        }
    }

};
#endif