#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &Cat);
		Cat		&operator=(const Cat &Cat);
		virtual	~Cat();
		void	makeSound() const;
};

#endif