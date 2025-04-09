#include "Point.hpp"

int main()
{
    Point p1, p2, p3, point;
    bool ola;

    p1 = Point(1.5f, 7.2f);
    p2 = Point(-1.5f, -7.2f);
    p3 = Point(9.5f, 4.2f);
    point = Point(2.0f, 4.0f);

    ola = bsp(p1, p2, p3, point);
    std::cout << ola << std::endl;
    return 0;
}
