
#ifndef Fixed_HPP
#define Fixed_HPP

#include <ostream>
#include <iostream>
#include <string>

class Fixed
{
private:
    int _fixedPoint;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int fixedPoint);
    Fixed(const float floatingPoint);
    ~Fixed();
    Fixed& operator=(const Fixed& other); // copy assignment operator
    int    getRawBits( void ) const;
    void    setRawBits( int const raw);
};



#endif
