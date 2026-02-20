#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>

class ScalarConverter
{
    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &oth);
    static void printNI(std::string &str);
    static bool checkNI(std::string &str);
    static void printFloat(std::string &str);
    static void printInt(std::string &str);
    static void printDouble(std::string &str);
    static void printChar(std::string &str);
    static bool if_number(std::string &str);
    public:
    static void convert(std::string &literal);
};

#endif