#ifndef NAMESPACE_H_INCLUDED
#define NAMESPACE_H_INCLUDED

#include<string>
#include<iostream>

namespace standard                              //namespace name standard
{
    std::string first()                         //namespace standard dummy function(checking function)
    {
        return "Welcome Namespace standard";
    }
    namespace math                              //Nested namespace name math
    {
        template<typename T>
        auto add(T number1,T number2)     //addition method
        {
            return number1 + number2;
        }

        template<typename T>
        auto sub(T number1,T number2)     //subtraction method
        {
            return number1 - number2;
        }

        template<typename T>
        auto mul(T number1,T number2)     //multiplication method
        {
            return number1 * number2;
        }

        template<typename T>
        auto div(T number1,T number2)     //division method
        {
            return number1 / number2;
        }

        template<typename T>
        auto abs(T number)                   //absolute value method
        {
            if(number < 0)
            {
                return -number;
            }
            return number;
        }

        template<typename T>
        auto max(T number1,T number2)     //two value compare return maximum value method
        {
            if(number1 < number2)
            {
                return number2;
            }
            return number1;
        }

        template<typename T>
        auto min(T number1,T number2)     //two value compare return  minimum value mehod
        {
            if(number1 < number2)
            {
                return number1;
            }
            return number2;
        }

        template<typename T>
        auto sqrt(T number)                  //square root value return method
        {
            auto saved = 0.0;
            auto sqrt = number / 2.0;

            while ((saved - sqrt) != 0)
            {
                saved = sqrt;
                sqrt = (saved + number/saved) / 2.0;
            }
            return sqrt;
        }

        template<typename T>
        auto pow(T number,int nTimes)        //power method
        {
            if(number == 0)
            {
                return 0;
            }
            if(nTimes == 0)
            {
                return 1;
            }

            auto result = 1;

            for(int iter = 1; iter <= nTimes; iter++)
            {
                result *= number;
            }
            return result;
        }

    }
};
#endif