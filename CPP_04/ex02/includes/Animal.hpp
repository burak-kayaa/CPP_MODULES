#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		Animal();
		Animal(std::string name);
		std::string type;
	public:
		Animal(const Animal &animal);
		Animal		&operator=(const Animal &animal);
		virtual		~Animal();
		std::string	getType() const;
		void		setType(std::string name);
		virtual void	makeSound() const;
};

#endif