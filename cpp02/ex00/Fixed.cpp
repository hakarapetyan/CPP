#include "Fixed.hpp"
const int Fixed::n_frbits = 8;
Fixed ::Fixed()
{
    this->fx_point = 0;
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout<<"Copy constructor called"<<std::endl;
 this->setRawBits(other.getRawBits());
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this == &other)
        return (*this);
    this->setRawBits(other.getRawBits());
    return (*this);
}

int Fixed ::getRawBits() const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return(this->fx_point);
}
void Fixed::setRawBits( int const raw )
{
    this->fx_point = raw;
}
