#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y) {}

Point::Point(Point const &p) : x(p.getX()), y(p.getY()) {}

Point &Point::operator=(Point const &p)
{
	if (this != &p)
	{
		this->x = p.getX();
		this->y = p.getY();
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return this->x; }

Fixed Point::getY() const { return this->y; }

std::ostream &operator<<(std::ostream &o, Point const &point)
{
	o << "Point(" << point.getX() << ", " << point.getY() << ")";
	return o;
}