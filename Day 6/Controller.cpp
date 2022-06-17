
#include<string>
#include<iostream>
#include<map>
#include "ExceptionHandling.h"
#include "InputCenter.h"
#include "Student.h"
#include "CustomException.h"

using std::string;
using std::cout;

class Controller
{
    map<string,Student> studentData;

    InputCenter inputCall;                  //InputCenter Object created Name inputCall
private:

    Student studentCall;

    void checkRollNumber(string rollNumber)      //Check Duplicate Student Method
    {
       //std::map<string,Student>::iterator saved = studentData.find(rollNumber);
       if(studentData.count(rollNumber) > 0)
       {
            throw CustomExcetion("Duplicate Student Error");
       } 
    }

public:

    void studentDetails()                           //Student Data Entry Method
    {
        cout << "Enter Your Roll Number :\n";

        inputCall.stringInput();

        string rollNumber = inputCall.stringInput();
        
        checkRollNumber(rollNumber);

        cout << "Enter Your Name :\n";

        string studentName = inputCall.stringInput();

        cout << "Enter Your Age : \n";

        int age = inputCall.intInput();

        cout << "Enter Your Course :\n";
        
        cout << "1.C\n2.C++\n3.JAVA\n";

        int courseNumber = inputCall.intInput();

        string course = studentCall.selectCourse(courseNumber);

        Student dataCall(rollNumber,studentName,age,course);

        studentData.insert(pair<string,Student>(rollNumber,dataCall));
    }

};

int main()
{
    ExceptionHandling exeCall;          //ExceptionHandling Object created Name exeCall

    InputCenter inputCall;              //InputCenter Object created Name inputCall

    Controller conCall;                 //Controller Object created Name conCall

    bool flag = false;

    while (!flag)
    {
        cout << "1.Find the Division Number\n2.AllocateMemory\n3.Find the name position Letter\n4.Print String Array all values\n5.Find the EligibleCandidate\n";

        cout << "6.Studentdata Entry\n7.Exit\n";    

        int choice = stoi(inputCall.stringInput());
            

    switch(choice)
    {
        case 1:
        {
            cout << "Find the Division Number\n";
    
            cout << "Enter the Value Dividend :\n";

            int dividend = inputCall.intInput();

            cout << "Enter the Value Divisor :\n";

            int divisor = inputCall.intInput();

            cout << "Division Number is " << exeCall.division(dividend,divisor) << "\n";        //Division Method Call

            inputCall.stringInput();            
            break;
        }

        case 2:
        {
            exeCall.allocateMemory();                                                    //AllocateMemory Method Call
            cout << "\n";
            break;
        }

        case 3:
        {
            cout << "Find the name position Letter\n";

            cout << "Enter the Name :\n";

            inputCall.stringInput();

            string name = inputCall.stringInput();

            cout << "Enter the Position :\n";

            int position = inputCall.intInput();

            cout << "Name Position Letter :\n" << exeCall.stringValue(name,position) << "\n";     //stringValue Method Call;
            break;
        }

        case 4:
        {
            cout << "Print String Array all values\n";

            cout << "Enter the array length : \n";

            int size = inputCall.intInput();

            string array[size];

            inputCall.stringInput();

            for(int iter = 0; iter < size; iter++)
            {
                cout << "Enter String Array Element " << iter << "\n";
                array[iter] = inputCall.stringInput();
            }

            cout << "Print String Array all values is\n" <<exeCall.stringArray(array,size) << "\n";       //stringArray Method Call
            break;
        }

        case 5:
        {
            cout << "Find the EligibleCandidate\n";

            cout << "Enter Your Name : \n";

            inputCall.stringInput();

            string name = inputCall.stringInput();
    
            std::cout << "Enter Your SSLCMark : \n";

            int sslcMark = inputCall.intInput();

            cout << "Enter Your HSCMark : \n";

            int hscMark = inputCall.intInput();

            cout << "Enter Your CGPA : \n";

            float cgpa = inputCall.floatInput();

            inputCall.stringInput();

            try
            {

                if(exeCall.eligibleCandidate(name,sslcMark,hscMark,cgpa))                               //EligibleCandidate Method Call
                {
                    cout << "Congratulations " << name << "\nSelected EligibleCandidate\n";
                }
                else
                {
                    cout << "Don\'t Worry! " << name << " \nNot Selected for EligibleCandidate\n";
                }
            }
            catch(...){}
            cout << "Exception Handling Accomplished\n";

            //----------------------------------------EXCEPTIONHANDLING-----------------------------------------------------------
            break;
        }

        case 6:
        {
            try
            {
                conCall.studentDetails();                       //Student Method
            }
            catch(...)
            {}
            break;
        }

        case 7:
        {
            flag = true;                                        //Exit Program
            break;
        }

        default:
        {
            cout << "Enter the Valid Choice" << "\n";
            break;
        }
    }
    }
}