
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point(){}

Point::Point(const float& x1, const float& y1) : x(Fixed(x1)), y(Fixed(y1)) {}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		const_cast<Fixed&>(x) = other.x;
		const_cast<Fixed&>(y) = other.y;
	}
	return (*this);
}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Fixed Point::operator*(const Point& other) const
{
	return (this->x * other.y) - (this->y * other.x);
}

Fixed Point::get_x() const
{
	return x;
}

Fixed Point::get_y() const
{
	return y;
}
