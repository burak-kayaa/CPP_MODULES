#include "Point.hpp"

static float	area(Point const a, Point const b, Point const c)
{
	int	area;

	area = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
	if (area >= 0)
		return (area);
	return (-area);
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	d0, d1, d2, d3;
	bool	ret;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, a, c);
	if (d1 == 0 || d2 == 0 || d3 == 0)
		ret = true;
	else if (d1 + d2 + d3 == d0)
		ret = true;
	else
		ret = false;
	return (ret);
}
