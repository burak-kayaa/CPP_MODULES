#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	int	i = -1;
	while (++i < 100)
		this->brain->setIdea("I am a dog", i);
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	this->brain = new Brain();
	int	i = -1;
	while (++i < 100)
		this->brain->setIdea("I am a dog", i);
	std::cout << "Dog name constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	Animal::operator=(dog);
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

void	Dog::setIdea(std::string idea, int index)
{
	this->brain->setIdea(idea, index);
}

void	Dog::getIdea(int index) const
{
	std::cout << this->brain->getIdea(index) << std::endl;
}