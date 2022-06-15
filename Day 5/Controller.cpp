
#include<iostream>
#include "NameSpace.h"
#include "InputCenter.h"


int main()
{

    InputCenter inputCall;

    std::cout << standard::first();

    std::cout << "\nEnter the value convert absolute value\n";

    std::cout << "Absolute Value is :" + std::to_string(standard::math::abs(inputCall.intInput()));

    std::cout << "\nEnter the value Find Maximum Value(compare two values)";

    std::cout << "\nEnter the value1\n";

    int saved = inputCall.intInput();
    
    std::cout << "Enter the value2\n";

    int dummy = inputCall.intInput();

    std::cout << "Maximum Value is :" + std::to_string(standard::math::max(saved,dummy));

    std::cout << "\nEnter the value Find Minimum Value(compare two values)";

    std::cout << "\nEnter the value1\n";

    saved = inputCall.intInput();
    
    std::cout << "Enter the value2\n";

    dummy = inputCall.intInput();

    std::cout << "Minimum Value is :" + std::to_string(standard::math::min(saved,dummy));

    std::cout << "\nEnter the value Find Square Root value\n";

    std::cout << "Square Root Value is :" + std::to_string(standard::math::sqrt(inputCall.intInput()));

    std::cout << "\nFind Power Value";

    std::cout << "Enter the Number\n";

    saved = inputCall.intInput();
    
    std::cout << "How many times you want power times(square 2 times,cube 3 times,number 2 is 2^4,etc..)\n";

    dummy = inputCall.intInput();

    namespace mathEquation = standard::math;                                    //Namespace aliases name mathEquation

    std::cout << "Minimum Value is :\n" + std::to_string(mathEquation::pow(saved,dummy));

    return 0;
}