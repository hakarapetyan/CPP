#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->base=other.base;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if(this != &other)
    {
        this->base=other.base;
    }
    return *this;
}

void BitcoinExchange:: csvloading(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
        throw std::runtime_error("Error: could not open file\n");

    std::string line;
    
    std::getline(file,line);
    while(std::getline(file,line))
    {
        std::stringstream ss(line);
        std::string date, value;

        if(std::getline(ss,date,',') && std::getline(ss,value))
        {
            std::stringstream ssvalue(value);
            float fvalue;
            ssvalue>>fvalue;
            if(!ssvalue.fail())
                base[date]=fvalue;
        }

    }
}
std::map<std::string, double>::iterator BitcoinExchange::findClosest(const std::string& date)
{
    std::map<std::string, double>::iterator it = base.lower_bound(date);
    if (it == base.begin() && it->first > date)
    return base.end();

    if (it == base.end() || it->first != date)
        --it;
    return it;
}
int BitcoinExchange::valid_date(std::string &date,int first,int second)
{
    std::string num = date.substr(first,second);
    std::stringstream ss(num);
    int inum;
    ss>>inum;
    if(ss.fail())
        return 0;
    return inum;
}
bool BitcoinExchange::isValNum(std::string &date)
{
    if(date.size() != 10 && date[4] != '-' && date[7] != '-')
        return false;
  
    int iyear;
    if(!(iyear=valid_date(date, 0, 4)))
        return false;
    if (iyear <= 0)
        return false;

    int imonth;
    if(!(imonth=valid_date(date, 5, 2)))
        return false;
    if(imonth < 1 || imonth > 12)
        return false;

    int iday;
    if(!(iday=valid_date(date, 8, 2)))
        return false;
    if((iday < 1 || iday > 31) || (imonth !=8 && imonth % 2==0 && iday > 30))
        return false;
    else if(iday > 31)
        return false;
    return true;
}
bool BitcoinExchange::isValValue(std::string &value,float &fvalue)
{
    std::stringstream ss(value);
    ss >> fvalue;
    if (ss.fail()) {
        std::cout << "Error: invalid numeric value.\n";
        return false;
    }
    if(fvalue < 0)
    {
        std::cout<<"Error: not a positive number.\n";
        return false;
    }
    if(fvalue > 1000)
    {
        std::cout<<"Error: too large a number.\n";
        return false;
    }
    char extra;
    if (ss >> extra) {
        std::cout << "Error: value contains unexpected characters.\n";
        return false;
    }
    return true;
}
void BitcoinExchange::inputprocess(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
        throw std::runtime_error("Error:could not open file");

    std::string line;
    std::getline(file,line);
    if(line != "date | value\r")
      throw std::runtime_error("Error: title not found.");  

    while(std::getline(file,line))
    {
        size_t str=line.find("|");
        
        std::stringstream ss;
        std::string date, value;
        date = line.substr(0, str);
        value=line.substr(str + 1);
        if(str == std::string::npos)
        {
                std::cout<<"Error: bad input"<<" => "<<date<<std::endl;
                continue;
        }
        float fvalue;
        if(!isValNum(date))
        {
            std::cout<<"Error: bad input"<<" => "<<date<<std::endl;
            continue;
        }
        if(!isValValue(value,fvalue))
        continue;
        
        
        std::map<std::string,double>::iterator it = findClosest(date);
  
        if(it == base.end())
          throw std::runtime_error("Error: no valid closest date found.");
        resizing(value);
        resizing(date);
        float result = fvalue * it->second;
        std::cout << date << " => " << value <<" = "<<result <<std::endl;
    }


}
void BitcoinExchange::resizing(std::string &value)
{
    while (!value.empty() && 
          (value[value.size() - 1] == '\r' || value[value.size() - 1] == ' ' || value[value.size() - 1] == '\t')) {
           value.resize(value.size() - 1);
    }
}