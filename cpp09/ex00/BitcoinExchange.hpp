#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include <string>

class BitcoinExchange
{
    private:
    std::map<std::string,double> base;
    public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    void csvloading(const std::string &filename);
    std::map<std::string, double>::iterator findClosest(const std::string& date);
    void inputprocess(const std::string &filename);
    bool isValNum(std::string &date);
    bool isValValue(std::string &v, float &f);
    int valid_date(std::string &date,int first,int second);
    void  resizing(std::string &date);
    
};
#endif