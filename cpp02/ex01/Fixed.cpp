#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedPoint)
{
	_fixedPoint = fixedPoint << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatingPoint)
{
	_fixedPoint = roundf(floatingPoint * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return (_fixedPoint >> _fractionalBits);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPoint = other._fixedPoint;
	}
    return *this;
}

Fixed::Fixed(const Fixed& other) : _fixedPoint(other._fixedPoint)
{
    std::cout << "Copy constructor called" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();  // Converte o Fixed para float antes de imprimir
    return os;
}
