#ifndef FIXED_H
#define FIXED_H

#include<iostream>

class Fixed
{
    private:
    int fx_point;
    static const int n_frbits;
    public:
    Fixed();
    Fixed(const Fixed &fix);
    ~Fixed();
    Fixed &operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
#endif