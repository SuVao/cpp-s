
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
	Fixed const x;
	Fixed const y;
	public:
	Point();
	Point(const float& x, const float& y);
	Point(const Point& other);
	~Point();
	Point& operator=(const Point& other);
	Fixed operator*( const Point& point) const;
	Fixed get_x() const;
	Fixed get_y() const;
};

bool zero_area(Point const a, Point const b, Point const c, Point const point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed area( Point const a, Point const b, Point const c );
//std::ostream& operator<<(std::ostream& os, const Point& point);

#endif