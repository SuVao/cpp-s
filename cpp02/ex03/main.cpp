#include "Point.hpp"

int main()
{
    Point p1, p2, p3, point;

    p1 = Point(3.0f, 3.0f);
    p2 = Point(3.0f, 0.0f);
    p3 = Point(0.0f, 3.0f);
    point = Point(2.9f, 3.1f);

	//std::cout << "Ponto a: (" << p1.get_x() << ", " << p1.get_y() << ")\n";
	//std::cout << "Ponto b: (" << p2.get_x() << ", " << p2.get_y() << ")\n";
	//std::cout << "Ponto c: (" << p3.get_x() << ", " << p3.get_y() << ")\n";
	//std::cout << "Ponto point: (" << point.get_x() << ", " << point.get_y() << ")\n";
	
//    std::cout << area(p1, p2, p3) << std::endl;


    std::cout << bsp(p1, p2, p3, point) << std::endl;
    return 0;
}
