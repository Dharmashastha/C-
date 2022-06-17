#ifndef NAMENOTVALIDEXCEPTION_H_INCLUDED
#define NAMENOTVALIDEXCEPTION_H_INCLUDED

#include<stdexcept>
#include<iostream>
#include<string>

class NameNotValidException : std::exception
{
public:
    
    NameNotValidException(std::string name)
    {
        std::cerr << "Access denied - Your Name Contains Numbers or Special Symbol\n";
        std::cerr << "But Your Name " << name << "\n";
    }
};
#endif