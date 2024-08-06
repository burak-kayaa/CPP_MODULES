#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain();
	int	i = -1;
	while (++i < 100)
		this->brain->setIdea("I am a cat", i);
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	this->brain = new Brain();
	int	i = -1;
	while (++i < 100)
		this->brain->setIdea("I am a cat", i);
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	Animal::operator=(cat);
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

void	Cat::setIdea(std::string idea, int index)
{
	this->brain->setIdea(idea, index);
}

void	Cat::getIdea(int index) const
{
	std::cout << this->brain->getIdea(index) << std::endl;
}