#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(Ice const &src)
{
	*this = src;
}

Ice::~Ice() {}

Ice	&Ice::operator=(Ice const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

AMateria	*Ice::clone() const
{
	Ice *clone = new Ice(*this);
	return (clone);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}