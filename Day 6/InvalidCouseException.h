#ifndef INVALIDCOURSEEXCEPTION_H_INCLUDED
#define INVALIDCOURSEEXCEPTION_H_INCLUDED

#include<stdexcept>
#include<iostream>

class InvalidCourseException : std::exception
{
public:
    
    InvalidCourseException()
    {
        std::cerr << "Access denied - Your Course Not Available\n";
    }
};
#endif