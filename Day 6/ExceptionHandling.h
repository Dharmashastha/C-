#ifndef EXCEPTIONHANDLING_H_INCLUDED
#define EXCEPTIONHANDLING_H_INCLUDED

#include<string>
#include<stdexcept>
#include<iostream>
#include "CustomException.h"

class ExceptionHandling
{

public:

   int division(int dividend,int divisor)                               //Division Method 
   {    
        int answer = 0;
        try
        {
            if(divisor == 0)
            {
                throw CustomExcetion("Invalid Division");
            }
        answer = dividend/divisor;
        }
        catch(...)
        {
            std::cerr << "Exception encountered" << "\n";
        }
        return answer;
   }

   void allocateMemory()
   {
        try
        {
            int *array = new int[100000000000000];                     //AllocateMemory Method
        }
        catch(std::exception &e)
        {
            std::cerr << "Memory is compromised!\n" << e.what(); 
        }
   }

   char stringValue(std::string txt,int position)                       //stringValue Method
   {
        char dummy = 0;
        try
        {
            int size = txt.length();

            for(int iter = 0; iter < size; iter++)
            {
                if(size < position)
                {
                    throw position;
                }

                if(iter == position)
                {
                    dummy = txt[10];
                }  
            }
        }
        catch(int position)
        {
            std::cerr << "Index is invalid";
        }
        return dummy;
   }



   std::string stringArray(std::string array[],int size)                            //StringArray Method
   {
        std::string dummy = "";
        try
        {
            for(int iter = 0; iter < size+1; iter++)
            {
                dummy += array[iter];  
            }
        }
        catch(std::exception &e)
        {
            std::cerr << "Array Index is invalid" << e.what();
        }
        return dummy;
   }

   bool eligibleCandidate(std::string name,int sslcMark,int hscMark,float cgpa)     //EgliableCandidate Method
   {
        bool checking = false;
        try
        {
            if(sslcMark > 500)
            {
                throw sslcMark;
            }

            if(sslcMark > 450)
            {
                std::cout << "Select First Criteria\n";
                checking = checkHscMark(hscMark,cgpa,checking);                     //Checking Hsc Mark 
            }
            else
            {
                return false;
            }
        }
        catch(int mark)
        {
            std::cerr << "Your Mark under 500 But your mark is " << mark << "\n";
        }
        catch(std::exception &e)
        {
            std::cerr << "Error Occurred " << e.what() << "\n";
        }
    return checking;    
   }
private:
    bool checkHscMark(int hscMark,float cgpa,bool checking)
    {
        try
            {
                if(hscMark > 1200)
                {
                    throw hscMark;
                }

                if(hscMark > 1000)
                {
                    std::cout << "Select Second Criteria\n";
                    checking = checkCgpa(cgpa,checking);                    //Checking CGPA Mark 
                }
                else
                {
                    return false;
                }
            }     
            catch(int mark)
            {
                std::cerr << "Your Mark under 1200 But your mark is " << mark << "\n";
            }
            catch(std::exception &e)
            {
                std::cerr << "Error Occurred " << e.what() << "\n";
            }
            return checking;
    }

    bool checkCgpa(float cgpa,bool checking)
    {
        try
           {
                if(cgpa > 10)
                {
                    throw cgpa;
                }

                if(cgpa > 8.0)
                {
                     checking = true;
                }
            }     
            catch(float mark)
            {
                std::cerr << "Your cgpa under 10 But your cgpa is " << mark << "\n";
            }
            catch(std::exception &e)
            {
                std::cerr << "Error Occurred " << e.what() << "\n";
            }
        return checking;
    }

};
#endif
