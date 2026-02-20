#include "ScalarConverter.hpp"

ScalarConverter:: ScalarConverter(){};
ScalarConverter::~ScalarConverter(){};
ScalarConverter::ScalarConverter(ScalarConverter &other){(void)other;};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &oth)
{(void)oth;
return(*this);};
bool ScalarConverter::checkNI(std::string &str)
{
    return(str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" 
            || str == "+inff" || str == "-inff");
}
void ScalarConverter::printNI(std::string &str)
{
            std::cout<<"char: "<<"impossible"<<std::endl;
            std::cout<<"int: "<<"impossible"<<std::endl;
            if (str != "nan" && str != "nanf")
            {
                 std::cout<<"float: "<<(str[0]=='-'?"-":"+")<<"inff"<<std::endl;
                std::cout<<"double: "<<(str[0]=='-'?"-":"+")<<"inf"<<std::endl;
            }
            else{
                std::cout<<"float: "<<"nanf"<<std::endl;
                std::cout<<"double: "<<"nan"<<std::endl;
            }
}
void ScalarConverter::printFloat(std::string &str)
{
    float num;

    num = std::strtof(str.c_str(),NULL);
    std::cout<<"float: "<<num;

    if(num==static_cast<int>(num))
        std::cout<<".0f"<<std::endl;
    else
        std::cout<<"f"<<std::endl;
}

void ScalarConverter::printDouble(std::string &str)
{
    double num;

    num = std::strtod(str.c_str(),NULL);
    std::cout<<"double: "<<num;
    if(num==static_cast<int>(num))
        std::cout<<".0"<<std::endl;
}
void ScalarConverter::printInt(std::string &str)
{
    std::cout<<"int: "<<std::strtol(str.c_str(), NULL, 10)<<std::endl;
}
void ScalarConverter::printChar(std::string &str)
{
    int num = std::atoi(str.c_str());
if (num < 0 || num > 127) {
    std::cout << "char: impossible" << std::endl;
}
else if (num < 32 || num == 127) {  
    std::cout << "char: Non displayable" << std::endl;
}
else {
    char c = static_cast<char>(num);
    std::cout << "char: '" << c << "'" << std::endl;
}

}
bool ScalarConverter::if_number(std::string &str)
{
    int i = 0;
    bool dot;
    bool dig;
    
    if(str.empty())
        return(false);
    if((str[0] == '+' || str[0] == '-') && str.size() == 1)
        return(false);
    else if (str[0] == '+' || str[0] == '-')
        i++;
    int len=str.length();
    while(str[i] && len > i)
    {
        if(str[len - 1] == 'f')
            len--;
        if(str[i] == '.')
        {
            if(dot)
                return(false);
            else
                dot = true;
        }
        else if(std::isdigit(str[i]))
            dig=true;
        else
            return(false);
        i++;


    }
    return dig;


}

void ScalarConverter:: convert(std::string &literal)
{
    if (checkNI(literal))
        printNI(literal);
    else if(if_number(literal))
    {
        printChar(literal);
        printInt(literal);
        printFloat(literal);
        printDouble(literal);
    }

}