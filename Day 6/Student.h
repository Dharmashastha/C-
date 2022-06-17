#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include<string>
#include "NameNotValidException.h"
#include "AgeNotWithinRangeException.h"
#include "InvalidCouseException.h"

using std::string;

class Student
{

private:                        //Attributes RollNumber,Name,Age,Course
    string rollNumber;
    string name;
    int age;
    string course;

public:

    Student(){}                 //Default Constructor

    Student(string rollNumber,string name,int age,string course)        //Constructor
    {
        this -> rollNumber = rollNumber;
        if(!checkName(name))
        {
            this -> name = name;
        }
        else
        {
            throw NameNotValidException(name);
        }

        if(!checkAge(age))
        {
            this -> age = age;
        }
        else
        {
            throw AgeNotWithinRangeException(age);
        }
        this -> course = course;
    }

    //geter Method

    string getRollNumber()
    {
        return rollNumber;
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    string getCourse()
    {
        return course;
    }

private:                            //checkName,checkAge Private Method

    bool checkName(string name)
    {
        int length = name.length();
        for(int iter = 0; iter < length; iter++)
        {
            if(33 <= name[iter] && name[iter] <= 64)
            {
                return true;
            }
        }
        return false;
    }

    bool checkAge(int age)
    {
        if(15 <= age  && age <= 21)
        {
            return false;
        }
        return true;
    }

public:             

    string selectCourse(int number)             //SelectCourse Method
    {
        string selCourse = "";
        switch(number)
        {
            case 1:
            {
                selCourse = "C";
                break;
            }

            case 2:
            {
                selCourse = "C++";
                break;
            }

            case 3:
            {
                selCourse = "JAVA";
                break;
            }
            default:
            {
                throw InvalidCourseException();
            }
        }
        return selCourse;
    }
};
#endif