
#include "Fixed.hpp"

bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->_fixedPoint > fixed._fixedPoint);
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (_fixedPoint < fixed._fixedPoint);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->_fixedPoint >= fixed._fixedPoint);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->_fixedPoint <= fixed._fixedPoint);
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->_fixedPoint == fixed._fixedPoint);
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->_fixedPoint != fixed._fixedPoint);
}

double Fixed::operator+(const Fixed& fixed) const
{
	return _fixedPoint + fixed._fixedPoint;
}

double Fixed::operator-(const Fixed& fixed) const
{
	return _fixedPoint - fixed._fixedPoint;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed res;
	res._fixedPoint = (_fixedPoint * fixed._fixedPoint) >> _fractionalBits;
	return (res);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed res;
	if (fixed == 0)
	{
		std::cout << "Cant divide by zero.";
		exit(-1);
	}
	res._fixedPoint = (_fixedPoint << _fractionalBits) / fixed._fixedPoint;
	return res;
}

Fixed& Fixed::min( Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

Fixed& Fixed::max( Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

Fixed& Fixed::operator++()
{
	_fixedPoint += 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	_fixedPoint -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fixedPoint -= 1;
	return tmp;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fixedPoint += 1;
	return tmp;
}

Fixed::Fixed() : _fixedPoint(0)
{
   // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedPoint)
{
	_fixedPoint = fixedPoint << _fractionalBits;
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatingPoint)
{
	_fixedPoint = roundf(floatingPoint * (1 << _fractionalBits));
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
 //   std::cout << "Destructor called" << std::endl;
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
    //std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPoint = other._fixedPoint;
	}
    return *this;
}

Fixed::Fixed(const Fixed& other) : _fixedPoint(other._fixedPoint)
{
   // std::cout << "Copy constructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();  // Converte o Fixed para float antes de imprimir
    return os;
}
