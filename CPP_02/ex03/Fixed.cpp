#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed(const int value)
{
	fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	fixedPointValue = fixed.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const
{
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)fixedPointValue / (1 << fractionalBits);
}

int		Fixed::toInt(void) const
{
	return fixedPointValue >> fractionalBits;
}

