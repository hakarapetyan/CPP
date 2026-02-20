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
    Fixed(const int fix);
    Fixed(const float fix);
    ~Fixed();
    Fixed &operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    public: 
    bool operator>=(const Fixed &fix)const;
    bool operator<=(const Fixed &fix)const;
    bool operator>(const Fixed &fix)const;
    bool operator<(const Fixed &fix)const;
    bool operator==(const Fixed &fix)const;
    bool operator!=(const Fixed &fix)const;
    Fixed operator+(const Fixed &fix);
    Fixed operator-(const Fixed &fix);
    Fixed operator*(const Fixed &fix);
    Fixed operator/(const Fixed &fix);
    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    static const Fixed &min(const Fixed &one, const Fixed  &two);
    static const Fixed &max(const Fixed &one, const Fixed  &two);
    static Fixed &min(Fixed &one, Fixed  &two);
    static Fixed &max(Fixed &one, Fixed  &two);
};
std::ostream& operator<<(std::ostream& out, Fixed const &fix);
#endif