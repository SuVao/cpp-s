
#include "Point.hpp"

// to do a funtion to calculate the area of triangle
Fixed area( Point const a, Point const b, Point const c )
{
	Fixed res;

	res = ((a.get_x() * (b.get_y() - c.get_y()))
		+ (b.get_x() * (c.get_y() - a.get_y()))
		+ (c.get_x() * (a.get_y() - b.get_y())) ) / 2;
	if (res < Fixed(0))
		res = res * Fixed(-1);
	return (res);
}


bool zero_area(Point const a, Point const b, Point const c, Point const point)
{
	if (area(a, b, point) == 0 || area(a, c, point) == 0 || area(c, b, point) == 0)
		return (false);
	return (true);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (area(a, b, c) == (area(a, b, point) + area(a, c, point) + area(c, b, point)) &&
	zero_area(a, b, c, point))
		return ( true );
	std::cout << area(a, b, point) + area(a, c, point) + area(c, b, point) << std::endl;
	return (false);
}