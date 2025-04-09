
#include "Point.hpp"

// to do a funtion to calculate the area of triangle
Fixed area( Point const a, Point const b, Point const c )
{
	Fixed res;

	
	res = ((a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat())) \
			+ (b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat())) \
			+ (c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat())));
	if (res < 0)
		res = res * -1;
	return (res / Fixed(2));
}
/*
Como saber se está dentro?
É como se dividíssemos o triângulo em três triângulos menores:
Um triângulo que junta o point, o 
𝐵
B e o 
𝐶
C.
Outro que junta o point, o 
𝐴
A e o 
𝐶
C.
E outro que junta o point, o 
𝐴
A e o 
𝐵
B.
Ou seja, cada vez usamos o point e dois dos três vértices.
Depois fazemos isto:
Calculamos a área do triângulo original 
𝐴
𝐵
𝐶
ABC.
Calculamos a área dos três triângulos pequenos que fizemos com o point.
Se a soma das três áreas pequenas for igual à área do triângulo original e nenhuma área
for zero (ou seja, o ponto não está em cima da linha), então o point está dentro.*/

bool zero_area(Point const a, Point const b, Point const c, Point const point)
{
	if (area(a, b, point) == 0 || area(a, c, point) == 0 || area(c, b, point) == 0)
		return true;
	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (area(a, b, c) == (area(a, b, point) + area(a, c, point) + area(c, b, point)) &&
	!zero_area(a, b, c, point))
		return ( true );
	return (false);
}