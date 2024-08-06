#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(Cure const &src)
{
	*this = src;
}

Cure::~Cure() {}

Cure	&Cure::operator=(Cure const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

AMateria	*Cure::clone() const
{
	Cure *clone = new Cure(*this);
	return (clone);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
