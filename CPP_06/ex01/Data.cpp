#include "Data.hpp"

Data::Data() : _str(""), _int(0), _float(0.0f)
{
}

Data::Data(std::string str, int i, float f) : _str(str), _int(i), _float(f)
{
}

Data::Data(const Data &src) : _str(src._str), _int(src._int), _float(src._float)
{
}

Data::~Data()
{
}

Data &Data::operator=(const Data &src)
{
	if (this == &src)
		return *this;
	_str = src._str;
	_int = src._int;
	_float = src._float;
	return *this;
}

std::string	Data::getStr() const
{
	return _str;
}

void	Data::setStr(std::string str)
{
	_str = str;
}

int	Data::getInt() const
{
	return _int;
}

void	Data::setInt(int i)
{
	_int = i;
}

float	Data::getFloat() const
{
	return _float;
}

void	Data::setFloat(float f)
{
	_float = f;
}
