#include "span.hpp"

int main()
{
    try
    {
        std::cout << " Subject example " << std::endl;
        Span sp1(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);

        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl; // 2
        std::cout << "Longest span : " << sp1.longestSpan() << std::endl;  // 14

        try
        {
            sp1.addNumber(42);
        }
        catch (std::length_error &e)
        {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n  Negative and extreme numbers " << std::endl;
        Span sp2(5);
        sp2.addNumber(6);
        sp2.addNumber(-2147483648);
        sp2.addNumber(2147483647);
        sp2.addNumber(-8);
        sp2.addNumber(-9);

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp2.longestSpan() << std::endl; 

        std::cout << "\n  addRange with vector " << std::endl;
        Span sp3(10);
        int arr[] = {1, 3, 5, 7, 9};                 
        std::vector<int> nums(arr, arr + 5);         

        sp3.addRange(nums.begin(), nums.end());      
        sp3.addNumber(2);
        sp3.addNumber(4);
        sp3.addNumber(6);
        sp3.addNumber(8);
        sp3.addNumber(10);

        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp3.longestSpan() << std::endl;

        try
        {
            sp3.addRange(nums.begin(), nums.end());
        }
        catch (std::length_error &e)
        {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n Large random test (10,000 numbers) " << std::endl;
        Span sp4(10000);
        srand(time(0));
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; i++)
            bigVec.push_back(rand());

        sp4.addRange(bigVec.begin(), bigVec.end());

        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp4.longestSpan() << std::endl;

        std::cout << "\n  Edge case, less than 2 numbers " << std::endl;
        Span sp5(3);
        sp5.addNumber(42);
        try
        {
            std::cout << sp5.shortestSpan() << std::endl;
        }
        catch (std::logic_error &e)
        {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

