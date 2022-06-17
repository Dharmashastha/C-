#ifndef CUSTOMEXCEPTION_H_INCLUDED
#define CUSTOMEXCEPTION_H_INCLUDED

#include<stdexcept>
#include<string>
#include<iostream>

class CustomExcetion : std::exception
{
public:
    CustomExcetion(std::string message)
    {
        std::cerr << message << "\n";
    }

    CustomExcetion(exception &e)
    {
        std::cerr << "Error Occurred" << e.what();
    }

    CustomExcetion(int number)
    {
        std::cerr << "Math Error " << number;
    }

};
#endif