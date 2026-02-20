
#include <iostream>
#include "Array.hpp" 
#include "Array.hpp"
#include <limits.h>

int main()
{

    std::cout << "---- Create empty array ----" << std::endl;
    Array<int> a0;
    std::cout << "a0 size = " << a0.size() << std::endl;

    std::cout << "\n---- Create array of size 5 ----" << std::endl;
    Array<int> a1(5);
    std::cout << "a1 size = " << a1.size() << std::endl;
    for (unsigned int i = 0; i < a1.size(); ++i)
        a1[i] = i * 10;

    std::cout << "\n----  Read array elements ----" << std::endl;
    for (unsigned int i = 0; i < a1.size(); ++i)
        std::cout << "a1[" << i << "] = " << a1[i] << std::endl;

    std::cout << "\n----  Const read access ----" << std::endl;
    const Array<int> a2 = a1; 
    for (unsigned int i = 0; i < a2.size(); ++i)
        std::cout << "a2[" << i << "] = " << a2[i] << std::endl;

    std::cout << "\n---- Out-of-range read ----" << std::endl;
    try {
        std::cout << a1[10] << std::endl; 
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n---- Out-of-range write ----" << std::endl;
    try {
        a1[999] = 123;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}