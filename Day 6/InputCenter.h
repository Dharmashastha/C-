#ifndef INPUTCENTER_H_INCLUDED
#define INPUTCENTER_H_INCLUDED

#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;


class InputCenter
{
public:

string stringInput()
{
    string myStr = "";
    getline(cin,myStr);
return myStr;
}

int intInput()
{
    int myInt = 0;
    try
    {
        cin >> myInt;
    }
    catch(exception &e)
    {
        cerr << "Format Mismatch " << e.what();
    }
return myInt;
}

float floatInput()
{
    float myFloat = 0.00f;
    try
    {
        cin >> myFloat;
    }
    catch(exception &e)
    {
        cerr << "Format Mismatch " << e.what();
    }
return myFloat;
}

double doubleInput()
{
    double myDouble = 0;
    try
    {
        cin >> myDouble;
    }
    catch(exception &e)
    {
        cerr << "Format Mismatch " << e.what();
    }
return myDouble;
}

char charInput()
{
    char myChar;
    try
    {
        cin >> myChar;
    }
    catch(...)
    {
        cerr << "Format Mismatch";
    }
return myChar;
}

};
#endif