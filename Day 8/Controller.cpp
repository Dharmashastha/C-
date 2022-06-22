

#include<iostream>
#include<string>
#include "MobileConnection.h"
#include "LandlineConnection.h"
#include "BillPayment.h"
#include "InputCenter.h"



using std::cout;
using std::to_string;
using std::string;

class Controller
{
        InputCenter inputCall;              //InputCenter Object Created Name inputCall

     void checkMobileNumber(string mobileNumber)
     {
        int size = mobileNumber.length();
        if(size != 10)
        {
            throw "Kindly! Check Your MobileNumber\n";
        }
     }

     void checkLandlineNumber(string landlineNumber)
     {
        int size = landlineNumber.length();
        if(size != 6)
        {
            throw "Kindly! Check Your LandlineNumber\n";
        }
     }   

     void checkSTDCode(string stdCode)
     {
        int size = stdCode.length();
        if(size < 3)
        {
            throw "Kindly! Check Your STDCode\n";
        }
     }   

public:

    void newMobileConnection(MobileConnection &mobileCall)
    {
        cout << "Enter the Your MobileNumber\n";
        
        string mobileNumber = inputCall.stringInput();

        checkMobileNumber(mobileNumber);

        mobileCall.setMobileNumber(mobileNumber);

        mobileCall.setBillAmount(0);    
    }

    void newLandlineConnection(LandlineConnection &landlineCall)
    {
        cout << "Enter the Your LandLineNumber\n";
        
        string landlineNumber = inputCall.stringInput();

        checkLandlineNumber(landlineNumber);

        landlineCall.setLandlineNumber(landlineNumber);

        cout << "Enter the Your STDCode\n";

        string stdCode = inputCall.stringInput();

        checkSTDCode(stdCode);

        landlineCall.setSTDCode(stdCode);

        landlineCall.setBillAmount(0);    
    }

};

int main()
{
    MobileConnection mobileCall;                 //MobileConnection Object Created Name mobileCall

    LandlineConnection landlineCall;             //LandlineConnection Object Created Name landlineCall

    InputCenter inputCall;                       //InputCenter Object Created Name inputCall

    Controller conCall;                          //Controller Object Created Name conCall 

    BillPayment<MobileConnection> billCall;      //BillPayment(MobileConnection) Object Created Name billCall

    BillPayment<LandlineConnection> payCall;     //BillPayment(LandlineConnection) Object Created Name payCall   

    bool flag = false;

    while(!flag)
    {

        cout << "1.Add a new mobile connection\n2.Add a new landline connection\n";

        cout << "3.Update bill amount using the connection number\n4.Exit\n";

        cout << "Enter Your Choice\n";

        int choice = inputCall.intInput();

        inputCall.stringInput();

        switch(choice)
        {
            case 1:
            {
                try
                {
                    conCall.newMobileConnection(mobileCall);

                    billCall.storedConnection(mobileCall);
                }
                catch(const char *error)
                {
                    cout << error << "\n";
                }    
                break;
            }

            case 2:
            {
                try
                {
                    conCall.newLandlineConnection(landlineCall);
                
                    payCall.storedConnection(landlineCall);
                }    
                catch(const char *error)
                {
                    cout << error << "\n";
                }
                break;
            }

            case 3:
            {
                cout << "Enter Your Connection Number\n";
                
                string connectionNumber = inputCall.stringInput();

                cout << "Enter Your Pay Bill Amount\n";

                double billAmount = inputCall.doubleInput();
                try
                {

                    if(billCall.updatePayBill(connectionNumber,billAmount))
                    {
                        cout << "Mobile Pay Bill Amount Successful Completed\n";

                        cout << "Your Mobile Balance Bill Amount : \n" << billCall.getPayBill(connectionNumber) << "\n";
 
                    }
                    else if(payCall.updatePayBill(connectionNumber,billAmount))
                    {
                        cout << "Landline Pay Bill Amount Successful Completed\n";

                        cout << "Your Landline Balance Bill Amount : \n" << payCall.getPayBill(connectionNumber) << "\n";
                    }
                    else
                    {
                        cout << "ConnectionNumber Not Found\n";
                    }
                }
                catch(const char *error)
                {
                    cout << error << "\n";
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
                cout << "Enter The Valid Choice\n";
                break;
            }
        }
    }
}