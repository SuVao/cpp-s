
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point(){}

Point::Point(const float& x1, const float& y1) : x(x1), y(y1) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}