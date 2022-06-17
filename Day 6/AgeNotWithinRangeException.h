#ifndef AGENOTWITHINRANGEEXCEPTION_H_INCLUDED
#define AGENOTWITHINRANGEEXCEPTION_H_INCLUDED

#include<stdexcept>
#include<iostream>

class AgeNotWithinRangeException : std::exception
{
public:
    AgeNotWithinRangeException(int age)
    {
        std::cerr << "Access denied - You must be at least between 15 - 21 years old\n";
        std::cerr << "But Your Age is :" << age << "\n";
    }
};
#endif