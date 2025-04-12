#ifndef Fixed_HPP
#define Fixed_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <cmath>

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
	
	bool operator>(const Fixed& fixed) const;
	bool operator<(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;
	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;
	
	double operator+(const Fixed& fixed) const;
	double operator-(const Fixed& fixed) const;
	Fixed operator*(const Fixed& fixed) const;
	Fixed operator/(const Fixed& fixed) const;
	
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	
	Fixed& min( Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	Fixed& max( Fixed& fixed1, Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
