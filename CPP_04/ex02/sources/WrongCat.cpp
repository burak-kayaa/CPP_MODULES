#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	this->brain = new Brain();
	int	i = -1;
	while (++i < 100)
		this->brain->setIdea("I am a wrong cat", i);
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	this->brain = new Brain();
	int	i = -1;
	while (++i < 100)
		this->brain->setIdea("I am a wrong cat", i);
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat)
{
	*this = cat;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &cat)
{
	WrongAnimal::operator=(cat);
	std::cout << "WrongCat assignation operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	delete this->brain;
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}

void	WrongCat::setIdea(std::string idea, int index)
{
	this->brain->setIdea(idea, index);
}

void	WrongCat::getIdea(int index) const
{
	std::cout << this->brain->getIdea(index) << std::endl;
}
