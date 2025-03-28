#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _fixedPoint) : _fixedPoint(0)
{
	(void)_fixedPoint;
}

Fixed::Fixed(const float _floatPoint) : _fixedPoint(0)
{
	(void)_floatPoint;	
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//Fixed::Fixed(const Fixed& other) : _fixedPoint(other._fixedPoint)
//{
//    std::cout << "Copy constructor called" << std::endl;
//    other.getRawBits();
//}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPoint = other.getRawBits();
	}
    return *this;
}

int    Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called!" << std::endl;
    return _fixedPoint;
}

void    Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits member function called!" << std::endl;
    _fixedPoint = raw;
}
