#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &wronganimal);
		WrongAnimal		&operator=(const WrongAnimal &wronganimal);
		virtual			~WrongAnimal();
		std::string		getType() const;
		void			setType(std::string type);
		virtual void	makeSound() const;
};

#endif