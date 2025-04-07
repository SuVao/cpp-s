
#ifndef Fixed_HPP
#define Fixed_HPP

#include <ostream>
#include <iostream>
#include <string>

class Fixed
{
private:
    int              _fixedPoint;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int fixedPoint);
    Fixed(const float floatingPoint);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other); // copy assignment operator
    ~Fixed();
    float toFloat( void ) const;
    int toInt( void ) const;
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};



#endif
