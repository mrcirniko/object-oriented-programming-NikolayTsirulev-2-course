#include <iostream>
#include "func.h"

int main()
{
    std::string str;
    int num;
    std::cout << "enter day of the week:";
    std::cin  >> str;
    std::cout << "enter a number:";
    std::cin  >> num;
    
    std::cout << "result: " << func(str,num) << std::endl;
    
    return 0;
}