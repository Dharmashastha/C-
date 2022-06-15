#ifndef INPUTCENTER_H_INCLUDED
#define INPUTCENTER_H_INCLUDED

#include<iostream>
#include<string>

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
    cin >> myInt;
return myInt;
}

float floatInput()
{
    float myFloat = 0.00f;
    cin >> myFloat;
return myFloat;
}

double doubleInput()
{
    double myDouble = 0;
    cin >> myDouble;
return myDouble;
}

char charInput()
{
    char myChar;
    cin >> myChar;
return myChar;
}

};
#endif