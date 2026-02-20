#ifndef FIXED_H
#define FIXED_H

#include<iostream>
#include <cmath>

class Fixed
{
    private:
    int fx_point;
    static const int n_frbits;
    public:
    Fixed();
    Fixed(const Fixed &fix);
    Fixed(const int fix);
    Fixed(const float fix);
    ~Fixed();
    Fixed &operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& out, Fixed const &fix);
#endif