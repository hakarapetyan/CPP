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
    this->fx_point = other.fx_point;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this == &other)
        return (*this);
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->fx_point = other.fx_point;
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
Fixed::Fixed(const int fix)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->fx_point=fix*(1<<n_frbits);
}
Fixed::Fixed(const float fix)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->fx_point=roundf((fix*(1<<n_frbits)));
}
float Fixed::toFloat( void ) const
{
    return((float)this->fx_point / (float)(1 << this->n_frbits));
}
int Fixed::toInt( void ) const
{
    return(this->fx_point >> this->n_frbits);
    
} 
std::ostream& operator<<(std::ostream& out, Fixed const &fix)
{
    out<<fix.toFloat();
    return(out);
}
